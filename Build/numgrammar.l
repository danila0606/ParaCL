%option c++
%option noyywrap
%option yylineno
%option yyclass="MyLexer"
%option nounput yylineno
%{

#include "../Nodes/MyLexer.h"
#define YY_USER_ACTION SetLocation ();

%}

WS              [ \t\n\v]+
DOT             [.]
DIGIT           [0-9]
DIGIT_NON_ZERO  [1-9]
DOUBLE          {DIGIT}+{DOT}?{DIGIT}*
INTEGER         {DIGIT_NON_ZERO}{DIGIT}*
LETTER          [a-zA-Z]
LETTER_OR_DIGIT [a-zA-Z0-9]
VARIABLE        {LETTER}{LETTER_OR_DIGIT}*

%%

{WS}                        /* skip blanks and tabs */
"+"                         return yy::parser::token_type::ADD;
"-"                         return yy::parser::token_type::SUB;
"*"                         return yy::parser::token_type::MUL;
"/"                         return yy::parser::token_type::DIV;
"="                         return yy::parser::token_type::ASSIGN;

";"                         return yy::parser::token_type::SCOLON;
"("                         return yy::parser::token_type::LB;
")"                         return yy::parser::token_type::RB;
"{"                         return yy::parser::token_type::LFB;
"}"                         return yy::parser::token_type::RFB;

">"                         return yy::parser::token_type::GREATER;
">="                        return yy::parser::token_type::GREATER_OR_EQ;
"<"                         return yy::parser::token_type::LESS;
"<="                        return yy::parser::token_type::LESS_OR_EQ;
"=="                        return yy::parser::token_type::EQUAL;
"!="                        return yy::parser::token_type::NOT_EQUAL;

"if"                        return yy::parser::token_type::IF;
"while"                     return yy::parser::token_type::WHILE;
"print"                     return yy::parser::token_type::PRINT;
"?"                         return yy::parser::token_type::SCAN;
{DOUBLE}                    return yy::parser::token_type::VALUE;
{VARIABLE}                  return yy::parser::token_type::VARIABLE;
.			                return PushGrammarError();

%%