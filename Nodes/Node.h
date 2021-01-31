#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <exception>
#include <string>
#include "../Build/location.hh"


enum class NodeType {

    SCOPE,

    VALUE,
    VARIABLE,

    ADD,
    SUB,
    MUL,
    DIV,

    ASSIGN,

    GREATER,
    GREATER_OR_EQ,
    LESS,
    LESS_OR_EQ,
    EQUAL,
    NOT_EQUAL,

    IF,
    WHILE,
    SCAN,
    PRINT,

    ERROR
};

/*class VariableTable final {

private:
    std::unordered_map<std::string, double> table;

public:
    VariableTable() = default;

    bool GetValue(const std::string& varname, double value) const;
    bool UpdateValue(const std::string& varname, double value);
    bool AddValue(const std::string& varname, double value = 0.0);

    VariableTable(const VariableTable& rhs) = delete;
    VariableTable& operator=(const VariableTable& rhs) = delete;

    VariableTable(VariableTable&& rhs) = delete;
    VariableTable& operator=(VariableTable&& rhs) = delete;
}*/

class Node {

protected:
    yy::location location_;
    NodeType type_;


public:

    explicit Node(NodeType type, const yy::location& l) : type_(type), location_(l) {};
    virtual ~Node() = default;


   NodeType GetType() const { return type_;};
   yy::location GetLocation() const {return location_;};

   virtual int Calc() = 0;

};

class ScopeNode final: public Node {

private:
    ScopeNode* parentScope_ = nullptr;

    std::unordered_map<std::string, double> table_;
    std::vector<Node*> expressions_ = {};

public:

    explicit ScopeNode(const yy::location& l, ScopeNode* parent = nullptr) :
    Node(NodeType::SCOPE, l), parentScope_(parent) {};

    bool AddValue(const std::string& varname, int value = 0);
    bool GetValue(const std::string& varname, int& value) const;
    bool PushNode(Node* node);

    ScopeNode* GetParent() {return parentScope_;};


    int Calc() override;


    ScopeNode(const ScopeNode& rhs) = delete;
    ScopeNode& operator=(const ScopeNode& rhs) = delete;

    ScopeNode(ScopeNode&& rhs) = delete;
    ScopeNode& operator=(ScopeNode&& rhs) = delete;

    ~ScopeNode() noexcept;
};

class ValueNode final : public Node {

private:
    const double value_;

public:

   explicit ValueNode(double value, const yy::location& l) : Node(NodeType::VALUE, l),value_(value) {};
   ~ValueNode() = default;

    int Calc() override;

};

class VariableNode final : public Node {

private:
    const std::string varname_;

public:

    explicit VariableNode(const std::string& varname, const yy::location& l) :
    Node(NodeType::VARIABLE, l),varname_(varname) {};

    ~VariableNode() = default;

    int Calc() override;
    std::string GetName() const {return varname_;};

};

class MathOpNode final: public Node {

private:
    Node* left_;
    Node* right_;

public:
    explicit MathOpNode(Node* left, Node* right, NodeType type, const yy::location& l)
    : Node(type, l), left_(left), right_(right) {};

    int Calc() override;

    ~MathOpNode() noexcept { delete left_; delete right_;};
};

class AssignNode final: public Node {

private:
    VariableNode* left_;
    Node* right_;

public:
    explicit AssignNode(VariableNode* left, Node* right, const yy::location& l) :
    Node(NodeType::ASSIGN, l), left_(left), right_(right) {};

    int Calc() override;

    ~AssignNode() noexcept { delete left_; delete right_;};
};

class ConditionNode final: public Node {

private:
    Node* condition_;
    ScopeNode* scope_;

public:

    ConditionNode(Node* condition, ScopeNode* scope, NodeType type, const yy::location& l) :
    Node(type, l), condition_(condition), scope_(scope) {};

    int Calc() override;

    ~ConditionNode() noexcept {delete condition_; delete scope_; };
};

class PrintNode final : public Node {

private:
    Node* arg_;
    std::ostream& out_ = std::cout;

public:

    explicit PrintNode(Node* arg, const yy::location& l, std::ostream& out = std::cout) :
    Node(NodeType::PRINT, l), out_(out), arg_(arg) {};

    int Calc() override;

    ~PrintNode() noexcept {delete arg_;};

};

class ScanNode final : public Node {

private:
    VariableNode* arg_;

public:

    explicit ScanNode(VariableNode* arg, const yy::location& l) : Node(NodeType::SCAN, l),
        arg_(arg) {};

    int Calc() override;

    ~ScanNode() noexcept {delete arg_;};

};
