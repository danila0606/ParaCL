%language "c++"

%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define parse.error custom


%param {yy::Driver* driver}
%locations

%code requires
{
    #include <algorithm>

    #include "../Nodes/Node.h"
    namespace yy {
        class Driver;
    }

}

%code
{
    #include "../Nodes/driver.h"
    #include "../Nodes/Node.h"

    namespace yy {
        parser::token_type yylex(parser::semantic_type* yylval, parser::location_type* location, Driver* driver);
        //void parser::report_syntax_error (parser::context const& context) const;

    }

    extern BraceNode* CurScope;
    extern FuncTable func_table;
    FuncScopeNode* CurFunc;
}

%token
  ADD 			"+"
  SUB			"-"
  MUL			"*"
  DIV			"/"
  ASSIGN		"="
  REM           "%"

  LB	        "("
  RB         	")"
  LFB   		"{"
  RFB       	"}"

  GREATER	  	">"
  GREATER_OR_EQ	">="
  LESS  		"<"
  LESS_OR_EQ  	"<="
  EQUAL  		"=="
  NOT_EQUAL  	"!="

  AND           "&&"

  IF			"if"
  ELSE          "else"
  WHILE			"while"
  PRINT			"print"
  SCAN			"?"
  SCOLON  		";"

  FUNCTION      "func"
  RETURN        "return"
  COLON         ":"
  COMMA         ","

  ERROR
;

%token <int> VALUE
%token <std::string> VARIABLE
%nterm <std::string> GLOBAL_FUNC

%nterm <Node*> exprLvl1 exprLvl2 exprLvl3
%nterm <Node*> assignment
%nterm <Node*> stream
%nterm <Node*> condition
%nterm <Node*> math_op
%nterm <Node*> scope
%nterm <Node*> inside_scope
%nterm <Node*> scope_assignment
%nterm <std::vector<std::string>> ARGS
%nterm <std::vector<std::string>> ARGS_C
%nterm <std::vector<Node*>> PARAMS
%nterm <std::vector<Node*>> PARAMS_C

%nterm <std::vector<Node*>> CONS

%nterm <Node*> func_scope
%nterm <Node*> f_inside_scope

%nterm <Node*> return
%nterm <Node*> function
%nterm <Node*> act

%nterm <ScopeNode*> ACTION
%nterm <ScopeNode*> els


%left '+' '-'
%left '*' '/'

%start inside_scope

%%

scope:
	begin_scope inside_scope end_scope			{ $$ = CurScope; CurScope = CurScope->GetParent(); }
;

begin_scope:
	LFB  								{
											ScopeNode* child = new ScopeNode (@1,CurScope, CurFunc);
											CurScope = child;
										}
;

inside_scope:
	inside_scope assignment SCOLON 		{ CurScope->PushNode ($2); }
|	inside_scope stream SCOLON 		    { CurScope->PushNode ($2); }
|	inside_scope condition				{ CurScope->PushNode ($2); }
|   inside_scope func                   { /* nothing */ }
|   inside_scope func SCOLON            { /* nothing */ }
|   inside_scope exprLvl1 SCOLON        { CurScope->PushNode($2); }
|   inside_scope return SCOLON          { CurScope->PushNode($2); }
|   inside_scope scope                  { CurScope->PushNode($2); }
|   inside_scope scope_assignment       {  CurScope->PushNode($2);}
|										{ /* nothing */ }
;

end_scope:
	RFB	{ }
;

func_scope:
	 f_begin_scope f_inside_scope end_scope			{ $$ = CurScope; CurScope = CurScope->GetParent(); CurFunc = nullptr;}
;

f_begin_scope:
	LB ARGS RB LFB  					{


											BraceNode* child = new FuncScopeNode (@1, CurScope);
											static_cast<FuncScopeNode*>(child)->SetArgs($2);
											for (const auto& elem : $2)
											    child->AddValue(elem, 0);

											CurScope = child;
											CurFunc = static_cast<FuncScopeNode*>(child);
										}
