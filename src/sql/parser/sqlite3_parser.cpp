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
#line 85 "sqlite3_parser.yy"

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
      case 152: // columnconstraint
        value.YY_MOVE_OR_COPY< ColumnConstraintInfo > (YY_MOVE (that.value));
        break;

      case 153: // columnconstraint_list
        value.YY_MOVE_OR_COPY< ColumnConstraintInfoVector > (YY_MOVE (that.value));
        break;

      case 154: // columndef
        value.YY_MOVE_OR_COPY< ColumndefData > (YY_MOVE (that.value));
        break;

      case 138: // optional_if_not_exists
      case 140: // optional_unique
      case 148: // optional_temporary
      case 149: // optional_withoutrowid
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 162: // tableconstraint
        value.YY_MOVE_OR_COPY< sqlb::ConstraintPtr > (YY_MOVE (that.value));
        break;

      case 163: // tableconstraint_list
      case 164: // optional_tableconstraint_list
        value.YY_MOVE_OR_COPY< sqlb::ConstraintSet > (YY_MOVE (that.value));
        break;

      case 145: // createindex_stmt
        value.YY_MOVE_OR_COPY< sqlb::IndexPtr > (YY_MOVE (that.value));
        break;

      case 143: // indexed_column
        value.YY_MOVE_OR_COPY< sqlb::IndexedColumn > (YY_MOVE (that.value));
        break;

      case 144: // indexed_column_list
        value.YY_MOVE_OR_COPY< sqlb::IndexedColumnVector > (YY_MOVE (that.value));
        break;

      case 157: // columnid_list
      case 158: // optional_columnid_with_paren_list
        value.YY_MOVE_OR_COPY< sqlb::StringVector > (YY_MOVE (that.value));
        break;

      case 147: // createvirtualtable_stmt
      case 165: // createtable_stmt
        value.YY_MOVE_OR_COPY< sqlb::TablePtr > (YY_MOVE (that.value));
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
      case 120: // columnid
      case 121: // signednumber
      case 122: // signednumber_or_numeric
      case 123: // typename_namelist
      case 124: // type_name
      case 125: // unary_expr
      case 126: // binary_expr
      case 127: // like_expr
      case 128: // exprlist_expr
      case 129: // function_expr
      case 130: // isnull_expr
      case 131: // between_expr
      case 132: // in_expr
      case 133: // whenthenlist_expr
      case 134: // case_expr
      case 135: // raise_expr
      case 136: // expr
      case 137: // select_stmt
      case 139: // optional_sort_order
      case 141: // optional_where
      case 142: // tableid_with_uninteresting_schema
      case 146: // optional_exprlist_with_paren
      case 150: // optional_conflictclause
      case 151: // optional_typename
      case 156: // optional_constraintname
      case 159: // fk_clause_part
      case 160: // fk_clause_part_list
      case 161: // optional_fk_clause
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 155: // columndef_list
        value.YY_MOVE_OR_COPY< std::vector<ColumndefData> > (YY_MOVE (that.value));
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
      case 152: // columnconstraint
        value.move< ColumnConstraintInfo > (YY_MOVE (that.value));
        break;

      case 153: // columnconstraint_list
        value.move< ColumnConstraintInfoVector > (YY_MOVE (that.value));
        break;

      case 154: // columndef
        value.move< ColumndefData > (YY_MOVE (that.value));
        break;

      case 138: // optional_if_not_exists
      case 140: // optional_unique
      case 148: // optional_temporary
      case 149: // optional_withoutrowid
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 162: // tableconstraint
        value.move< sqlb::ConstraintPtr > (YY_MOVE (that.value));
        break;

      case 163: // tableconstraint_list
      case 164: // optional_tableconstraint_list
        value.move< sqlb::ConstraintSet > (YY_MOVE (that.value));
        break;

      case 145: // createindex_stmt
        value.move< sqlb::IndexPtr > (YY_MOVE (that.value));
        break;

      case 143: // indexed_column
        value.move< sqlb::IndexedColumn > (YY_MOVE (that.value));
        break;

      case 144: // indexed_column_list
        value.move< sqlb::IndexedColumnVector > (YY_MOVE (that.value));
        break;

      case 157: // columnid_list
      case 158: // optional_columnid_with_paren_list
        value.move< sqlb::StringVector > (YY_MOVE (that.value));
        break;

      case 147: // createvirtualtable_stmt
      case 165: // createtable_stmt
        value.move< sqlb::TablePtr > (YY_MOVE (that.value));
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
      case 120: // columnid
      case 121: // signednumber
      case 122: // signednumber_or_numeric
      case 123: // typename_namelist
      case 124: // type_name
      case 125: // unary_expr
      case 126: // binary_expr
      case 127: // like_expr
      case 128: // exprlist_expr
      case 129: // function_expr
      case 130: // isnull_expr
      case 131: // between_expr
      case 132: // in_expr
      case 133: // whenthenlist_expr
      case 134: // case_expr
      case 135: // raise_expr
      case 136: // expr
      case 137: // select_stmt
      case 139: // optional_sort_order
      case 141: // optional_where
      case 142: // tableid_with_uninteresting_schema
      case 146: // optional_exprlist_with_paren
      case 150: // optional_conflictclause
      case 151: // optional_typename
      case 156: // optional_constraintname
      case 159: // fk_clause_part
      case 160: // fk_clause_part_list
      case 161: // optional_fk_clause
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 155: // columndef_list
        value.move< std::vector<ColumndefData> > (YY_MOVE (that.value));
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
      case 152: // columnconstraint
        value.move< ColumnConstraintInfo > (that.value);
        break;

      case 153: // columnconstraint_list
        value.move< ColumnConstraintInfoVector > (that.value);
        break;

      case 154: // columndef
        value.move< ColumndefData > (that.value);
        break;

      case 138: // optional_if_not_exists
      case 140: // optional_unique
      case 148: // optional_temporary
      case 149: // optional_withoutrowid
        value.move< bool > (that.value);
        break;

      case 162: // tableconstraint
        value.move< sqlb::ConstraintPtr > (that.value);
        break;

      case 163: // tableconstraint_list
      case 164: // optional_tableconstraint_list
        value.move< sqlb::ConstraintSet > (that.value);
        break;

      case 145: // createindex_stmt
        value.move< sqlb::IndexPtr > (that.value);
        break;

      case 143: // indexed_column
        value.move< sqlb::IndexedColumn > (that.value);
        break;

      case 144: // indexed_column_list
        value.move< sqlb::IndexedColumnVector > (that.value);
        break;

      case 157: // columnid_list
      case 158: // optional_columnid_with_paren_list
        value.move< sqlb::StringVector > (that.value);
        break;

      case 147: // createvirtualtable_stmt
      case 165: // createtable_stmt
        value.move< sqlb::TablePtr > (that.value);
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
      case 120: // columnid
      case 121: // signednumber
      case 122: // signednumber_or_numeric
      case 123: // typename_namelist
      case 124: // type_name
      case 125: // unary_expr
      case 126: // binary_expr
      case 127: // like_expr
      case 128: // exprlist_expr
      case 129: // function_expr
      case 130: // isnull_expr
      case 131: // between_expr
      case 132: // in_expr
      case 133: // whenthenlist_expr
      case 134: // case_expr
      case 135: // raise_expr
      case 136: // expr
      case 137: // select_stmt
      case 139: // optional_sort_order
      case 141: // optional_where
      case 142: // tableid_with_uninteresting_schema
      case 146: // optional_exprlist_with_paren
      case 150: // optional_conflictclause
      case 151: // optional_typename
      case 156: // optional_constraintname
      case 159: // fk_clause_part
      case 160: // fk_clause_part_list
      case 161: // optional_fk_clause
        value.move< std::string > (that.value);
        break;

      case 155: // columndef_list
        value.move< std::vector<ColumndefData> > (that.value);
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
      case 152: // columnconstraint
        yylhs.value.emplace< ColumnConstraintInfo > ();
        break;

      case 153: // columnconstraint_list
        yylhs.value.emplace< ColumnConstraintInfoVector > ();
        break;

      case 154: // columndef
        yylhs.value.emplace< ColumndefData > ();
        break;

      case 138: // optional_if_not_exists
      case 140: // optional_unique
      case 148: // optional_temporary
      case 149: // optional_withoutrowid
        yylhs.value.emplace< bool > ();
        break;

      case 162: // tableconstraint
        yylhs.value.emplace< sqlb::ConstraintPtr > ();
        break;

      case 163: // tableconstraint_list
      case 164: // optional_tableconstraint_list
        yylhs.value.emplace< sqlb::ConstraintSet > ();
        break;

      case 145: // createindex_stmt
        yylhs.value.emplace< sqlb::IndexPtr > ();
        break;

      case 143: // indexed_column
        yylhs.value.emplace< sqlb::IndexedColumn > ();
        break;

      case 144: // indexed_column_list
        yylhs.value.emplace< sqlb::IndexedColumnVector > ();
        break;

      case 157: // columnid_list
      case 158: // optional_columnid_with_paren_list
        yylhs.value.emplace< sqlb::StringVector > ();
        break;

      case 147: // createvirtualtable_stmt
      case 165: // createtable_stmt
        yylhs.value.emplace< sqlb::TablePtr > ();
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
      case 120: // columnid
      case 121: // signednumber
      case 122: // signednumber_or_numeric
      case 123: // typename_namelist
      case 124: // type_name
      case 125: // unary_expr
      case 126: // binary_expr
      case 127: // like_expr
      case 128: // exprlist_expr
      case 129: // function_expr
      case 130: // isnull_expr
      case 131: // between_expr
      case 132: // in_expr
      case 133: // whenthenlist_expr
      case 134: // case_expr
      case 135: // raise_expr
      case 136: // expr
      case 137: // select_stmt
      case 139: // optional_sort_order
      case 141: // optional_where
      case 142: // tableid_with_uninteresting_schema
      case 146: // optional_exprlist_with_paren
      case 150: // optional_conflictclause
      case 151: // optional_typename
      case 156: // optional_constraintname
      case 159: // fk_clause_part
      case 160: // fk_clause_part_list
      case 161: // optional_fk_clause
        yylhs.value.emplace< std::string > ();
        break;

      case 155: // columndef_list
        yylhs.value.emplace< std::vector<ColumndefData> > ();
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
#line 305 "sqlite3_parser.yy"
    { drv.result = yystack_[0].value.as < sqlb::IndexPtr > (); }
#line 1274 "sqlite3_parser.cpp"
    break;

  case 5:
#line 306 "sqlite3_parser.yy"
    { drv.result = yystack_[0].value.as < sqlb::TablePtr > (); }
#line 1280 "sqlite3_parser.cpp"
    break;

  case 6:
#line 307 "sqlite3_parser.yy"
    { drv.result = yystack_[0].value.as < sqlb::TablePtr > (); }
#line 1286 "sqlite3_parser.cpp"
    break;

  case 7:
#line 315 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1292 "sqlite3_parser.cpp"
    break;

  case 8:
#line 316 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1298 "sqlite3_parser.cpp"
    break;

  case 9:
#line 317 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1304 "sqlite3_parser.cpp"
    break;

  case 10:
#line 318 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1310 "sqlite3_parser.cpp"
    break;

  case 11:
#line 319 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1316 "sqlite3_parser.cpp"
    break;

  case 12:
#line 320 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1322 "sqlite3_parser.cpp"
    break;

  case 13:
#line 321 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1328 "sqlite3_parser.cpp"
    break;

  case 14:
#line 322 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1334 "sqlite3_parser.cpp"
    break;

  case 15:
#line 323 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1340 "sqlite3_parser.cpp"
    break;

  case 16:
#line 327 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1346 "sqlite3_parser.cpp"
    break;

  case 17:
#line 328 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1352 "sqlite3_parser.cpp"
    break;

  case 18:
#line 333 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1358 "sqlite3_parser.cpp"
    break;

  case 19:
#line 334 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1364 "sqlite3_parser.cpp"
    break;

  case 20:
#line 335 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1370 "sqlite3_parser.cpp"
    break;

  case 21:
#line 336 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1376 "sqlite3_parser.cpp"
    break;

  case 22:
#line 337 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1382 "sqlite3_parser.cpp"
    break;

  case 23:
#line 338 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1388 "sqlite3_parser.cpp"
    break;

  case 24:
#line 339 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1394 "sqlite3_parser.cpp"
    break;

  case 25:
#line 340 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1400 "sqlite3_parser.cpp"
    break;

  case 26:
#line 341 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1406 "sqlite3_parser.cpp"
    break;

  case 27:
#line 342 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1412 "sqlite3_parser.cpp"
    break;

  case 28:
#line 343 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1418 "sqlite3_parser.cpp"
    break;

  case 29:
#line 344 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1424 "sqlite3_parser.cpp"
    break;

  case 30:
#line 345 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1430 "sqlite3_parser.cpp"
    break;

  case 31:
#line 346 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1436 "sqlite3_parser.cpp"
    break;

  case 32:
#line 347 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1442 "sqlite3_parser.cpp"
    break;

  case 33:
#line 348 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1448 "sqlite3_parser.cpp"
    break;

  case 34:
#line 349 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1454 "sqlite3_parser.cpp"
    break;

  case 35:
#line 350 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1460 "sqlite3_parser.cpp"
    break;

  case 36:
#line 351 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1466 "sqlite3_parser.cpp"
    break;

  case 37:
#line 352 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1472 "sqlite3_parser.cpp"
    break;

  case 38:
#line 353 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1478 "sqlite3_parser.cpp"
    break;

  case 39:
#line 354 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1484 "sqlite3_parser.cpp"
    break;

  case 40:
#line 355 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1490 "sqlite3_parser.cpp"
    break;

  case 41:
#line 356 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1496 "sqlite3_parser.cpp"
    break;

  case 42:
#line 357 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1502 "sqlite3_parser.cpp"
    break;

  case 43:
#line 358 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1508 "sqlite3_parser.cpp"
    break;

  case 44:
#line 359 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1514 "sqlite3_parser.cpp"
    break;

  case 45:
#line 360 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1520 "sqlite3_parser.cpp"
    break;

  case 46:
#line 361 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1526 "sqlite3_parser.cpp"
    break;

  case 47:
#line 362 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1532 "sqlite3_parser.cpp"
    break;

  case 48:
#line 363 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1538 "sqlite3_parser.cpp"
    break;

  case 49:
#line 364 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1544 "sqlite3_parser.cpp"
    break;

  case 50:
#line 365 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1550 "sqlite3_parser.cpp"
    break;

  case 51:
#line 366 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1556 "sqlite3_parser.cpp"
    break;

  case 52:
#line 367 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1562 "sqlite3_parser.cpp"
    break;

  case 53:
#line 368 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1568 "sqlite3_parser.cpp"
    break;

  case 54:
#line 372 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1574 "sqlite3_parser.cpp"
    break;

  case 55:
#line 373 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1580 "sqlite3_parser.cpp"
    break;

  case 56:
#line 374 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1586 "sqlite3_parser.cpp"
    break;

  case 57:
#line 375 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1592 "sqlite3_parser.cpp"
    break;

  case 58:
#line 376 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1598 "sqlite3_parser.cpp"
    break;

  case 59:
#line 377 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = unquote_text(yystack_[0].value.as < std::string > (), '\''); }
#line 1604 "sqlite3_parser.cpp"
    break;

  case 60:
#line 381 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1610 "sqlite3_parser.cpp"
    break;

  case 61:
#line 382 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1616 "sqlite3_parser.cpp"
    break;

  case 62:
#line 383 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1622 "sqlite3_parser.cpp"
    break;

  case 63:
#line 384 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1628 "sqlite3_parser.cpp"
    break;

  case 64:
#line 385 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1634 "sqlite3_parser.cpp"
    break;

  case 65:
#line 386 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1640 "sqlite3_parser.cpp"
    break;

  case 66:
#line 387 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = unquote_text(yystack_[0].value.as < std::string > (), '\''); }
#line 1646 "sqlite3_parser.cpp"
    break;

  case 67:
#line 391 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "+" + yystack_[0].value.as < std::string > (); }
#line 1652 "sqlite3_parser.cpp"
    break;

  case 68:
#line 392 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "-" + yystack_[0].value.as < std::string > (); }
#line 1658 "sqlite3_parser.cpp"
    break;

  case 69:
#line 396 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1664 "sqlite3_parser.cpp"
    break;

  case 70:
#line 397 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1670 "sqlite3_parser.cpp"
    break;

  case 71:
#line 401 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1676 "sqlite3_parser.cpp"
    break;

  case 72:
#line 402 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 1682 "sqlite3_parser.cpp"
    break;

  case 73:
#line 406 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1688 "sqlite3_parser.cpp"
    break;

  case 74:
#line 407 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1694 "sqlite3_parser.cpp"
    break;

  case 75:
#line 408 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + "(" + yystack_[3].value.as < std::string > () + ", " + yystack_[1].value.as < std::string > () + ")"; }
#line 1700 "sqlite3_parser.cpp"
    break;

  case 76:
#line 412 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "-" + yystack_[0].value.as < std::string > (); }
#line 1706 "sqlite3_parser.cpp"
    break;

  case 77:
#line 413 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "+" + yystack_[0].value.as < std::string > (); }
#line 1712 "sqlite3_parser.cpp"
    break;

  case 78:
#line 414 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "~" + yystack_[0].value.as < std::string > (); }
#line 1718 "sqlite3_parser.cpp"
    break;

  case 79:
#line 415 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "NOT " + yystack_[0].value.as < std::string > (); }
#line 1724 "sqlite3_parser.cpp"
    break;

  case 80:
#line 419 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " || " + yystack_[0].value.as < std::string > (); }
#line 1730 "sqlite3_parser.cpp"
    break;

  case 81:
#line 420 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " * " + yystack_[0].value.as < std::string > (); }
#line 1736 "sqlite3_parser.cpp"
    break;

  case 82:
#line 421 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " / " + yystack_[0].value.as < std::string > (); }
#line 1742 "sqlite3_parser.cpp"
    break;

  case 83:
#line 422 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " % " + yystack_[0].value.as < std::string > (); }
#line 1748 "sqlite3_parser.cpp"
    break;

  case 84:
#line 423 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " + " + yystack_[0].value.as < std::string > (); }
#line 1754 "sqlite3_parser.cpp"
    break;

  case 85:
#line 424 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " - " + yystack_[0].value.as < std::string > (); }
#line 1760 "sqlite3_parser.cpp"
    break;

  case 86:
#line 425 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " << " + yystack_[0].value.as < std::string > (); }
#line 1766 "sqlite3_parser.cpp"
    break;

  case 87:
#line 426 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " >> " + yystack_[0].value.as < std::string > (); }
#line 1772 "sqlite3_parser.cpp"
    break;

  case 88:
#line 427 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " & " + yystack_[0].value.as < std::string > (); }
#line 1778 "sqlite3_parser.cpp"
    break;

  case 89:
#line 428 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " | " + yystack_[0].value.as < std::string > (); }
#line 1784 "sqlite3_parser.cpp"
    break;

  case 90:
#line 429 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " < " + yystack_[0].value.as < std::string > (); }
#line 1790 "sqlite3_parser.cpp"
    break;

  case 91:
#line 430 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " <= " + yystack_[0].value.as < std::string > (); }
#line 1796 "sqlite3_parser.cpp"
    break;

  case 92:
#line 431 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " > " + yystack_[0].value.as < std::string > (); }
#line 1802 "sqlite3_parser.cpp"
    break;

  case 93:
#line 432 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " >= " + yystack_[0].value.as < std::string > (); }
#line 1808 "sqlite3_parser.cpp"
    break;

  case 94:
#line 433 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " = " + yystack_[0].value.as < std::string > (); }
#line 1814 "sqlite3_parser.cpp"
    break;

  case 95:
#line 434 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " == " + yystack_[0].value.as < std::string > (); }
#line 1820 "sqlite3_parser.cpp"
    break;

  case 96:
#line 435 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " != " + yystack_[0].value.as < std::string > (); }
#line 1826 "sqlite3_parser.cpp"
    break;

  case 97:
#line 436 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " <> " + yystack_[0].value.as < std::string > (); }
#line 1832 "sqlite3_parser.cpp"
    break;

  case 98:
#line 437 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " IS " + yystack_[0].value.as < std::string > (); }
#line 1838 "sqlite3_parser.cpp"
    break;

  case 99:
#line 438 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 1844 "sqlite3_parser.cpp"
    break;

  case 100:
#line 439 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " OR " + yystack_[0].value.as < std::string > (); }
#line 1850 "sqlite3_parser.cpp"
    break;

  case 101:
#line 443 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " LIKE " + yystack_[0].value.as < std::string > (); }
#line 1856 "sqlite3_parser.cpp"
    break;

  case 102:
#line 444 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " GLOB " + yystack_[0].value.as < std::string > (); }
#line 1862 "sqlite3_parser.cpp"
    break;

  case 103:
#line 445 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " MATCH " + yystack_[0].value.as < std::string > (); }
#line 1868 "sqlite3_parser.cpp"
    break;

  case 104:
#line 446 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " REGEXP " + yystack_[0].value.as < std::string > (); }
#line 1874 "sqlite3_parser.cpp"
    break;

  case 105:
#line 447 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT LIKE " + yystack_[1].value.as < std::string > (); }
#line 1880 "sqlite3_parser.cpp"
    break;

  case 106:
#line 448 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT GLOB " + yystack_[1].value.as < std::string > (); }
#line 1886 "sqlite3_parser.cpp"
    break;

  case 107:
#line 449 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT MATCH " + yystack_[1].value.as < std::string > (); }
#line 1892 "sqlite3_parser.cpp"
    break;

  case 108:
#line 450 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT REGEXP " + yystack_[1].value.as < std::string > (); }
#line 1898 "sqlite3_parser.cpp"
    break;

  case 109:
#line 451 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " LIKE " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1904 "sqlite3_parser.cpp"
    break;

  case 110:
#line 452 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " GLOB " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1910 "sqlite3_parser.cpp"
    break;

  case 111:
