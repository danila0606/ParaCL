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
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
        value.copy< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
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
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
        value.move< Node* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
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
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
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
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
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
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
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
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< int > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
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
      case symbol_kind::S_func_scope: // func_scope
      case symbol_kind::S_f_inside_scope: // f_inside_scope
      case symbol_kind::S_return: // return
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_VALUE: // VALUE
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_PARAMS: // PARAMS
      case symbol_kind::S_PARAMS_C: // PARAMS_C
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
#line 107 "numgrammar.y"
                                                                { yylhs.value.as < Node* > () = CurScope; CurScope = CurScope->GetParent(); }
#line 867 "numgrammar.tab.cc"
    break;

  case 3: // begin_scope: "{"
#line 111 "numgrammar.y"
                                                                        {
											ScopeNode* child = new ScopeNode (yystack_[0].location,CurScope, CurFunc);
											CurScope = child;
										}
#line 876 "numgrammar.tab.cc"
    break;

  case 4: // inside_scope: inside_scope assignment ";"
#line 118 "numgrammar.y"
                                                { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 882 "numgrammar.tab.cc"
    break;

  case 5: // inside_scope: inside_scope stream ";"
#line 119 "numgrammar.y"
                                                    { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 888 "numgrammar.tab.cc"
    break;

  case 6: // inside_scope: inside_scope condition
#line 120 "numgrammar.y"
                                                        { CurScope->PushNode (yystack_[0].value.as < Node* > ()); }
#line 894 "numgrammar.tab.cc"
    break;

  case 7: // inside_scope: inside_scope func
#line 121 "numgrammar.y"
                                        { /* nothing */ }
#line 900 "numgrammar.tab.cc"
    break;

  case 8: // inside_scope: inside_scope func ";"
#line 122 "numgrammar.y"
                                        { /* nothing */ }
#line 906 "numgrammar.tab.cc"
    break;

  case 9: // inside_scope: inside_scope exprLvl1 ";"
#line 123 "numgrammar.y"
                                        { CurScope->PushNode(yystack_[1].value.as < Node* > ()); }
#line 912 "numgrammar.tab.cc"
    break;

  case 10: // inside_scope: inside_scope return ";"
#line 124 "numgrammar.y"
                                      { CurScope->PushNode(yystack_[1].value.as < Node* > ()); }
#line 918 "numgrammar.tab.cc"
    break;

  case 11: // inside_scope: inside_scope scope
#line 125 "numgrammar.y"
                                       { CurScope->PushNode(yystack_[0].value.as < Node* > ()); }
#line 924 "numgrammar.tab.cc"
    break;

  case 12: // inside_scope: %empty
#line 127 "numgrammar.y"
                                                                                {}
#line 930 "numgrammar.tab.cc"
    break;

  case 13: // end_scope: "}"
#line 131 "numgrammar.y"
                { }
#line 936 "numgrammar.tab.cc"
    break;

  case 14: // func_scope: f_begin_scope f_inside_scope end_scope
#line 137 "numgrammar.y"
                                                                { yylhs.value.as < Node* > () = CurScope; CurScope = CurScope->GetParent(); CurFunc = nullptr;}
#line 942 "numgrammar.tab.cc"
    break;

  case 15: // f_begin_scope: "{"
#line 141 "numgrammar.y"
                                                                        {

											BraceNode* child = new FuncScopeNode (yystack_[0].location, CurScope);
											CurScope = child;
											CurFunc = static_cast<FuncScopeNode*>(child);
										}
#line 953 "numgrammar.tab.cc"
    break;

  case 16: // f_inside_scope: f_inside_scope assignment ";"
#line 150 "numgrammar.y"
                                                        { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 959 "numgrammar.tab.cc"
    break;

  case 17: // f_inside_scope: f_inside_scope stream ";"
#line 151 "numgrammar.y"
                                                    { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 965 "numgrammar.tab.cc"
    break;

  case 18: // f_inside_scope: f_inside_scope condition
#line 152 "numgrammar.y"
                                                                { CurScope->PushNode (yystack_[0].value.as < Node* > ()); }
#line 971 "numgrammar.tab.cc"
    break;

  case 19: // f_inside_scope: f_inside_scope exprLvl1 ";"
#line 153 "numgrammar.y"
                                        { CurScope->PushNode(yystack_[1].value.as < Node* > ()); }
#line 977 "numgrammar.tab.cc"
    break;

  case 20: // f_inside_scope: %empty
#line 157 "numgrammar.y"
                                                                                {}
#line 983 "numgrammar.tab.cc"
    break;

  case 21: // condition: "if" "(" math_op ")" scope
#line 161 "numgrammar.y"
                                    { yylhs.value.as < Node* > () = new ConditionNode(yystack_[2].value.as < Node* > (), static_cast<ScopeNode*>(yystack_[0].value.as < Node* > ()), NodeType::IF, yystack_[4].location); }
#line 989 "numgrammar.tab.cc"
    break;

  case 22: // condition: "while" "(" math_op ")" scope
#line 162 "numgrammar.y"
                                        { yylhs.value.as < Node* > () = new ConditionNode(yystack_[2].value.as < Node* > (), static_cast<ScopeNode*>(yystack_[0].value.as < Node* > ()), NodeType::WHILE, yystack_[4].location); }
#line 995 "numgrammar.tab.cc"
    break;

  case 23: // func: VARIABLE "=" "func" "(" ARGS ")" func_scope
#line 167 "numgrammar.y"
                                                   { FuncScopeNode* f_ptr = static_cast<FuncScopeNode*> (yystack_[0].value.as < Node* > ());
                                                     f_ptr->SetArgs(yystack_[2].value.as < std::vector<std::string> > ());
                                                     CurScope->AddFuncVariable(yystack_[6].value.as < std::string > ());
                                                     //CurScope->AddValue($1, $5.size());
                                                     func_table.AddFunc(yystack_[6].value.as < std::string > (), f_ptr);
                                                    }
#line 1006 "numgrammar.tab.cc"
    break;

  case 24: // ARGS: ARGS_C
#line 178 "numgrammar.y"
           {     yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > ();    }
#line 1012 "numgrammar.tab.cc"
    break;

  case 25: // ARGS: %empty
#line 179 "numgrammar.y"
           {/*no arguments */}
#line 1018 "numgrammar.tab.cc"
    break;

  case 26: // ARGS_C: VARIABLE "," ARGS_C
#line 185 "numgrammar.y"
                              { yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[2].value.as < std::string > ());

                                for (const auto& elem : yystack_[0].value.as < std::vector<std::string> > ())
                                   yylhs.value.as < std::vector<std::string> > ().push_back(elem);                     }
#line 1027 "numgrammar.tab.cc"
    break;

  case 27: // ARGS_C: VARIABLE
#line 189 "numgrammar.y"
                              { yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());                    }
#line 1033 "numgrammar.tab.cc"
    break;

  case 28: // PARAMS: PARAMS_C
#line 195 "numgrammar.y"
             {     yylhs.value.as < std::vector<Node*> > () = yystack_[0].value.as < std::vector<Node*> > ();    }
#line 1039 "numgrammar.tab.cc"
    break;

  case 29: // PARAMS: %empty
#line 196 "numgrammar.y"
           {/*no arguments */}
#line 1045 "numgrammar.tab.cc"
    break;

  case 30: // PARAMS_C: exprLvl1 "," PARAMS_C
#line 202 "numgrammar.y"
                                {
                                yylhs.value.as < std::vector<Node*> > ().push_back(yystack_[2].value.as < Node* > ());

                                for (const auto& elem : yystack_[0].value.as < std::vector<Node*> > ())
                                    yylhs.value.as < std::vector<Node*> > ().push_back(elem);

                                                     }
#line 1057 "numgrammar.tab.cc"
    break;

  case 31: // PARAMS_C: exprLvl1
#line 209 "numgrammar.y"
                                {     yylhs.value.as < std::vector<Node*> > ().push_back(yystack_[0].value.as < Node* > ());                     }
#line 1063 "numgrammar.tab.cc"
    break;

  case 32: // return: "return" exprLvl1
#line 214 "numgrammar.y"
                    {   if (CurFunc == nullptr)
                            assert(0);

                        yylhs.value.as < Node* > () = new ReturnNode(yystack_[1].location, yystack_[0].value.as < Node* > (), CurFunc);
                    }
#line 1073 "numgrammar.tab.cc"
    break;

  case 33: // math_op: exprLvl1 ">" exprLvl1
#line 222 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::GREATER, yystack_[1].location); }
#line 1079 "numgrammar.tab.cc"
    break;

  case 34: // math_op: exprLvl1 ">=" exprLvl1
#line 223 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::GREATER_OR_EQ, yystack_[1].location); }
#line 1085 "numgrammar.tab.cc"
    break;

  case 35: // math_op: exprLvl1 "<" exprLvl1
#line 224 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::LESS, yystack_[1].location); }
#line 1091 "numgrammar.tab.cc"
    break;

  case 36: // math_op: exprLvl1 "<=" exprLvl1
#line 225 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::LESS_OR_EQ, yystack_[1].location); }
#line 1097 "numgrammar.tab.cc"
    break;

  case 37: // math_op: exprLvl1 "==" exprLvl1
#line 226 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::EQUAL, yystack_[1].location); }
#line 1103 "numgrammar.tab.cc"
    break;

  case 38: // math_op: exprLvl1 "!=" exprLvl1
#line 227 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::NOT_EQUAL, yystack_[1].location); }
#line 1109 "numgrammar.tab.cc"
    break;

  case 39: // assignment: VARIABLE "=" exprLvl1
#line 231 "numgrammar.y"
                                        {
\
									CurScope->AddValue(yystack_[2].value.as < std::string > (), 0);

								  	yylhs.value.as < Node* > () = new AssignNode(new VariableNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[0].value.as < Node* > (), yystack_[1].location);

								}
#line 1121 "numgrammar.tab.cc"
    break;

  case 40: // assignment: VARIABLE "=" VARIABLE "(" PARAMS ")"
#line 239 "numgrammar.y"
                                          {

            if (!CurScope->GetFuncVariable (yystack_[3].value.as < std::string > ()))
                driver->EmergencyExit(yystack_[3].location, yy::Errors::non_existent_variable);

            CurScope->AddValue(yystack_[5].value.as < std::string > (), 0);

            yylhs.value.as < Node* > () = new AssignNode(new VariableNode(yystack_[5].value.as < std::string > (), yystack_[5].location), new FuncNode(yystack_[3].location,yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Node*> > ()), yystack_[4].location);

                                 }
#line 1136 "numgrammar.tab.cc"
    break;

  case 41: // stream: "print" exprLvl1
#line 254 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new  PrintNode(yystack_[0].value.as < Node* > (), yystack_[1].location, driver->GetOstream()); }
#line 1142 "numgrammar.tab.cc"
    break;

  case 42: // stream: VARIABLE "=" "?"
#line 255 "numgrammar.y"
                                        {
                                    CurScope->AddValue(yystack_[2].value.as < std::string > (), 0.0);

								  	yylhs.value.as < Node* > () = new ScanNode(new VariableNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[1].location);
								}
#line 1152 "numgrammar.tab.cc"
    break;

  case 43: // exprLvl1: exprLvl2 "+" exprLvl1
#line 263 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::ADD, yystack_[1].location); }
#line 1158 "numgrammar.tab.cc"
    break;

  case 44: // exprLvl1: exprLvl2 "-" exprLvl1
#line 264 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::SUB, yystack_[1].location); }
#line 1164 "numgrammar.tab.cc"
    break;

  case 45: // exprLvl1: exprLvl2
#line 265 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1170 "numgrammar.tab.cc"
    break;

  case 46: // exprLvl2: exprLvl3 "*" exprLvl2
#line 269 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::MUL, yystack_[1].location); }
#line 1176 "numgrammar.tab.cc"
    break;

  case 47: // exprLvl2: exprLvl3 "/" exprLvl2
#line 270 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::DIV, yystack_[1].location); }
#line 1182 "numgrammar.tab.cc"
    break;

  case 48: // exprLvl2: exprLvl3
#line 271 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1188 "numgrammar.tab.cc"
    break;

  case 49: // exprLvl3: "(" exprLvl1 ")"
#line 275 "numgrammar.y"
                        { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1194 "numgrammar.tab.cc"
    break;

  case 50: // exprLvl3: VALUE
#line 276 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new ValueNode(yystack_[0].value.as < int > (), yystack_[0].location); }
#line 1200 "numgrammar.tab.cc"
    break;

  case 51: // exprLvl3: VARIABLE
#line 277 "numgrammar.y"
                                {
											int x;
											if (!CurScope->GetValue (yystack_[0].value.as < std::string > (), x)) {
									            if (CurScope->WhoAmI() == NodeType::SCOPE)
                                                    driver->EmergencyExit(yystack_[0].location, yy::Errors::non_existent_variable);

                                            CurScope->AddUnknownVariable(yystack_[0].value.as < std::string > ());
                                            }
											yylhs.value.as < Node* > () = new VariableNode(yystack_[0].value.as < std::string > (), yystack_[0].location);
					}
#line 1215 "numgrammar.tab.cc"
    break;


#line 1219 "numgrammar.tab.cc"

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
    "end of file", "error", "invalid token", "+", "-", "*", "/", "=", "(",
  ")", "{", "}", ">", ">=", "<", "<=", "==", "!=", "if", "while", "print",
  "?", ";", "func", "return", ":", ",", "ERROR", "VALUE", "VARIABLE",
  "'+'", "'-'", "'*'", "'/'", "$accept", "exprLvl1", "exprLvl2",
  "exprLvl3", "assignment", "stream", "condition", "math_op", "scope",
  "inside_scope", "ARGS", "ARGS_C", "PARAMS", "PARAMS_C", "func_scope",
  "f_inside_scope", "return", "begin_scope", "end_scope", "f_begin_scope",
  "func", YY_NULLPTR
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




  const signed char parser::yypact_ninf_ = -19;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -19,    15,   -19,    59,   -19,    -5,     6,    59,    59,   -19,
      12,     0,    -2,     7,    10,    16,   -19,   -19,    20,   -19,
      24,   -19,    19,    59,    59,   -19,   -19,     8,   -19,    59,
      59,    59,    59,   -19,   -19,   -19,    37,   -19,   -19,    -6,
      21,    63,   -19,    52,    56,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,    59,    59,    59,    59,    59,    59,    58,    58,
      44,    59,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
      48,    68,   -19,    60,    69,   -19,    44,    71,    59,   -19,
     -19,   -19,   -19,   -19,   -19,    51,    78,    70,    72,    73,
     -19,   -19,    55,   -19,   -19,   -19
  };

  const signed char
  parser::yydefact_[] =
  {
      12,     0,     1,     0,     3,     0,     0,     0,     0,    50,
      51,     0,    45,    48,     0,     0,     6,    11,     0,    12,
       7,    51,     0,     0,     0,    41,    32,     0,     9,     0,
       0,     0,     0,     4,     5,    10,     0,     8,    49,     0,
       0,     0,    42,     0,    51,    39,    43,    44,    46,    47,
      13,     2,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    29,    33,    34,    35,    36,    37,    38,    21,    22,
      27,     0,    24,    31,     0,    28,     0,     0,     0,    40,
      26,    15,    23,    20,    30,     0,    51,     0,     0,     0,
      18,    14,     0,    19,    16,    17
  };

  const signed char
  parser::yypgoto_[] =
  {
     -19,    -3,   -14,   -19,     5,    11,    13,    67,   -18,    74,
     -19,    23,   -19,    22,   -19,   -19,   -19,   -19,    17,   -19,
     -19
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    11,    12,    13,    14,    15,    16,    40,    17,     1,
      71,    72,    74,    75,    82,    85,    18,    19,    51,    83,
      20
  };

  const signed char
  parser::yytable_[] =
  {
      22,    29,    30,    23,    25,    26,    52,    53,    54,    55,
      56,    57,    31,    32,    24,     2,     3,    48,    49,    27,
      39,    39,    28,     3,    45,     4,    46,    47,    38,    42,
      58,    43,    33,     5,     6,     7,     9,    44,    34,     8,
      68,    69,    35,     9,    10,     3,    37,     4,    50,    62,
      63,    64,    65,    66,    67,     5,     6,     7,    73,     3,
      60,     8,    50,     3,    61,     9,    10,     3,     4,     5,
       6,     7,    59,    70,    76,    73,    42,    77,    79,     9,
      86,    81,    87,     9,    44,    92,    78,     9,    21,    45,
      88,    41,    93,    36,    94,    95,    89,     0,    90,    80,
      84,     0,    91
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     3,     4,     8,     7,     8,    12,    13,    14,    15,
      16,    17,     5,     6,     8,     0,     8,    31,    32,     7,
      23,    24,    22,     8,    27,    10,    29,    30,     9,    21,
       9,    23,    22,    18,    19,    20,    28,    29,    22,    24,
      58,    59,    22,    28,    29,     8,    22,    10,    11,    52,
      53,    54,    55,    56,    57,    18,    19,    20,    61,     8,
       8,    24,    11,     8,     8,    28,    29,     8,    10,    18,
      19,    20,     9,    29,    26,    78,    21,     9,     9,    28,
      29,    10,    85,    28,    29,     7,    26,    28,    29,    92,
      85,    24,    22,    19,    22,    22,    85,    -1,    85,    76,
      78,    -1,    85
  };

  const signed char
  parser::yystos_[] =
  {
       0,    43,     0,     8,    10,    18,    19,    20,    24,    28,
      29,    35,    36,    37,    38,    39,    40,    42,    50,    51,
      54,    29,    35,     8,     8,    35,    35,     7,    22,     3,
       4,     5,     6,    22,    22,    22,    43,    22,     9,    35,
      41,    41,    21,    23,    29,    35,    35,    35,    36,    36,
      11,    52,    12,    13,    14,    15,    16,    17,     9,     9,
       8,     8,    35,    35,    35,    35,    35,    35,    42,    42,
      29,    44,    45,    35,    46,    47,    26,     9,    26,     9,
      45,    10,    48,    53,    47,    49,    29,    35,    38,    39,
      40,    52,     7,    22,    22,    22
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    34,    42,    51,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    52,    48,    53,    49,    49,    49,    49,
      49,    40,    40,    54,    44,    44,    45,    45,    46,    46,
      47,    47,    50,    41,    41,    41,    41,    41,    41,    38,
      38,    39,    39,    35,    35,    35,    36,    36,    36,    37,
      37,    37
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     1,     3,     3,     2,     2,     3,     3,
       3,     2,     0,     1,     3,     1,     3,     3,     2,     3,
       0,     5,     5,     7,     1,     0,     3,     1,     1,     0,
       3,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       6,     2,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   107,   107,   111,   118,   119,   120,   121,   122,   123,
     124,   125,   127,   131,   137,   141,   150,   151,   152,   153,
     157,   161,   162,   167,   178,   179,   185,   189,   195,   196,
     202,   209,   214,   222,   223,   224,   225,   226,   227,   231,
     239,   254,   255,   263,   264,   265,   269,   270,   271,   275,
     276,   277
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
       2,     2,    32,    30,     2,    31,     2,    33,     2,     2,
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
      25,    26,    27,    28,    29
    };
    // Last valid token kind.
    const int code_max = 284;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1670 "numgrammar.tab.cc"

#line 289 "numgrammar.y"

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