|   LB ARGS RB COLON GLOBAL_FUNC LFB		{

  											BraceNode* child = new FuncScopeNode (@1, CurScope);
  											static_cast<FuncScopeNode*>(child)->SetArgs($2);

  											static_cast<FuncScopeNode*>(child)->SetName($5);



  											for (const auto& elem : $2)
  											    child->AddValue(elem, 0);

  											CurScope = child;
  											CurFunc = static_cast<FuncScopeNode*>(child);
  										}
;

GLOBAL_FUNC :
    VARIABLE {
                                                    int x;
          											if (!CurScope->GetValue($1,x) || !CurScope->GetFuncVariable($1)) {

          											    func_table.AddGlobalFunc($1, nullptr);
          											    }
          											else
          											    assert(0);

          											$$ = $1;
    }
;

f_inside_scope:
	inside_scope assignment SCOLON 		{ CurScope->PushNode ($2); }
|	inside_scope stream SCOLON 		    { CurScope->PushNode ($2); }
|	inside_scope condition				{ CurScope->PushNode ($2); }
|   inside_scope exprLvl1 SCOLON        { CurScope->PushNode ($2); }
|   inside_scope return SCOLON          { CurScope->PushNode ($2); }
|										{ /* nothing */            }
;

condition:

    IF LB CONS RB ACTION els { $$ = new ConditionNode($3, static_cast<ScopeNode*>($5), NodeType::IF, @1, $6);}
|   WHILE LB CONS RB ACTION  { $$ = new ConditionNode($3, static_cast<ScopeNode*>($5), NodeType::WHILE, @1) ;}

ACTION :
    scope { $$ = static_cast<ScopeNode*>($1);                        }
|   act   { ScopeNode* child = new ScopeNode (@1,CurScope, CurFunc);
            child->PushNode($1);
            $$ = child;  child = nullptr;                            }
;

act:
    	 stream SCOLON 		    { $$ = $1; }
    |	 condition			    { $$ = $1; }
    |    exprLvl1 SCOLON        { $$ = $1; }
    |    return SCOLON          { $$ = $1; }
    |    scope_assignment       { $$ = $1; }
    |    assignment SCOLON 		{ $$ = $1; }
;

els :
       ELSE ACTION { $$ = $2;     }
|                  { $$ = nullptr;}
;


CONS : math_op          { $$.push_back($1);       }
|      math_op AND CONS { $$.push_back($1);

                          for (const auto& elem : $3)
                              $$.push_back(elem);
                                                  }
;

func :

    VARIABLE ASSIGN FUNCTION func_scope { FuncScopeNode* f_ptr = static_cast<FuncScopeNode*> ($4);
                                          CurScope->AddFuncVariable($1);

                                          if (!f_ptr->GetName().empty()) {
                                              func_table.AddGlobalFunc(f_ptr->GetName(), f_ptr, true);
                                              func_table.AddRepeatFunc($1, f_ptr->GetName(), true);
                                          }
                                          else
                                              func_table.AddLocalFunc($1, f_ptr);
    }
;

ARGS :

    ARGS_C {     $$ = $1;    }
|          {/*no arguments */}

;


ARGS_C :
        VARIABLE COMMA ARGS_C { $$.push_back($1);

                                for (const auto& elem : $3)
                                   $$.push_back(elem);         }

    |   VARIABLE              { $$.push_back($1);              }
;

PARAMS :


    PARAMS_C {     $$ = $1;    }
|            {/*no arguments */}
;

PARAMS_C :
        exprLvl1 COMMA PARAMS_C {
                                $$.push_back($1);

                                for (const auto& elem : $3)
                                    $$.push_back(elem);

                                                            }
    |   exprLvl1                {     $$.push_back($1);     }
;

