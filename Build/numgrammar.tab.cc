// A Bison parser, made by GNU Bison 3.7.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "numgrammar.tab.hh"


// Unqualified %code blocks.
#line 24 "numgrammar.y"

    #include "../Nodes/driver.h"
    #include "../Nodes/Node.h"

    namespace yy {
        parser::token_type yylex(parser::semantic_type* yylval, parser::location_type* location, Driver* driver);
        //void parser::report_syntax_error (parser::context const& context) const;

    }

    extern BraceNode* CurScope;
    extern FuncTable func_table;
    FuncScopeNode* CurFunc;

#line 61 "numgrammar.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 153 "numgrammar.tab.cc"

  /// Build a parser object.
  parser::parser (yy::Driver* driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_stream: // stream
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_math_op: // math_op
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_inside_scope: // inside_scope
      case symbol_kind::S_scope_assignment: // scope_assignment
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
      case symbol_kind::S_function: // function
      case symbol_kind::S_act: // act
        value.copy< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ACTION: // ACTION
      case symbol_kind::S_els: // els
        value.copy< ScopeNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_GLOBAL_FUNC: // GLOBAL_FUNC
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
      case symbol_kind::S_CONS: // CONS
        value.copy< std::vector<Node*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_ARGS_C: // ARGS_C
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_stream: // stream
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_math_op: // math_op
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_inside_scope: // inside_scope
      case symbol_kind::S_scope_assignment: // scope_assignment
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
      case symbol_kind::S_function: // function
      case symbol_kind::S_act: // act
        value.move< Node* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ACTION: // ACTION
      case symbol_kind::S_els: // els
        value.move< ScopeNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_GLOBAL_FUNC: // GLOBAL_FUNC
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
      case symbol_kind::S_CONS: // CONS
        value.move< std::vector<Node*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_ARGS_C: // ARGS_C
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_stream: // stream
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_math_op: // math_op
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_inside_scope: // inside_scope
      case symbol_kind::S_scope_assignment: // scope_assignment
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
      case symbol_kind::S_function: // function
      case symbol_kind::S_act: // act
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ACTION: // ACTION
      case symbol_kind::S_els: // els
        value.YY_MOVE_OR_COPY< ScopeNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_GLOBAL_FUNC: // GLOBAL_FUNC
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
      case symbol_kind::S_CONS: // CONS
        value.YY_MOVE_OR_COPY< std::vector<Node*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_ARGS_C: // ARGS_C
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_stream: // stream
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_math_op: // math_op
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_inside_scope: // inside_scope
      case symbol_kind::S_scope_assignment: // scope_assignment
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
      case symbol_kind::S_function: // function
      case symbol_kind::S_act: // act
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ACTION: // ACTION
      case symbol_kind::S_els: // els
        value.move< ScopeNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_GLOBAL_FUNC: // GLOBAL_FUNC
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
      case symbol_kind::S_CONS: // CONS
        value.move< std::vector<Node*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_ARGS_C: // ARGS_C
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_stream: // stream
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_math_op: // math_op
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_inside_scope: // inside_scope
      case symbol_kind::S_scope_assignment: // scope_assignment
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
      case symbol_kind::S_function: // function
      case symbol_kind::S_act: // act
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_ACTION: // ACTION
      case symbol_kind::S_els: // els
        value.copy< ScopeNode* > (that.value);
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_GLOBAL_FUNC: // GLOBAL_FUNC
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
      case symbol_kind::S_CONS: // CONS
        value.copy< std::vector<Node*> > (that.value);
        break;

      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_ARGS_C: // ARGS_C
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_stream: // stream
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_math_op: // math_op
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_inside_scope: // inside_scope
      case symbol_kind::S_scope_assignment: // scope_assignment
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
      case symbol_kind::S_function: // function
      case symbol_kind::S_act: // act
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_ACTION: // ACTION
      case symbol_kind::S_els: // els
        value.move< ScopeNode* > (that.value);
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< int > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_GLOBAL_FUNC: // GLOBAL_FUNC
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
      case symbol_kind::S_CONS: // CONS
        value.move< std::vector<Node*> > (that.value);
        break;

      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_ARGS_C: // ARGS_C
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_stream: // stream
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_math_op: // math_op
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_inside_scope: // inside_scope
      case symbol_kind::S_scope_assignment: // scope_assignment
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
      case symbol_kind::S_function: // function
      case symbol_kind::S_act: // act
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_ACTION: // ACTION
      case symbol_kind::S_els: // els
        yylhs.value.emplace< ScopeNode* > ();
        break;

      case symbol_kind::S_VALUE: // VALUE
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_GLOBAL_FUNC: // GLOBAL_FUNC
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
      case symbol_kind::S_CONS: // CONS
        yylhs.value.emplace< std::vector<Node*> > ();
        break;

      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_ARGS_C: // ARGS_C
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // scope: begin_scope inside_scope end_scope
#line 114 "numgrammar.y"
                                                                { yylhs.value.as < Node* > () = CurScope; CurScope = CurScope->GetParent(); }
#line 937 "numgrammar.tab.cc"
    break;

  case 3: // begin_scope: "{"
#line 118 "numgrammar.y"
                                                                        {
											ScopeNode* child = new ScopeNode (yystack_[0].location,CurScope, CurFunc);
											CurScope = child;
										}
#line 946 "numgrammar.tab.cc"
    break;

  case 4: // inside_scope: inside_scope assignment ";"
#line 125 "numgrammar.y"
                                                { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 952 "numgrammar.tab.cc"
    break;

  case 5: // inside_scope: inside_scope stream ";"
#line 126 "numgrammar.y"
                                                    { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 958 "numgrammar.tab.cc"
    break;

  case 6: // inside_scope: inside_scope condition
#line 127 "numgrammar.y"
                                                        { CurScope->PushNode (yystack_[0].value.as < Node* > ()); }
#line 964 "numgrammar.tab.cc"
    break;

  case 7: // inside_scope: inside_scope func
#line 128 "numgrammar.y"
                                        { /* nothing */ }
#line 970 "numgrammar.tab.cc"
    break;

  case 8: // inside_scope: inside_scope func ";"
#line 129 "numgrammar.y"
                                        { /* nothing */ }
#line 976 "numgrammar.tab.cc"
    break;

  case 9: // inside_scope: inside_scope exprLvl1 ";"
#line 130 "numgrammar.y"
                                        { CurScope->PushNode(yystack_[1].value.as < Node* > ()); }
#line 982 "numgrammar.tab.cc"
    break;

  case 10: // inside_scope: inside_scope return ";"
#line 131 "numgrammar.y"
                                        { CurScope->PushNode(yystack_[1].value.as < Node* > ()); }
#line 988 "numgrammar.tab.cc"
    break;

  case 11: // inside_scope: inside_scope scope
#line 132 "numgrammar.y"
                                        { CurScope->PushNode(yystack_[0].value.as < Node* > ()); }
#line 994 "numgrammar.tab.cc"
    break;

  case 12: // inside_scope: inside_scope scope_assignment
#line 133 "numgrammar.y"
                                        {  CurScope->PushNode(yystack_[0].value.as < Node* > ());}
#line 1000 "numgrammar.tab.cc"
    break;

  case 13: // inside_scope: %empty
#line 134 "numgrammar.y"
                                                                                { /* nothing */ }
#line 1006 "numgrammar.tab.cc"
    break;

  case 14: // end_scope: "}"
#line 138 "numgrammar.y"
                { }
#line 1012 "numgrammar.tab.cc"
    break;

  case 15: // func_scope: f_begin_scope f_inside_scope end_scope
#line 142 "numgrammar.y"
                                                                { yylhs.value.as < Node* > () = CurScope; CurScope = CurScope->GetParent(); CurFunc = nullptr;}
#line 1018 "numgrammar.tab.cc"
    break;

  case 16: // f_begin_scope: "(" ARGS ")" "{"
#line 146 "numgrammar.y"
                                                                {


											BraceNode* child = new FuncScopeNode (yystack_[3].location, CurScope);
											static_cast<FuncScopeNode*>(child)->SetArgs(yystack_[2].value.as < std::vector<std::string> > ());
											for (const auto& elem : yystack_[2].value.as < std::vector<std::string> > ())
											    child->AddValue(elem, 0);

											CurScope = child;
											CurFunc = static_cast<FuncScopeNode*>(child);
										}
#line 1034 "numgrammar.tab.cc"
    break;

  case 17: // f_begin_scope: "(" ARGS ")" ":" GLOBAL_FUNC "{"
#line 157 "numgrammar.y"
                                                {

  											BraceNode* child = new FuncScopeNode (yystack_[5].location, CurScope);
  											static_cast<FuncScopeNode*>(child)->SetArgs(yystack_[4].value.as < std::vector<std::string> > ());

  											static_cast<FuncScopeNode*>(child)->SetName(yystack_[1].value.as < std::string > ());



  											for (const auto& elem : yystack_[4].value.as < std::vector<std::string> > ())
  											    child->AddValue(elem, 0);

  											CurScope = child;
  											CurFunc = static_cast<FuncScopeNode*>(child);
  										}
#line 1054 "numgrammar.tab.cc"
    break;

  case 18: // GLOBAL_FUNC: VARIABLE
#line 175 "numgrammar.y"
             {
                                                    int x;
          											if (!CurScope->GetValue(yystack_[0].value.as < std::string > (),x) || !CurScope->GetFuncVariable(yystack_[0].value.as < std::string > ())) {

          											    func_table.AddGlobalFunc(yystack_[0].value.as < std::string > (), nullptr);
          											    }
          											else
          											    assert(0);

          											yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 1070 "numgrammar.tab.cc"
    break;

  case 19: // f_inside_scope: inside_scope assignment ";"
#line 189 "numgrammar.y"
                                                { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 1076 "numgrammar.tab.cc"
    break;

  case 20: // f_inside_scope: inside_scope stream ";"
#line 190 "numgrammar.y"
                                                    { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 1082 "numgrammar.tab.cc"
    break;

  case 21: // f_inside_scope: inside_scope condition
#line 191 "numgrammar.y"
                                                        { CurScope->PushNode (yystack_[0].value.as < Node* > ()); }
#line 1088 "numgrammar.tab.cc"
    break;

  case 22: // f_inside_scope: inside_scope exprLvl1 ";"
#line 192 "numgrammar.y"
                                        { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 1094 "numgrammar.tab.cc"
    break;

  case 23: // f_inside_scope: inside_scope return ";"
#line 193 "numgrammar.y"
                                        { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 1100 "numgrammar.tab.cc"
    break;

  case 24: // f_inside_scope: %empty
#line 194 "numgrammar.y"
                                                                                { /* nothing */            }
#line 1106 "numgrammar.tab.cc"
    break;

  case 25: // condition: "if" "(" CONS ")" ACTION els
#line 199 "numgrammar.y"
                             { yylhs.value.as < Node* > () = new ConditionNode(yystack_[3].value.as < std::vector<Node*> > (), static_cast<ScopeNode*>(yystack_[1].value.as < ScopeNode* > ()), NodeType::IF, yystack_[5].location, yystack_[0].value.as < ScopeNode* > ());}
#line 1112 "numgrammar.tab.cc"
    break;

  case 26: // condition: "while" "(" CONS ")" ACTION
#line 200 "numgrammar.y"
                             { yylhs.value.as < Node* > () = new ConditionNode(yystack_[2].value.as < std::vector<Node*> > (), static_cast<ScopeNode*>(yystack_[0].value.as < ScopeNode* > ()), NodeType::WHILE, yystack_[4].location) ;}
#line 1118 "numgrammar.tab.cc"
    break;

  case 27: // ACTION: scope
#line 203 "numgrammar.y"
          { yylhs.value.as < ScopeNode* > () = static_cast<ScopeNode*>(yystack_[0].value.as < Node* > ());                        }
#line 1124 "numgrammar.tab.cc"
    break;

  case 28: // ACTION: act
#line 204 "numgrammar.y"
          { ScopeNode* child = new ScopeNode (yystack_[0].location,CurScope, CurFunc);
            child->PushNode(yystack_[0].value.as < Node* > ());
            yylhs.value.as < ScopeNode* > () = child;  child = nullptr;                            }
#line 1132 "numgrammar.tab.cc"
    break;

  case 29: // act: stream ";"
#line 210 "numgrammar.y"
                                    { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1138 "numgrammar.tab.cc"
    break;

  case 30: // act: condition
#line 211 "numgrammar.y"
                                            { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1144 "numgrammar.tab.cc"
    break;

  case 31: // act: exprLvl1 ";"
#line 212 "numgrammar.y"
                                { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1150 "numgrammar.tab.cc"
    break;

  case 32: // act: return ";"
#line 213 "numgrammar.y"
                                { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1156 "numgrammar.tab.cc"
    break;

  case 33: // act: scope_assignment
#line 214 "numgrammar.y"
                                { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1162 "numgrammar.tab.cc"
    break;

  case 34: // act: assignment ";"
#line 215 "numgrammar.y"
                                        { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1168 "numgrammar.tab.cc"
    break;

  case 35: // els: "else" ACTION
#line 219 "numgrammar.y"
                   { yylhs.value.as < ScopeNode* > () = yystack_[0].value.as < ScopeNode* > ();     }
#line 1174 "numgrammar.tab.cc"
    break;

  case 36: // els: %empty
#line 220 "numgrammar.y"
                   { yylhs.value.as < ScopeNode* > () = nullptr;}
#line 1180 "numgrammar.tab.cc"
    break;

  case 37: // CONS: math_op
#line 224 "numgrammar.y"
                        { yylhs.value.as < std::vector<Node*> > ().push_back(yystack_[0].value.as < Node* > ());       }
#line 1186 "numgrammar.tab.cc"
    break;

  case 38: // CONS: math_op "&&" CONS
#line 225 "numgrammar.y"
                        { yylhs.value.as < std::vector<Node*> > ().push_back(yystack_[2].value.as < Node* > ());

                          for (const auto& elem : yystack_[0].value.as < std::vector<Node*> > ())
                              yylhs.value.as < std::vector<Node*> > ().push_back(elem);
                                                  }
#line 1196 "numgrammar.tab.cc"
    break;

  case 39: // func: VARIABLE "=" "func" func_scope
#line 234 "numgrammar.y"
                                        { FuncScopeNode* f_ptr = static_cast<FuncScopeNode*> (yystack_[0].value.as < Node* > ());
                                          CurScope->AddFuncVariable(yystack_[3].value.as < std::string > ());

                                          if (!f_ptr->GetName().empty()) {
                                              func_table.AddGlobalFunc(f_ptr->GetName(), f_ptr, true);
                                              func_table.AddRepeatFunc(yystack_[3].value.as < std::string > (), f_ptr->GetName(), true);
                                          }
                                          else
                                              func_table.AddLocalFunc(yystack_[3].value.as < std::string > (), f_ptr);
    }
#line 1211 "numgrammar.tab.cc"
    break;

  case 40: // ARGS: ARGS_C
#line 248 "numgrammar.y"
           {     yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > ();    }
#line 1217 "numgrammar.tab.cc"
    break;

  case 41: // ARGS: %empty
#line 249 "numgrammar.y"
           {/*no arguments */}
#line 1223 "numgrammar.tab.cc"
    break;

  case 42: // ARGS_C: VARIABLE "," ARGS_C
#line 255 "numgrammar.y"
                              { yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[2].value.as < std::string > ());

                                for (const auto& elem : yystack_[0].value.as < std::vector<std::string> > ())
                                   yylhs.value.as < std::vector<std::string> > ().push_back(elem);         }
#line 1232 "numgrammar.tab.cc"
    break;

  case 43: // ARGS_C: VARIABLE
#line 260 "numgrammar.y"
                              { yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());              }
#line 1238 "numgrammar.tab.cc"
    break;

  case 44: // PARAMS: PARAMS_C
#line 266 "numgrammar.y"
             {     yylhs.value.as < std::vector<Node*> > () = yystack_[0].value.as < std::vector<Node*> > ();    }
#line 1244 "numgrammar.tab.cc"
    break;

  case 45: // PARAMS: %empty
#line 267 "numgrammar.y"
             {/*no arguments */}
#line 1250 "numgrammar.tab.cc"
    break;

  case 46: // PARAMS_C: exprLvl1 "," PARAMS_C
#line 271 "numgrammar.y"
                                {
                                yylhs.value.as < std::vector<Node*> > ().push_back(yystack_[2].value.as < Node* > ());

                                for (const auto& elem : yystack_[0].value.as < std::vector<Node*> > ())
                                    yylhs.value.as < std::vector<Node*> > ().push_back(elem);

                                                            }
#line 1262 "numgrammar.tab.cc"
    break;

  case 47: // PARAMS_C: exprLvl1
#line 278 "numgrammar.y"
                                {     yylhs.value.as < std::vector<Node*> > ().push_back(yystack_[0].value.as < Node* > ());     }
#line 1268 "numgrammar.tab.cc"
    break;

  case 48: // return: "return" exprLvl1
#line 282 "numgrammar.y"
                    {   if (CurFunc == nullptr)
                            assert(0);

                        yylhs.value.as < Node* > () = new ReturnNode(yystack_[1].location, yystack_[0].value.as < Node* > (), CurFunc);
                    }
#line 1278 "numgrammar.tab.cc"
    break;

  case 49: // math_op: exprLvl1 ">" exprLvl1
#line 290 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::GREATER, yystack_[1].location); }
#line 1284 "numgrammar.tab.cc"
    break;

  case 50: // math_op: exprLvl1 ">=" exprLvl1
#line 291 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::GREATER_OR_EQ, yystack_[1].location); }
#line 1290 "numgrammar.tab.cc"
    break;

  case 51: // math_op: exprLvl1 "<" exprLvl1
#line 292 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::LESS, yystack_[1].location); }
#line 1296 "numgrammar.tab.cc"
    break;

  case 52: // math_op: exprLvl1 "<=" exprLvl1
#line 293 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::LESS_OR_EQ, yystack_[1].location); }
#line 1302 "numgrammar.tab.cc"
    break;

  case 53: // math_op: exprLvl1 "==" exprLvl1
#line 294 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::EQUAL, yystack_[1].location); }
#line 1308 "numgrammar.tab.cc"
    break;

  case 54: // math_op: exprLvl1 "!=" exprLvl1
#line 295 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::NOT_EQUAL, yystack_[1].location); }
#line 1314 "numgrammar.tab.cc"
    break;

  case 55: // function: VARIABLE "(" PARAMS ")"
#line 300 "numgrammar.y"
                          {
        if (!CurScope->GetFuncVariable (yystack_[3].value.as < std::string > ())) {
            if (!func_table.CheckGlobalFunc(yystack_[3].value.as < std::string > ()))
                driver->EmergencyExit(yystack_[3].location, yy::Errors::non_existent_variable);
        }
        yylhs.value.as < Node* > () = new FuncNode(yystack_[3].location,yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Node*> > ());
    }
#line 1326 "numgrammar.tab.cc"
    break;

  case 56: // assignment: VARIABLE "=" exprLvl1
#line 309 "numgrammar.y"
                                        {
									CurScope->AddValue(yystack_[2].value.as < std::string > (), 0);
								  	yylhs.value.as < Node* > () = new AssignNode(new VariableNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[0].value.as < Node* > (), yystack_[1].location);
								}
#line 1335 "numgrammar.tab.cc"
    break;

  case 57: // scope_assignment: VARIABLE "=" scope
#line 316 "numgrammar.y"
                          {
        CurScope->AddValue(yystack_[2].value.as < std::string > (), 0);

        yylhs.value.as < Node* > () = new AssignNode(new VariableNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[0].value.as < Node* > (), yystack_[1].location);
    }
#line 1345 "numgrammar.tab.cc"
    break;

  case 58: // stream: "print" exprLvl1
#line 324 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new  PrintNode(yystack_[0].value.as < Node* > (), yystack_[1].location, driver->GetOstream()); }
#line 1351 "numgrammar.tab.cc"
    break;

  case 59: // stream: VARIABLE "=" "?"
#line 325 "numgrammar.y"
                                        {
                                    CurScope->AddValue(yystack_[2].value.as < std::string > (), 0.0);

								  	yylhs.value.as < Node* > () = new ScanNode(new VariableNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[1].location);
								}
#line 1361 "numgrammar.tab.cc"
    break;

  case 60: // exprLvl1: exprLvl2 "+" exprLvl1
#line 333 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::ADD, yystack_[1].location); }
#line 1367 "numgrammar.tab.cc"
    break;

  case 61: // exprLvl1: exprLvl2 "-" exprLvl1
#line 334 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::SUB, yystack_[1].location); }
#line 1373 "numgrammar.tab.cc"
    break;

  case 62: // exprLvl1: exprLvl2
#line 335 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1379 "numgrammar.tab.cc"
    break;

  case 63: // exprLvl2: exprLvl3 "*" exprLvl2
#line 339 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::MUL, yystack_[1].location); }
#line 1385 "numgrammar.tab.cc"
    break;

  case 64: // exprLvl2: exprLvl3 "/" exprLvl2
#line 340 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::DIV, yystack_[1].location); }
#line 1391 "numgrammar.tab.cc"
    break;

  case 65: // exprLvl2: exprLvl3 "%" exprLvl2
#line 341 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::REM, yystack_[1].location); }
#line 1397 "numgrammar.tab.cc"
    break;

  case 66: // exprLvl2: exprLvl3
#line 342 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1403 "numgrammar.tab.cc"
    break;

  case 67: // exprLvl3: "(" exprLvl1 ")"
#line 346 "numgrammar.y"
                        { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1409 "numgrammar.tab.cc"
    break;

  case 68: // exprLvl3: VALUE
#line 347 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new ValueNode(yystack_[0].value.as < int > (), yystack_[0].location); }
#line 1415 "numgrammar.tab.cc"
    break;

  case 69: // exprLvl3: VARIABLE
#line 348 "numgrammar.y"
                                {
											int x;
											if (!CurScope->GetValue (yystack_[0].value.as < std::string > (), x)) {
                                                    driver->EmergencyExit(yystack_[0].location, yy::Errors::non_existent_variable);
                                            }
											yylhs.value.as < Node* > () = new VariableNode(yystack_[0].value.as < std::string > (), yystack_[0].location);
					}
#line 1427 "numgrammar.tab.cc"
    break;

  case 70: // exprLvl3: function
#line 356 "numgrammar.y"
              {
            yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
          }
#line 1435 "numgrammar.tab.cc"
    break;


#line 1439 "numgrammar.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        report_syntax_error (yyctx);
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "+", "-", "*", "/", "=", "%",
  "(", ")", "{", "}", ">", ">=", "<", "<=", "==", "!=", "&&", "if", "else",
  "while", "print", "?", ";", "func", "return", ":", ",", "ERROR", "VALUE",
  "VARIABLE", "'+'", "'-'", "'*'", "'/'", "$accept", "GLOBAL_FUNC",
  "exprLvl1", "exprLvl2", "exprLvl3", "assignment", "stream", "condition",
  "math_op", "scope", "inside_scope", "scope_assignment", "ARGS", "ARGS_C",
  "PARAMS", "PARAMS_C", "CONS", "func_scope", "f_inside_scope", "return",
  "function", "act", "ACTION", "els", "begin_scope", "end_scope",
  "f_begin_scope", "func", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  const signed char parser::yypact_ninf_ = -58;

  const signed char parser::yytable_ninf_ = -25;

  const short
  parser::yypact_[] =
  {
     -58,    14,   -58,    44,   -58,    10,    29,    44,    44,   -58,
      15,   -17,    23,    12,    -4,    17,   -58,   -58,   -58,    31,
     -58,   -58,    33,    50,    56,    44,    44,   -58,   -58,   106,
      44,   -58,    44,    44,    44,    44,    44,   -58,   -58,   -58,
      70,   -58,   -58,   126,    54,    59,    61,   -58,    65,   -58,
     -58,    55,    73,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,    44,    44,    44,    44,    44,    44,    44,    96,    96,
      57,   -58,    79,    44,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,    26,    69,    81,    83,   -58,   -58,   -58,    84,
     -58,    89,   -58,    85,   110,   -58,   102,   100,   -58,    46,
     -58,   -58,   -58,   -58,    96,   -58,    57,     2,   101,   111,
     120,   109,   121,   -58,   -58,   -58,   -58,    99,   123,   135,
     136,   137,   -58,   139,   -58
  };

  const signed char
  parser::yydefact_[] =
  {
      13,     0,     1,     0,     3,     0,     0,     0,     0,    68,
      69,     0,    62,    66,     0,     0,     6,    11,    12,     0,
      70,    13,     7,    69,     0,     0,     0,    58,    48,     0,
      45,     9,     0,     0,     0,     0,     0,     4,     5,    10,
       0,     8,    67,     0,    37,     0,     0,    59,     0,    56,
      57,    47,     0,    44,    60,    61,    63,    64,    65,    14,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    39,    13,     0,    55,    49,    50,    51,    52,    53,
      54,    38,    69,     0,     0,     0,    30,    27,    33,     0,
      28,    36,    26,    43,     0,    40,     0,     0,    46,     0,
      31,    34,    29,    32,     0,    25,     0,     0,     0,     0,
       0,     6,     0,    15,    35,    42,    16,     0,     9,     4,
       5,    10,    18,     0,    17
  };

  const signed char
  parser::yypgoto_[] =
  {
     -58,   -58,    -1,    52,   -58,     0,     3,     4,   -58,   -19,
     -18,   -53,   -58,    45,   -58,    80,   -15,   -58,   -58,     8,
     -58,   -58,   -57,   -58,   -58,    58,   -58,   -58
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,   123,    43,    12,    13,    84,    85,    86,    44,    17,
       1,    18,    94,    95,    52,    53,    45,    71,    97,    89,
      20,    90,    91,   105,    21,    60,    72,    22
  };

  const signed char
  parser::yytable_[] =
  {
      11,    14,    24,    40,    15,    16,    27,    28,    31,    19,
      50,    46,    92,   116,     2,    88,    88,    34,    35,    25,
      36,    37,    29,     3,    30,     4,    32,    33,    49,    51,
     117,    54,    55,    99,     5,    30,     6,     7,    26,    11,
      14,     8,    38,    15,    16,     9,    10,   114,    19,    87,
      87,    88,    81,     3,    96,     3,    39,     4,    41,    30,
      75,    76,    77,    78,    79,    80,    42,    83,    83,    68,
      47,    69,    51,    67,    70,     9,    23,     9,    23,     3,
      50,     4,    59,    74,    73,    87,    56,    57,    58,    93,
       5,   -24,     6,     7,   100,   108,   109,     8,    49,   110,
     111,     9,    10,    83,   112,     3,   101,     4,   102,   103,
     104,     3,    59,     4,   106,     3,     5,     4,     6,     7,
     107,   -21,     5,     8,     6,     7,   118,     9,    82,     8,
      47,   122,    48,     9,    10,   -22,   119,     9,    23,    61,
      62,    63,    64,    65,    66,   120,   121,   -19,   -20,   -23,
     124,   115,     0,    98,     0,   113
  };

  const signed char
  parser::yycheck_[] =
  {
       1,     1,     3,    21,     1,     1,     7,     8,    25,     1,
      29,    26,    69,    11,     0,    68,    69,     5,     6,     9,
       8,    25,     7,     9,     9,    11,     3,     4,    29,    30,
      28,    32,    33,     7,    20,     9,    22,    23,     9,    40,
      40,    27,    25,    40,    40,    31,    32,   104,    40,    68,
      69,   104,    67,     9,    72,     9,    25,    11,    25,     9,
      61,    62,    63,    64,    65,    66,    10,    68,    69,    10,
      24,    10,    73,    19,     9,    31,    32,    31,    32,     9,
      99,    11,    12,    10,    29,   104,    34,    35,    36,    32,
      20,    12,    22,    23,    25,    96,    96,    27,    99,    96,
      96,    31,    32,   104,    96,     9,    25,    11,    25,    25,
      21,     9,    12,    11,    29,     9,    20,    11,    22,    23,
      10,    12,    20,    27,    22,    23,    25,    31,    32,    27,
      24,    32,    26,    31,    32,    12,    25,    31,    32,    13,
      14,    15,    16,    17,    18,    25,    25,    12,    12,    12,
      11,   106,    -1,    73,    -1,    97
  };

  const signed char
  parser::yystos_[] =
  {
       0,    47,     0,     9,    11,    20,    22,    23,    27,    31,
      32,    39,    40,    41,    42,    43,    44,    46,    48,    56,
      57,    61,    64,    32,    39,     9,     9,    39,    39,     7,
       9,    25,     3,     4,     5,     6,     8,    25,    25,    25,
      47,    25,    10,    39,    45,    53,    53,    24,    26,    39,
      46,    39,    51,    52,    39,    39,    40,    40,    40,    12,
      62,    13,    14,    15,    16,    17,    18,    19,    10,    10,
       9,    54,    63,    29,    10,    39,    39,    39,    39,    39,
      39,    53,    32,    39,    42,    43,    44,    46,    48,    56,
      58,    59,    59,    32,    49,    50,    47,    55,    52,     7,
      25,    25,    25,    25,    21,    60,    29,    10,    39,    42,
      43,    44,    56,    62,    59,    50,    11,    28,    25,    25,
      25,    25,    32,    38,    11
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    46,    61,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    62,    54,    63,    63,    38,    55,
      55,    55,    55,    55,    55,    44,    44,    59,    59,    58,
      58,    58,    58,    58,    58,    60,    60,    53,    53,    64,
      49,    49,    50,    50,    51,    51,    52,    52,    56,    45,
      45,    45,    45,    45,    45,    57,    42,    48,    43,    43,
      39,    39,    39,    40,    40,    40,    40,    41,    41,    41,
      41
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     1,     3,     3,     2,     2,     3,     3,
       3,     2,     2,     0,     1,     3,     4,     6,     1,     3,
       3,     2,     3,     3,     0,     6,     5,     1,     1,     2,
       1,     2,     2,     1,     2,     2,     0,     1,     3,     4,
       1,     0,     3,     1,     1,     0,     3,     1,     2,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     2,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     1,
       1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   114,   114,   118,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   138,   142,   146,   157,   175,   189,
     190,   191,   192,   193,   194,   199,   200,   203,   204,   210,
     211,   212,   213,   214,   215,   219,   220,   224,   225,   234,
     248,   249,   255,   260,   266,   267,   271,   278,   282,   290,
     291,   292,   293,   294,   295,   300,   309,   316,   324,   325,
     333,   334,   335,   339,   340,   341,   342,   346,   347,   348,
     356
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    35,    33,     2,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
    };
    // Last valid token kind.
    const int code_max = 287;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1916 "numgrammar.tab.cc"

#line 361 "numgrammar.y"

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
