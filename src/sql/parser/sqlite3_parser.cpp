// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "sqlite3_parser.hpp"


// Unqualified %code blocks.
#line 29 "sqlite3_parser.yy"

	#include "ParserDriver.h"
	
	static std::string unquote_text(std::string str, char quote_char)
	{
		if(str.front() != quote_char || str.back() != quote_char)
			return str;

		str = str.substr(1, str.size()-2);

		std::string quote(2, quote_char);

		size_t pos = 0;
		while((pos = str.find(quote, pos)) != std::string::npos)
		{
			str.erase(pos, 1);
			pos += 1;               // Don't remove the other quote char too
		}
		return str;
	}

#line 67 "sqlite3_parser.cpp"


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


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      yystack_print_ ();                \
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

#line 10 "sqlite3_parser.yy"
namespace  sqlb { namespace parser  {
#line 162 "sqlite3_parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (yyscan_t yyscanner_yyarg, ParserDriver& drv_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      yyscanner (yyscanner_yyarg),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



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

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 137: // optional_if_not_exists
      case 139: // optional_unique
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 144: // createindex_stmt
        value.YY_MOVE_OR_COPY< sqlb::IndexPtr > (YY_MOVE (that.value));
        break;

      case 142: // indexed_column
        value.YY_MOVE_OR_COPY< sqlb::IndexedColumn > (YY_MOVE (that.value));
        break;

      case 143: // indexed_column_list
        value.YY_MOVE_OR_COPY< sqlb::IndexedColumnVector > (YY_MOVE (that.value));
        break;

      case 27: // "ABORT"
      case 28: // "ACTION"
      case 29: // "AND"
      case 30: // "AS"
      case 31: // "ASC"
      case 32: // "AUTOINCREMENT"
      case 33: // "BETWEEN"
      case 34: // "CASCADE"
      case 35: // "CASE"
      case 36: // "CAST"
      case 37: // "CHECK"
      case 38: // "COLLATE"
      case 39: // "CONFLICT"
      case 40: // "CONSTRAINT"
      case 41: // "CREATE"
      case 42: // "CURRENT_DATE"
      case 43: // "CURRENT_TIME"
      case 44: // "CURRENT_TIMESTAMP"
      case 45: // "DEFAULT"
      case 46: // "DEFERRABLE"
      case 47: // "DEFERRED"
      case 48: // "DELETE"
      case 49: // "DESC"
      case 50: // "DISTINCT"
      case 51: // "ELSE"
      case 52: // "END"
      case 53: // "ESCAPE"
      case 54: // "EXISTS"
      case 55: // "FAIL"
      case 56: // "FALSE"
      case 57: // "FILTER"
      case 58: // "FOLLOWING"
      case 59: // "FOREIGN"
      case 60: // "GLOB"
      case 61: // "IF"
      case 62: // "IGNORE"
      case 63: // "IMMEDIATE"
      case 64: // "IN"
      case 65: // "INDEX"
      case 66: // "INITIALLY"
      case 67: // "INSERT"
      case 68: // "IS"
      case 69: // "ISNULL"
      case 70: // "KEY"
      case 71: // "LIKE"
      case 72: // "MATCH"
      case 73: // "NO"
      case 74: // "NOT"
      case 75: // "NOTNULL"
      case 76: // "NULL"
      case 77: // "ON"
      case 78: // "OR"
      case 79: // "OVER"
      case 80: // "PARTITION"
      case 81: // "PRECEDING"
      case 82: // "PRIMARY"
      case 83: // "RAISE"
      case 84: // "RANGE"
      case 85: // "REFERENCES"
      case 86: // "REGEXP"
      case 87: // "REPLACE"
      case 88: // "RESTRICT"
      case 89: // "ROLLBACK"
      case 90: // "ROWID"
      case 91: // "ROWS"
      case 92: // "SELECT"
      case 93: // "SET"
      case 94: // "TABLE"
      case 95: // "TEMP"
      case 96: // "TEMPORARY"
      case 97: // "THEN"
      case 98: // "TRUE"
      case 99: // "UNBOUNDED"
      case 100: // "UNIQUE"
      case 101: // "UPDATE"
      case 102: // "USING"
      case 103: // "VIRTUAL"
      case 104: // "WHEN"
      case 105: // "WHERE"
      case 106: // "WITHOUT"
      case 107: // "identifier"
      case 108: // "numeric"
      case 109: // "string literal"
      case 110: // "quoted literal"
      case 111: // "blob literal"
      case 112: // "bind parameter"
      case 116: // literalvalue
      case 117: // id
      case 118: // allowed_keywords_as_identifier
      case 119: // tableid
      case 120: // signednumber
      case 121: // signednumber_or_numeric
      case 122: // typename_namelist
      case 123: // type_name
      case 124: // unary_expr
      case 125: // binary_expr
      case 126: // like_expr
      case 127: // exprlist_expr
      case 128: // function_expr
      case 129: // isnull_expr
      case 130: // between_expr
      case 131: // in_expr
      case 132: // whenthenlist_expr
      case 133: // case_expr
      case 134: // raise_expr
      case 135: // expr
      case 136: // select_stmt
      case 138: // optional_sort_order
      case 140: // optional_where
      case 141: // tableid_with_uninteresting_schema
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
    switch (that.type_get ())
    {
      case 137: // optional_if_not_exists
      case 139: // optional_unique
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 144: // createindex_stmt
        value.move< sqlb::IndexPtr > (YY_MOVE (that.value));
        break;

      case 142: // indexed_column
        value.move< sqlb::IndexedColumn > (YY_MOVE (that.value));
        break;

      case 143: // indexed_column_list
        value.move< sqlb::IndexedColumnVector > (YY_MOVE (that.value));
        break;

      case 27: // "ABORT"
      case 28: // "ACTION"
      case 29: // "AND"
      case 30: // "AS"
      case 31: // "ASC"
      case 32: // "AUTOINCREMENT"
      case 33: // "BETWEEN"
      case 34: // "CASCADE"
      case 35: // "CASE"
      case 36: // "CAST"
      case 37: // "CHECK"
      case 38: // "COLLATE"
      case 39: // "CONFLICT"
      case 40: // "CONSTRAINT"
      case 41: // "CREATE"
      case 42: // "CURRENT_DATE"
      case 43: // "CURRENT_TIME"
      case 44: // "CURRENT_TIMESTAMP"
      case 45: // "DEFAULT"
      case 46: // "DEFERRABLE"
      case 47: // "DEFERRED"
      case 48: // "DELETE"
      case 49: // "DESC"
      case 50: // "DISTINCT"
      case 51: // "ELSE"
      case 52: // "END"
      case 53: // "ESCAPE"
      case 54: // "EXISTS"
      case 55: // "FAIL"
      case 56: // "FALSE"
      case 57: // "FILTER"
      case 58: // "FOLLOWING"
      case 59: // "FOREIGN"
      case 60: // "GLOB"
      case 61: // "IF"
      case 62: // "IGNORE"
      case 63: // "IMMEDIATE"
      case 64: // "IN"
      case 65: // "INDEX"
      case 66: // "INITIALLY"
      case 67: // "INSERT"
      case 68: // "IS"
      case 69: // "ISNULL"
      case 70: // "KEY"
      case 71: // "LIKE"
      case 72: // "MATCH"
      case 73: // "NO"
      case 74: // "NOT"
      case 75: // "NOTNULL"
      case 76: // "NULL"
      case 77: // "ON"
      case 78: // "OR"
      case 79: // "OVER"
      case 80: // "PARTITION"
      case 81: // "PRECEDING"
      case 82: // "PRIMARY"
      case 83: // "RAISE"
      case 84: // "RANGE"
      case 85: // "REFERENCES"
      case 86: // "REGEXP"
      case 87: // "REPLACE"
      case 88: // "RESTRICT"
      case 89: // "ROLLBACK"
      case 90: // "ROWID"
      case 91: // "ROWS"
      case 92: // "SELECT"
      case 93: // "SET"
      case 94: // "TABLE"
      case 95: // "TEMP"
      case 96: // "TEMPORARY"
      case 97: // "THEN"
      case 98: // "TRUE"
      case 99: // "UNBOUNDED"
      case 100: // "UNIQUE"
      case 101: // "UPDATE"
      case 102: // "USING"
      case 103: // "VIRTUAL"
      case 104: // "WHEN"
      case 105: // "WHERE"
      case 106: // "WITHOUT"
      case 107: // "identifier"
      case 108: // "numeric"
      case 109: // "string literal"
      case 110: // "quoted literal"
      case 111: // "blob literal"
      case 112: // "bind parameter"
      case 116: // literalvalue
      case 117: // id
      case 118: // allowed_keywords_as_identifier
      case 119: // tableid
      case 120: // signednumber
      case 121: // signednumber_or_numeric
      case 122: // typename_namelist
      case 123: // type_name
      case 124: // unary_expr
      case 125: // binary_expr
      case 126: // like_expr
      case 127: // exprlist_expr
      case 128: // function_expr
      case 129: // isnull_expr
      case 130: // between_expr
      case 131: // in_expr
      case 132: // whenthenlist_expr
      case 133: // case_expr
      case 134: // raise_expr
      case 135: // expr
      case 136: // select_stmt
      case 138: // optional_sort_order
      case 140: // optional_where
      case 141: // tableid_with_uninteresting_schema
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 137: // optional_if_not_exists
      case 139: // optional_unique
        value.move< bool > (that.value);
        break;

      case 144: // createindex_stmt
        value.move< sqlb::IndexPtr > (that.value);
        break;

      case 142: // indexed_column
        value.move< sqlb::IndexedColumn > (that.value);
        break;

      case 143: // indexed_column_list
        value.move< sqlb::IndexedColumnVector > (that.value);
        break;

      case 27: // "ABORT"
      case 28: // "ACTION"
      case 29: // "AND"
      case 30: // "AS"
      case 31: // "ASC"
      case 32: // "AUTOINCREMENT"
      case 33: // "BETWEEN"
      case 34: // "CASCADE"
      case 35: // "CASE"
      case 36: // "CAST"
      case 37: // "CHECK"
      case 38: // "COLLATE"
      case 39: // "CONFLICT"
      case 40: // "CONSTRAINT"
      case 41: // "CREATE"
      case 42: // "CURRENT_DATE"
      case 43: // "CURRENT_TIME"
      case 44: // "CURRENT_TIMESTAMP"
      case 45: // "DEFAULT"
      case 46: // "DEFERRABLE"
      case 47: // "DEFERRED"
      case 48: // "DELETE"
      case 49: // "DESC"
      case 50: // "DISTINCT"
      case 51: // "ELSE"
      case 52: // "END"
      case 53: // "ESCAPE"
      case 54: // "EXISTS"
      case 55: // "FAIL"
      case 56: // "FALSE"
      case 57: // "FILTER"
      case 58: // "FOLLOWING"
      case 59: // "FOREIGN"
      case 60: // "GLOB"
      case 61: // "IF"
      case 62: // "IGNORE"
      case 63: // "IMMEDIATE"
      case 64: // "IN"
      case 65: // "INDEX"
      case 66: // "INITIALLY"
      case 67: // "INSERT"
      case 68: // "IS"
      case 69: // "ISNULL"
      case 70: // "KEY"
      case 71: // "LIKE"
      case 72: // "MATCH"
      case 73: // "NO"
      case 74: // "NOT"
      case 75: // "NOTNULL"
      case 76: // "NULL"
      case 77: // "ON"
      case 78: // "OR"
      case 79: // "OVER"
      case 80: // "PARTITION"
      case 81: // "PRECEDING"
      case 82: // "PRIMARY"
      case 83: // "RAISE"
      case 84: // "RANGE"
      case 85: // "REFERENCES"
      case 86: // "REGEXP"
      case 87: // "REPLACE"
      case 88: // "RESTRICT"
      case 89: // "ROLLBACK"
      case 90: // "ROWID"
      case 91: // "ROWS"
      case 92: // "SELECT"
      case 93: // "SET"
      case 94: // "TABLE"
      case 95: // "TEMP"
      case 96: // "TEMPORARY"
      case 97: // "THEN"
      case 98: // "TRUE"
      case 99: // "UNBOUNDED"
      case 100: // "UNIQUE"
      case 101: // "UPDATE"
      case 102: // "USING"
      case 103: // "VIRTUAL"
      case 104: // "WHEN"
      case 105: // "WHERE"
      case 106: // "WITHOUT"
      case 107: // "identifier"
      case 108: // "numeric"
      case 109: // "string literal"
      case 110: // "quoted literal"
      case 111: // "blob literal"
      case 112: // "bind parameter"
      case 116: // literalvalue
      case 117: // id
      case 118: // allowed_keywords_as_identifier
      case 119: // tableid
      case 120: // signednumber
      case 121: // signednumber_or_numeric
      case 122: // typename_namelist
      case 123: // type_name
      case 124: // unary_expr
      case 125: // binary_expr
      case 126: // like_expr
      case 127: // exprlist_expr
      case 128: // function_expr
      case 129: // isnull_expr
      case 130: // between_expr
      case 131: // in_expr
      case 132: // whenthenlist_expr
      case 133: // case_expr
      case 134: // raise_expr
      case 135: // expr
      case 136: // select_stmt
      case 138: // optional_sort_order
      case 140: // optional_where
      case 141: // tableid_with_uninteresting_schema
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
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
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
    // State.
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
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (yyscanner, drv));
            yyla.move (yylookahead);
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
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
      case 137: // optional_if_not_exists
      case 139: // optional_unique
        yylhs.value.emplace< bool > ();
        break;