#line 453 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " MATCH " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1916 "sqlite3_parser.cpp"
    break;

  case 112:
#line 454 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " REGEXP " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1922 "sqlite3_parser.cpp"
    break;

  case 113:
#line 455 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT LIKE " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1928 "sqlite3_parser.cpp"
    break;

  case 114:
#line 456 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT GLOB " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1934 "sqlite3_parser.cpp"
    break;

  case 115:
#line 457 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT MATCH " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1940 "sqlite3_parser.cpp"
    break;

  case 116:
#line 458 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT REGEXP " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 1946 "sqlite3_parser.cpp"
    break;

  case 117:
#line 462 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1952 "sqlite3_parser.cpp"
    break;

  case 118:
#line 463 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + ", " + yystack_[0].value.as < std::string > (); }
#line 1958 "sqlite3_parser.cpp"
    break;

  case 119:
#line 467 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1964 "sqlite3_parser.cpp"
    break;

  case 120:
#line 468 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + "(DISTINCT " + yystack_[1].value.as < std::string > () + ")"; }
#line 1970 "sqlite3_parser.cpp"
    break;

  case 121:
#line 469 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "()"; }
#line 1976 "sqlite3_parser.cpp"
    break;

  case 122:
#line 470 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(*)"; }
#line 1982 "sqlite3_parser.cpp"
    break;

  case 123:
#line 474 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " ISNULL"; }
#line 1988 "sqlite3_parser.cpp"
    break;

  case 124:
#line 475 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " NOTNULL"; }
#line 1994 "sqlite3_parser.cpp"
    break;

  case 125:
#line 476 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " NOT NULL"; }
#line 2000 "sqlite3_parser.cpp"
    break;

  case 126:
#line 480 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " BETWEEN " + yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 2006 "sqlite3_parser.cpp"
    break;

  case 127:
#line 481 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT BETWEEN " + yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 2012 "sqlite3_parser.cpp"
    break;

  case 128:
#line 485 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " IN ()"; }
#line 2018 "sqlite3_parser.cpp"
    break;

  case 129:
#line 486 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2024 "sqlite3_parser.cpp"
    break;

  case 130:
#line 487 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2030 "sqlite3_parser.cpp"
    break;

  case 131:
#line 488 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2036 "sqlite3_parser.cpp"
    break;

  case 132:
#line 489 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2042 "sqlite3_parser.cpp"
    break;

  case 133:
#line 490 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[6].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + yystack_[2].value.as < std::string > () + "()"; }
#line 2048 "sqlite3_parser.cpp"
    break;

  case 134:
#line 491 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[7].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[5].value.as < std::string > ()) + "." + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2054 "sqlite3_parser.cpp"
    break;

  case 135:
#line 492 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " IN " + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2060 "sqlite3_parser.cpp"
    break;

  case 136:
#line 493 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " NOT IN ()"; }
#line 2066 "sqlite3_parser.cpp"
    break;

  case 137:
#line 494 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2072 "sqlite3_parser.cpp"
    break;

  case 138:
#line 495 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2078 "sqlite3_parser.cpp"
    break;

  case 139:
#line 496 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2084 "sqlite3_parser.cpp"
    break;

  case 140:
#line 497 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2090 "sqlite3_parser.cpp"
    break;

  case 141:
#line 498 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[7].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + yystack_[2].value.as < std::string > () + "()"; }
#line 2096 "sqlite3_parser.cpp"
    break;

  case 142:
#line 499 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[8].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[5].value.as < std::string > ()) + "." + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2102 "sqlite3_parser.cpp"
    break;

  case 143:
#line 500 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[6].value.as < std::string > () + " NOT IN " + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2108 "sqlite3_parser.cpp"
    break;

  case 144:
#line 504 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "WHEN " + yystack_[2].value.as < std::string > () + " THEN " + yystack_[0].value.as < std::string > (); }
#line 2114 "sqlite3_parser.cpp"
    break;

  case 145:
#line 505 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " WHEN" + yystack_[2].value.as < std::string > () + " THEN " + yystack_[0].value.as < std::string > (); }
#line 2120 "sqlite3_parser.cpp"
    break;

  case 146:
#line 509 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[4].value.as < std::string > () + " " + yystack_[3].value.as < std::string > () + " ELSE " + yystack_[1].value.as < std::string > () + " END"; }
#line 2126 "sqlite3_parser.cpp"
    break;

  case 147:
#line 510 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " END"; }
#line 2132 "sqlite3_parser.cpp"
    break;

  case 148:
#line 511 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[3].value.as < std::string > () + " ELSE " + yystack_[1].value.as < std::string > () + " END"; }
#line 2138 "sqlite3_parser.cpp"
    break;

  case 149:
#line 512 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CASE " + yystack_[1].value.as < std::string > () + " END"; }
#line 2144 "sqlite3_parser.cpp"
    break;

  case 150:
#line 516 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(IGNORE)"; }
#line 2150 "sqlite3_parser.cpp"
    break;

  case 151:
#line 517 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(ROLLBACK, " + yystack_[1].value.as < std::string > () + ")"; }
#line 2156 "sqlite3_parser.cpp"
    break;

  case 152:
#line 518 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(ABORT, " + yystack_[1].value.as < std::string > () + ")"; }
#line 2162 "sqlite3_parser.cpp"
    break;

  case 153:
#line 519 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "RAISE(FAIL, " + yystack_[1].value.as < std::string > () + ")"; }
#line 2168 "sqlite3_parser.cpp"
    break;

  case 154:
#line 523 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2174 "sqlite3_parser.cpp"
    break;

  case 155:
#line 524 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2180 "sqlite3_parser.cpp"
    break;

  case 156:
#line 525 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2186 "sqlite3_parser.cpp"
    break;

  case 157:
#line 526 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2192 "sqlite3_parser.cpp"
    break;

  case 158:
#line 527 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2198 "sqlite3_parser.cpp"
    break;

  case 159:
#line 528 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2204 "sqlite3_parser.cpp"
    break;

  case 160:
#line 529 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2210 "sqlite3_parser.cpp"
    break;

  case 161:
#line 530 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2216 "sqlite3_parser.cpp"
    break;

  case 162:
#line 531 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2222 "sqlite3_parser.cpp"
    break;

  case 163:
#line 532 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2228 "sqlite3_parser.cpp"
    break;

  case 164:
#line 533 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "CAST(" + yystack_[3].value.as < std::string > () + " AS " + yystack_[1].value.as < std::string > () + ")"; }
#line 2234 "sqlite3_parser.cpp"
    break;

  case 165:
#line 534 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " COLLATE " + yystack_[0].value.as < std::string > (); }
#line 2240 "sqlite3_parser.cpp"
    break;

  case 166:
#line 535 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2246 "sqlite3_parser.cpp"
    break;

  case 167:
#line 536 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2252 "sqlite3_parser.cpp"
    break;

  case 168:
#line 537 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2258 "sqlite3_parser.cpp"
    break;

  case 169:
#line 538 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2264 "sqlite3_parser.cpp"
    break;

  case 170:
#line 539 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2270 "sqlite3_parser.cpp"
    break;

  case 171:
#line 540 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2276 "sqlite3_parser.cpp"
    break;

  case 172:
#line 549 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "SELECT"; }
#line 2282 "sqlite3_parser.cpp"
    break;

  case 173:
#line 557 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = false; }
#line 2288 "sqlite3_parser.cpp"
    break;

  case 174:
#line 558 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = true; }
#line 2294 "sqlite3_parser.cpp"
    break;

  case 175:
#line 562 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2300 "sqlite3_parser.cpp"
    break;

  case 176:
#line 563 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "ASC"; }
#line 2306 "sqlite3_parser.cpp"
    break;

  case 177:
#line 564 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = "DESC"; }
#line 2312 "sqlite3_parser.cpp"
    break;

  case 178:
#line 572 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = false; }
#line 2318 "sqlite3_parser.cpp"
    break;

  case 179:
#line 573 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = true; }
#line 2324 "sqlite3_parser.cpp"
    break;

  case 180:
#line 577 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2330 "sqlite3_parser.cpp"
    break;

  case 181:
#line 578 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2336 "sqlite3_parser.cpp"
    break;

  case 182:
#line 582 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2342 "sqlite3_parser.cpp"
    break;

  case 183:
#line 583 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2348 "sqlite3_parser.cpp"
    break;

  case 184:
#line 584 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2354 "sqlite3_parser.cpp"
    break;

  case 185:
#line 588 "sqlite3_parser.yy"
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
#line 2370 "sqlite3_parser.cpp"
    break;

  case 186:
#line 602 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::IndexedColumnVector > () = sqlb::IndexedColumnVector(1, yystack_[0].value.as < sqlb::IndexedColumn > ()); }
#line 2376 "sqlite3_parser.cpp"
    break;

  case 187:
#line 603 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::IndexedColumnVector > () = yystack_[2].value.as < sqlb::IndexedColumnVector > (); yylhs.value.as < sqlb::IndexedColumnVector > ().push_back(yystack_[0].value.as < sqlb::IndexedColumn > ()); }
#line 2382 "sqlite3_parser.cpp"
    break;

  case 188:
#line 607 "sqlite3_parser.yy"
    {
													yylhs.value.as < sqlb::IndexPtr > () = sqlb::IndexPtr(new sqlb::Index(yystack_[6].value.as < std::string > ()));
													yylhs.value.as < sqlb::IndexPtr > ()->setTable(yystack_[4].value.as < std::string > ());
													yylhs.value.as < sqlb::IndexPtr > ()->setUnique(yystack_[9].value.as < bool > ());
													yylhs.value.as < sqlb::IndexPtr > ()->setWhereExpr(yystack_[0].value.as < std::string > ());
													yylhs.value.as < sqlb::IndexPtr > ()->fields = yystack_[2].value.as < sqlb::IndexedColumnVector > ();
													yylhs.value.as < sqlb::IndexPtr > ()->setFullyParsed(true);
												}
#line 2395 "sqlite3_parser.cpp"
    break;

  case 189:
#line 622 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = {}; }
#line 2401 "sqlite3_parser.cpp"
    break;

  case 190:
#line 623 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = {}; }
#line 2407 "sqlite3_parser.cpp"
    break;

  case 191:
#line 624 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2413 "sqlite3_parser.cpp"
    break;

  case 192:
#line 628 "sqlite3_parser.yy"
    {
													yylhs.value.as < sqlb::TablePtr > () = sqlb::TablePtr(new sqlb::Table(yystack_[3].value.as < std::string > ()));
													yylhs.value.as < sqlb::TablePtr > ()->setVirtualUsing(yystack_[1].value.as < std::string > ());
													yylhs.value.as < sqlb::TablePtr > ()->setFullyParsed(false);
												}
#line 2423 "sqlite3_parser.cpp"
    break;

  case 193:
#line 640 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = false; }
#line 2429 "sqlite3_parser.cpp"
    break;

  case 194:
#line 641 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = true; }
#line 2435 "sqlite3_parser.cpp"
    break;

  case 195:
#line 642 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = true; }
#line 2441 "sqlite3_parser.cpp"
    break;

  case 196:
#line 646 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = false; }
#line 2447 "sqlite3_parser.cpp"
    break;

  case 197:
#line 647 "sqlite3_parser.yy"
    { yylhs.value.as < bool > () = true; }
#line 2453 "sqlite3_parser.cpp"
    break;

  case 198:
#line 651 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2459 "sqlite3_parser.cpp"
    break;

  case 199:
#line 652 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2465 "sqlite3_parser.cpp"
    break;

  case 200:
#line 653 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2471 "sqlite3_parser.cpp"
    break;

  case 201:
#line 654 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2477 "sqlite3_parser.cpp"
    break;

  case 202:
#line 655 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2483 "sqlite3_parser.cpp"
    break;

  case 203:
#line 656 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2489 "sqlite3_parser.cpp"
    break;

  case 204:
#line 660 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2495 "sqlite3_parser.cpp"
    break;

  case 205:
#line 661 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2501 "sqlite3_parser.cpp"
    break;

  case 206:
#line 665 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::PrimaryKey;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = true;
												sqlb::PrimaryKeyConstraint* pk = new sqlb::PrimaryKeyConstraint({sqlb::IndexedColumn("", false, yystack_[1].value.as < std::string > ())});
												pk->setName(yystack_[4].value.as < std::string > ());
												pk->setConflictAction(yystack_[0].value.as < std::string > ());
												yylhs.value.as < ColumnConstraintInfo > ().table_constraint = sqlb::ConstraintPtr(pk);
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = true;
											}
#line 2515 "sqlite3_parser.cpp"
    break;

  case 207:
#line 674 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::PrimaryKey;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = true;
												sqlb::PrimaryKeyConstraint* pk = new sqlb::PrimaryKeyConstraint({sqlb::IndexedColumn("", false, yystack_[2].value.as < std::string > ())});
												pk->setName(yystack_[5].value.as < std::string > ());
												pk->setConflictAction(yystack_[1].value.as < std::string > ());
												pk->setAutoIncrement(true);
												yylhs.value.as < ColumnConstraintInfo > ().table_constraint = sqlb::ConstraintPtr(pk);
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = true;
											}
#line 2530 "sqlite3_parser.cpp"
    break;

  case 208:
#line 684 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::NotNull;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[3].value.as < std::string > () == "" && yystack_[0].value.as < std::string > () == "");
											}
#line 2540 "sqlite3_parser.cpp"
    break;

  case 209:
#line 689 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::None;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = true;
											}
#line 2550 "sqlite3_parser.cpp"
    break;

  case 210:
#line 694 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Unique;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[2].value.as < std::string > () == "" && yystack_[0].value.as < std::string > () == "");
											}
#line 2560 "sqlite3_parser.cpp"
    break;

  case 211:
#line 699 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Check;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = yystack_[1].value.as < std::string > ();
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[4].value.as < std::string > () == "");
											}
#line 2571 "sqlite3_parser.cpp"
    break;

  case 212:
#line 705 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Default;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = yystack_[0].value.as < std::string > ();
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[2].value.as < std::string > () == "");
											}
#line 2582 "sqlite3_parser.cpp"
    break;

  case 213:
#line 711 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Default;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = yystack_[0].value.as < std::string > ();
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[2].value.as < std::string > () == "");
											}
#line 2593 "sqlite3_parser.cpp"
    break;

  case 214:
#line 717 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Default;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = yystack_[0].value.as < std::string > ();
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[2].value.as < std::string > () == "");
											}
#line 2604 "sqlite3_parser.cpp"
    break;

  case 215:
#line 723 "sqlite3_parser.yy"
    {	// We must allow the same keywords as unquoted default values as in the columnid context.
												// But we do not use columnid here in order to avoid reduce/reduce conflicts.
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Default;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = yystack_[0].value.as < std::string > ();
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[2].value.as < std::string > () == "");
											}
#line 2616 "sqlite3_parser.cpp"
    break;

  case 216:
#line 730 "sqlite3_parser.yy"
    {	// Same as above.
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Default;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = yystack_[0].value.as < std::string > ();
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[2].value.as < std::string > () == "");
											}
#line 2627 "sqlite3_parser.cpp"
    break;

  case 217:
#line 736 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Default;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = "(" + yystack_[1].value.as < std::string > () + ")";
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[4].value.as < std::string > () == "");
											}
#line 2638 "sqlite3_parser.cpp"
    break;

  case 218:
#line 742 "sqlite3_parser.yy"
    {
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::Collate;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = false;
												yylhs.value.as < ColumnConstraintInfo > ().text = yystack_[0].value.as < std::string > ();
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = (yystack_[2].value.as < std::string > () == "");
											}
#line 2649 "sqlite3_parser.cpp"
    break;

  case 219:
#line 748 "sqlite3_parser.yy"
    {	// TODO Solve shift/reduce conflict. It is not super important though as shifting seems to be right here.
												yylhs.value.as < ColumnConstraintInfo > ().type = ColumnConstraintInfo::ForeignKey;
												yylhs.value.as < ColumnConstraintInfo > ().is_table_constraint = true;
												sqlb::ForeignKeyClause* fk = new sqlb::ForeignKeyClause();
												fk->setName(yystack_[4].value.as < std::string > ());
												fk->setTable(yystack_[2].value.as < std::string > ());
												fk->setColumns(yystack_[1].value.as < sqlb::StringVector > ());
												fk->setConstraint(yystack_[0].value.as < std::string > ());
												yylhs.value.as < ColumnConstraintInfo > ().table_constraint = sqlb::ConstraintPtr(fk);
												yylhs.value.as < ColumnConstraintInfo > ().fully_parsed = true;
											}
#line 2665 "sqlite3_parser.cpp"
    break;

  case 220:
#line 762 "sqlite3_parser.yy"
    { yylhs.value.as < ColumnConstraintInfoVector > () = { yystack_[0].value.as < ColumnConstraintInfo > () }; }
#line 2671 "sqlite3_parser.cpp"
    break;

  case 221:
#line 763 "sqlite3_parser.yy"
    { yylhs.value.as < ColumnConstraintInfoVector > () = yystack_[1].value.as < ColumnConstraintInfoVector > (); yylhs.value.as < ColumnConstraintInfoVector > ().push_back(yystack_[0].value.as < ColumnConstraintInfo > ()); }
#line 2677 "sqlite3_parser.cpp"
    break;

  case 222:
#line 767 "sqlite3_parser.yy"
    {
								sqlb::Field f(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ());
								bool fully_parsed = true;
								sqlb::ConstraintSet table_constraints{};
								for(auto c : yystack_[0].value.as < ColumnConstraintInfoVector > ())
								{
									if(c.fully_parsed == false)
										fully_parsed = false;

									if(c.type == ColumnConstraintInfo::None)
										continue;

									if(c.is_table_constraint)
									{
										if(c.table_constraint->columnList().empty())
											c.table_constraint->setColumnList({yystack_[2].value.as < std::string > ()});
										else
											c.table_constraint->replaceInColumnList("", yystack_[2].value.as < std::string > ());
										table_constraints.insert(c.table_constraint);
									} else {
										if(c.type == ColumnConstraintInfo::NotNull) {
											f.setNotNull(true);
										} else if(c.type == ColumnConstraintInfo::Unique) {
											f.setUnique(true);
										} else if(c.type == ColumnConstraintInfo::Check) {
											f.setCheck(c.text);
										} else if(c.type == ColumnConstraintInfo::Default) {
											f.setDefaultValue(c.text);
										} else if(c.type == ColumnConstraintInfo::Collate) {
											f.setCollation(c.text);
										} else {
											fully_parsed = false;
										}
									}
								}

								yylhs.value.as < ColumndefData > () = std::make_tuple(f, table_constraints, fully_parsed);
							}
#line 2720 "sqlite3_parser.cpp"
    break;

  case 223:
#line 805 "sqlite3_parser.yy"
    { yylhs.value.as < ColumndefData > () = std::make_tuple(sqlb::Field(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ()), sqlb::ConstraintSet{}, true); }
#line 2726 "sqlite3_parser.cpp"
    break;

  case 224:
#line 809 "sqlite3_parser.yy"
    { yylhs.value.as < std::vector<ColumndefData> > () = {yystack_[0].value.as < ColumndefData > ()}; }
#line 2732 "sqlite3_parser.cpp"
    break;

  case 225:
#line 810 "sqlite3_parser.yy"
    { yylhs.value.as < std::vector<ColumndefData> > () = yystack_[2].value.as < std::vector<ColumndefData> > (); yylhs.value.as < std::vector<ColumndefData> > ().push_back(yystack_[0].value.as < ColumndefData > ()); }
#line 2738 "sqlite3_parser.cpp"
    break;

  case 226:
#line 814 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2744 "sqlite3_parser.cpp"
    break;

  case 227:
#line 815 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2750 "sqlite3_parser.cpp"
    break;

  case 228:
#line 819 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::StringVector > () = sqlb::StringVector(1, yystack_[0].value.as < std::string > ()); }
#line 2756 "sqlite3_parser.cpp"
    break;

  case 229:
#line 820 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::StringVector > () = yystack_[2].value.as < sqlb::StringVector > (); yylhs.value.as < sqlb::StringVector > ().push_back(yystack_[0].value.as < std::string > ()); }
#line 2762 "sqlite3_parser.cpp"
    break;

  case 230:
#line 824 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::StringVector > () = sqlb::StringVector(); }
#line 2768 "sqlite3_parser.cpp"
    break;

  case 231:
#line 825 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::StringVector > () = yystack_[1].value.as < sqlb::StringVector > (); }
#line 2774 "sqlite3_parser.cpp"
    break;

  case 232:
#line 829 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2780 "sqlite3_parser.cpp"
    break;

  case 233:
#line 830 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2786 "sqlite3_parser.cpp"
    break;

  case 234:
#line 831 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2792 "sqlite3_parser.cpp"
    break;

  case 235:
#line 832 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2798 "sqlite3_parser.cpp"
    break;

  case 236:
#line 833 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2804 "sqlite3_parser.cpp"
    break;

  case 237:
#line 834 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2810 "sqlite3_parser.cpp"
    break;

  case 238:
#line 835 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2816 "sqlite3_parser.cpp"
    break;

  case 239:
#line 836 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2822 "sqlite3_parser.cpp"
    break;

  case 240:
#line 837 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2828 "sqlite3_parser.cpp"
    break;

  case 241:
#line 838 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2834 "sqlite3_parser.cpp"
    break;

  case 242:
#line 839 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2840 "sqlite3_parser.cpp"
    break;

  case 243:
#line 840 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2846 "sqlite3_parser.cpp"
    break;

  case 244:
#line 841 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2852 "sqlite3_parser.cpp"
    break;

  case 245:
#line 842 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2858 "sqlite3_parser.cpp"
    break;

  case 246:
#line 843 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2864 "sqlite3_parser.cpp"
    break;

  case 247:
#line 844 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2870 "sqlite3_parser.cpp"
    break;

  case 248:
#line 848 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2876 "sqlite3_parser.cpp"
    break;

  case 249:
#line 849 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2882 "sqlite3_parser.cpp"
    break;

  case 250:
#line 853 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = ""; }
#line 2888 "sqlite3_parser.cpp"
    break;

  case 251:
#line 854 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2894 "sqlite3_parser.cpp"
    break;

  case 252:
#line 855 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2900 "sqlite3_parser.cpp"
    break;

  case 253:
#line 856 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2906 "sqlite3_parser.cpp"
    break;

  case 254:
#line 857 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2912 "sqlite3_parser.cpp"
    break;

  case 255:
#line 858 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " " + yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2918 "sqlite3_parser.cpp"
    break;

  case 256:
#line 859 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " " + yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2924 "sqlite3_parser.cpp"
    break;

  case 257:
#line 860 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2930 "sqlite3_parser.cpp"
    break;

  case 258:
#line 861 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2936 "sqlite3_parser.cpp"
    break;

  case 259:
#line 862 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2942 "sqlite3_parser.cpp"
    break;

  case 260:
#line 863 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2948 "sqlite3_parser.cpp"
    break;

  case 261:
#line 864 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2954 "sqlite3_parser.cpp"
    break;

  case 262:
#line 865 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2960 "sqlite3_parser.cpp"
    break;

  case 263:
#line 866 "sqlite3_parser.yy"
    { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 2966 "sqlite3_parser.cpp"
    break;

  case 264:
#line 870 "sqlite3_parser.yy"
    {
														sqlb::PrimaryKeyConstraint* pk = new sqlb::PrimaryKeyConstraint(yystack_[2].value.as < sqlb::IndexedColumnVector > ());
														pk->setName(yystack_[6].value.as < std::string > ());
														pk->setConflictAction(yystack_[0].value.as < std::string > ());
														yylhs.value.as < sqlb::ConstraintPtr > () = sqlb::ConstraintPtr(pk);
													}
#line 2977 "sqlite3_parser.cpp"
    break;

  case 265:
#line 876 "sqlite3_parser.yy"
    {
														sqlb::PrimaryKeyConstraint* pk = new sqlb::PrimaryKeyConstraint(yystack_[3].value.as < sqlb::IndexedColumnVector > ());
														pk->setName(yystack_[7].value.as < std::string > ());
														pk->setConflictAction(yystack_[0].value.as < std::string > ());
														pk->setAutoIncrement(true);
														yylhs.value.as < sqlb::ConstraintPtr > () = sqlb::ConstraintPtr(pk);
													}
#line 2989 "sqlite3_parser.cpp"
    break;

  case 266:
#line 883 "sqlite3_parser.yy"
    {
														sqlb::UniqueConstraint* u = new sqlb::UniqueConstraint(yystack_[2].value.as < sqlb::IndexedColumnVector > ());
														u->setName(yystack_[5].value.as < std::string > ());
														u->setConflictAction(yystack_[0].value.as < std::string > ());
														yylhs.value.as < sqlb::ConstraintPtr > () = sqlb::ConstraintPtr(u);
													}
#line 3000 "sqlite3_parser.cpp"
    break;

  case 267:
#line 889 "sqlite3_parser.yy"
    {
														yylhs.value.as < sqlb::ConstraintPtr > () = sqlb::ConstraintPtr(new sqlb::CheckConstraint(yystack_[1].value.as < std::string > ()));
														yylhs.value.as < sqlb::ConstraintPtr > ()->setName(yystack_[4].value.as < std::string > ());
													}
#line 3009 "sqlite3_parser.cpp"
    break;

  case 268:
#line 893 "sqlite3_parser.yy"
    {
														yylhs.value.as < sqlb::ConstraintPtr > () = sqlb::ConstraintPtr(new sqlb::ForeignKeyClause(yystack_[2].value.as < std::string > (), yystack_[1].value.as < sqlb::StringVector > (), yystack_[0].value.as < std::string > ()));
														yylhs.value.as < sqlb::ConstraintPtr > ()->setColumnList(yystack_[5].value.as < sqlb::StringVector > ());
														yylhs.value.as < sqlb::ConstraintPtr > ()->setName(yystack_[9].value.as < std::string > ());
													}
#line 3019 "sqlite3_parser.cpp"
    break;

  case 269:
#line 901 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::ConstraintSet > () = {yystack_[0].value.as < sqlb::ConstraintPtr > ()}; }
#line 3025 "sqlite3_parser.cpp"
    break;

  case 270:
#line 902 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::ConstraintSet > () = yystack_[2].value.as < sqlb::ConstraintSet > (); yylhs.value.as < sqlb::ConstraintSet > ().insert(yystack_[0].value.as < sqlb::ConstraintPtr > ()); }
#line 3031 "sqlite3_parser.cpp"
    break;

  case 271:
#line 903 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::ConstraintSet > () = yystack_[1].value.as < sqlb::ConstraintSet > (); yylhs.value.as < sqlb::ConstraintSet > ().insert(yystack_[0].value.as < sqlb::ConstraintPtr > ()); }
#line 3037 "sqlite3_parser.cpp"
    break;

  case 272:
#line 907 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::ConstraintSet > () = {}; }
#line 3043 "sqlite3_parser.cpp"
    break;

  case 273:
#line 908 "sqlite3_parser.yy"
    { yylhs.value.as < sqlb::ConstraintSet > () = yystack_[0].value.as < sqlb::ConstraintSet > (); }
#line 3049 "sqlite3_parser.cpp"
    break;

  case 274:
#line 912 "sqlite3_parser.yy"
    {
										yylhs.value.as < sqlb::TablePtr > () = sqlb::TablePtr(new sqlb::Table(yystack_[2].value.as < std::string > ()));
										yylhs.value.as < sqlb::TablePtr > ()->setFullyParsed(false);
									}
#line 3058 "sqlite3_parser.cpp"
    break;

  case 275:
#line 916 "sqlite3_parser.yy"
    {
										yylhs.value.as < sqlb::TablePtr > () = sqlb::TablePtr(new sqlb::Table(yystack_[5].value.as < std::string > ()));
										yylhs.value.as < sqlb::TablePtr > ()->setWithoutRowidTable(yystack_[0].value.as < bool > ());
										yylhs.value.as < sqlb::TablePtr > ()->setConstraints(yystack_[2].value.as < sqlb::ConstraintSet > ());
										yylhs.value.as < sqlb::TablePtr > ()->setFullyParsed(true);

										for(const auto& column : yystack_[3].value.as < std::vector<ColumndefData> > ())
										{
											sqlb::Field f;
											sqlb::ConstraintSet c;
											bool fully_parsed;
											std::tie(f, c, fully_parsed) = column;

											if(fully_parsed == false)
												yylhs.value.as < sqlb::TablePtr > ()->setFullyParsed(false);
											yylhs.value.as < sqlb::TablePtr > ()->fields.push_back(f);
											for(const auto& i : c)
												yylhs.value.as < sqlb::TablePtr > ()->addConstraint(i);
										}
									}
#line 3083 "sqlite3_parser.cpp"
    break;


#line 3087 "sqlite3_parser.cpp"

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


  const short parser::yypact_ninf_ = -333;

  const short parser::yytable_ninf_ = -274;

  const short
  parser::yypact_[] =
  {
      -3,   170,    27,    39,  -333,  -333,  -333,  -333,  -333,  -333,
     -28,    90,    69,  -333,  -333,   112,   112,   112,   121,  2043,
    2043,  2043,   144,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,   202,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,   211,  -333,  -333,    98,   134,
     128,  -333,  2120,  2120,   -16,  2120,  1966,   135,  -333,  -333,
    -333,  -333,   233,   245,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  2120,  -333,   228,  -333,  -333,   888,  -333,  1328,  -333,
    1527,  -333,    36,  1889,   250,  1328,  -333,  1328,  1328,  1328,
     998,   257,  -333,  -333,  -333,  -333,  1328,  -333,   260,  -333,
    -333,  -333,  -333,  -333,  -333,   163,  -333,  -333,  -333,  -333,
     195,  -333,  -333,  -333,  -333,  -333,  -333,  2621,  2367,  -333,
     227,     5,  -333,   -16,  -333,    43,    30,  -333,    14,  -333,
      81,   165,   231,  -333,  -333,  -333,  1328,    -7,   435,  1328,
    2833,    37,   558,   -16,  -333,  1328,  1328,  1328,  1328,  1328,
    1328,  1328,  1328,  1328,  1328,  1328,  1328,  1328,  1328,  1328,
    1328,  1328,  1328,  1328,  1328,  1328,   -16,  1328,  1616,  1328,
    -333,  1328,  1328,    74,  -333,  1328,  1328,  -333,  -333,  -333,
     176,  1328,   167,   181,  -333,  -333,   255,  -333,  -333,   291,
     -16,  1438,   221,  -333,   232,   -16,   241,   302,   239,   253,
     322,   287,  -333,   236,  -333,  -333,  1808,  1328,  -333,  1328,
      67,  2441,   324,   325,   328,   329,  -333,   330,  1328,   263,
     331,  2621,   137,   137,   104,   104,   194,   104,   194,   301,
     332,   332,   402,   402,   402,   402,   332,   332,   194,   194,
    2833,  2653,  -333,   168,   668,   271,  -333,   332,   204,   230,
    1328,  1328,  1705,  1328,  1328,  -333,  1328,  2759,  2865,  1328,
    -333,  -333,  -333,  -333,  -333,     5,  1328,  -333,  1328,  -333,
    -333,  -333,  -333,  -333,   241,   108,   335,   305,  -333,  1328,
     346,   347,  1328,  -333,  -333,  1328,  2473,  1840,  1328,  -333,
    2120,   246,   251,  -333,   254,  -333,   273,  -333,   -16,  1328,
    1328,  -333,   274,   355,  1328,  2120,  1328,  1328,  2727,  2901,
     778,   279,  -333,  2921,  2942,  2962,  1328,  2621,   360,  2224,
    2256,  -333,   241,  1966,    63,    16,  2335,  1966,  1328,   281,
    2621,  -333,  1328,  2547,   362,   363,   365,   388,  -333,  -333,
      10,   332,  -333,  -333,   282,   391,  -333,   332,   332,  1328,
    1328,  -333,   286,   392,  1328,  2120,  1328,  1328,  1328,   332,
    -333,  -333,  -333,   367,  -333,   289,   334,   -16,   358,    26,
    -333,    87,  -333,  -333,  -333,  -333,  -333,  -333,  -333,   294,
     148,   241,  2621,  -333,  -333,  -333,  -333,  -333,  -333,  1108,
      10,   332,  -333,  -333,   297,   403,  -333,   332,   332,   332,
    -333,  -333,  1966,   -30,  -333,   339,     7,    29,    35,   343,
     368,  -333,   336,   241,   415,  -333,  -333,   304,  -333,  1218,
    -333,  -333,  -333,   -13,  -333,   394,  -333,    53,  -333,   395,
    -333,    56,  -333,   396,  -333,    65,   102,   354,   -16,  -333,
     241,  -333,  -333,   313,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,   109,   335,  -333,
    -333,  -333,  -333,    63,  -333
  };

  const unsigned short
  parser::yydefact_[] =
  {
       0,   178,     0,     2,     4,     5,     6,   194,   195,   179,
       0,     0,     0,     1,     3,   173,   173,   173,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    56,
      55,    57,    24,    25,    26,    27,    28,    29,    30,    33,
      35,    34,    31,    32,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    50,    49,    51,
      52,    53,    16,    59,    17,    58,    54,   184,     0,     0,
       0,   174,     0,     0,     0,     0,     0,     0,    50,    58,
     183,   182,   189,     0,    62,    61,    63,    64,    66,    65,
      60,   204,   224,   272,   172,   274,     0,   192,     0,    71,
      73,   205,   226,   226,     0,     0,   190,     0,     0,     0,
       0,    22,    14,    13,    15,    12,     0,    10,    41,    11,
       7,     8,     9,   156,   154,   159,   155,   160,   161,   166,
       0,   162,   167,   168,   169,   170,   171,   117,   175,   186,
       0,     0,    72,     0,   220,   226,     0,   225,     0,   269,
     226,   196,     0,    77,    76,    78,     0,     0,     0,     0,
      79,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   124,     0,     0,   176,   177,   185,
     180,     0,     0,     0,    70,    69,     0,   227,   221,     0,
       0,     0,     0,   209,     0,     0,   198,     0,     0,     0,
       0,   226,   271,     0,   275,   163,     0,     0,   149,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     158,   118,    84,    85,    81,    82,    88,    83,    89,    80,
      94,    95,    92,    93,    90,    91,    96,    97,    86,    87,
      99,     0,   165,   102,     0,    58,   132,    98,   101,   103,
       0,     0,     0,     0,     0,   125,     0,   100,   104,     0,
     188,   187,    67,    68,    74,     0,     0,   218,     0,   216,
     213,   214,   215,   212,   198,   175,   230,     0,   210,     0,
       0,     0,     0,   270,   197,     0,     0,     0,     0,   147,
       0,     0,     0,   150,     0,   122,     0,   119,     0,     0,
       0,   128,     0,     0,     0,     0,     0,     0,     0,   106,
       0,    58,   140,   105,   107,   108,     0,   181,     0,     0,
       0,   208,   198,     0,   250,     0,     0,     0,     0,     0,
     144,   148,     0,     0,     0,     0,     0,     0,   120,   157,
     126,   110,   130,   129,     0,    58,   131,   109,   111,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,   112,
      75,   211,   217,   206,   228,     0,   260,     0,     0,     0,
     248,   251,   219,   200,   201,   202,   203,   199,   267,     0,
       0,   198,   145,   146,   164,   152,   153,   151,   135,     0,
     127,   114,   138,   137,     0,    58,   139,   113,   115,   116,
     207,   231,     0,     0,   247,   263,     0,     0,     0,   254,
       0,   249,     0,   198,     0,   266,   133,     0,   143,     0,
     229,   258,   259,     0,   234,     0,   235,     0,   244,     0,
     245,     0,   239,     0,   240,     0,     0,   257,     0,   264,
     198,   134,   141,     0,   261,   262,   236,   233,   232,   246,
     243,   242,   241,   238,   237,   252,   253,     0,   230,   265,
     142,   255,   256,   250,   268
  };

  const short
  parser::yypgoto_[] =
  {
    -333,  -333,  -333,   214,   -19,   -14,   -63,  -332,   215,   145,
    -333,   119,  -333,  -333,  -333,  -102,  -333,  -333,  -333,  -333,
     276,  -333,  -333,   206,  -248,   169,   136,  -333,  -333,   300,
     235,  -232,  -333,  -333,  -333,  -333,  -333,  -290,  -333,   292,
    -333,   338,  -333,   -80,    85,   -40,    51,  -333,   -36,  -142,
    -333,  -333,  -333
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,   124,   125,   126,    67,    91,   205,   206,
     100,   101,   127,   128,   129,   130,   131,   132,   133,   134,
     157,   135,   136,   137,    95,    19,   199,    11,   280,    68,
     139,   140,     4,    97,     5,    12,   224,   298,   102,   144,
     145,    92,    93,   148,   385,   344,   390,   391,   392,   149,
     150,   104,     6
  };

  const short
  parser::yytable_[] =
  {
      65,    65,    65,   152,   341,    66,    66,    66,   222,    80,
      81,   384,    83,   202,   203,   384,   323,   441,   166,   167,
     168,   169,   146,   170,   171,   172,   173,    13,    99,   176,
     177,   178,   179,   442,   464,   182,   183,   142,     1,   -99,
    -223,   444,  -223,   393,   227,   228,    14,  -222,   186,  -222,
     465,   217,   383,    79,    79,    82,    79,    89,    66,    66,
     239,    66,    90,   448,   232,   146,    15,   209,   210,   452,
     349,   394,    79,   218,   426,   211,   143,    66,   395,   303,
     445,    79,   373,   143,    89,  -273,    66,   221,   -99,    90,
     440,    62,   233,   427,    64,   446,   219,   229,   467,   234,
     447,   470,   449,   396,   212,   397,   213,   270,   453,   386,
     473,   435,   214,   204,   220,   215,   400,   450,   308,   309,
     173,   143,   451,   454,   207,   266,   235,   428,   455,   468,
     216,    76,   471,   429,   271,   387,   316,   388,   272,   197,
     389,   474,   186,   459,   240,   273,   274,   168,   169,   475,
     275,   171,   433,   173,   201,    16,   481,   198,    77,   387,
     276,   430,   322,    17,   389,   476,   162,   262,   163,   265,
     479,   229,   482,    18,    66,   186,   166,   167,   168,   169,
     434,   170,   171,   172,   173,    20,    21,   176,   177,   178,
     179,   287,   291,   182,   183,    22,   296,   292,    71,   164,
      74,   165,   166,   167,   168,   169,   186,    72,   171,   332,
     173,    75,   166,   167,   168,   169,    73,   170,   171,   172,
     173,   320,   364,   176,   177,   178,   179,    94,   372,   182,
     183,   200,   186,   201,   103,   225,    96,   165,   166,   167,
     168,   169,   186,   170,   171,   172,   173,    99,    98,   176,
     177,   178,   179,   331,   151,   182,   183,   326,    66,   284,
     159,   285,   366,   161,  -193,     7,     8,   317,   186,   165,
       9,   223,   414,    10,   324,   282,   325,   358,   362,   165,
     165,   279,   374,   327,   375,   401,   408,   201,   165,   283,
     412,    79,   165,   421,   286,   422,    66,   294,   432,   359,
     422,   438,   295,   165,   138,   299,   365,   437,   461,   300,
     165,    66,   416,   153,   154,   155,   158,   480,   297,   165,
      69,    70,   160,   301,    89,   302,   304,   143,    89,    90,
     311,   312,   313,    90,   315,   314,   318,   463,   343,   186,
     166,   167,   168,   169,   345,   170,   171,   172,   173,   347,
     348,   176,   177,   178,   179,   355,   415,   182,   183,   363,
     356,    66,   226,   357,   380,   231,   404,   405,   424,   406,
     186,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   407,   263,   409,   267,   413,   268,   269,   420,
     423,   277,   278,    89,   425,   443,   439,   138,    90,   456,
     166,   167,   168,   169,   457,   170,   171,   172,   173,   460,
     477,   458,   466,   469,   472,   290,   293,   182,   183,   354,
     338,   342,   399,   306,   230,   307,   281,   208,   483,   478,
     186,   147,   431,   166,   167,   168,   169,   484,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,     0,     0,   184,     0,     0,     0,   185,     0,
       0,     0,     0,   186,     0,     0,   328,   329,     0,   333,
     334,     0,   335,     0,     0,   337,     0,     0,     0,     0,
       0,     0,   339,     0,   340,   187,     0,     0,     0,   188,
       0,     0,     0,   189,   190,   346,   191,   192,   138,   193,
     194,   350,     0,   195,   353,     0,     0,     0,     0,     0,
       0,   196,     0,     0,     0,   360,   361,     0,     0,     0,
       0,     0,   367,   368,     0,     0,     0,     0,     0,   156,
       0,     0,   379,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,   402,     0,
       0,   105,   236,     0,     0,     0,   107,   108,   237,     0,
     109,     0,     0,     0,     0,   410,   411,     0,     0,     0,
       0,     0,   417,   418,   419,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,   238,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
     123,   105,   321,     0,     0,     0,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
      94,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
     123,   105,   371,     0,     0,     0,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
      94,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
     123,   105,   106,     0,     0,     0,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
     123,   105,     0,     0,     0,     0,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,   156,     0,    61,    62,   120,   121,    64,   122,
     123,   105,   436,     0,     0,     0,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
     123,   105,   462,     0,     0,     0,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
     123,   105,     0,     0,     0,     0,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,   110,   111,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,     0,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,   116,     0,   117,     0,     0,    46,    47,    48,
       0,   118,    50,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
     123,   288,     0,     0,     0,     0,   202,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    25,
       0,     0,    26,     0,    27,     0,     0,    28,     0,     0,
     112,   113,   114,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   115,    36,    37,     0,    38,   289,
      39,    40,     0,     0,    41,     0,     0,     0,    42,    43,
      44,    45,     0,     0,   117,     0,     0,    46,    47,    48,
       0,    49,    50,     0,    51,    52,    53,    54,    55,    56,
     141,     0,     0,    78,    58,     0,   119,    59,     0,     0,
       0,    60,     0,     0,    61,    62,   120,   121,    64,   122,
       0,     0,     0,     0,    23,    24,     0,     0,    25,     0,
       0,    26,     0,    27,     0,     0,    28,     0,     0,    29,
      30,    31,     0,     0,    32,     0,    33,     0,     0,    34,
       0,     0,    35,     0,    36,    37,     0,    38,     0,    39,
      40,     0,     0,    41,     0,     0,     0,    42,    43,    44,
      45,     0,     0,     0,     0,     0,    46,    47,    48,     0,
      49,    50,     0,    51,    52,    53,    54,    55,    56,   264,
       0,     0,    78,    58,     0,     0,    59,     0,     0,     0,
      60,     0,     0,    61,    62,     0,    63,    64,     0,     0,
       0,     0,     0,    23,    24,     0,     0,    25,     0,     0,
      26,     0,    27,     0,     0,    28,     0,     0,    29,    30,
      31,     0,     0,    32,     0,    33,     0,     0,    34,     0,
       0,    35,     0,    36,    37,     0,    38,     0,    39,    40,
       0,     0,    41,     0,     0,     0,    42,    43,    44,    45,
       0,     0,     0,     0,     0,    46,    47,    48,     0,    49,
      50,     0,    51,    52,    53,    54,    55,    56,   330,     0,
       0,    78,    58,     0,     0,    59,     0,     0,     0,    60,
       0,     0,    61,    62,     0,    63,    64,     0,     0,     0,
       0,     0,    23,    24,     0,     0,    25,     0,     0,    26,
       0,    27,     0,     0,    28,     0,     0,    29,    30,    31,
       0,     0,    32,     0,    33,     0,     0,    34,     0,     0,
      35,     0,    36,    37,     0,    38,     0,    39,    40,     0,
       0,    41,     0,     0,     0,    42,    43,    44,    45,     0,
       0,     0,     0,     0,    46,    47,    48,     0,    49,    50,
       0,    51,    52,    53,    54,    55,    56,     0,     0,     0,
      78,    58,     0,     0,    59,     0,     0,     0,    60,     0,
       0,    61,    62,     0,    63,    64,   166,   167,   168,   169,
       0,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     0,     0,   184,     0,     0,
       0,   185,     0,     0,     0,     0,   186,     0,   166,   167,
     168,   169,     0,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     0,   187,   184,
       0,     0,   188,   185,     0,     0,   189,   190,   186,   191,
     192,     0,   193,   194,     0,     0,   195,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,     0,     0,     0,
     187,     0,     0,     0,   188,   305,     0,     0,   189,   190,
       0,   191,   192,     0,   193,   194,    23,    24,   195,     0,
      25,     0,     0,    26,     0,    27,   196,     0,    28,   143,
       0,    84,    85,    86,     0,     0,    32,   352,    33,     0,
       0,    34,     0,     0,    35,     0,    36,    37,     0,    38,
      87,    39,    40,     0,     0,    41,     0,     0,     0,    42,
      43,    44,    45,     0,     0,     0,     0,     0,    46,    47,
      48,     0,    49,    50,     0,    51,    52,    53,    54,    55,
      56,     0,     0,     0,    78,    58,     0,     0,    59,     0,
       0,     0,    60,    23,    24,    61,    62,    25,    88,    64,
      26,     0,    27,     0,     0,    28,     0,     0,    84,    85,
      86,     0,     0,    32,     0,    33,     0,     0,    34,     0,
       0,    35,     0,    36,    37,     0,    38,    87,    39,    40,
       0,     0,    41,     0,     0,     0,    42,    43,    44,    45,
       0,     0,     0,     0,     0,    46,    47,    48,     0,    49,
      50,     0,    51,    52,    53,    54,    55,    56,     0,     0,
       0,    78,    58,     0,     0,    59,     0,     0,     0,    60,
      23,    24,    61,    62,    25,    88,    64,    26,     0,    27,
       0,     0,    28,     0,     0,    29,    30,    31,     0,     0,
      32,     0,    33,     0,     0,    34,     0,     0,    35,     0,
      36,    37,     0,    38,     0,    39,    40,     0,     0,    41,
       0,     0,     0,    42,    43,    44,    45,     0,     0,     0,
       0,     0,    46,    47,    48,     0,    49,    50,     0,    51,
      52,    53,    54,    55,    56,     0,     0,     0,    57,    58,
       0,     0,    59,     0,     0,     0,    60,    23,    24,    61,
      62,    25,    63,    64,    26,     0,    27,     0,     0,    28,
       0,     0,    29,    30,    31,     0,     0,    32,     0,    33,
       0,     0,    34,     0,     0,    35,     0,    36,    37,     0,
      38,     0,    39,    40,     0,     0,    41,     0,     0,     0,
      42,    43,    44,    45,     0,     0,     0,     0,     0,    46,
      47,    48,     0,    49,    50,     0,    51,    52,    53,    54,
      55,    56,     0,     0,     0,    78,    58,     0,     0,    59,
       0,     0,     0,    60,     0,     0,    61,    62,   381,    63,
      64,     0,   166,   167,   168,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     0,     0,   184,     0,     0,     0,   185,     0,     0,
     382,     0,   186,     0,   166,   167,   168,   169,     0,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     0,   187,   184,     0,     0,   188,   185,
       0,     0,   189,   190,   186,   191,   192,     0,   193,   194,
       0,     0,   195,     0,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,     0,     0,   187,     0,     0,     0,
     188,     0,     0,     0,   189,   190,     0,   191,   192,     0,
     193,   194,     0,     0,   195,     0,     0,     0,     0,   398,
       0,     0,   196,   166,   167,   168,   169,     0,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,     0,     0,   184,     0,     0,     0,   185,     0,
       0,     0,     0,   186,     0,   166,   167,   168,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,     0,   187,   184,     0,   197,   188,
     185,     0,     0,   189,   190,   186,   191,   192,     0,   193,
     194,     0,     0,   195,     0,     0,   198,     0,     0,     0,
       0,   196,     0,     0,     0,     0,     0,   187,     0,     0,
       0,   188,     0,     0,     0,   189,   190,     0,   191,   192,
       0,   193,   194,     0,     0,   195,     0,     0,     0,   166,
     167,   168,   169,   196,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,     0,     0,
     184,   310,     0,     0,   185,     0,     0,     0,     0,   186,
       0,   166,   167,   168,   169,     0,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
       0,   187,   184,     0,     0,   188,   185,     0,     0,   189,
     190,   186,   191,   192,     0,   193,   194,     0,     0,   195,
       0,     0,     0,     0,     0,   351,     0,   196,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   188,     0,     0,
       0,   189,   190,     0,   191,   192,     0,   193,   194,     0,
       0,   195,     0,     0,     0,   166,   167,   168,   169,   196,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,     0,     0,   184,     0,     0,     0,
     185,     0,     0,     0,     0,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   403,
       0,     0,     0,     0,     0,     0,     0,   187,     0,     0,
       0,   188,     0,     0,     0,   189,   190,     0,   191,   192,
       0,   193,   194,     0,     0,   195,     0,     0,     0,   166,
     167,   168,   169,   196,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,     0,     0,
     184,     0,     0,     0,   185,     0,     0,     0,     0,   186,
       0,   166,   167,   168,   169,     0,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
       0,   187,   319,     0,     0,   188,   185,     0,     0,   189,
     190,   186,   191,   192,     0,   193,   194,     0,     0,   195,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   188,     0,     0,
       0,   189,   190,     0,   191,   192,     0,   193,   194,     0,
       0,   195,     0,     0,     0,   166,   167,   168,   169,   196,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,     0,     0,   369,     0,     0,     0,
     185,     0,     0,     0,     0,   186,     0,   166,   167,   168,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,     0,   187,   184,     0,
       0,   188,   185,     0,     0,   189,   190,   186,   191,   192,
       0,   193,   194,     0,     0,   195,     0,     0,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,   187,
       0,     0,     0,   188,     0,     0,     0,   189,   190,     0,
     191,   192,     0,   193,   194,     0,     0,     0,     0,     0,
       0,   166,   167,   168,   169,   196,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
       0,     0,     0,     0,     0,     0,   185,     0,     0,     0,
       0,   186,     0,   166,   167,   168,   169,     0,   170,   171,
     172,   173,     0,     0,   176,   177,   178,   179,     0,     0,
     182,   183,     0,   187,     0,     0,     0,   188,     0,     0,
       0,   189,   190,   186,   191,   192,     0,   193,   194,   166,
     167,   168,   169,     0,   170,   171,   172,   173,   336,   196,
     176,   177,   178,   179,     0,     0,   182,   183,     0,   166,
     167,   168,   169,     0,   170,   171,   172,   173,     0,   186,
     176,   177,   178,   179,     0,     0,   182,   183,     0,     0,
     166,   167,   168,   169,   370,   170,   171,   172,   173,   186,
       0,   176,   177,   178,   179,     0,     0,   182,   183,     0,
     166,   167,   168,   169,   376,   170,   171,   172,   173,     0,
     186,   176,   177,   178,   179,     0,     0,   182,   183,     0,
       0,     0,     0,     0,     0,   377,     0,     0,     0,     0,
     186,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   378
  };

  const short
  parser::yycheck_[] =
  {
      19,    20,    21,   105,   294,    19,    20,    21,   150,    72,
      73,   343,    75,     8,     9,   347,   264,    47,     8,     9,
      10,    11,   102,    13,    14,    15,    16,     0,    91,    19,
      20,    21,    22,    63,    47,    25,    26,   100,    41,    29,
       4,    34,     6,    27,    51,    52,     7,     4,    38,     6,
      63,    37,   342,    72,    73,    74,    75,    76,    72,    73,
     162,    75,    76,    34,    27,   145,    94,    37,    38,    34,
     302,    55,    91,    59,    48,    45,    40,    91,    62,   221,
      73,   100,   330,    40,   103,     4,   100,     6,    78,   103,
     422,   107,    55,    67,   110,    88,    82,   104,    45,    62,
      93,    45,    73,    87,    74,    89,    76,    33,    73,    46,
      45,   401,    82,   108,   100,    85,   348,    88,    51,    52,
      16,    40,    93,    88,   143,   188,    89,   101,    93,    76,
     100,     3,    76,    46,    60,    72,   238,    74,    64,    31,
      77,    76,    38,   433,   163,    71,    72,    10,    11,    47,
      76,    14,     4,    16,     6,    65,    47,    49,    30,    72,
      86,    74,   264,    94,    77,    63,     3,   186,     5,   188,
     460,   104,    63,    61,   188,    38,     8,     9,    10,    11,
      32,    13,    14,    15,    16,    16,    17,    19,    20,    21,
      22,   210,   211,    25,    26,    74,   215,   211,    54,     4,
     102,     6,     8,     9,    10,    11,    38,     5,    14,   272,
      16,    77,     8,     9,    10,    11,     5,    13,    14,    15,
      16,    53,   324,    19,    20,    21,    22,    92,   330,    25,
      26,     4,    38,     6,     6,     4,     3,     6,     8,     9,
      10,    11,    38,    13,    14,    15,    16,   310,     3,    19,
      20,    21,    22,   272,     4,    25,    26,    53,   272,     4,
       3,     6,   325,     3,    94,    95,    96,     4,    38,     6,
     100,   106,   374,   103,     3,   108,     5,     4,     4,     6,
       6,   105,     3,    53,     5,     4,     4,     6,     6,   108,
       4,   310,     6,     4,     3,     6,   310,    76,     4,   318,
       6,     4,    70,     6,    98,     3,   325,   409,     4,    70,
       6,   325,   375,   107,   108,   109,   110,     4,    77,     6,
      20,    21,   116,    70,   343,     3,    90,    40,   347,   343,
       6,     6,     4,   347,     4,     6,     5,   439,     3,    38,
       8,     9,    10,    11,    39,    13,    14,    15,    16,     3,
       3,    19,    20,    21,    22,   109,   375,    25,    26,     4,
     109,   375,   156,   109,     4,   159,     4,     4,   387,     4,
      38,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     4,   187,     3,   189,     4,   191,   192,    32,
      66,   195,   196,   422,    46,    66,     3,   201,   422,    66,
       8,     9,    10,    11,    46,    13,    14,    15,    16,     4,
      66,    85,    28,    28,    28,   211,   211,    25,    26,   310,
     285,   295,   347,   227,   158,   229,   201,   145,   478,   458,
      38,   103,   391,     8,     9,    10,    11,   483,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,   270,   271,    -1,   273,
     274,    -1,   276,    -1,    -1,   279,    -1,    -1,    -1,    -1,
      -1,    -1,   286,    -1,   288,    60,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    68,    69,   299,    71,    72,   302,    74,
      75,   305,    -1,    78,   308,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,   319,   320,    -1,    -1,    -1,
      -1,    -1,   326,   327,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,   352,    -1,
      -1,     3,     4,    -1,    -1,    -1,     8,     9,    10,    -1,
      12,    -1,    -1,    -1,    -1,   369,   370,    -1,    -1,    -1,
      -1,    -1,   376,   377,   378,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    50,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,   104,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,     3,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    -1,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
       3,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    34,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,
      43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,    -1,    57,    58,    -1,    60,    -1,    62,
      63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,     3,
      -1,    -1,    95,    96,    -1,    -1,    99,    -1,    -1,    -1,
     103,    -1,    -1,   106,   107,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      34,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    47,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    -1,    57,    58,    -1,    60,    -1,    62,    63,
      -1,    -1,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,     3,    -1,
      -1,    95,    96,    -1,    -1,    99,    -1,    -1,    -1,   103,
      -1,    -1,   106,   107,    -1,   109,   110,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    34,
      -1,    36,    -1,    -1,    39,    -1,    -1,    42,    43,    44,
      -1,    -1,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    -1,    57,    58,    -1,    60,    -1,    62,    63,    -1,
      -1,    66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    -1,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      95,    96,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,
      -1,   106,   107,    -1,   109,   110,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    38,    -1,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    60,    29,
      -1,    -1,    64,    33,    -1,    -1,    68,    69,    38,    71,
      72,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    64,    97,    -1,    -1,    68,    69,
      -1,    71,    72,    -1,    74,    75,    27,    28,    78,    -1,
      31,    -1,    -1,    34,    -1,    36,    86,    -1,    39,    40,
      -1,    42,    43,    44,    -1,    -1,    47,    97,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    57,    58,    -1,    60,
      61,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    -1,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,    -1,
      -1,    -1,   103,    27,    28,   106,   107,    31,   109,   110,
      34,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    47,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    -1,    57,    58,    -1,    60,    61,    62,    63,
      -1,    -1,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    95,    96,    -1,    -1,    99,    -1,    -1,    -1,   103,
      27,    28,   106,   107,    31,   109,   110,    34,    -1,    36,
      -1,    -1,    39,    -1,    -1,    42,    43,    44,    -1,    -1,
      47,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,    -1,
      57,    58,    -1,    60,    -1,    62,    63,    -1,    -1,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    80,    81,    -1,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    96,
      -1,    -1,    99,    -1,    -1,    -1,   103,    27,    28,   106,
     107,    31,   109,   110,    34,    -1,    36,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,    -1,    57,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,   107,     4,   109,
     110,    -1,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,    -1,
       4,    -1,    38,    -1,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    60,    29,    -1,    -1,    64,    33,
      -1,    -1,    68,    69,    38,    71,    72,    -1,    74,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    68,    69,    -1,    71,    72,    -1,
      74,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    86,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    -1,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    60,    29,    -1,    31,    64,
      33,    -1,    -1,    68,    69,    38,    71,    72,    -1,    74,
      75,    -1,    -1,    78,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    68,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,     8,
       9,    10,    11,    86,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    60,    29,    -1,    -1,    64,    33,    -1,    -1,    68,
      69,    38,    71,    72,    -1,    74,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    68,    69,    -1,    71,    72,    -1,    74,    75,    -1,
      -1,    78,    -1,    -1,    -1,     8,     9,    10,    11,    86,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
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
      -1,    78,    -1,    -1,    -1,     8,     9,    10,    11,    86,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    38,    -1,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    60,    29,    -1,
      -1,    64,    33,    -1,    -1,    68,    69,    38,    71,    72,
      -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    69,    -1,
      71,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    10,    11,    86,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    38,    -1,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    60,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    68,    69,    38,    71,    72,    -1,    74,    75,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    53,    86,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    -1,    38,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
       8,     9,    10,    11,    53,    13,    14,    15,    16,    38,
      -1,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
       8,     9,    10,    11,    53,    13,    14,    15,    16,    -1,
      38,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    41,   114,   115,   145,   147,   165,    95,    96,   100,
     103,   140,   148,     0,     7,    94,    65,    94,    61,   138,
     138,   138,    74,    27,    28,    31,    34,    36,    39,    42,
      43,    44,    47,    49,    52,    55,    57,    58,    60,    62,
      63,    66,    70,    71,    72,    73,    79,    80,    81,    83,
      84,    86,    87,    88,    89,    90,    91,    95,    96,    99,
     103,   106,   107,   109,   110,   117,   118,   119,   142,   142,
     142,    54,     5,     5,   102,    77,     3,    30,    95,   117,
     119,   119,   117,   119,    42,    43,    44,    61,   109,   117,
     118,   120,   154,   155,    92,   137,     3,   146,     3,   119,
     123,   124,   151,     6,   164,     3,     4,     8,     9,    12,
      35,    36,    42,    43,    44,    56,    74,    76,    83,    98,
     108,   109,   111,   112,   116,   117,   118,   125,   126,   127,
     128,   129,   130,   131,   132,   134,   135,   136,   136,   143,
     144,     3,   119,    40,   152,   153,   156,   154,   156,   162,
     163,     4,   128,   136,   136,   136,   104,   133,   136,     3,
     136,     3,     3,     5,     4,     6,     8,     9,    10,    11,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    29,    33,    38,    60,    64,    68,
      69,    71,    72,    74,    75,    78,    86,    31,    49,   139,
       4,     6,     8,     9,   108,   121,   122,   117,   152,    37,
      38,    45,    74,    76,    82,    85,   100,    37,    59,    82,
     100,     6,   162,   106,   149,     4,   136,    51,    52,   104,
     133,   136,    27,    55,    62,    89,     4,    10,    50,   128,
     117,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   117,   136,     3,   117,   119,   136,   136,   136,
      33,    60,    64,    71,    72,    76,    86,   136,   136,   105,
     141,   143,   108,   108,     4,     6,     3,   117,     3,    61,
     116,   117,   118,   121,    76,    70,   117,    77,   150,     3,
      70,    70,     3,   162,    90,    97,   136,   136,    51,    52,
      30,     6,     6,     4,     6,     4,   128,     4,     5,    29,
      53,     4,   128,   137,     3,     5,    53,    53,   136,   136,
       3,   117,   119,   136,   136,   136,    53,   136,   122,   136,
     136,   150,   139,     3,   158,    39,   136,     3,     3,   144,
     136,    52,    97,   136,   124,   109,   109,   109,     4,   117,
     136,   136,     4,     4,   128,   117,   119,   136,   136,    29,
      53,     4,   128,   137,     3,     5,    53,    53,    53,   136,
       4,     4,     4,   150,   120,   157,    46,    72,    74,    77,
     159,   160,   161,    27,    55,    62,    87,    89,     4,   157,
     144,     4,   136,    52,     4,     4,     4,     4,     4,     3,
     136,   136,     4,     4,   128,   117,   119,   136,   136,   136,
      32,     4,     6,    66,   117,    46,    48,    67,   101,    46,
      74,   159,     4,     4,    32,   150,     4,   128,     4,     3,
     120,    47,    63,    66,    34,    73,    88,    93,    34,    73,
      88,    93,    34,    73,    88,    93,    66,    46,    85,   150,
       4,     4,     4,   128,    47,    63,    28,    45,    76,    28,
      45,    76,    28,    45,    76,    47,    63,    66,   117,   150,
       4,    47,    63,   158,   161
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   113,   114,   114,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   129,   129,   130,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   134,   134,   134,   134,
     135,   135,   135,   135,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   138,   138,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   142,   143,   144,   144,   145,   146,
     146,   146,   147,   148,   148,   148,   149,   149,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     158,   158,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   160,   160,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   162,   162,   162,   163,
     163,   163,   164,   164,   165,   165
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     2,     1,     4,     6,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     4,     5,
       5,     5,     5,     6,     6,     6,     6,     1,     3,     4,
       5,     3,     4,     2,     2,     3,     5,     6,     4,     5,
       5,     5,     3,     7,     8,     6,     5,     6,     6,     6,
       4,     8,     9,     7,     4,     5,     6,     4,     5,     3,
       4,     6,     6,     6,     1,     1,     1,     5,     3,     1,
       1,     1,     1,     3,     6,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     1,     1,     0,     1,
       0,     2,     3,     3,     1,     2,     1,     3,    11,     0,
       2,     3,     8,     0,     1,     1,     0,     2,     0,     3,
       3,     3,     3,     3,     0,     1,     5,     6,     4,     2,
       3,     5,     3,     3,     3,     3,     3,     5,     3,     5,
       1,     2,     3,     2,     1,     3,     0,     2,     1,     3,
       0,     3,     4,     4,     3,     3,     4,     4,     4,     3,
       3,     4,     4,     4,     3,     3,     4,     2,     1,     2,
       0,     1,     4,     4,     2,     5,     5,     3,     3,     3,
       1,     4,     4,     2,     7,     8,     6,     5,    10,     1,
       3,     2,     0,     2,     7,    10
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
  "columnid", "signednumber", "signednumber_or_numeric",
  "typename_namelist", "type_name", "unary_expr", "binary_expr",
  "like_expr", "exprlist_expr", "function_expr", "isnull_expr",
  "between_expr", "in_expr", "whenthenlist_expr", "case_expr",
  "raise_expr", "expr", "select_stmt", "optional_if_not_exists",
  "optional_sort_order", "optional_unique", "optional_where",
  "tableid_with_uninteresting_schema", "indexed_column",
  "indexed_column_list", "createindex_stmt",
  "optional_exprlist_with_paren", "createvirtualtable_stmt",
  "optional_temporary", "optional_withoutrowid", "optional_conflictclause",
  "optional_typename", "columnconstraint", "columnconstraint_list",
  "columndef", "columndef_list", "optional_constraintname",
  "columnid_list", "optional_columnid_with_paren_list", "fk_clause_part",
  "fk_clause_part_list", "optional_fk_clause", "tableconstraint",
  "tableconstraint_list", "optional_tableconstraint_list",
  "createtable_stmt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   300,   300,   301,   305,   306,   307,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   327,   328,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   372,   373,   374,   375,   376,   377,
     381,   382,   383,   384,   385,   386,   387,   391,   392,   396,
     397,   401,   402,   406,   407,   408,   412,   413,   414,   415,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   462,   463,   467,
     468,   469,   470,   474,   475,   476,   480,   481,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   504,   505,   509,   510,   511,   512,
     516,   517,   518,   519,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   549,   557,   558,   562,   563,   564,   572,   573,
     577,   578,   582,   583,   584,   588,   602,   603,   607,   622,
     623,   624,   628,   640,   641,   642,   646,   647,   651,   652,
     653,   654,   655,   656,   660,   661,   665,   674,   684,   689,
     694,   699,   705,   711,   717,   723,   730,   736,   742,   748,
     762,   763,   767,   805,   809,   810,   814,   815,   819,   820,
     824,   825,   829,   830,   831,   832,   833,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   848,   849,
     853,   854,   855,   856,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   870,   876,   883,   889,   893,   901,
     902,   903,   907,   908,   912,   916
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
#line 4341 "sqlite3_parser.cpp"

#line 938 "sqlite3_parser.yy"


void sqlb::parser::parser::error(const location_type& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}
