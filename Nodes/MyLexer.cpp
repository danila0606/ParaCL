#include "MyLexer.h"

void MyLexer::SetLocation() {
    int old_end_column = location_.end.column;
    location_.begin.line = location_.end.line = lineno();
    if (isCR (yytext)) {
        location_.begin.column = location_.end.column = 1;
        currentString_.clear ();
    }
    else {
        location_.begin.column = old_end_column;
        location_.end.column = location_.begin.column + YYLeng();
        currentString_ += yytext;
    }
}

yy::parser::token_type MyLexer::PushGrammarError() {

    std::string message = std::string("Grammar Error {\n") +
                          std::string("\tOn line: ") + std::to_string(location_.begin.line) +
                          std::string("\n\t") + GetCurrentString() +
                          std::string ("\n\t");
    std::string err_location = {};

    for (int i = 0; i < location_.begin.column - 1; ++i) {
        err_location += "-";
    }

    for (int i = 0; i < location_.end.column - location_.begin.column; ++i) {
        err_location += "^";
    }
    err_location+= "\nUnknown symbol\n}";

    message += err_location;

    error_messages.emplace_back(message);

    NextString();
    return yy::parser::token_type ::ERROR;
}

void MyLexer::PrintErrors() {
    for (const auto &mes : error_messages)
        std::cout<<mes<<std::endl;
}