      case 144: // createindex_stmt
        yylhs.value.emplace< sqlb::IndexPtr > ();
        break;

      case 142: // indexed_column
        yylhs.value.emplace< sqlb::IndexedColumn > ();
        break;

      case 143: // indexed_column_list
        yylhs.value.emplace< sqlb::IndexedColumnVector > ();
        break;

      case 27: // "ABORT"
      case 28: // "ACTION"
      case 29: // "AND"
      case 30: // "AS"
      case 31: // "ASC"
      case 32: // "AUTOINCREMENT"
      case 33: // "BETWEEN"
      case 34: // "CASCADE"
      case 35: // "CASE"
      case 36: // "CAST"
      case 37: // "CHECK"
      case 38: // "COLLATE"
      case 39: // "CONFLICT"
      case 40: // "CONSTRAINT"
      case 41: // "CREATE"
      case 42: // "CURRENT_DATE"
      case 43: // "CURRENT_TIME"
      case 44: // "CURRENT_TIMESTAMP"
      case 45: // "DEFAULT"
      case 46: // "DEFERRABLE"
      case 47: // "DEFERRED"
      case 48: // "DELETE"
      case 49: // "DESC"
      case 50: // "DISTINCT"
      case 51: // "ELSE"
      case 52: // "END"
      case 53: // "ESCAPE"
      case 54: // "EXISTS"
      case 55: // "FAIL"
      case 56: // "FALSE"
      case 57: // "FILTER"
      case 58: // "FOLLOWING"
      case 59: // "FOREIGN"
      case 60: // "GLOB"
      case 61: // "IF"
      case 62: // "IGNORE"
      case 63: // "IMMEDIATE"
      case 64: // "IN"
      case 65: // "INDEX"
      case 66: // "INITIALLY"
      case 67: // "INSERT"
      case 68: // "IS"
      case 69: // "ISNULL"
      case 70: // "KEY"
      case 71: // "LIKE"
      case 72: // "MATCH"
      case 73: // "NO"
      case 74: // "NOT"
      case 75: // "NOTNULL"
      case 76: // "NULL"
      case 77: // "ON"
      case 78: // "OR"
      case 79: // "OVER"
      case 80: // "PARTITION"
      case 81: // "PRECEDING"
      case 82: // "PRIMARY"
      case 83: // "RAISE"
      case 84: // "RANGE"
      case 85: // "REFERENCES"
      case 86: // "REGEXP"
      case 87: // "REPLACE"
      case 88: // "RESTRICT"
      case 89: // "ROLLBACK"
      case 90: // "ROWID"
      case 91: // "ROWS"
      case 92: // "SELECT"
      case 93: // "SET"
      case 94: // "TABLE"
      case 95: // "TEMP"
      case 96: // "TEMPORARY"
      case 97: // "THEN"
      case 98: // "TRUE"
      case 99: // "UNBOUNDED"
      case 100: // "UNIQUE"
      case 101: // "UPDATE"
      case 102: // "USING"
      case 103: // "VIRTUAL"
      case 104: // "WHEN"
      case 105: // "WHERE"
      case 106: // "WITHOUT"
      case 107: // "identifier"
      case 108: // "numeric"
      case 109: // "string literal"
      case 110: // "quoted literal"
      case 111: // "blob literal"
      case 112: // "bind parameter"
      case 116: // literalvalue
      case 117: // id
      case 118: // allowed_keywords_as_identifier
      case 119: // tableid
      case 120: // signednumber
      case 121: // signednumber_or_numeric
      case 122: // typename_namelist
      case 123: // type_name
      case 124: // unary_expr
      case 125: // binary_expr
      case 126: // like_expr
      case 127: // exprlist_expr
      case 128: // function_expr
      case 129: // isnull_expr
      case 130: // between_expr
      case 131: // in_expr
      case 132: // whenthenlist_expr
      case 133: // case_expr
      case 134: // raise_expr
      case 135: // expr
      case 136: // select_stmt
      case 138: // optional_sort_order
      case 140: // optional_where
      case 141: // tableid_with_uninteresting_schema
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
  case 4:
#line 227 "sqlite3_parser.yy"
    { drv.result = yystack_[0].value.as < sqlb::IndexPtr > (); }
#line 1094 "sqlite3_parser.cpp"
    break;

