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

    extern ScopeNode* CurScope;

#line 59 "numgrammar.tab.cc"


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
#line 151 "numgrammar.tab.cc"

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
        value.copy< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< std::string > (YY_MOVE (that.value));
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
        value.move< Node* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (YY_MOVE (s.value));
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
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (YY_MOVE (that.value));
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
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< std::string > (that.value);
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
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_VALUE: // VALUE
        value.move< double > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (that.value);
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
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_VALUE: // VALUE
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        yylhs.value.emplace< std::string > ();
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
#line 87 "numgrammar.y"
                                                                { yylhs.value.as < Node* > () = CurScope; CurScope = CurScope->GetParent(); }
#line 774 "numgrammar.tab.cc"
    break;

  case 3: // begin_scope: "{"
#line 91 "numgrammar.y"
                                                                        {
											ScopeNode* child = new ScopeNode (yystack_[0].location,CurScope);
											CurScope = child;
										}
#line 783 "numgrammar.tab.cc"
    break;

  case 4: // inside_scope: inside_scope assignment ";"
#line 98 "numgrammar.y"
                                                { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 789 "numgrammar.tab.cc"
    break;

  case 5: // inside_scope: inside_scope stream ";"
#line 99 "numgrammar.y"
                                                    { CurScope->PushNode (yystack_[1].value.as < Node* > ()); }
#line 795 "numgrammar.tab.cc"
    break;

  case 6: // inside_scope: inside_scope condition
#line 100 "numgrammar.y"
                                                        { CurScope->PushNode (yystack_[0].value.as < Node* > ()); }
#line 801 "numgrammar.tab.cc"
    break;

  case 7: // inside_scope: %empty
#line 102 "numgrammar.y"
                                                                                {}
#line 807 "numgrammar.tab.cc"
    break;

  case 8: // end_scope: "}"
#line 106 "numgrammar.y"
                { }
#line 813 "numgrammar.tab.cc"
    break;

  case 9: // condition: "if" "(" math_op ")" scope
#line 118 "numgrammar.y"
                                    { yylhs.value.as < Node* > () = new ConditionNode(yystack_[2].value.as < Node* > (), static_cast<ScopeNode*>(yystack_[0].value.as < Node* > ()), NodeType::IF, yystack_[4].location); }
#line 819 "numgrammar.tab.cc"
    break;

  case 10: // condition: "while" "(" math_op ")" scope
#line 119 "numgrammar.y"
                                        { yylhs.value.as < Node* > () = new ConditionNode(yystack_[2].value.as < Node* > (), static_cast<ScopeNode*>(yystack_[0].value.as < Node* > ()), NodeType::WHILE, yystack_[4].location); }
#line 825 "numgrammar.tab.cc"
    break;

  case 11: // math_op: exprLvl1 ">" exprLvl1
#line 123 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::GREATER, yystack_[1].location); }
#line 831 "numgrammar.tab.cc"
    break;

  case 12: // math_op: exprLvl1 ">=" exprLvl1
#line 124 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::GREATER_OR_EQ, yystack_[1].location); }
#line 837 "numgrammar.tab.cc"
    break;

  case 13: // math_op: exprLvl1 "<" exprLvl1
#line 125 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::LESS, yystack_[1].location); }
#line 843 "numgrammar.tab.cc"
    break;

  case 14: // math_op: exprLvl1 "<=" exprLvl1
#line 126 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::LESS_OR_EQ, yystack_[1].location); }
#line 849 "numgrammar.tab.cc"
    break;

  case 15: // math_op: exprLvl1 "==" exprLvl1
#line 127 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::EQUAL, yystack_[1].location); }
#line 855 "numgrammar.tab.cc"
    break;

  case 16: // math_op: exprLvl1 "!=" exprLvl1
#line 128 "numgrammar.y"
                                                        { yylhs.value.as < Node* > () = new MathOpNode (yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::NOT_EQUAL, yystack_[1].location); }
#line 861 "numgrammar.tab.cc"
    break;

  case 17: // assignment: VARIABLE "=" exprLvl1
#line 132 "numgrammar.y"
                                        {
\
									CurScope->AddValue(yystack_[2].value.as < std::string > (), 0.0);

								  	yylhs.value.as < Node* > () = new AssignNode(new VariableNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[0].value.as < Node* > (), yystack_[1].location);

								}
#line 873 "numgrammar.tab.cc"
    break;

  case 18: // stream: "print" exprLvl1
#line 143 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = new  PrintNode(yystack_[0].value.as < Node* > (), yystack_[1].location, driver->GetOstream()); }
#line 879 "numgrammar.tab.cc"
    break;

  case 19: // stream: VARIABLE "=" "?"
#line 144 "numgrammar.y"
                                        {
                                    CurScope->AddValue(yystack_[2].value.as < std::string > (), 0.0);

								  	yylhs.value.as < Node* > () = new ScanNode(new VariableNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[1].location);
								}
#line 889 "numgrammar.tab.cc"
    break;

  case 20: // exprLvl1: exprLvl2 "+" exprLvl1
#line 152 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::ADD, yystack_[1].location); }
#line 895 "numgrammar.tab.cc"
    break;

  case 21: // exprLvl1: exprLvl2 "-" exprLvl1
#line 153 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::SUB, yystack_[1].location); }
#line 901 "numgrammar.tab.cc"
    break;

  case 22: // exprLvl1: exprLvl2
#line 154 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 907 "numgrammar.tab.cc"
    break;

  case 23: // exprLvl2: exprLvl3 "*" exprLvl2
#line 158 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::MUL, yystack_[1].location); }
#line 913 "numgrammar.tab.cc"
    break;

  case 24: // exprLvl2: exprLvl3 "/" exprLvl2
#line 159 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new MathOpNode(yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > (), NodeType::DIV, yystack_[1].location); }
#line 919 "numgrammar.tab.cc"
    break;

  case 25: // exprLvl2: exprLvl3
#line 160 "numgrammar.y"
                                                { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 925 "numgrammar.tab.cc"
    break;

  case 26: // exprLvl3: "(" exprLvl1 ")"
#line 164 "numgrammar.y"
                        { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 931 "numgrammar.tab.cc"
    break;

  case 27: // exprLvl3: VALUE
#line 165 "numgrammar.y"
                                { yylhs.value.as < Node* > () = new ValueNode(yystack_[0].value.as < double > (), yystack_[0].location);

            }
#line 939 "numgrammar.tab.cc"
    break;

  case 28: // exprLvl3: VARIABLE
#line 168 "numgrammar.y"
                                {
											int x;
											if (!CurScope->GetValue (yystack_[0].value.as < std::string > (), x))
											    driver->EmergencyExit(yystack_[0].location, yy::Errors::non_existent_variable);

											yylhs.value.as < Node* > () = new VariableNode(yystack_[0].value.as < std::string > (), yystack_[0].location);

					}
#line 952 "numgrammar.tab.cc"
    break;


#line 956 "numgrammar.tab.cc"

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
  "?", ";", "ERROR", "VALUE", "VARIABLE", "'+'", "'-'", "'*'", "'/'",
  "$accept", "exprLvl1", "exprLvl2", "exprLvl3", "assignment", "stream",
  "condition", "math_op", "scope", "inside_scope", "begin_scope",
  "end_scope", YY_NULLPTR
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




  const signed char parser::yypact_ninf_ = -9;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -9,    14,    -9,    -7,     8,    -2,    29,    13,    15,    -9,
      -2,    -2,    -2,    -9,    -9,    -9,     1,     3,    -6,    -9,
      -9,    28,    37,    38,    39,    -2,    -2,    -2,    -2,    -9,
      -9,    -2,    -2,    -2,    -2,    -2,    -2,    40,    40,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,    -8,    -9,    -9
  };

  const signed char
  parser::yydefact_[] =
  {
       7,     0,     1,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,    27,    28,    18,    22,    25,     0,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      17,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      20,    21,    23,    24,    11,    12,    13,    14,    15,    16,
       3,     9,     7,    10,     0,     8,     2
  };

  const signed char
  parser::yypgoto_[] =
  {
      -9,    -5,    -3,    -9,    -9,    -9,    -9,    27,    11,    -1,
      -9,    -9
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    21,    16,    17,     7,     8,     9,    22,    51,     1,
      52,    56
  };

  const signed char
  parser::yytable_[] =
  {
      15,    10,    12,    55,    25,    26,    12,    24,    27,    28,
       3,     4,     5,    30,     2,    29,    11,     6,    13,    14,
      40,    41,    13,    14,    42,    43,    44,    45,    46,    47,
      48,    49,     3,     4,     5,    19,    18,    20,    23,     6,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    53,
      50,    54
  };

  const signed char
  parser::yycheck_[] =
  {
       5,     8,     8,    11,     3,     4,     8,    12,     5,     6,
      18,    19,    20,    18,     0,    21,     8,    25,    24,    25,
      25,    26,    24,    25,    27,    28,    31,    32,    33,    34,
      35,    36,    18,    19,    20,    22,     7,    22,    11,    25,
      12,    13,    14,    15,    16,    17,     9,     9,     9,    38,
      10,    52
  };

  const signed char
  parser::yystos_[] =
  {
       0,    39,     0,    18,    19,    20,    25,    34,    35,    36,
       8,     8,     8,    24,    25,    31,    32,    33,     7,    22,
      22,    31,    37,    37,    31,     3,     4,     5,     6,    21,
      31,    12,    13,    14,    15,    16,    17,     9,     9,     9,
      31,    31,    32,    32,    31,    31,    31,    31,    31,    31,
      10,    38,    40,    38,    39,    11,    41
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    30,    38,    40,    39,    39,    39,    39,    41,    36,
      36,    37,    37,    37,    37,    37,    37,    34,    35,    35,
      31,    31,    31,    32,    32,    32,    33,    33,    33
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     1,     3,     3,     2,     0,     1,     5,
       5,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     1
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    87,    87,    91,    98,    99,   100,   102,   106,   118,
     119,   123,   124,   125,   126,   127,   128,   132,   143,   144,
     152,   153,   154,   158,   159,   160,   164,   165,   168
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
       2,     2,    28,    26,     2,    27,     2,    29,     2,     2,
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
      25
    };
    // Last valid token kind.
    const int code_max = 280;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1372 "numgrammar.tab.cc"

#line 180 "numgrammar.y"

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