return :
    RETURN exprLvl1 {   if (CurFunc == nullptr)
                            assert(0);

                        $$ = new ReturnNode(@1, $2, CurFunc);
                    }
;

math_op:
	exprLvl1 GREATER exprLvl1			{ $$ = new MathOpNode ($1, $3, NodeType::GREATER, @2); }
|	exprLvl1 GREATER_OR_EQ exprLvl1		{ $$ = new MathOpNode ($1, $3, NodeType::GREATER_OR_EQ, @2); }
|	exprLvl1 LESS exprLvl1				{ $$ = new MathOpNode ($1, $3, NodeType::LESS, @2); }
|	exprLvl1 LESS_OR_EQ exprLvl1		{ $$ = new MathOpNode ($1, $3, NodeType::LESS_OR_EQ, @2); }
|	exprLvl1 EQUAL exprLvl1				{ $$ = new MathOpNode ($1, $3, NodeType::EQUAL, @2); }
|	exprLvl1 NOT_EQUAL exprLvl1			{ $$ = new MathOpNode ($1, $3, NodeType::NOT_EQUAL, @2); }
;

function :

    VARIABLE LB PARAMS RB {
        if (!CurScope->GetFuncVariable ($1)) {
            if (!func_table.CheckGlobalFunc($1))
                driver->EmergencyExit(@1, yy::Errors::non_existent_variable);
        }
        $$ = new FuncNode(@1,$1, $3);
    }

assignment:
	VARIABLE ASSIGN exprLvl1	{
									CurScope->AddValue($1, 0);
								  	$$ = new AssignNode(new VariableNode($1, @1), $3, @2);
								}
;

scope_assignment:
    VARIABLE ASSIGN scope {
        CurScope->AddValue($1, 0);

        $$ = new AssignNode(new VariableNode($1, @1), $3, @2);
    }
;

stream:
	PRINT exprLvl1				{ $$ = new  PrintNode($2, @1, driver->GetOstream()); }
|	VARIABLE ASSIGN SCAN		{
                                    CurScope->AddValue($1, 0.0);

								  	$$ = new ScanNode(new VariableNode($1, @1), @2);
								}
;

exprLvl1:
	exprLvl2 ADD exprLvl1  	{ $$ = new MathOpNode($1, $3, NodeType::ADD, @2); }
| 	exprLvl2 SUB exprLvl1 	{ $$ = new MathOpNode($1, $3, NodeType::SUB, @2); }
| 	exprLvl2				{ $$ = $1; }
;

exprLvl2:
	exprLvl3 MUL exprLvl2  	{ $$ = new MathOpNode($1, $3, NodeType::MUL, @2); }
| 	exprLvl3 DIV exprLvl2 	{ $$ = new MathOpNode($1, $3, NodeType::DIV, @2); }
| 	exprLvl3 REM exprLvl2 	{ $$ = new MathOpNode($1, $3, NodeType::REM, @2); }
| 	exprLvl3				{ $$ = $1; }
;

exprLvl3:
	LB exprLvl1 RB  { $$ = $2; }
| 	VALUE   		{ $$ = new ValueNode($1, @1); }
|	VARIABLE		{
											int x;
											if (!CurScope->GetValue ($1, x)) {
                                                    driver->EmergencyExit(@1, yy::Errors::non_existent_variable);
                                            }
											$$ = new VariableNode($1, @1);
					}

|    function {
            $$ = $1;
          }
;

%%
namespace yy {

	parser::token_type yylex (parser::semantic_type* yylval, parser::location_type* location, Driver* driver) {
		return driver->yylex (yylval, location);
	}

	void parser::error (const parser::location_type& location, const std::string& string) {
	    if (!(driver->IsGrammarError()))
	        driver->EmergencyExit(location, yy::Errors::syntax_error);
	}

    void parser::report_syntax_error (parser::context const& context) const {
        if (!(driver->IsGrammarError()))
		    driver->EmergencyExit(context.location (), yy::Errors::syntax_error);
	}

}