  case 5:
#line 235 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1100 "sqlite3_parser.cpp"
    break;

  case 6:
#line 236 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1106 "sqlite3_parser.cpp"
    break;

  case 7:
#line 237 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1112 "sqlite3_parser.cpp"
    break;

  case 8:
#line 238 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1118 "sqlite3_parser.cpp"
    break;

  case 9:
#line 239 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1124 "sqlite3_parser.cpp"
    break;

  case 10:
#line 240 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1130 "sqlite3_parser.cpp"
    break;

  case 11:
#line 241 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1136 "sqlite3_parser.cpp"
    break;

  case 12:
#line 242 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1142 "sqlite3_parser.cpp"
    break;

  case 13:
#line 243 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1148 "sqlite3_parser.cpp"
    break;

  case 14:
#line 247 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1154 "sqlite3_parser.cpp"
    break;

  case 15:
#line 248 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1160 "sqlite3_parser.cpp"
    break;

  case 16:
#line 253 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1166 "sqlite3_parser.cpp"
    break;

  case 17:
#line 254 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1172 "sqlite3_parser.cpp"
    break;

  case 18:
#line 255 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1178 "sqlite3_parser.cpp"
    break;

  case 19:
#line 256 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1184 "sqlite3_parser.cpp"
    break;

  case 20:
#line 257 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1190 "sqlite3_parser.cpp"
    break;

  case 21:
#line 258 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1196 "sqlite3_parser.cpp"
    break;

  case 22:
#line 259 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1202 "sqlite3_parser.cpp"
    break;

  case 23:
#line 260 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1208 "sqlite3_parser.cpp"
    break;

  case 24:
#line 261 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1214 "sqlite3_parser.cpp"
    break;

  case 25:
#line 262 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1220 "sqlite3_parser.cpp"
    break;

  case 26:
#line 263 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1226 "sqlite3_parser.cpp"
    break;

  case 27:
#line 264 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1232 "sqlite3_parser.cpp"
    break;

  case 28:
#line 265 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1238 "sqlite3_parser.cpp"
    break;

  case 29:
#line 266 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1244 "sqlite3_parser.cpp"
    break;

  case 30:
#line 267 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1250 "sqlite3_parser.cpp"
    break;

  case 31:
#line 268 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1256 "sqlite3_parser.cpp"
    break;

  case 32:
#line 269 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1262 "sqlite3_parser.cpp"
    break;

  case 33:
#line 270 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1268 "sqlite3_parser.cpp"
    break;

  case 34:
#line 271 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1274 "sqlite3_parser.cpp"
    break;

  case 35:
#line 272 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1280 "sqlite3_parser.cpp"
    break;

  case 36:
#line 273 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1286 "sqlite3_parser.cpp"
    break;

  case 37:
#line 274 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1292 "sqlite3_parser.cpp"
    break;

  case 38:
#line 275 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1298 "sqlite3_parser.cpp"
    break;

  case 39:
#line 276 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1304 "sqlite3_parser.cpp"
    break;

  case 40:
#line 277 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1310 "sqlite3_parser.cpp"
    break;

  case 41:
#line 278 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1316 "sqlite3_parser.cpp"
    break;

  case 42:
#line 279 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1322 "sqlite3_parser.cpp"
    break;

  case 43:
#line 280 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1328 "sqlite3_parser.cpp"
    break;

  case 44:
#line 281 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1334 "sqlite3_parser.cpp"
    break;

  case 45:
#line 282 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1340 "sqlite3_parser.cpp"
    break;

  case 46:
#line 283 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1346 "sqlite3_parser.cpp"
    break;

  case 47:
#line 284 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1352 "sqlite3_parser.cpp"
    break;

  case 48:
#line 285 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1358 "sqlite3_parser.cpp"
    break;

  case 49:
#line 286 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1364 "sqlite3_parser.cpp"
    break;

  case 50:
#line 287 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1370 "sqlite3_parser.cpp"
    break;

  case 51:
#line 288 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1376 "sqlite3_parser.cpp"
    break;

  case 52:
#line 292 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1382 "sqlite3_parser.cpp"
    break;

  case 53:
#line 293 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1388 "sqlite3_parser.cpp"
    break;

  case 54:
#line 294 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1394 "sqlite3_parser.cpp"
    break;

  case 55:
#line 295 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1400 "sqlite3_parser.cpp"
    break;

  case 56:
#line 296 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1406 "sqlite3_parser.cpp"
    break;

  case 57:
#line 297 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = unquote_text(yystack_[0].value.as < std::string > (), '\''); }
#line 1412 "sqlite3_parser.cpp"
    break;

  case 58:
#line 311 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "+" + yystack_[0].value.as < std::string > (); }
#line 1418 "sqlite3_parser.cpp"
    break;

  case 59:
#line 312 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "-" + yystack_[0].value.as < std::string > (); }
#line 1424 "sqlite3_parser.cpp"
    break;

  case 60:
#line 316 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1430 "sqlite3_parser.cpp"
    break;

  case 61:
#line 317 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1436 "sqlite3_parser.cpp"
    break;

  case 62:
#line 321 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1442 "sqlite3_parser.cpp"
    break;

  case 63:
#line 322 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 1448 "sqlite3_parser.cpp"
    break;

  case 64:
#line 326 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1454 "sqlite3_parser.cpp"
    break;

  case 65:
#line 327 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1460 "sqlite3_parser.cpp"
    break;

  case 66:
#line 328 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + "(" + yystack_[3].value.as < std::string > () + ", " + yystack_[1].value.as < std::string > () + ")"; }
#line 1466 "sqlite3_parser.cpp"
    break;

  case 67:
#line 332 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "-" + yystack_[0].value.as < std::string > (); }
#line 1472 "sqlite3_parser.cpp"
    break;

  case 68:
#line 333 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "+" + yystack_[0].value.as < std::string > (); }
#line 1478 "sqlite3_parser.cpp"
    break;

  case 69:
#line 334 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "~" + yystack_[0].value.as < std::string > (); }
#line 1484 "sqlite3_parser.cpp"
    break;

  case 70:
#line 335 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "NOT " + yystack_[0].value.as < std::string > (); }
#line 1490 "sqlite3_parser.cpp"
    break;

  case 71:
#line 339 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " || " + yystack_[0].value.as < std::string > (); }
#line 1496 "sqlite3_parser.cpp"
    break;

  case 72:
#line 340 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " * " + yystack_[0].value.as < std::string > (); }
#line 1502 "sqlite3_parser.cpp"
    break;

  case 73:
#line 341 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " / " + yystack_[0].value.as < std::string > (); }
#line 1508 "sqlite3_parser.cpp"
    break;

  case 74:
#line 342 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " % " + yystack_[0].value.as < std::string > (); }
#line 1514 "sqlite3_parser.cpp"
    break;

  case 75:
#line 343 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " + " + yystack_[0].value.as < std::string > (); }
#line 1520 "sqlite3_parser.cpp"
    break;

  case 76:
#line 344 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " - " + yystack_[0].value.as < std::string > (); }
#line 1526 "sqlite3_parser.cpp"
    break;

  case 77:
#line 345 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " << " + yystack_[0].value.as < std::string > (); }
#line 1532 "sqlite3_parser.cpp"
    break;

  case 78:
#line 346 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " >> " + yystack_[0].value.as < std::string > (); }
#line 1538 "sqlite3_parser.cpp"
    break;

  case 79:
#line 347 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " & " + yystack_[0].value.as < std::string > (); }
#line 1544 "sqlite3_parser.cpp"
    break;

  case 80:
#line 348 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " | " + yystack_[0].value.as < std::string > (); }
#line 1550 "sqlite3_parser.cpp"
    break;

  case 81:
#line 349 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " < " + yystack_[0].value.as < std::string > (); }
#line 1556 "sqlite3_parser.cpp"
    break;

  case 82:
#line 350 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " <= " + yystack_[0].value.as < std::string > (); }
#line 1562 "sqlite3_parser.cpp"
    break;

  case 83:
#line 351 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " > " + yystack_[0].value.as < std::string > (); }
#line 1568 "sqlite3_parser.cpp"
    break;

  case 84:
#line 352 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " >= " + yystack_[0].value.as < std::string > (); }
#line 1574 "sqlite3_parser.cpp"
    break;

  case 85:
#line 353 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " = " + yystack_[0].value.as < std::string > (); }
#line 1580 "sqlite3_parser.cpp"
    break;

  case 86:
#line 354 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " == " + yystack_[0].value.as < std::string > (); }
#line 1586 "sqlite3_parser.cpp"
    break;

