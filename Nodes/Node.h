#pragma once

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <exception>
#include <string>

#include <set>
#include "../Build/location.hh"


enum class NodeType {

    SCOPE,

    VALUE,
    VARIABLE,

    ADD,
    SUB,
    MUL,
    DIV,
    REM,

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

    FUNCSCOPE,
    ARGS,

    FUNCTION,
    RETURN,

    ERROR
};

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

class BraceNode : public Node {

protected:

    std::unordered_map<std::string, int> table_;
    std::set<std::string> FuncList_;

    std::vector<Node*> expressions_ = {};

    Node* returned_ = nullptr;

    BraceNode* ThisFunc_ = nullptr;

public:

    explicit BraceNode(const yy::location& l, NodeType type, BraceNode* ThisFunc = nullptr) :
             Node(type, l), ThisFunc_(ThisFunc) {};

    virtual bool AddValue(const std::string& varname, int value = 0) = 0;
    virtual bool GetValue(const std::string& varname, int& value) const = 0;

    virtual void AddFuncVariable(const std::string& name) = 0;
    virtual bool GetFuncVariable(const std::string& name) const = 0;

    void AddReturnedValue(Node* returnNode);
    bool IsReturned() const {return returned_ != nullptr;};

    std::unordered_map<std::string, int> GetValuess() const;
    void UpdateValuess(const std::unordered_map<std::string, int>& table);

    bool PushNode(Node* node);

    int Calc () final;

    virtual BraceNode* GetParent() = 0;
    virtual NodeType WhoAmI() const = 0;

public:

    BraceNode(const BraceNode& rhs) = delete;
    BraceNode& operator=(const BraceNode& rhs) = delete;

    BraceNode(BraceNode&& rhs) = delete;
    BraceNode& operator=(BraceNode&& rhs) = delete;

    virtual ~BraceNode();
};

class FuncScopeNode final : public BraceNode {

private:

    std::string func_name = {};
    BraceNode* parentScope_ = nullptr;
    std::vector<std::string> args_;

public:

    explicit FuncScopeNode(const yy::location& l, BraceNode* parent) :
            BraceNode(l, NodeType::FUNCSCOPE), parentScope_(parent) {}

    bool AddValue(const std::string& varname, int value = 0) override;
    bool GetValue(const std::string& varname, int& value) const override;

    void AddFuncVariable(const std::string& name) override;
    bool GetFuncVariable(const std::string& name) const override;

    void SetArgs(std::vector<std::string> args);

    void SetName (const std::string& name) {func_name = name;};
    std::string GetName () {return func_name;};

public:

    BraceNode* GetParent() override {return parentScope_;};
    NodeType WhoAmI() const override {return NodeType::FUNCSCOPE;};

    int Execute(std::vector<int> args);

    ~FuncScopeNode() = default;
};


class ScopeNode final : public BraceNode {

private:
    BraceNode* parentScope_ = nullptr;

public:

    explicit ScopeNode(const yy::location& l, BraceNode* parent = nullptr, FuncScopeNode* ThisFunc = nullptr) :
    BraceNode(l, NodeType::SCOPE, ThisFunc), parentScope_(parent) {};

    bool AddValue(const std::string& varname, int value = 0) override;
    bool GetValue(const std::string& varname, int& value) const override;

    void AddFuncVariable(const std::string& name) override;
    bool GetFuncVariable(const std::string& name) const override;

public:

    BraceNode* GetParent() override {return parentScope_;};
    NodeType WhoAmI() const override;

    ~ScopeNode() = default;
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
    std::vector<Node*> conditions_;
    ScopeNode* scope_;
    ScopeNode* else_scope_;

public:

    ConditionNode(std::vector<Node*> conditions, ScopeNode* scope,
                  NodeType type, const yy::location& l, ScopeNode* else_node = nullptr) :
                  Node(type, l), conditions_(std::move(conditions)), scope_(scope), else_scope_(else_node) {};

    int Calc() override;
    bool CheckCondition();

    ~ConditionNode() noexcept {for (auto& c: conditions_) delete c; delete scope_; };
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

/*class ArgsNode final : public Node {

private:
    std::vector<std::string> names_;


public:

    explicit ArgsNode( const yy::location& l) : Node(NodeType::ARGS, l) {};

    bool AddArg(std::string name);
    std::vector<std::string> GetArgsNames() const {return names_;};


    int Calc() override;

    ~ArgsNode() = default;

};*/

class FuncNode final: public Node {

private:
    std::string name_;
    std::vector<Node*> args_;
public:

    FuncNode(const yy::location l, std::string name, std::vector<Node*> args) :
        Node(NodeType::FUNCTION, l),name_(std::move(name)), args_(args) {};

    std::string GetName() const {return name_;};

    int Calc() override;

    ~FuncNode() = default;
};

class ReturnNode final : public Node {

private:

    BraceNode* ReturnTo_;
    Node* arg_;

public:

    ReturnNode(const yy::location& l, Node* arg, BraceNode* ReturnTo) :
        Node(NodeType::RETURN, l), arg_(arg), ReturnTo_(ReturnTo) {};

    int Calc() override;


    ~ReturnNode() {delete arg_;};
};



class FuncTable final {

private:
    std::unordered_map<std::string, FuncScopeNode*> global_table;

    std::unordered_map<std::string, FuncScopeNode*> local_table;

    std::unordered_map<std::string, std::string> repeated_table;

public:

    FuncTable() = default;

    //LocalTable
    void AddLocalFunc(const std::string& name, FuncScopeNode* f_Scope);
    //-----------------------

    void AddGlobalFunc(const std::string& name, FuncScopeNode* f_Scope, bool update = false);

    void AddRepeatFunc(const std::string& name, const std::string& global_func, bool update = false);

    bool CheckGlobalFunc(const std::string& name) const { return global_table.count(name);};
    int Execute(const std::string&, const std::vector<int>& args);

    //Ctors and etc...

    FuncTable(const FuncTable& rhs) = delete;
    FuncTable& operator = (const FuncTable& rhs) = delete;

    FuncTable(FuncTable&& rhs) = delete;
    FuncTable& operator = (FuncTable&& rhs) = delete;

    void DeleteAll() ;

    ~FuncTable() = default;

};
