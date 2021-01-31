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

    extern ScopeNode* CurScope;
}

%token
  ADD 			"+"
  SUB			"-"
  MUL			"*"
  DIV			"/"
  ASSIGN		"="

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

  IF			"if"
  WHILE			"while"
  PRINT			"print"
  SCAN			"?"
  SCOLON  		";"

  ERROR
;

%token <double> VALUE
%token <std::string> VARIABLE
//%token <std::string> error

%nterm <Node*> exprLvl1 exprLvl2 exprLvl3
%nterm <Node*> assignment
%nterm <Node*> stream
%nterm <Node*> condition
%nterm <Node*> math_op
%nterm <Node*> scope
%nterm <Node*> inside_scope
//%nterm <Node*> ERR


%left '+' '-'
%left '*' '/'

%start inside_scope

%%

scope:
	begin_scope inside_scope end_scope			{ $$ = CurScope; CurScope = CurScope->GetParent(); }
;

begin_scope:
	LFB  								{
											ScopeNode* child = new ScopeNode (@1,CurScope);
											CurScope = child;
										}
;

inside_scope:
	inside_scope assignment SCOLON 		{ CurScope->PushNode ($2); }
|	inside_scope stream SCOLON 		    { CurScope->PushNode ($2); }
|	inside_scope condition				{ CurScope->PushNode ($2); }
//|   ERR                                 {CurScope->PushNode ($1);}
|										{}
;

end_scope:
	RFB	{ }
;

//ERR :
//    ERR  error SCOLON {$$ = new ValueNode(0, @2);}
//|   LB error RB {$$ = new ValueNode(0, @2);}
//|   error {$$ = new ValueNode(0, @1);}
//|   error ERR  SCOLON {$$ = new ValueNode(0, @1);}
//|   error SCOLON {$$ = new ValueNode(0, @1);}
//;

condition:
	IF LB math_op RB scope	    { $$ = new ConditionNode($3, static_cast<ScopeNode*>($5), NodeType::IF, @1); }
|	WHILE LB math_op RB scope	{ $$ = new ConditionNode($3, static_cast<ScopeNode*>($5), NodeType::WHILE, @1); }
;

math_op:
	exprLvl1 GREATER exprLvl1			{ $$ = new MathOpNode ($1, $3, NodeType::GREATER, @2); }
|	exprLvl1 GREATER_OR_EQ exprLvl1		{ $$ = new MathOpNode ($1, $3, NodeType::GREATER_OR_EQ, @2); }
|	exprLvl1 LESS exprLvl1				{ $$ = new MathOpNode ($1, $3, NodeType::LESS, @2); }
|	exprLvl1 LESS_OR_EQ exprLvl1		{ $$ = new MathOpNode ($1, $3, NodeType::LESS_OR_EQ, @2); }
|	exprLvl1 EQUAL exprLvl1				{ $$ = new MathOpNode ($1, $3, NodeType::EQUAL, @2); }
|	exprLvl1 NOT_EQUAL exprLvl1			{ $$ = new MathOpNode ($1, $3, NodeType::NOT_EQUAL, @2); }
;

assignment:
	VARIABLE ASSIGN exprLvl1	{
\
									CurScope->AddValue($1, 0.0);

								  	$$ = new AssignNode(new VariableNode($1, @1), $3, @2);

								}
	//| ERR {$$ = new VariableNode(0, @1);}
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
| 	exprLvl3				{ $$ = $1; }
;

exprLvl3:
	LB exprLvl1 RB  { $$ = $2; }
| 	VALUE   		{ $$ = new ValueNode($1, @1);

            }
|	VARIABLE		{
											int x;
											if (!CurScope->GetValue ($1, x))
											    driver->EmergencyExit(@1, yy::Errors::non_existent_variable);

											$$ = new VariableNode($1, @1);

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