  case 87:
#line 355 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " != " + yystack_[0].value.as < std::string > (); }
#line 1592 "sqlite3_parser.cpp"
    break;

  case 88:
#line 356 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " <> " + yystack_[0].value.as < std::string > (); }
#line 1598 "sqlite3_parser.cpp"
    break;

  case 89:
#line 357 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " IS " + yystack_[0].value.as < std::string > (); }
#line 1604 "sqlite3_parser.cpp"
    break;

  case 90:
#line 358 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 1610 "sqlite3_parser.cpp"
    break;

  case 91:
#line 359 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " OR " + yystack_[0].value.as < std::string > (); }
#line 1616 "sqlite3_parser.cpp"
    break;

  case 92:
#line 363 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " LIKE " + yystack_[0].value.as < std::string > (); }
#line 1622 "sqlite3_parser.cpp"
    break;

  case 93:
#line 364 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " GLOB " + yystack_[0].value.as < std::string > (); }
#line 1628 "sqlite3_parser.cpp"
    break;

  case 94:
#line 365 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " MATCH " + yystack_[0].value.as < std::string > (); }
#line 1634 "sqlite3_parser.cpp"
    break;

  case 95:
#line 366 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " REGEXP " + yystack_[0].value.as < std::string > (); }
#line 1640 "sqlite3_parser.cpp"
    break;

  case 96:
#line 367 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT LIKE " + yystack_[1].value.as < std::string > (); }
#line 1646 "sqlite3_parser.cpp"
    break;

  case 97:
#line 368 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT GLOB " + yystack_[1].value.as < std::string > (); }
#line 1652 "sqlite3_parser.cpp"
    break;

  case 98:
#line 369 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT MATCH " + yystack_[1].value.as < std::string > (); }
#line 1658 "sqlite3_parser.cpp"
    break;

  case 99:
#line 370 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT REGEXP " + yystack_[1].value.as < std::string > (); }
#line 1664 "sqlite3_parser.cpp"
    break;

  case 100:
#line 371 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " LIKE " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1670 "sqlite3_parser.cpp"
    break;

  case 101:
#line 372 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " GLOB " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1676 "sqlite3_parser.cpp"
    break;

  case 102:
#line 373 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " MATCH " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1682 "sqlite3_parser.cpp"
    break;

  case 103:
#line 374 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " REGEXP " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1688 "sqlite3_parser.cpp"
    break;

  case 104:
#line 375 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT LIKE " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1694 "sqlite3_parser.cpp"
    break;

  case 105:
#line 376 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT GLOB " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1700 "sqlite3_parser.cpp"
    break;

  case 106:
#line 377 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT MATCH " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1706 "sqlite3_parser.cpp"
    break;

  case 107:
#line 378 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT REGEXP " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1712 "sqlite3_parser.cpp"
    break;

  case 108:
#line 382 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1718 "sqlite3_parser.cpp"
    break;

  case 109:
#line 383 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + ", " + yystack_[0].value.as < std::string > (); }
#line 1724 "sqlite3_parser.cpp"
    break;

  case 110:
#line 387 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1730 "sqlite3_parser.cpp"
    break;

  case 111:
#line 388 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + "(DISTINCT " + yystack_[1].value.as < std::string > () + ")"; }
#line 1736 "sqlite3_parser.cpp"
    break;

  case 112:
#line 389 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "()"; }
#line 1742 "sqlite3_parser.cpp"
    break;

  case 113:
#line 390 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(*)"; }
#line 1748 "sqlite3_parser.cpp"
    break;

  case 114:
#line 394 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " ISNULL"; }
#line 1754 "sqlite3_parser.cpp"
    break;

  case 115:
#line 395 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " NOTNULL"; }
#line 1760 "sqlite3_parser.cpp"
    break;

  case 116:
#line 396 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " NOT NULL"; }
#line 1766 "sqlite3_parser.cpp"
    break;

  case 117:
#line 400 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " BETWEEN " + yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 1772 "sqlite3_parser.cpp"
    break;

  case 118:
#line 401 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT BETWEEN " + yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 1778 "sqlite3_parser.cpp"
    break;

  case 119:
#line 405 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " IN ()"; }
#line 1784 "sqlite3_parser.cpp"
    break;

  case 120:
#line 406 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 1790 "sqlite3_parser.cpp"
    break;

  case 121:
#line 407 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 1796 "sqlite3_parser.cpp"
    break;

  case 122:
#line 408 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1802 "sqlite3_parser.cpp"
    break;

  case 123:
#line 409 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1808 "sqlite3_parser.cpp"
    break;

  case 124:
#line 410 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[6].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + yystack_[2].value.as < std::string > () + "()"; }
#line 1814 "sqlite3_parser.cpp"
    break;

  case 125:
#line 411 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[7].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[5].value.as < std::string > ()) + "." + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1820 "sqlite3_parser.cpp"
    break;

  case 126:
#line 412 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " IN " + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1826 "sqlite3_parser.cpp"
    break;

  case 127:
#line 413 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " NOT IN ()"; }
#line 1832 "sqlite3_parser.cpp"
    break;

  case 128:
#line 414 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 1838 "sqlite3_parser.cpp"
    break;

  case 129:
#line 415 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 1844 "sqlite3_parser.cpp"
    break;

  case 130:
#line 416 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1850 "sqlite3_parser.cpp"
    break;

  case 131:
#line 417 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1856 "sqlite3_parser.cpp"
    break;

  case 132:
#line 418 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[7].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + yystack_[2].value.as < std::string > () + "()"; }
#line 1862 "sqlite3_parser.cpp"
    break;

  case 133:
#line 419 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[8].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[5].value.as < std::string > ()) + "." + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1868 "sqlite3_parser.cpp"
    break;

  case 134:
#line 420 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[6].value.as < std::string > () + " NOT IN " + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1874 "sqlite3_parser.cpp"
    break;

  case 135:
#line 424 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "WHEN " + yystack_[2].value.as < std::string > () + " THEN " + yystack_[0].value.as < std::string > (); }
#line 1880 "sqlite3_parser.cpp"
    break;

  case 136:
#line 425 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " WHEN" + yystack_[2].value.as < std::string > () + " THEN " + yystack_[0].value.as < std::string > (); }
#line 1886 "sqlite3_parser.cpp"
    break;

  case 137:
#line 429 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[4].value.as < std::string > () + " " + yystack_[3].value.as < std::string > () + " ELSE " + yystack_[1].value.as < std::string > () + " END"; }
#line 1892 "sqlite3_parser.cpp"
    break;

  case 138:
#line 430 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " END"; }
#line 1898 "sqlite3_parser.cpp"
    break;

  case 139:
#line 431 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[3].value.as < std::string > () + " ELSE " + yystack_[1].value.as < std::string > () + " END"; }
#line 1904 "sqlite3_parser.cpp"
    break;

  case 140:
#line 432 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[1].value.as < std::string > () + " END"; }
#line 1910 "sqlite3_parser.cpp"
    break;

  case 141:
#line 436 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(IGNORE)"; }
#line 1916 "sqlite3_parser.cpp"
    break;

  case 142:
#line 437 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(ROLLBACK, " + yystack_[1].value.as < std::string > () + ")"; }
#line 1922 "sqlite3_parser.cpp"
    break;

  case 143:
#line 438 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(ABORT, " + yystack_[1].value.as < std::string > () + ")"; }
#line 1928 "sqlite3_parser.cpp"
    break;

  case 144:
#line 439 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(FAIL, " + yystack_[1].value.as < std::string > () + ")"; }
#line 1934 "sqlite3_parser.cpp"
    break;

  case 145:
#line 443 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1940 "sqlite3_parser.cpp"
    break;

  case 146:
#line 444 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1946 "sqlite3_parser.cpp"
    break;

  case 147:
#line 445 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1952 "sqlite3_parser.cpp"
    break;

  case 148:
#line 446 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1958 "sqlite3_parser.cpp"
    break;

  case 149:
#line 447 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1964 "sqlite3_parser.cpp"
    break;

  case 150:
#line 448 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1970 "sqlite3_parser.cpp"
    break;

  case 151:
#line 449 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1976 "sqlite3_parser.cpp"
    break;

  case 152:
#line 450 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1982 "sqlite3_parser.cpp"
    break;

  case 153:
#line 451 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1988 "sqlite3_parser.cpp"
    break;

  case 154:
#line 452 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1994 "sqlite3_parser.cpp"
    break;

  case 155:
#line 453 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CAST(" + yystack_[3].value.as < std::string > () + " AS " + yystack_[1].value.as < std::string > () + ")"; }
#line 2000 "sqlite3_parser.cpp"
    break;

  case 156:
#line 454 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " COLLATE " + yystack_[0].value.as < std::string > (); }
#line 2006 "sqlite3_parser.cpp"
    break;

