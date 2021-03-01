#include "driver.h"


BraceNode* CurScope = nullptr;
FuncTable func_table;
extern BraceNode* OldScope;

yy::Driver::Driver (std::ifstream& in, std::ostream& out):
        lexer_ (new MyLexer), out_(out)
{
    lexer_->switch_streams (in, std::cout);

    CurScope = new ScopeNode(yy::location(0,0,0), nullptr);
}

yy::parser::token_type yy::Driver::yylex (yy::parser::semantic_type* yylval, yy::parser::location_type* location) {
    yy::parser::token_type tt = static_cast <yy::parser::token_type> (lexer_->yylex ());
    switch (tt) {
        case yy::parser::token_type::VALUE: {

            yylval->as <int> () = std::stod (lexer_->YYText ());
            break;
        }
        case yy::parser::token_type::VARIABLE: {

            std::string word(lexer_->YYText());
            parser::semantic_type tmp;
            tmp.as<std::string>() = word;
            yylval->swap< std::string >(tmp);
            break;
        }
        case yy::parser::token_type::ERROR: {
            break;
        }
        default: {
            break;
        }
    }
   *location = lexer_->GetLocation();

    return tt;
}

bool yy::Driver::parse () {
    yy::parser parser (this);
    bool result = parser.parse ();

    if (result) {
        std::cerr<<"Compilation dead"<<std::endl;
        lexer_->PrintErrors();
        exit(0);
    }

    return !result;
}

void yy::Driver::Calculate() {

    CurScope->Calc();
}

void yy::Driver::EmergencyExit(const yy::parser::location_type& location, Errors err) {

    std::string message;

    switch (err) {
        case (Errors::non_existent_variable) : {

            message = std::string("Non existent variable {\n");
            break;
        }
        case (Errors::division_by_zero) : {
            message = std::string("Division by zero {\n");
            break;
        }
        case (Errors::syntax_error) : {
            message = std::string("Syntax Error {\n");
            break;
        }
    }

    message +=  std::string("\tOn line: ") + std::to_string(location.begin.line) +
                std::string("\n\t") + lexer_->GetCurrentString() +
                std::string("\n\t");
                std::string err_location = {};

    for (int i = 0; i < location.begin.column - 1; ++i) {
        err_location += "-";
    }

    for (int i = 0; i < location.end.column - location.begin.column; ++i) {
        err_location += "^";
    }

    message += err_location;
    message += "\n}";

    throw std::invalid_argument(message);
}

yy::Driver::~Driver() {

    delete lexer_;
    lexer_ = nullptr;
    delete CurScope;
    CurScope = nullptr;
    OldScope = nullptr;
    //func_table.DeleteAll();
}