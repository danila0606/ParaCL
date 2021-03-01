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

            ans = exp->Calc();

            if (returned_ != nullptr)
                return returned_->Calc();

            ++i;
        }
        return ans;
    }
    else if (GetType() == NodeType::SCOPE) {

        for (auto &exp : expressions_) {

            ans = exp->Calc();

            if (ThisFunc_) {
                if (!ThisFunc_->IsReturned())
                    return 322;
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

void BraceNode::AddReturnedValue(Node* returnNode) {

    if (WhoAmI() != NodeType::FUNCSCOPE)
        throw std::invalid_argument("You can only use return in functions!");

    if (GetType() == NodeType::FUNCSCOPE) {
        returned_ = returnNode;
    }
    else if (GetType() == NodeType::SCOPE) {
        if (!GetParent())
            GetParent()->AddReturnedValue(returnNode);
        else
            assert(0);
    }
    else
        assert(0);
}

std::unordered_map<std::string, int> BraceNode::GetValuess() const {

    if (ThisFunc_)
        return  ThisFunc_->GetValuess();
    else
        return table_;
}

void BraceNode::UpdateValuess(const std::unordered_map<std::string, int>& table) {


    if (ThisFunc_)
        ThisFunc_->UpdateValuess(table);
    else
        table_ = table;
}

//_______________________________________________________________


//_________________________ScopeNode___________________________________

bool ScopeNode::AddValue(const std::string &varname, int value) {

    if (table_.find(varname) == table_.end()) {
        if (parentScope_) {
            int x = 0;
            if (parentScope_->GetValue(varname, x))
                return parentScope_->AddValue(varname, value);
            else if (WhoAmI() == NodeType::FUNCSCOPE) {



            } else
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

NodeType ScopeNode::WhoAmI() const {
    if (!parentScope_)
        return NodeType::SCOPE;
    else
        return parentScope_->WhoAmI();
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
    for (const auto& elem : args_)
        AddValue(elem, 0);
}

int FuncScopeNode::Execute(std::vector<int> elems) {

    if (elems.size() != args_.size()) {
        throw std::invalid_argument("When calling the function: " + func_name +" used: "
            + std::to_string(elems.size()) + " args, instead of: " + std::to_string(args_.size()));
    }

    for (int i = 0; i < elems.size(); ++i) {

        AddValue(args_[i], elems[i]);
    }

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
        assert(0);
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
        //CurScope = OldScope;

        CurScope->AddValue(left_->GetName(), rhs);
    }
    else
        CurScope->AddValue(left_->GetName(), right_->Calc());

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
                return 0;
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

/*int ArgsNode::Calc() {

    return names_.size();

}

bool ArgsNode::AddArg(std::string name) {

    for (const auto& elem : names_) {

        if (elem == name)
            return false;
    }

    names_.push_back(name);
    return true;
}*/

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

    ReturnTo_->AddReturnedValue(arg_);
    return 228;
}

//_______________________________________________________________

//______________________FuncTable_________________________________

void FuncTable::AddLocalFunc(const std::string& name, FuncScopeNode* f_Scope) {

    auto it_local = local_table.find(name);
    auto it_repeat = repeated_table.find(name);

    auto it_global = global_table.find(name);

    if (it_global != global_table.end())
        assert(0);

    if (it_local!= local_table.end())
        delete local_table[name];

    if (it_repeat != repeated_table.end())
        repeated_table.erase(name);

    local_table[name] = f_Scope;

}

void FuncTable::AddGlobalFunc(const std::string& name, FuncScopeNode* f_Scope, bool update ) {
    auto it_global = global_table.find(name);

    auto it_local = local_table.find(name);
    auto it_repeat = repeated_table.find(name);

    if (it_local!= local_table.end())
        delete local_table[name];

    if (it_repeat != repeated_table.end())
        repeated_table.erase(name);

    if (it_global != global_table.end()) {
        if (update)
            global_table[name] = f_Scope;
        else
            throw std::invalid_argument("the function name is already taken: " + name);
    }
    else
        global_table[name] = f_Scope;

}

void FuncTable::AddRepeatFunc(const std::string& name, const std::string& global_func, bool update) {
    auto it_global = global_table.find(global_func);
    auto it_local = local_table.find(name);

    if (it_global != global_table.end()) {
        if (!update)
            throw std::invalid_argument("the function name is already taken: " + name);
    }


    if (it_local!= local_table.end())
        delete local_table[name];

    repeated_table[name] = global_func;
}

int FuncTable::Execute(const std::string& name, const std::vector<int>& args) {

    OldScope = CurScope;

    std::unordered_map<std::string, int> old_table;

    bool update = false;

    if (CurScope->WhoAmI()== NodeType::FUNCSCOPE) {
        update = true;
        old_table = OldScope->GetValuess();
    }

    auto global_it = global_table.find(name);
    auto repeat_it = repeated_table.find(name);
    auto local_it = local_table.find(name);

    int ans = 0;

    if (global_it != global_table.end()) {
        CurScope = global_table[name];
        ans = global_table[name]->Execute(args);
    }
    else if (repeat_it != repeated_table.end()) {
        CurScope = global_table[repeated_table[name]];
        ans = global_table[repeated_table[name]]->Execute(args);
    }
    else if (local_it != local_table.end()) {
        CurScope = local_table[name];
        ans = local_table[name]->Execute(args);
    }
    else
        assert(0);


    if (update) {
        OldScope->UpdateValuess(old_table);
    }

    return ans;
}

void FuncTable::DeleteAll() {

    for (auto& elem : global_table)
        delete elem.second;

    for (auto& elem : local_table)
        delete elem.second;
}

//_______________________________________________________________