  case 157:
#line 455 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2012 "sqlite3_parser.cpp"
    break;

  case 158:
#line 456 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2018 "sqlite3_parser.cpp"
    break;

  case 159:
#line 457 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2024 "sqlite3_parser.cpp"
    break;

  case 160:
#line 458 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2030 "sqlite3_parser.cpp"
    break;

  case 161:
#line 459 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2036 "sqlite3_parser.cpp"
    break;

  case 162:
#line 460 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2042 "sqlite3_parser.cpp"
    break;

  case 163:
#line 469 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "SELECT"; }
#line 2048 "sqlite3_parser.cpp"
    break;

  case 164:
#line 477 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = false; }
#line 2054 "sqlite3_parser.cpp"
    break;

  case 165:
#line 478 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = true; }
#line 2060 "sqlite3_parser.cpp"
    break;

  case 166:
#line 482 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2066 "sqlite3_parser.cpp"
    break;

  case 167:
#line 483 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "ASC"; }
#line 2072 "sqlite3_parser.cpp"
    break;

  case 168:
#line 484 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "DESC"; }
#line 2078 "sqlite3_parser.cpp"
    break;

  case 169:
#line 492 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = false; }
#line 2084 "sqlite3_parser.cpp"
    break;

  case 170:
#line 493 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = true; }
#line 2090 "sqlite3_parser.cpp"
    break;

  case 171:
#line 497 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2096 "sqlite3_parser.cpp"
    break;

  case 172:
#line 498 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2102 "sqlite3_parser.cpp"
    break;

  case 173:
#line 502 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2108 "sqlite3_parser.cpp"
    break;

  case 174:
#line 503 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2114 "sqlite3_parser.cpp"
    break;

  case 175:
#line 504 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2120 "sqlite3_parser.cpp"
    break;

  case 176:
#line 508 "sqlite3_parser.yy"
    {
							// If the expression is only one column name and nothing else, treat it as a column name; otherwise as an expression.
							char quote = getIdentifierQuoteChar();
							if((quote == '[' && std::count(yystack_[1].value.as < std::string > ().begin(), yystack_[1].value.as < std::string > ().end(), quote) == 1 && yystack_[1].value.as < std::string > ().front() == '[' && yystack_[1].value.as < std::string > ().back() == ']') ||
								(quote != '[' && std::count(yystack_[1].value.as < std::string > ().begin(), yystack_[1].value.as < std::string > ().end(), quote) == 2 && yystack_[1].value.as < std::string > ().front() == quote && yystack_[1].value.as < std::string > ().back() == quote))
							{
								yylhs.value.as < sqlb::IndexedColumn > () = sqlb::IndexedColumn(unquote_text(yystack_[1].value.as < std::string > (), quote), false, yystack_[0].value.as < std::string > ());
							} else {
								yylhs.value.as < sqlb::IndexedColumn > () = sqlb::IndexedColumn(yystack_[1].value.as < std::string > (), true, yystack_[0].value.as < std::string > ());
							}
						}
#line 2136 "sqlite3_parser.cpp"
    break;

  case 177:
#line 522 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::IndexedColumnVector > () = sqlb::IndexedColumnVector(1, yystack_[0].value.as < sqlb::IndexedColumn > ()); }
#line 2142 "sqlite3_parser.cpp"
    break;

  case 178:
#line 523 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::IndexedColumnVector > () = yystack_[2].value.as < sqlb::IndexedColumnVector > (); yylhs.value.as < sqlb::IndexedColumnVector > ().push_back(yystack_[0].value.as < sqlb::IndexedColumn > ()); }
#line 2148 "sqlite3_parser.cpp"
    break;

  case 179:
#line 527 "sqlite3_parser.yy"
    {
													yylhs.value.as < sqlb::IndexPtr > () = sqlb::IndexPtr(new sqlb::Index(yystack_[6].value.as < std::string > ()));
													yylhs.value.as < sqlb::IndexPtr > ()->setTable(yystack_[4].value.as < std::string > ());
													yylhs.value.as < sqlb::IndexPtr > ()->setUnique(yystack_[9].value.as < bool > ());
													yylhs.value.as < sqlb::IndexPtr > ()->setWhereExpr(yystack_[0].value.as < std::string > ());
													yylhs.value.as < sqlb::IndexPtr > ()->fields = yystack_[2].value.as < sqlb::IndexedColumnVector > ();
													yylhs.value.as < sqlb::IndexPtr > ()->setFullyParsed(true);
												}
#line 2161 "sqlite3_parser.cpp"
    break;


#line 2165 "sqlite3_parser.cpp"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
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

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -126;

  const signed char parser::yytable_ninf_ = -91;

  const short
  parser::yypact_[] =
  {
     -29,   -69,    44,    25,  -126,  -126,   -10,  -126,  -126,     4,
     -12,  1511,    12,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,    68,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,    71,  -126,  -126,     8,  -126,
    1588,  1588,  1588,  -126,  -126,  -126,  -126,    78,  1060,  1060,
    1060,  1060,  1060,   730,    85,  -126,  -126,  -126,  -126,  1060,
    -126,    89,  -126,  -126,  -126,  -126,  -126,  -126,    74,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  1691,
    -126,    76,    87,  1945,  -126,  -126,  -126,  1060,   -17,     0,
    1060,  2157,     1,   400,   -80,  1060,  1060,  1060,  1060,  1060,
    1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,
    1060,  1060,  1060,  1060,  -126,  1060,   -80,  -126,  1060,  1149,
    1060,  -126,  1060,  1060,    34,  -126,  1060,  1060,  -126,    -6,
    1060,  -126,  1060,  1430,  1060,  -126,  1060,   -15,  1765,   102,
     109,    91,   115,  -126,   118,  1060,   112,   121,    86,    86,
      23,    23,   103,    23,   103,    92,  1723,  1723,    32,    32,
      32,    32,  1723,  1723,   103,   103,  2157,  1977,  -126,   303,
     510,   104,  -126,  1723,  2189,  2225,  1060,  1060,  1238,  1060,
    1060,  -126,  1060,  2083,  2245,  1060,  -126,  -126,  1945,  1060,
    1797,  1462,  1060,  -126,  1588,    18,    27,  -126,    38,  -126,
     148,  -126,   -80,  1060,  1060,  -126,  -126,   151,   144,  1060,
    1588,  1060,  1060,  2051,  2266,   620,   156,  -126,  2286,  2307,
    2327,  1060,  1945,  1945,  -126,  1060,  1871,  -126,  1327,   147,
     152,   168,   172,  -126,  -126,   124,  1723,  -126,  -126,   160,
     157,  -126,  1723,  1723,  1060,  1060,  -126,   161,   176,  1060,
    1588,  1060,  1060,  1060,  1723,  1945,  -126,    -7,  -126,  -126,
    -126,  -126,  -126,  -126,   840,   124,  1723,  -126,  -126,   164,
     178,  -126,  1723,  1723,  1723,    75,    77,  -126,  -126,   165,
    -126,   169,  -126,   950,  -126,  -126,  -126,    -7,  -126,  -126,
     173,   180,  -126,  -126
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   169,     0,     2,     4,   170,     0,     1,     3,   164,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    54,
      53,    55,    22,    23,    24,    25,    26,    27,    28,    31,
      33,    32,    29,    30,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    48,    47,    49,
      50,    51,    14,    57,    15,    56,    52,   175,     0,   165,
       0,     0,     0,    48,    56,   174,   173,     0,     0,     0,
       0,     0,     0,     0,    20,    12,    11,    13,    10,     0,
       8,    39,     9,     5,     6,     7,   147,   145,   150,   146,
     151,   152,   157,   153,   158,   159,   160,   161,   162,   166,
     177,     0,     0,   108,    68,    67,    69,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,   168,     0,     0,
       0,   114,     0,     0,     0,   115,     0,     0,   176,   171,
       0,   154,     0,     0,     0,   140,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,   149,    75,    76,
      72,    73,    79,    74,    80,    71,    85,    86,    83,    84,
      81,    82,    87,    88,    77,    78,    90,     0,   156,    93,
       0,    56,   123,    89,    92,    94,     0,     0,     0,     0,
       0,   116,     0,    91,    95,     0,   179,   178,   109,     0,
       0,     0,     0,   138,     0,     0,     0,   141,     0,   113,
       0,   110,     0,     0,     0,   119,   163,     0,     0,     0,
       0,     0,     0,     0,    97,     0,    56,   131,    96,    98,
      99,     0,   172,   135,   139,     0,     0,    62,    64,     0,
       0,     0,     0,   111,   148,   117,   101,   121,   120,     0,
      56,   122,   100,   102,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,   103,   136,   137,     0,    63,   155,
     143,   144,   142,   126,     0,   118,   105,   129,   128,     0,
      56,   130,   104,   106,   107,     0,     0,    61,    60,     0,
     124,     0,   134,     0,    58,    59,    65,     0,   125,   132,
       0,     0,   133,    66
  };

