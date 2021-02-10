#include "Node.h"
#include <cassert>
#include <sstream>
#include <utility>

extern BraceNode* CurScope;
extern FuncTable func_table;

BraceNode* OldScope = nullptr;

std::stringstream ostr;

#ifdef GTESTS
#define OUT ostr
#else
#define OUT std::cout
#endif

//______________________BraceNode________________________________

BraceNode::~BraceNode() noexcept {

    for (auto& node : expressions_)
        delete node;
}

bool BraceNode::PushNode(Node *node) {
    if (node == nullptr)
        return false;

    expressions_.push_back(node);
    return true;
}

int BraceNode::Calc() {

    int ans = 0;
    int i = 0;

    if (GetType() == NodeType::FUNCSCOPE) {
        for (auto &exp : expressions_) {
            //std::cout<<CurScope<<std::endl;


            ans = exp->Calc();


            if (!returned_.empty()) {
                return returned_[0];

            }

            ++i;
        }
        return ans;
    }
    else if (GetType() == NodeType::SCOPE) {

        for (auto &exp : expressions_) {
            //std::cout<<CurScope<<std::endl;
            ans = exp->Calc();

            if (ThisFunc_) {
                if (!ThisFunc_->returned_.empty()) {
                    return 322;
                }
            }

            ++i;
        }
        return ans;
    } else
        assert(0);

   /* if (!returned_.empty())
        return returned_[0];
    else
        return ans;*/
}

void BraceNode::AddReturnedValue(int ans) {

    if (GetType() == NodeType::FUNCSCOPE) {
        returned_.push_back(ans);
        //std::cout<<"1\n";
    }
    else if (GetType() == NodeType::SCOPE) {
        if (!GetParent()) {
            //std::cout<<"2\n";
            GetParent()->AddReturnedValue(ans);
            //std::cout<<"3\n";
        }
        else
            assert(0);
    }
    else
        assert(0);

}


//_______________________________________________________________


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

void ScopeNode::AddFuncVariable(const std::string& name) {

    if (FuncList_.find(name) == FuncList_.end()) {
        if (parentScope_) {
            if (parentScope_->GetFuncVariable(name))
                return parentScope_->AddFuncVariable(name);
            else
                FuncList_.insert(name);
        }
        else
            FuncList_.insert(name);
    }
}

bool ScopeNode::GetFuncVariable(const std::string& name) const {

    auto it = FuncList_.find(name);

    if (it == FuncList_.end()) {
        if (parentScope_)
            return parentScope_->GetFuncVariable(name);
        else
            return false;
    }
    else
        return true;
}

//_______________________________________________________________


//______________________FuncScopeNode_____________________________

bool FuncScopeNode::AddValue(const std::string& varname, int value) {

    if (table_.find(varname) == table_.end()) {

        table_[varname] = value;
        return true;
    }
    else {

        table_[varname] = value;
        return false;
    }
}


bool FuncScopeNode::GetValue(const std::string& varname, int& value) const {

    auto it = table_.find(varname);

    if (it == table_.end())
        return false;
    else
        value = it->second;

    return true;
}

void FuncScopeNode::SetArgs(std::vector<std::string> args) {
    args_ = std::move(args);
    for (const auto& elem : args_) {
        //std::cout<<elem<<" ";
        CurScope->AddValue(elem, 0);
    }
}

int FuncScopeNode::Execute(std::vector<int> elems) {

    if (elems.size() != args_.size())
        assert(0);


    for (int i = 0; i < elems.size(); ++i) {
      //  std::cout<<args_[i]<<" "<<elems[i]<<std::endl;
        AddValue(args_[i], elems[i]);
        not_in_args_.erase(args_[i]);
       // std::cout<<args_[i]<<" "<<elems[i]<<std::endl;
    }

    if (!not_in_args_.empty())
        assert(0);

    return Calc();
}

void FuncScopeNode::AddFuncVariable(const std::string& name) {

    FuncList_.insert(name);
}

bool FuncScopeNode::GetFuncVariable(const std::string& name) const {

    return !(FuncList_.find(name) == FuncList_.end());
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

    if (!CurScope->GetValue(varname_, x)) {
        std::cout<<"OOOOOOps "<<varname_<<std::endl;
        exit(0);
    }

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

    if (right_->GetType() == NodeType::FUNCTION) {
        int rhs = right_->Calc();
        CurScope = OldScope;

        CurScope->AddValue(left_->GetName(), rhs);
    }
    else {
        CurScope->AddValue(left_->GetName(), right_->Calc());
    }

    return 3;
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
                if (CurScope->IsReturned())
                    return 10;
            }
            return 0;
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


    return 1;
}

//_______________________________________________________________

//______________________ScanNode_________________________________

int ScanNode::Calc() {

    if (!arg_)
        assert(0);

    int x = 0;
    std::cin>>x;

    CurScope->AddValue(arg_->GetName(),x);

    return 2;
}

//_______________________________________________________________

//______________________ArgsNode_________________________________

int ArgsNode::Calc() {

    return names_.size();

}

bool ArgsNode::AddArg(std::string name) {

    for (const auto& elem : names_) {

        if (elem == name)
            return false;
    }

    names_.push_back(name);
    return true;
}

//_______________________________________________________________

//______________________FuncNode_________________________________

int FuncNode::Calc() {

    std::vector<int> arguments(args_.size());
    for (int i = 0; i < arguments.size(); ++i)
        arguments[i] = args_[i]->Calc();

    return func_table.Execute(name_, arguments);
}



//_______________________________________________________________

//______________________ReturnNode_________________________________

int ReturnNode::Calc() {

    std::cout <<"returnCalc\n";
    ReturnTo_->AddReturnedValue(arg_->Calc());
    return 228;
}



//_______________________________________________________________

//______________________FuncTable_________________________________

void FuncTable::AddFunc(const std::string& name, FuncScopeNode* f_Scope) {

    table[name] = f_Scope;
}

bool FuncTable::Check(const std::string& name, size_t args_num) const {
    return table.count(name);
}

int FuncTable::Execute(const std::string& name, const std::vector<int>& args) {

    OldScope = CurScope;
    CurScope = table[name];

    return table[name]->Execute(args);
}



//_______________________________________________________________