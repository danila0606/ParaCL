#include "Node.h"
#include <cassert>
#include <sstream>

extern ScopeNode* CurScope;

std::stringstream ostr;

#ifdef GTESTS
#define OUT ostr
#else
#define OUT std::cout
#endif

//_________________________ScopeNode___________________________________

bool ScopeNode::AddValue(const std::string &varname, int value) {

    if (table_.find(varname) == table_.end()) {
        if (parentScope_) {
            int x = 0;
            if (parentScope_->GetValue(varname, x))
                return parentScope_->AddValue(varname, value);
            else
                table_[varname] = value;
        }
        else
            table_[varname] = value;

        return true;
    }
    else {
        table_[varname] = value;
        return false;
    }
}

bool ScopeNode::GetValue(const std::string &varname, int& value) const {

    auto it = table_.find(varname);

    if (it == table_.end()) {
        if (parentScope_)
            return parentScope_->GetValue(varname, value);
        else
            return false;
    }
    else
        value = it->second;

    return true;
}

/*bool ScopeNode::UpdateValue(const std::string &varname, double value) {

    auto it = table_.find(varname);

    if (it == table_.end())
        return false;
    else
        it->second = value;

    return true;
}*/

bool ScopeNode::PushNode(Node *node) {
    if (node == nullptr)
        return false;

    expressions_.push_back(node);
    return true;
}

int ScopeNode::Calc() {

    double ans = 0.0;
    int i = 0;
    for (auto& exp : expressions_) {
        if (!i)
            ans = exp->Calc();
        else
            exp->Calc();
        i++;
    }

    return ans;
}

ScopeNode::~ScopeNode() noexcept {

    for (auto& node : expressions_)
        delete node;
}

//_______________________________________________________________

//______________________ValueNode________________________________

int ValueNode::Calc() {
    return value_;
}

//_______________________________________________________________

//______________________VariableNode_____________________________

int VariableNode::Calc() {
    int x;
    CurScope->GetValue(varname_, x);
    return x;
}

//_______________________________________________________________

//______________________MathOpNode_____________________________

int MathOpNode::Calc() {

    switch (type_) {
        case NodeType::ADD: {
            return left_->Calc() + right_->Calc();
        }
        case NodeType::SUB: {
            return left_->Calc() - right_->Calc();
        }
        case NodeType::MUL: {
            return left_->Calc() * right_->Calc();
        }
        case NodeType::DIV: {
            int divisor = right_->Calc();
            if (!divisor) {
                std::string message = std::string("Division by zero {\n") +
                                      std::string("\tOn line: ") + std::to_string(right_->GetLocation().begin.line);

                message += "\n}";

                std::cerr << message << std::endl;
                exit(0);
                break;
            }
            return left_->Calc() / right_->Calc();
        }
        case NodeType::GREATER: {
            return (left_->Calc() > right_->Calc());
        }
        case NodeType::GREATER_OR_EQ: {
            return (left_->Calc() >= right_->Calc());
        }
        case NodeType::LESS: {
            return (left_->Calc() < right_->Calc());
        }
        case NodeType::LESS_OR_EQ: {
            return (left_->Calc() <= right_->Calc());
        }
        case NodeType::EQUAL: {
            return (left_->Calc() == right_->Calc());
        }
        case NodeType::NOT_EQUAL: {
            return (left_->Calc() != right_->Calc());
        }
    }

    assert(0);
}

//_______________________________________________________________

//______________________AssignNode_______________________________

int AssignNode::Calc() {

    if(left_->GetType()!= NodeType::VARIABLE)
        assert(0);

    CurScope->AddValue(left_->GetName(), right_->Calc());

    return 0.0;
}

//_______________________________________________________________

//______________________ConditionNode____________________________

int ConditionNode::Calc() {

    switch(type_) {
        case (NodeType::IF) : {

            if (condition_->Calc() != 0) {
                CurScope = scope_;
                CurScope->Calc();
                CurScope = scope_->GetParent();
            }
                return 0.0;
        }
        case (NodeType::WHILE) : {
            while (condition_->Calc() != 0) {
                CurScope = scope_;
                CurScope->Calc();
                CurScope = scope_->GetParent();
            }
            return 0.0;
        }
    }

    assert(0);

}

//_______________________________________________________________

//______________________PrintNode_______________________________

int PrintNode::Calc() {

    if (!arg_)
        assert(0);


    OUT<<arg_->Calc()<<std::endl;


    return 0.0;
}

//_______________________________________________________________

//______________________ScanNode_________________________________

int ScanNode::Calc() {

    if (!arg_)
        assert(0);

    double x = 0.0;
    std::cin>>x;

    CurScope->AddValue(arg_->GetName(),x);

    return 0.0;
}
//_______________________________________________________________