  const short
  parser::yypgoto_[] =
  {
    -126,  -126,  -126,  -126,   -11,    -8,   -56,  -126,  -125,  -126,
    -126,  -126,  -126,  -126,  -106,  -126,  -126,  -126,  -126,    79,
    -126,  -126,   153,   -49,  -126,  -126,  -126,  -126,  -126,    39,
    -126,  -126
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    87,    88,    89,    57,   298,   299,   248,
     249,    90,    91,    92,   102,    93,    94,    95,    96,   108,
      97,    98,   103,   228,    11,   148,     6,   206,    58,   100,
     101,     4
  };

  const short
  parser::yytable_[] =
  {
      55,   295,   296,    56,    65,    66,    67,   166,   115,   116,
     117,   118,     1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    52,   159,   133,
      54,     5,     8,   135,   154,   155,   212,   213,   136,   122,
     115,   116,   117,   118,     7,   119,   120,   121,   122,    64,
      64,    64,    56,    56,    56,     9,   160,   131,   132,   220,
     138,   136,    12,   161,   139,    10,    59,   196,   140,   141,
     136,   142,   143,    60,   144,   145,    61,   113,   146,   114,
     149,    68,   150,   192,   227,    62,   147,   156,   110,   156,
     162,   151,   112,   152,   197,   217,   117,   118,   198,   205,
     120,   297,   122,   167,   107,   199,   200,   229,   215,   230,
     201,   115,   116,   117,   118,   216,   221,   120,   152,   122,
     202,   218,   219,   259,   136,   188,   222,   250,   191,   267,
     136,    56,   115,   116,   117,   118,   251,   119,   120,   121,
     122,   136,   237,   125,   126,   127,   128,   252,   258,   131,
     132,   279,   253,   -90,   152,   257,   280,   152,   247,   269,
     284,   270,   136,   289,   283,   287,   152,   152,   302,   306,
     152,   307,   281,   308,   261,   152,   282,   312,   301,   152,
     288,   303,   311,   304,   313,   305,   268,   236,   157,   207,
      56,     0,   278,     0,     0,     0,     0,   310,     0,     0,
       0,     0,   -90,    64,     0,     0,    56,     0,     0,     0,
       0,   254,     0,     0,   291,     0,     0,     0,     0,   260,
       0,    99,    56,   104,   105,   106,   109,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,    64,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     153,     0,    56,   158,     0,     0,     0,     0,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,     0,
       0,   189,     0,   193,     0,   194,   195,     0,     0,   203,
     204,     0,     0,    99,     0,   208,     0,   210,     0,   211,
       0,   115,   116,   117,   118,     0,   119,   120,   121,   122,
       0,     0,   125,   126,   127,   128,     0,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,   233,
     234,     0,   238,   239,     0,   240,   224,     0,   242,     0,
       0,     0,   243,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,     0,     0,
       0,     0,     0,     0,   262,   263,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,     0,   275,     0,
       0,     0,     0,    69,   163,     0,     0,     0,    70,    71,
     164,     0,    72,     0,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,   292,   293,   294,    13,    14,     0,
       0,    15,     0,     0,    16,    73,    74,     0,     0,    18,
       0,     0,    75,    76,    77,     0,     0,    22,     0,    23,
     165,     0,    24,     0,     0,    25,    78,    26,    27,     0,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
      32,    33,    34,    35,    79,     0,    80,     0,     0,    36,
      37,    38,     0,    81,    40,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,    63,    48,     0,    82,    49,
       0,     0,     0,    50,     0,     0,    51,    52,    83,    84,
      54,    85,    86,    69,   225,     0,     0,     0,    70,    71,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,     0,     0,    16,    73,    74,     0,     0,    18,
       0,     0,    75,    76,    77,     0,     0,    22,     0,    23,
       0,     0,    24,     0,     0,    25,    78,    26,    27,     0,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
      32,    33,    34,    35,    79,     0,    80,     0,     0,    36,
      37,    38,     0,    81,    40,     0,    41,    42,    43,    44,
      45,    46,   226,     0,     0,    63,    48,     0,    82,    49,
       0,     0,     0,    50,     0,     0,    51,    52,    83,    84,
      54,    85,    86,    69,   266,     0,     0,     0,    70,    71,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,     0,     0,    16,    73,    74,     0,     0,    18,
       0,     0,    75,    76,    77,     0,     0,    22,     0,    23,
       0,     0,    24,     0,     0,    25,    78,    26,    27,     0,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
      32,    33,    34,    35,    79,     0,    80,     0,     0,    36,
      37,    38,     0,    81,    40,     0,    41,    42,    43,    44,
      45,    46,   226,     0,     0,    63,    48,     0,    82,    49,
       0,     0,     0,    50,     0,     0,    51,    52,    83,    84,
      54,    85,    86,    69,     0,     0,     0,     0,    70,    71,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,     0,     0,    16,    73,    74,     0,     0,    18,
       0,     0,    75,    76,    77,     0,     0,    22,     0,    23,
       0,     0,    24,     0,     0,    25,    78,    26,    27,     0,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
      32,    33,    34,    35,    79,     0,    80,     0,     0,    36,
      37,    38,     0,    81,    40,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,    63,    48,     0,    82,    49,
       0,     0,     0,    50,   107,     0,    51,    52,    83,    84,
      54,    85,    86,    69,   300,     0,     0,     0,    70,    71,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,     0,     0,    16,    73,    74,     0,     0,    18,
       0,     0,    75,    76,    77,     0,     0,    22,     0,    23,
       0,     0,    24,     0,     0,    25,    78,    26,    27,     0,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
      32,    33,    34,    35,    79,     0,    80,     0,     0,    36,
      37,    38,     0,    81,    40,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,    63,    48,     0,    82,    49,
       0,     0,     0,    50,     0,     0,    51,    52,    83,    84,
      54,    85,    86,    69,   309,     0,     0,     0,    70,    71,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,     0,     0,    16,    73,    74,     0,     0,    18,
       0,     0,    75,    76,    77,     0,     0,    22,     0,    23,
       0,     0,    24,     0,     0,    25,    78,    26,    27,     0,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
      32,    33,    34,    35,    79,     0,    80,     0,     0,    36,
      37,    38,     0,    81,    40,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,    63,    48,     0,    82,    49,
       0,     0,     0,    50,     0,     0,    51,    52,    83,    84,
      54,    85,    86,    69,     0,     0,     0,     0,    70,    71,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,     0,     0,    16,    73,    74,     0,     0,    18,
       0,     0,    75,    76,    77,     0,     0,    22,     0,    23,
       0,     0,    24,     0,     0,    25,    78,    26,    27,     0,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
      32,    33,    34,    35,    79,     0,    80,     0,     0,    36,
      37,    38,     0,    81,    40,     0,    41,    42,    43,    44,
      45,    46,   190,     0,     0,    63,    48,     0,    82,    49,
       0,     0,     0,    50,     0,     0,    51,    52,    83,    84,
      54,    85,    86,     0,     0,     0,    13,    14,     0,     0,
      15,     0,     0,    16,     0,    17,     0,     0,    18,     0,
       0,    19,    20,    21,     0,     0,    22,     0,    23,     0,
       0,    24,     0,     0,    25,     0,    26,    27,     0,    28,
       0,    29,    30,     0,     0,    31,     0,     0,     0,    32,
      33,    34,    35,     0,     0,     0,     0,     0,    36,    37,
      38,     0,    39,    40,     0,    41,    42,    43,    44,    45,
      46,   235,     0,     0,    63,    48,     0,     0,    49,     0,
       0,     0,    50,     0,     0,    51,    52,     0,    53,    54,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    15,
       0,     0,    16,     0,    17,     0,     0,    18,     0,     0,
      19,    20,    21,     0,     0,    22,     0,    23,     0,     0,
      24,     0,     0,    25,     0,    26,    27,     0,    28,     0,
      29,    30,     0,     0,    31,     0,     0,     0,    32,    33,
      34,    35,     0,     0,     0,     0,     0,    36,    37,    38,
       0,    39,    40,     0,    41,    42,    43,    44,    45,    46,
     277,     0,     0,    63,    48,     0,     0,    49,     0,     0,
       0,    50,     0,     0,    51,    52,     0,    53,    54,     0,
       0,     0,     0,     0,    13,    14,     0,     0,    15,     0,
       0,    16,     0,    17,     0,     0,    18,     0,     0,    19,
      20,    21,     0,     0,    22,     0,    23,     0,     0,    24,
       0,     0,    25,     0,    26,    27,     0,    28,     0,    29,
      30,     0,     0,    31,     0,     0,     0,    32,    33,    34,
      35,     0,     0,     0,     0,     0,    36,    37,    38,     0,
      39,    40,     0,    41,    42,    43,    44,    45,    46,     0,
       0,     0,    63,    48,     0,     0,    49,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,    54,   115,   116,
     117,   118,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   133,
       0,     0,     0,   135,     0,     0,     0,     0,   136,     0,
     115,   116,   117,   118,     0,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
     138,   133,     0,     0,   139,   135,     0,     0,   140,   141,
     136,   142,   143,     0,   144,   145,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,   138,     0,     0,     0,   139,   209,     0,     0,
     140,   141,     0,   142,   143,     0,   144,   145,    13,    14,
     146,     0,    15,     0,     0,    16,     0,    17,   147,     0,
      18,     0,     0,    19,    20,    21,     0,     0,    22,   245,
      23,     0,     0,    24,     0,     0,    25,     0,    26,    27,
       0,    28,     0,    29,    30,     0,     0,    31,     0,     0,
       0,    32,    33,    34,    35,     0,     0,     0,     0,     0,
      36,    37,    38,     0,    39,    40,     0,    41,    42,    43,
      44,    45,    46,     0,     0,     0,    47,    48,     0,     0,
      49,     0,     0,     0,    50,    13,    14,    51,    52,    15,
      53,    54,    16,     0,    17,     0,     0,    18,     0,     0,
      19,    20,    21,     0,     0,    22,     0,    23,     0,     0,
      24,     0,     0,    25,     0,    26,    27,     0,    28,     0,
      29,    30,     0,     0,    31,     0,     0,     0,    32,    33,
      34,    35,     0,     0,     0,     0,     0,    36,    37,    38,
       0,    39,    40,     0,    41,    42,    43,    44,    45,    46,
       0,     0,     0,    63,    48,     0,     0,    49,     0,     0,
       0,    50,     0,     0,    51,    52,     0,    53,    54,   115,
     116,   117,   118,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     133,     0,   134,     0,   135,     0,     0,     0,     0,   136,
       0,   115,   116,   117,   118,     0,   119,   120,   121,   122,
     137,     0,   125,   126,   127,   128,     0,     0,   131,   132,
       0,   138,     0,     0,     0,   139,     0,     0,     0,   140,
     141,   136,   142,   143,     0,   144,   145,     0,     0,   146,
       0,     0,     0,   115,   116,   117,   118,   147,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,   133,   214,     0,     0,   135,     0,
       0,     0,     0,   136,     0,   115,   116,   117,   118,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,   138,   133,     0,     0,   139,
     135,     0,     0,   140,   141,   136,   142,   143,     0,   144,
     145,     0,     0,   146,     0,     0,     0,     0,     0,   244,
       0,   147,     0,     0,     0,     0,     0,   138,     0,     0,
       0,   139,     0,     0,     0,   140,   141,     0,   142,   143,
       0,   144,   145,     0,     0,   146,     0,     0,     0,   115,
     116,   117,   118,   147,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     133,     0,     0,     0,   135,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,   139,     0,     0,     0,   140,
     141,     0,   142,   143,     0,   144,   145,     0,     0,   146,
       0,     0,     0,   115,   116,   117,   118,   147,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,   133,     0,     0,     0,   135,     0,
       0,     0,     0,   136,     0,   115,   116,   117,   118,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,   138,   223,     0,     0,   139,
     135,     0,     0,   140,   141,   136,   142,   143,     0,   144,
     145,     0,     0,   146,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,   138,     0,     0,
       0,   139,     0,     0,     0,   140,   141,     0,   142,   143,
       0,   144,   145,     0,     0,   146,     0,     0,     0,   115,
     116,   117,   118,   147,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     264,     0,     0,     0,   135,     0,     0,     0,     0,   136,
       0,   115,   116,   117,   118,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
       0,   138,   133,     0,     0,   139,   135,     0,     0,   140,
     141,   136,   142,   143,     0,   144,   145,     0,     0,   146,
       0,     0,     0,     0,     0,     0,     0,   147,     0,     0,
       0,     0,     0,   138,     0,     0,     0,   139,     0,     0,
       0,   140,   141,     0,   142,   143,     0,   144,   145,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   147,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
     135,     0,     0,     0,     0,   136,     0,   115,   116,   117,
     118,     0,   119,   120,   121,   122,     0,     0,   125,   126,
     127,   128,     0,     0,   131,   132,     0,   138,     0,     0,
       0,   139,     0,     0,     0,   140,   141,   136,   142,   143,
       0,   144,   145,   115,   116,   117,   118,     0,   119,   120,
     121,   122,   231,   147,   125,   126,   127,   128,     0,     0,
     131,   132,     0,   115,   116,   117,   118,     0,   119,   120,
     121,   122,     0,   136,   125,   126,   127,   128,     0,     0,
     131,   132,     0,     0,   115,   116,   117,   118,   232,   119,
     120,   121,   122,   136,     0,   125,   126,   127,   128,     0,
       0,   131,   132,     0,   115,   116,   117,   118,   241,   119,
     120,   121,   122,     0,   136,   125,   126,   127,   128,     0,
       0,   131,   132,     0,     0,   115,   116,   117,   118,   265,
     119,   120,   121,   122,   136,     0,   125,   126,   127,   128,
       0,     0,   131,   132,     0,   115,   116,   117,   118,   271,
     119,   120,   121,   122,     0,   136,   125,   126,   127,   128,
       0,     0,   131,   132,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273
  };

