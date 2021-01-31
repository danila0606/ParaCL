#pragma once

#include <vector>
#include <string>
#include "../Build/numgrammar.tab.hh"
#include "../Build/location.hh"
#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

class MyLexer  : public yyFlexLexer {
    yy::location location_ {};
    std::string currentString_ {};
    std::vector<std::string> error_messages;

protected:
    bool isCR (const char* str) {
        return ((str[0] == '\n') || (str[0] == '\v'));
    }
public:
    MyLexer ():
            location_ ({})
    {}

    yy::parser::token_type PushGrammarError();
    void PrintErrors();
    void SetLocation ();
    void NextString() {
        location_.begin.line +=1;
        location_.end.line +=1;
        location_.begin.column = location_.end.column = 1;
    }
    yy::location GetLocation () const {
        return location_;
    }
    std::string GetCurrentString () const {
        return currentString_;
    }
    bool IsError() const {return !error_messages.empty();};

    int yylex () override;

};