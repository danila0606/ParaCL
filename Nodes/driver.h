#pragma once

#include "MyLexer.h"
#include "../Build/numgrammar.tab.hh"
#include <fstream>
#include <sstream>

namespace yy {

    enum class Errors {
        non_existent_variable,
        division_by_zero,
        syntax_error
    };

    class Driver {

    private:
        MyLexer* lexer_;

        std::ostream& out_ = std::cout; //for tests

    public:

        Driver (std::ifstream& in, std::ostream& out = std::cout);

        std::ostream& GetOstream() {return out_;};

        parser::token_type yylex (parser::semantic_type* yylval, parser::location_type* location);
        void EmergencyExit(const parser::location_type& location, Errors err);
        bool IsGrammarError() const {return lexer_->IsError();};

        bool parse();
        void Calculate();

        ~Driver();
    };

}