  const short
  parser::yycheck_[] =
  {
      11,     8,     9,    11,    60,    61,    62,   113,     8,     9,
      10,    11,    41,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   107,    27,    29,
     110,   100,     7,    33,    51,    52,    51,    52,    38,    16,
       8,     9,    10,    11,     0,    13,    14,    15,    16,    60,
      61,    62,    60,    61,    62,    65,    55,    25,    26,   165,
      60,    38,    74,    62,    64,    61,    54,    33,    68,    69,
      38,    71,    72,     5,    74,    75,     5,     3,    78,     5,
       4,     3,     6,   139,   190,    77,    86,   104,     3,   104,
      89,     4,     3,     6,    60,     4,    10,    11,    64,   105,
      14,   108,    16,   114,   104,    71,    72,     3,     6,     5,
      76,     8,     9,    10,    11,     6,     4,    14,     6,    16,
      86,     6,     4,   229,    38,   136,     5,   109,   139,   235,
      38,   139,     8,     9,    10,    11,   109,    13,    14,    15,
      16,    38,   198,    19,    20,    21,    22,   109,     4,    25,
      26,     4,     4,    29,     6,     4,     4,     6,   214,     3,
       3,     5,    38,   269,     4,     4,     6,     6,     4,     4,
       6,     6,     4,     4,   230,     6,     4,     4,   284,     6,
       4,     3,   307,   108,     4,   108,   235,   198,   109,   150,
     198,    -1,   248,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    78,   214,    -1,    -1,   214,    -1,    -1,    -1,
      -1,   222,    -1,    -1,   270,    -1,    -1,    -1,    -1,   230,
      -1,    68,   230,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,   248,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
     107,    -1,   270,   110,    -1,    -1,    -1,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,    -1,
      -1,   138,    -1,   140,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,    -1,   150,    -1,   152,    -1,   154,    -1,   156,
      -1,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    -1,   199,   200,    -1,   202,    53,    -1,   205,    -1,
      -1,    -1,   209,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    -1,    12,    -1,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,   271,   272,   273,    27,    28,    -1,
      -1,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      50,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,     3,     4,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,     3,     4,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,     3,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,    -1,   106,   107,   108,   109,
     110,   111,   112,     3,     4,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,     3,     4,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,     3,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,     3,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    34,    -1,    36,    -1,    -1,    39,    -1,
      -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    57,    58,    -1,    60,
      -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    -1,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,     3,    -1,    -1,    95,    96,    -1,    -1,    99,    -1,
      -1,    -1,   103,    -1,    -1,   106,   107,    -1,   109,   110,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    -1,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    -1,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
       3,    -1,    -1,    95,    96,    -1,    -1,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    34,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,
      43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,    -1,    57,    58,    -1,    60,    -1,    62,
      63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    95,    96,    -1,    -1,    99,    -1,    -1,    -1,
     103,    -1,    -1,   106,   107,    -1,   109,   110,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      60,    29,    -1,    -1,    64,    33,    -1,    -1,    68,    69,
      38,    71,    72,    -1,    74,    75,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    64,    97,    -1,    -1,
      68,    69,    -1,    71,    72,    -1,    74,    75,    27,    28,
      78,    -1,    31,    -1,    -1,    34,    -1,    36,    86,    -1,
      39,    -1,    -1,    42,    43,    44,    -1,    -1,    47,    97,
      49,    -1,    -1,    52,    -1,    -1,    55,    -1,    57,    58,
      -1,    60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    -1,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    96,    -1,    -1,
      99,    -1,    -1,    -1,   103,    27,    28,   106,   107,    31,
     109,   110,    34,    -1,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    -1,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    -1,    -1,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,    -1,   109,   110,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      49,    -1,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    60,    -1,    -1,    -1,    64,    -1,    -1,    -1,    68,
      69,    38,    71,    72,    -1,    74,    75,    -1,    -1,    78,
      -1,    -1,    -1,     8,     9,    10,    11,    86,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    30,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    -1,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    60,    29,    -1,    -1,    64,
      33,    -1,    -1,    68,    69,    38,    71,    72,    -1,    74,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    68,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,     8,
       9,    10,    11,    86,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    64,    -1,    -1,    -1,    68,
      69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,    78,
      -1,    -1,    -1,     8,     9,    10,    11,    86,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    -1,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    60,    29,    -1,    -1,    64,
      33,    -1,    -1,    68,    69,    38,    71,    72,    -1,    74,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    68,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,     8,
       9,    10,    11,    86,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    60,    29,    -1,    -1,    64,    33,    -1,    -1,    68,
      69,    38,    71,    72,    -1,    74,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    68,    69,    -1,    71,    72,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,    86,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    38,    -1,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    68,    69,    38,    71,    72,
      -1,    74,    75,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    53,    86,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    -1,    38,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,     8,     9,    10,    11,    53,    13,
      14,    15,    16,    38,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,     8,     9,    10,    11,    53,    13,
      14,    15,    16,    -1,    38,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,     8,     9,    10,    11,    53,
      13,    14,    15,    16,    38,    -1,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,     8,     9,    10,    11,    53,
      13,    14,    15,    16,    -1,    38,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    41,   114,   115,   144,   100,   139,     0,     7,    65,
      61,   137,    74,    27,    28,    31,    34,    36,    39,    42,
      43,    44,    47,    49,    52,    55,    57,    58,    60,    62,
      63,    66,    70,    71,    72,    73,    79,    80,    81,    83,
      84,    86,    87,    88,    89,    90,    91,    95,    96,    99,
     103,   106,   107,   109,   110,   117,   118,   119,   141,    54,
       5,     5,    77,    95,   117,   119,   119,   119,     3,     3,
       8,     9,    12,    35,    36,    42,    43,    44,    56,    74,
      76,    83,    98,   108,   109,   111,   112,   116,   117,   118,
     124,   125,   126,   128,   129,   130,   131,   133,   134,   135,
     142,   143,   127,   135,   135,   135,   135,   104,   132,   135,
       3,   135,     3,     3,     5,     8,     9,    10,    11,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    29,    31,    33,    38,    49,    60,    64,
      68,    69,    71,    72,    74,    75,    78,    86,   138,     4,
       6,     4,     6,   135,    51,    52,   104,   132,   135,    27,
      55,    62,    89,     4,    10,    50,   127,   117,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   117,   135,
       3,   117,   119,   135,   135,   135,    33,    60,    64,    71,
      72,    76,    86,   135,   135,   105,   140,   142,   135,    97,
     135,   135,    51,    52,    30,     6,     6,     4,     6,     4,
     127,     4,     5,    29,    53,     4,    92,   127,   136,     3,
       5,    53,    53,   135,   135,     3,   117,   119,   135,   135,
     135,    53,   135,   135,    52,    97,   135,   119,   122,   123,
     109,   109,   109,     4,   117,   135,   135,     4,     4,   127,
     117,   119,   135,   135,    29,    53,     4,   127,   136,     3,
       5,    53,    53,    53,   135,   135,    52,     3,   119,     4,
       4,     4,     4,     4,     3,   135,   135,     4,     4,   127,
     117,   119,   135,   135,   135,     8,     9,   108,   120,   121,
       4,   127,     4,     3,   108,   108,     4,     6,     4,     4,
     127,   121,     4,     4
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   113,   114,   114,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     128,   128,   128,   128,   129,   129,   129,   130,   130,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   133,
     133,   134,   134,   134,   134,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   137,   137,   138,   138,   138,   139,
     139,   140,   140,   141,   141,   141,   142,   143,   143,   144
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     1,     4,     6,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       5,     5,     5,     5,     6,     6,     6,     6,     1,     3,
       4,     5,     3,     4,     2,     2,     3,     5,     6,     4,
       5,     5,     5,     3,     7,     8,     6,     5,     6,     6,
       6,     4,     8,     9,     7,     4,     5,     6,     4,     5,
       3,     4,     6,     6,     6,     1,     1,     1,     5,     3,
       1,     1,     1,     1,     3,     6,     3,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     1,     1,     0,
       1,     0,     2,     3,     3,     1,     2,     1,     3,    11
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"(\"", "\")\"", "\".\"",
  "\",\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"~\"", "\"&\"",
  "\"%\"", "\"|\"", "\"||\"", "\"=\"", "\"==\"", "\">\"", "\">=\"",
  "\"<\"", "\"<=\"", "\"!=\"", "\"<>\"", "\"<<\"", "\">>\"", "\"ABORT\"",
  "\"ACTION\"", "\"AND\"", "\"AS\"", "\"ASC\"", "\"AUTOINCREMENT\"",
  "\"BETWEEN\"", "\"CASCADE\"", "\"CASE\"", "\"CAST\"", "\"CHECK\"",
  "\"COLLATE\"", "\"CONFLICT\"", "\"CONSTRAINT\"", "\"CREATE\"",
  "\"CURRENT_DATE\"", "\"CURRENT_TIME\"", "\"CURRENT_TIMESTAMP\"",
  "\"DEFAULT\"", "\"DEFERRABLE\"", "\"DEFERRED\"", "\"DELETE\"",
  "\"DESC\"", "\"DISTINCT\"", "\"ELSE\"", "\"END\"", "\"ESCAPE\"",
  "\"EXISTS\"", "\"FAIL\"", "\"FALSE\"", "\"FILTER\"", "\"FOLLOWING\"",
  "\"FOREIGN\"", "\"GLOB\"", "\"IF\"", "\"IGNORE\"", "\"IMMEDIATE\"",
  "\"IN\"", "\"INDEX\"", "\"INITIALLY\"", "\"INSERT\"", "\"IS\"",
  "\"ISNULL\"", "\"KEY\"", "\"LIKE\"", "\"MATCH\"", "\"NO\"", "\"NOT\"",
  "\"NOTNULL\"", "\"NULL\"", "\"ON\"", "\"OR\"", "\"OVER\"",
  "\"PARTITION\"", "\"PRECEDING\"", "\"PRIMARY\"", "\"RAISE\"",
  "\"RANGE\"", "\"REFERENCES\"", "\"REGEXP\"", "\"REPLACE\"",
  "\"RESTRICT\"", "\"ROLLBACK\"", "\"ROWID\"", "\"ROWS\"", "\"SELECT\"",
  "\"SET\"", "\"TABLE\"", "\"TEMP\"", "\"TEMPORARY\"", "\"THEN\"",
  "\"TRUE\"", "\"UNBOUNDED\"", "\"UNIQUE\"", "\"UPDATE\"", "\"USING\"",
  "\"VIRTUAL\"", "\"WHEN\"", "\"WHERE\"", "\"WITHOUT\"", "\"identifier\"",
  "\"numeric\"", "\"string literal\"", "\"quoted literal\"",
  "\"blob literal\"", "\"bind parameter\"", "$accept", "sql", "statement",
  "literalvalue", "id", "allowed_keywords_as_identifier", "tableid",
  "signednumber", "signednumber_or_numeric", "typename_namelist",
  "type_name", "unary_expr", "binary_expr", "like_expr", "exprlist_expr",
  "function_expr", "isnull_expr", "between_expr", "in_expr",
  "whenthenlist_expr", "case_expr", "raise_expr", "expr", "select_stmt",
  "optional_if_not_exists", "optional_sort_order", "optional_unique",
  "optional_where", "tableid_with_uninteresting_schema", "indexed_column",
  "indexed_column_list", "createindex_stmt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   222,   222,   223,   227,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   247,   248,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   292,   293,   294,   295,   296,   297,   311,   312,
     316,   317,   321,   322,   326,   327,   328,   332,   333,   334,
     335,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   382,   383,
     387,   388,   389,   390,   394,   395,   396,   400,   401,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   424,   425,   429,   430,   431,
     432,   436,   437,   438,   439,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   469,   477,   478,   482,   483,   484,   492,
     493,   497,   498,   502,   503,   504,   508,   522,   523,   527
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
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


#line 10 "sqlite3_parser.yy"
} } //  sqlb::parser 
#line 3199 "sqlite3_parser.cpp"

#line 537 "sqlite3_parser.yy"


void sqlb::parser::parser::error(const location_type& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}
