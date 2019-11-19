/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C
   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

   /* As a special exception, you may create a larger work that contains
	  part or all of the Bison parser skeleton and distribute that work
	  under terms of your choice, so long as that work isn't itself a
	  parser generator using the skeleton or a modified version thereof
	  as a parser skeleton.  Alternatively, if you modify or redistribute
	  the parser skeleton itself, you may (at your option) remove this
	  special exception, which will cause the skeleton and the resulting
	  Bison output files to be licensed under the GNU General Public
	  License without this special exception.
	  This special exception was added by the Free Software Foundation in
	  version 2.2 of Bison.  */

	  /* C LALR(1) parser skeleton written by Richard Stallman, by
		 simplifying the original so-called "semantic" parser.  */

		 /* All symbols defined below should begin with yy or YY, to avoid
			infringing on user name space.  This should be done even for local
			variables, as they might otherwise be expanded by user macros.
			There are some unavoidable exceptions within include files to
			define necessary library symbols; they are noted "INFRINGES ON
			USER NAME SPACE" below.  */

			/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "cminus.y" /* yacc.c:339  */

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedNum;
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex

static TreeNode *l = NULL; /* local dec list */
static TreeNode *s = NULL; /* stmt list */
static TreeNode *d = NULL; /* dec list */
static TreeNode *p = NULL; /* params list */
static TreeNode *a = NULL; /* argument list */


#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
   /* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
enum yytokentype
{
	IF = 258,
	ELSE = 259,
	RETURN = 260,
	WHILE = 261,
	VOID = 262,
	INT = 263,
	ID = 264,
	NUM = 265,
	ASSIGN = 266,
	EQ = 267,
	NE = 268,
	LT = 269,
	LE = 270,
	GT = 271,
	GE = 272,
	PLUS = 273,
	MINUS = 274,
	TIMES = 275,
	OVER = 276,
	SEMI = 277,
	COMMA = 278,
	LPAREN = 279,
	RPAREN = 280,
	LBRACE = 281,
	RBRACE = 282,
	LCURLY = 283,
	RCURLY = 284,
	ERROR = 285
};
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define RETURN 260
#define WHILE 261
#define VOID 262
#define INT 263
#define ID 264
#define NUM 265
#define ASSIGN 266
#define EQ 267
#define NE 268
#define LT 269
#define LE 270
#define GT 271
#define GE 272
#define PLUS 273
#define MINUS 274
#define TIMES 275
#define OVER 276
#define SEMI 277
#define COMMA 278
#define LPAREN 279
#define RPAREN 280
#define LBRACE 281
#define RBRACE 282
#define LCURLY 283
#define RCURLY 284
#define ERROR 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse(void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
	  /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
	/* The OS might guarantee only one guard page at the bottom of the stack,
	   and a page size can be as small as 4096 bytes.  So we cannot safely
	   invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
	   to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free(void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
	yytype_int16 yyss_alloc;
	YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

   /* Relocate STACK from its old location to the new one.  The
	  local variables YYSIZE and YYSTACKSIZE give the old and new number of
	  elements in the stack, and YYPTR gives the new location of the
	  stack.  Advance YYPTR to a properly aligned location for the next
	  stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
	  /* Copy COUNT objects from SRC to DST.  The source and destination do
		 not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

		 /* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

   /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
	  as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
	   0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
	   5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
	  15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
	  25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
	   0,    36,    36,    40,    54,    57,    58,    61,    67,    73,
	  79,    72,    89,    94,   102,   101,   116,   117,   124,   137,
	 140,   146,   156,   164,   177,   180,   193,   196,   197,   198,
	 199,   200,   203,   204,   207,   213,   221,   229,   233,   240,
	 247,   250,   256,   255,   267,   273,   276,   280,   284,   288,
	 292,   296,   302,   308,   311,   315,   321,   327,   330,   334,
	 340,   344,   348,   352,   360,   359,   371,   372,   375,   388
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "RETURN", "WHILE", "VOID",
  "INT", "ID", "NUM", "ASSIGN", "EQ", "NE", "LT", "LE", "GT", "GE", "PLUS",
  "MINUS", "TIMES", "OVER", "SEMI", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LCURLY", "RCURLY", "ERROR", "$accept", "program", "dec_list",
  "dec", "id", "var_dec", "@1", "@2", "type_spec", "fun_dec", "@3",
  "params", "params_list", "param", "comp_stmt", "local_dec", "stmt_list",
  "stmt", "exp_stmt", "select_stmt", "iter_stmt", "return_stmt", "exp",
  "var", "@4", "simple_exp", "relop", "add_exp", "addop", "term", "mulop",
  "factor", "call", "@5", "args", "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
	   0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
	 265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
	 275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
	 285
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
	  46,   -93,   -93,     6,    46,   -93,   -93,     1,   -93,   -93,
	 -93,   -93,    11,   -93,   -10,     5,    15,    48,   -93,     7,
	   1,    14,    39,   -93,    45,    47,    49,    46,    53,    51,
	 -93,   -93,   -93,   -93,   -93,    46,   -93,     1,    12,    54,
	  50,    28,    55,   -93,   -93,    33,   -93,    25,   -93,   -93,
	 -93,   -93,   -93,   -93,    58,    70,   -93,    52,    38,   -93,
	 -93,    33,   -93,    60,    33,    59,    57,    61,   -93,    33,
	 -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    33,    33,
	 -93,   -93,    33,    62,   -93,    63,   -93,    33,    33,   -93,
	 -93,    42,    38,   -93,     2,     2,    64,   -93,    65,    66,
	  82,   -93,   -93,   -93,    33,     2,   -93,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
	   0,    13,    12,     0,     2,     4,     5,     0,     6,     1,
	   3,     7,     9,     8,     0,     0,     0,     0,    10,    13,
	   0,     0,    16,    19,     0,    20,     0,     0,     0,     0,
	  24,    15,    18,    11,    21,    26,    23,     0,     0,     9,
	   0,     0,     0,    63,    33,     0,    22,    41,    28,    25,
	  27,    29,    30,    31,     0,    61,    40,    45,    53,    57,
	  62,     0,    37,     0,     0,     0,     0,     0,    32,     0,
	  50,    51,    47,    46,    48,    49,    54,    55,     0,     0,
	  58,    59,     0,     0,    38,     0,    60,     0,    67,    39,
	  61,    44,    52,    56,     0,     0,     0,    69,     0,    66,
	  34,    36,    43,    65,     0,     0,    68,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
	 -93,   -93,   -93,    88,    -6,    67,   -93,   -93,    -8,   -93,
	 -93,   -93,   -93,    68,    71,   -93,   -93,   -92,   -93,   -93,
	 -93,   -93,   -41,   -34,   -93,   -93,   -93,    16,   -93,    17,
	 -93,    18,   -93,   -93,   -93,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
	  -1,     3,     4,     5,    47,     6,    14,    24,     7,     8,
	  15,    21,    22,    23,    48,    35,    38,    49,    50,    51,
	  52,    53,    54,    55,    66,    56,    78,    57,    79,    58,
	  82,    59,    60,    67,    98,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
	  63,    12,   100,   101,    65,    40,     9,    41,    42,    20,
	  11,    11,    43,   107,    25,    40,    16,    41,    42,    20,
	  83,    11,    43,    85,    44,    18,    45,    37,    89,    17,
	  30,    39,   -17,    13,    44,   -14,    45,    11,    43,    26,
	  30,    46,    11,    43,    90,    90,    96,    97,    90,   -64,
	  62,   -42,    45,     1,     2,    19,     2,    45,    80,    81,
	  76,    77,    27,   106,    70,    71,    72,    73,    74,    75,
	  76,    77,    28,    29,    61,    33,    13,    30,    34,    64,
	  68,    69,    84,    87,    86,    88,   105,    94,    95,   104,
	 103,   102,    10,     0,    91,    32,    92,    31,     0,     0,
	  93,     0,    36
};

static const yytype_int8 yycheck[] =
{
	  41,     7,    94,    95,    45,     3,     0,     5,     6,    17,
	   9,     9,    10,   105,    20,     3,    26,     5,     6,    27,
	  61,     9,    10,    64,    22,    10,    24,    35,    69,    24,
	  28,    37,    25,    22,    22,    24,    24,     9,    10,    25,
	  28,    29,     9,    10,    78,    79,    87,    88,    82,    24,
	  22,    26,    24,     7,     8,     7,     8,    24,    20,    21,
	  18,    19,    23,   104,    12,    13,    14,    15,    16,    17,
	  18,    19,    27,    26,    24,    22,    22,    28,    27,    24,
	  22,    11,    22,    26,    25,    24,     4,    25,    25,    23,
	  25,    27,     4,    -1,    78,    27,    79,    26,    -1,    -1,
	  82,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
	   0,     7,     8,    32,    33,    34,    36,    39,    40,     0,
	  34,     9,    35,    22,    37,    41,    26,    24,    10,     7,
	  39,    42,    43,    44,    38,    35,    25,    23,    27,    26,
	  28,    45,    44,    22,    27,    46,    36,    39,    47,    35,
	   3,     5,     6,    10,    22,    24,    29,    35,    45,    48,
	  49,    50,    51,    52,    53,    54,    56,    58,    60,    62,
	  63,    24,    22,    53,    24,    53,    55,    64,    22,    11,
	  12,    13,    14,    15,    16,    17,    18,    19,    57,    59,
	  20,    21,    61,    53,    22,    53,    25,    26,    24,    53,
	  54,    58,    60,    62,    25,    25,    53,    53,    65,    66,
	  48,    48,    27,    25,    23,     4,    53,    48
};

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
	   0,    31,    32,    33,    33,    34,    34,    35,    36,    37,
	  38,    36,    39,    39,    41,    40,    42,    42,    43,    43,
	  44,    44,    45,    46,    46,    47,    47,    48,    48,    48,
	  48,    48,    49,    49,    50,    50,    51,    52,    52,    53,
	  53,    54,    55,    54,    56,    56,    57,    57,    57,    57,
	  57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
	  62,    62,    62,    62,    64,    63,    65,    65,    66,    66
};

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
	   0,     2,     1,     2,     1,     1,     1,     1,     3,     0,
	   0,     8,     1,     1,     0,     7,     1,     1,     3,     1,
	   2,     4,     4,     2,     0,     2,     0,     1,     1,     1,
	   1,     1,     2,     1,     5,     7,     5,     2,     3,     3,
	   1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
	   1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
	   3,     1,     1,     1,     0,     5,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print(FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
	FILE *yyo = yyoutput;
	YYUSE(yyo);
	if (!yyvaluep)
		return;
# ifdef YYPRINT
	if (yytype < YYNTOKENS)
		YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
# endif
	YYUSE(yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print(FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
	YYFPRINTF(yyoutput, "%s %s (",
		yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

	yy_symbol_value_print(yyoutput, yytype, yyvaluep);
	YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print(yytype_int16 *yybottom, yytype_int16 *yytop)
{
	YYFPRINTF(stderr, "Stack now");
	for (; yybottom <= yytop; yybottom++)
	{
		int yybot = *yybottom;
		YYFPRINTF(stderr, " %d", yybot);
	}
	YYFPRINTF(stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print(yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
	unsigned long int yylno = yyrline[yyrule];
	int yynrhs = yyr2[yyrule];
	int yyi;
	YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n",
		yyrule - 1, yylno);
	/* The symbols being reduced.  */
	for (yyi = 0; yyi < yynrhs; yyi++)
	{
		YYFPRINTF(stderr, "   $%d = ", yyi + 1);
		yy_symbol_print(stderr,
			yystos[yyssp[yyi + 1 - yynrhs]],
			&(yyvsp[(yyi + 1) - (yynrhs)])
		);
		YYFPRINTF(stderr, "\n");
	}
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).
   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
   /* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen(const char *yystr)
{
	YYSIZE_T yylen;
	for (yylen = 0; yystr[yylen]; yylen++)
		continue;
	return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy(char *yydest, const char *yysrc)
{
	char *yyd = yydest;
	const char *yys = yysrc;

	while ((*yyd++ = *yys++) != '\0')
		continue;

	return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr(char *yyres, const char *yystr)
{
	if (*yystr == '"')
	{
		YYSIZE_T yyn = 0;
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
				/* Fall through.  */
			default:
				if (yyres)
					yyres[yyn] = *yyp;
				yyn++;
				break;

			case '"':
				if (yyres)
					yyres[yyn] = '\0';
				return yyn;
			}
	do_not_strip_quotes:;
	}

	if (!yyres)
		return yystrlen(yystr);

	return yystpcpy(yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.
   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error(YYSIZE_T *yymsg_alloc, char **yymsg,
	yytype_int16 *yyssp, int yytoken)
{
	YYSIZE_T yysize0 = yytnamerr(YY_NULLPTR, yytname[yytoken]);
	YYSIZE_T yysize = yysize0;
	enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
	/* Internationalized format string. */
	const char *yyformat = YY_NULLPTR;
	/* Arguments of yyformat. */
	char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	/* Number of reported tokens (one for the "unexpected", one per
	   "expected"). */
	int yycount = 0;

	/* There are many possibilities here to consider:
	   - If this state is a consistent state with a default action, then
		 the only way this function was invoked is if the default action
		 is an error action.  In that case, don't check for expected
		 tokens because there are none.
	   - The only way there can be no lookahead present (in yychar) is if
		 this state is a consistent state with a default action.  Thus,
		 detecting the absence of a lookahead is sufficient to determine
		 that there is no unexpected or expected token to report.  In that
		 case, just report a simple "syntax error".
	   - Don't assume there isn't a lookahead just because this state is a
		 consistent state with a default action.  There might have been a
		 previous inconsistent state, consistent state with a non-default
		 action, or user semantic action that manipulated yychar.
	   - Of course, the expected token list depends on states to have
		 correct lookahead information, and it depends on the parser not
		 to perform extra reductions after fetching a lookahead from the
		 scanner and before detecting a syntax error.  Thus, state merging
		 (from LALR or IELR) and default reductions corrupt the expected
		 token list.  However, the list is correct for canonical LR with
		 one exception: it will still contain any token that will not be
		 accepted due to an error action in a later state.
	*/
	if (yytoken != YYEMPTY)
	{
		int yyn = yypact[*yyssp];
		yyarg[yycount++] = yytname[yytoken];
		if (!yypact_value_is_default(yyn))
		{
			/* Start YYX at -YYN if negative to avoid negative indexes in
			   YYCHECK.  In other words, skip the first -YYN actions for
			   this state because they are default actions.  */
			int yyxbegin = yyn < 0 ? -yyn : 0;
			/* Stay within bounds of both yycheck and yytname.  */
			int yychecklim = YYLAST - yyn + 1;
			int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
			int yyx;

			for (yyx = yyxbegin; yyx < yyxend; ++yyx)
				if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
					&& !yytable_value_is_error(yytable[yyx + yyn]))
				{
					if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
					{
						yycount = 1;
						yysize = yysize0;
						break;
					}
					yyarg[yycount++] = yytname[yyx];
					{
						YYSIZE_T yysize1 = yysize + yytnamerr(YY_NULLPTR, yytname[yyx]);
						if (!(yysize <= yysize1
							&& yysize1 <= YYSTACK_ALLOC_MAXIMUM))
							return 2;
						yysize = yysize1;
					}
				}
		}
	}

	switch (yycount)
	{
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
		YYCASE_(0, YY_("syntax error"));
		YYCASE_(1, YY_("syntax error, unexpected %s"));
		YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
		YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
		YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
		YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
	}

	{
		YYSIZE_T yysize1 = yysize + yystrlen(yyformat);
		if (!(yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
			return 2;
		yysize = yysize1;
	}

	if (*yymsg_alloc < yysize)
	{
		*yymsg_alloc = 2 * yysize;
		if (!(yysize <= *yymsg_alloc
			&& *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
			*yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
		return 1;
	}

	/* Avoid sprintf, as that infringes on the user's name space.
	   Don't have undefined behavior even if the translation
	   produced a string with the wrong number of "%s"s.  */
	{
		char *yyp = *yymsg;
		int yyi = 0;
		while ((*yyp = *yyformat) != '\0')
			if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
			{
				yyp += yytnamerr(yyp, yyarg[yyi++]);
				yyformat += 2;
			}
			else
			{
				yyp++;
				yyformat++;
			}
	}
	return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
	YYUSE(yyvaluep);
	if (!yymsg)
		yymsg = "Deleting";
	YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

	YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
		YYUSE(yytype);
	YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse(void)
{
	int yystate;
	/* Number of tokens to shift before error messages enabled.  */
	int yyerrstatus;

	/* The stacks and their tools:
	   'yyss': related to states.
	   'yyvs': related to semantic values.
	   Refer to the stacks through separate pointers, to allow yyoverflow
	   to reallocate them elsewhere.  */

	   /* The state stack.  */
	yytype_int16 yyssa[YYINITDEPTH];
	yytype_int16 *yyss;
	yytype_int16 *yyssp;

	/* The semantic value stack.  */
	YYSTYPE yyvsa[YYINITDEPTH];
	YYSTYPE *yyvs;
	YYSTYPE *yyvsp;

	YYSIZE_T yystacksize;

	int yyn;
	int yyresult;
	/* Lookahead token as an internal (translated) token number.  */
	int yytoken = 0;
	/* The variables used to return semantic value and location from the
	   action routines.  */
	YYSTYPE yyval;

#if YYERROR_VERBOSE
	/* Buffer for error messages, and its allocated size.  */
	char yymsgbuf[128];
	char *yymsg = yymsgbuf;
	YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

	/* The number of symbols on the RHS of the reduced rule.
	   Keep to zero when no symbol should be popped.  */
	int yylen = 0;

	yyssp = yyss = yyssa;
	yyvsp = yyvs = yyvsa;
	yystacksize = YYINITDEPTH;

	YYDPRINTF((stderr, "Starting parse\n"));

	yystate = 0;
	yyerrstatus = 0;
	yynerrs = 0;
	yychar = YYEMPTY; /* Cause a token to be read.  */
	goto yysetstate;

	/*------------------------------------------------------------.
	| yynewstate -- Push a new state, which is found in yystate.  |
	`------------------------------------------------------------*/
yynewstate:
	/* In all cases, when you get here, the value and location stacks
	   have just been pushed.  So pushing a state here evens the stacks.  */
	yyssp++;

yysetstate:
	*yyssp = yystate;

	if (yyss + yystacksize - 1 <= yyssp)
	{
		/* Get the current used size of the three stacks, in elements.  */
		YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
		{
			/* Give user a chance to reallocate the stack.  Use copies of
			   these so that the &'s don't force the real ones into
			   memory.  */
			YYSTYPE *yyvs1 = yyvs;
			yytype_int16 *yyss1 = yyss;

			/* Each stack pointer address is followed by the size of the
			   data in use in that stack, in bytes.  This used to be a
			   conditional around just the two extra args, but that might
			   be undefined if yyoverflow is a macro.  */
			yyoverflow(YY_("memory exhausted"),
				&yyss1, yysize * sizeof(*yyssp),
				&yyvs1, yysize * sizeof(*yyvsp),
				&yystacksize);

			yyss = yyss1;
			yyvs = yyvs1;
		}
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
		goto yyexhaustedlab;
# else
		/* Extend the stack our own way.  */
		if (YYMAXDEPTH <= yystacksize)
			goto yyexhaustedlab;
		yystacksize *= 2;
		if (YYMAXDEPTH < yystacksize)
			yystacksize = YYMAXDEPTH;

		{
			yytype_int16 *yyss1 = yyss;
			union yyalloc *yyptr =
				(union yyalloc *) YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
			if (!yyptr)
				goto yyexhaustedlab;
			YYSTACK_RELOCATE(yyss_alloc, yyss);
			YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
			if (yyss1 != yyssa)
				YYSTACK_FREE(yyss1);
		}
# endif
#endif /* no yyoverflow */

		yyssp = yyss + yysize - 1;
		yyvsp = yyvs + yysize - 1;

		YYDPRINTF((stderr, "Stack size increased to %lu\n",
			(unsigned long int) yystacksize));

		if (yyss + yystacksize - 1 <= yyssp)
			YYABORT;
	}

	YYDPRINTF((stderr, "Entering state %d\n", yystate));

	if (yystate == YYFINAL)
		YYACCEPT;

	goto yybackup;

	/*-----------.
	| yybackup.  |
	`-----------*/
yybackup:

	/* Do appropriate processing given the current state.  Read a
	   lookahead token if we need one and don't already have one.  */

	   /* First try to decide what to do without reference to lookahead token.  */
	yyn = yypact[yystate];
	if (yypact_value_is_default(yyn))
		goto yydefault;

	/* Not known => get a lookahead token if don't already have one.  */

	/* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
	if (yychar == YYEMPTY)
	{
		YYDPRINTF((stderr, "Reading a token: "));
		yychar = yylex();
	}

	if (yychar <= YYEOF)
	{
		yychar = yytoken = YYEOF;
		YYDPRINTF((stderr, "Now at end of input.\n"));
	}
	else
	{
		yytoken = YYTRANSLATE(yychar);
		YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
	}

	/* If the proper action on seeing token YYTOKEN is to reduce or to
	   detect an error, take that action.  */
	yyn += yytoken;
	if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
		goto yydefault;
	yyn = yytable[yyn];
	if (yyn <= 0)
	{
		if (yytable_value_is_error(yyn))
			goto yyerrlab;
		yyn = -yyn;
		goto yyreduce;
	}

	/* Count tokens shifted since error; after three, turn off error
	   status.  */
	if (yyerrstatus)
		yyerrstatus--;

	/* Shift the lookahead token.  */
	YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

	/* Discard the shifted token.  */
	yychar = YYEMPTY;

	yystate = yyn;
	YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
		*++yyvsp = yylval;
	YY_IGNORE_MAYBE_UNINITIALIZED_END

		goto yynewstate;


	/*-----------------------------------------------------------.
	| yydefault -- do the default action for the current state.  |
	`-----------------------------------------------------------*/
yydefault:
	yyn = yydefact[yystate];
	if (yyn == 0)
		goto yyerrlab;
	goto yyreduce;


	/*-----------------------------.
	| yyreduce -- Do a reduction.  |
	`-----------------------------*/
yyreduce:
	/* yyn is the number of a rule to reduce with.  */
	yylen = yyr2[yyn];

	/* If YYLEN is nonzero, implement the default value of the action:
	   '$$ = $1'.
	   Otherwise, the following line sets YYVAL to garbage.
	   This behavior is undocumented and Bison
	   users should not rely upon it.  Assigning to YYVAL
	   unconditionally makes the parser a bit smaller, and it avoids a
	   GCC warning that YYVAL may be used uninitialized.  */
	yyval = yyvsp[1 - yylen];


	YY_REDUCE_PRINT(yyn);
	switch (yyn)
	{
	case 2:
#line 37 "cminus.y" /* yacc.c:1646  */
	{ savedTree = (yyvsp[0]); }
#line 1351 "y.tab.c" /* yacc.c:1646  */
	break;

	case 3:
#line 41 "cminus.y" /* yacc.c:1646  */
	{
		d = (yyvsp[-1]);
		if (d == NULL) {
			(yyval) = (yyvsp[0]);
		}
		else {
			while (d->sibling != NULL) {
				d = d->sibling;
			}
			d->sibling = (yyvsp[0]);
			(yyval) = (yyvsp[-1]);
		}
	}
#line 1368 "y.tab.c" /* yacc.c:1646  */
	break;

	case 4:
#line 54 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1374 "y.tab.c" /* yacc.c:1646  */
	break;

	case 5:
#line 57 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1380 "y.tab.c" /* yacc.c:1646  */
	break;

	case 6:
#line 58 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1386 "y.tab.c" /* yacc.c:1646  */
	break;

	case 7:
#line 62 "cminus.y" /* yacc.c:1646  */
	{
		savedName = copyString(tokenString);
	}
#line 1394 "y.tab.c" /* yacc.c:1646  */
	break;

	case 8:
#line 68 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-2]);
		(yyval)->attr.name = savedName;
	}
#line 1403 "y.tab.c" /* yacc.c:1646  */
	break;

	case 9:
#line 73 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-1]);
		(yyval)->attr.name = savedName;
		(yyval)->type = Array;
	}
#line 1413 "y.tab.c" /* yacc.c:1646  */
	break;

	case 10:
#line 79 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-2]);
		(yyval)->size = atoi(tokenString);
	}
#line 1422 "y.tab.c" /* yacc.c:1646  */
	break;

	case 11:
#line 84 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-2]);
	}
#line 1430 "y.tab.c" /* yacc.c:1646  */
	break;

	case 12:
#line 90 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newDecNode(VarK);
		(yyval)->type = Integer;
	}
#line 1439 "y.tab.c" /* yacc.c:1646  */
	break;

	case 13:
#line 95 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newDecNode(VarK);
		(yyval)->type = Void;
	}
#line 1448 "y.tab.c" /* yacc.c:1646  */
	break;

	case 14:
#line 102 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-1]);
		(yyval)->kind.dec = FunK;
		(yyval)->attr.name = savedName;
	}
#line 1458 "y.tab.c" /* yacc.c:1646  */
	break;

	case 15:
#line 108 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-4]);

		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	}
#line 1469 "y.tab.c" /* yacc.c:1646  */
	break;

	case 16:
#line 116 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[0]); }
#line 1475 "y.tab.c" /* yacc.c:1646  */
	break;

	case 17:
#line 118 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newDecNode(ParamK);
		(yyval)->type = Void;
	}
#line 1484 "y.tab.c" /* yacc.c:1646  */
	break;

	case 18:
#line 125 "cminus.y" /* yacc.c:1646  */
	{
		p = (yyvsp[-2]);
		if (p == NULL) {
			(yyval) = (yyvsp[0]);
		}
		else {
			while (p->sibling != NULL) {
				p = p->sibling;
			}
			p->sibling = (yyvsp[0]);
			(yyval) = (yyvsp[-2]);
		}
	}
#line 1501 "y.tab.c" /* yacc.c:1646  */
	break;

	case 19:
#line 137 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1507 "y.tab.c" /* yacc.c:1646  */
	break;

	case 20:
#line 141 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-1]);
		(yyval)->kind.dec = ParamK;
		(yyval)->attr.name = savedName;
	}
#line 1517 "y.tab.c" /* yacc.c:1646  */
	break;

	case 21:
#line 147 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-3]);
		(yyval)->kind.dec = ParamK;
		(yyval)->type = Array;
		(yyval)->size = 0;
		(yyval)->attr.name = savedName;
	}
#line 1529 "y.tab.c" /* yacc.c:1646  */
	break;

	case 22:
#line 157 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newStmtNode(CompK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[-1]);
	}
#line 1539 "y.tab.c" /* yacc.c:1646  */
	break;

	case 23:
#line 165 "cminus.y" /* yacc.c:1646  */
	{
		l = (yyvsp[-1]);
		if (l == NULL) {
			(yyval) = (yyvsp[0]);
		}
		else {
			while (l->sibling != NULL) {
				l = l->sibling;
			}
			l->sibling = (yyvsp[0]);
			(yyval) = (yyvsp[-1]);
		}
	}
#line 1556 "y.tab.c" /* yacc.c:1646  */
	break;

	case 24:
#line 177 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = NULL; }
#line 1562 "y.tab.c" /* yacc.c:1646  */
	break;

	case 25:
#line 181 "cminus.y" /* yacc.c:1646  */
	{
		s = (yyvsp[-1]);
		if (s == NULL) {
			(yyval) = (yyvsp[0]);
		}
		else {
			while (s->sibling != NULL) {
				s = s->sibling;
			}
			s->sibling = (yyvsp[0]);
			(yyval) = (yyvsp[-1]);
		}
	}
#line 1579 "y.tab.c" /* yacc.c:1646  */
	break;

	case 26:
#line 193 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = NULL; }
#line 1585 "y.tab.c" /* yacc.c:1646  */
	break;

	case 27:
#line 196 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
	break;

	case 28:
#line 197 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
	break;

	case 29:
#line 198 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
	break;

	case 30:
#line 199 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
	break;

	case 31:
#line 200 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
	break;

	case 32:
#line 203 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[-1]); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
	break;

	case 33:
#line 204 "cminus.y" /* yacc.c:1646  */
	{(yyval) = NULL; }
#line 1627 "y.tab.c" /* yacc.c:1646  */
	break;

	case 34:
#line 208 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = newStmtNode(IfK);
	(yyval)->child[0] = (yyvsp[-2]);
	(yyval)->child[1] = (yyvsp[0]);
	(yyval)->child[2] = NULL;
	}
#line 1637 "y.tab.c" /* yacc.c:1646  */
	break;

	case 35:
#line 214 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = newStmtNode(IfK);
	(yyval)->child[0] = (yyvsp[-4]);
	(yyval)->child[1] = (yyvsp[-2]);
	(yyval)->child[2] = (yyvsp[0]);
	}
#line 1647 "y.tab.c" /* yacc.c:1646  */
	break;

	case 36:
#line 222 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newStmtNode(WhileK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	}
#line 1657 "y.tab.c" /* yacc.c:1646  */
	break;

	case 37:
#line 230 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newStmtNode(RetK);
	}
#line 1665 "y.tab.c" /* yacc.c:1646  */
	break;

	case 38:
#line 234 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newStmtNode(RetK);
		(yyval)->child[0] = (yyvsp[-1]);
	}
#line 1674 "y.tab.c" /* yacc.c:1646  */
	break;

	case 39:
#line 241 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = ASSIGN;
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	}
#line 1685 "y.tab.c" /* yacc.c:1646  */
	break;

	case 40:
#line 247 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[0]); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
	break;

	case 41:
#line 251 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(IdK);
		(yyval)->attr.name = savedName;
	}
#line 1700 "y.tab.c" /* yacc.c:1646  */
	break;

	case 42:
#line 256 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(ArrIdK);
		(yyval)->attr.name = savedName;
	}
#line 1709 "y.tab.c" /* yacc.c:1646  */
	break;

	case 43:
#line 261 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-3]);
		(yyval)->child[0] = (yyvsp[-1]);
	}
#line 1718 "y.tab.c" /* yacc.c:1646  */
	break;

	case 44:
#line 268 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-1]);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	}
#line 1728 "y.tab.c" /* yacc.c:1646  */
	break;

	case 45:
#line 273 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[0]); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
	break;

	case 46:
#line 276 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = LE;
	}
#line 1743 "y.tab.c" /* yacc.c:1646  */
	break;

	case 47:
#line 280 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = LT;
	}
#line 1752 "y.tab.c" /* yacc.c:1646  */
	break;

	case 48:
#line 284 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = GT;
	}
#line 1761 "y.tab.c" /* yacc.c:1646  */
	break;

	case 49:
#line 288 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = GE;
	}
#line 1770 "y.tab.c" /* yacc.c:1646  */
	break;

	case 50:
#line 292 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = EQ;
	}
#line 1779 "y.tab.c" /* yacc.c:1646  */
	break;

	case 51:
#line 296 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = NE;
	}
#line 1788 "y.tab.c" /* yacc.c:1646  */
	break;

	case 52:
#line 303 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-1]);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	}
#line 1798 "y.tab.c" /* yacc.c:1646  */
	break;

	case 53:
#line 308 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[0]); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
	break;

	case 54:
#line 311 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = PLUS;
	}
#line 1813 "y.tab.c" /* yacc.c:1646  */
	break;

	case 55:
#line 315 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = MINUS;
	}
#line 1822 "y.tab.c" /* yacc.c:1646  */
	break;

	case 56:
#line 322 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-1]);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	}
#line 1832 "y.tab.c" /* yacc.c:1646  */
	break;

	case 57:
#line 327 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[0]); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
	break;

	case 58:
#line 330 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = TIMES;
	}
#line 1847 "y.tab.c" /* yacc.c:1646  */
	break;

	case 59:
#line 334 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(OpK);
		(yyval)->attr.op = OVER;
	}
#line 1856 "y.tab.c" /* yacc.c:1646  */
	break;

	case 60:
#line 341 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-1]);
	}
#line 1864 "y.tab.c" /* yacc.c:1646  */
	break;

	case 61:
#line 345 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[0]);
	}
#line 1872 "y.tab.c" /* yacc.c:1646  */
	break;

	case 62:
#line 349 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[0]);
	}
#line 1880 "y.tab.c" /* yacc.c:1646  */
	break;

	case 63:
#line 353 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(ConstK);
		(yyval)->attr.val = atoi(tokenString);
	}
#line 1889 "y.tab.c" /* yacc.c:1646  */
	break;

	case 64:
#line 360 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = newExpNode(CallK);
		(yyval)->attr.name = savedName;
	}
#line 1898 "y.tab.c" /* yacc.c:1646  */
	break;

	case 65:
#line 365 "cminus.y" /* yacc.c:1646  */
	{
		(yyval) = (yyvsp[-3]);
		(yyval)->child[0] = (yyvsp[-1]);
	}
#line 1907 "y.tab.c" /* yacc.c:1646  */
	break;

	case 66:
#line 371 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[0]); }
#line 1913 "y.tab.c" /* yacc.c:1646  */
	break;

	case 67:
#line 372 "cminus.y" /* yacc.c:1646  */
	{ (yyval) = NULL; }
#line 1919 "y.tab.c" /* yacc.c:1646  */
	break;

	case 68:
#line 376 "cminus.y" /* yacc.c:1646  */
	{
		a = (yyvsp[-2]);
		if (a == NULL) {
			(yyval) = (yyvsp[0]);
		}
		else {
			while (a->sibling != NULL) {
				a = a->sibling;
			}
			a->sibling = (yyvsp[0]);
			(yyval) = (yyvsp[-2]);
		}
	}
#line 1936 "y.tab.c" /* yacc.c:1646  */
	break;

	case 69:
#line 388 "cminus.y" /* yacc.c:1646  */
	{(yyval) = (yyvsp[0]); }
#line 1942 "y.tab.c" /* yacc.c:1646  */
	break;


#line 1946 "y.tab.c" /* yacc.c:1646  */
	default: break;
	}
	/* User semantic actions sometimes alter yychar, and that requires
	   that yytoken be updated with the new translation.  We take the
	   approach of translating immediately before every use of yytoken.
	   One alternative is translating here after every semantic action,
	   but that translation would be missed if the semantic action invokes
	   YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
	   if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
	   incorrect destructor might then be invoked immediately.  In the
	   case of YYERROR or YYBACKUP, subsequent parser actions might lead
	   to an incorrect destructor call or verbose syntax error message
	   before the lookahead is translated.  */
	YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);

	*++yyvsp = yyval;

	/* Now 'shift' the result of the reduction.  Determine what state
	   that goes to, based on the state we popped back to and the rule
	   number reduced by.  */

	yyn = yyr1[yyn];

	yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
	if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
		yystate = yytable[yystate];
	else
		yystate = yydefgoto[yyn - YYNTOKENS];

	goto yynewstate;


	/*--------------------------------------.
	| yyerrlab -- here on detecting error.  |
	`--------------------------------------*/
yyerrlab:
	/* Make sure we have latest lookahead translation.  See comments at
	   user semantic actions for why this is necessary.  */
	yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE(yychar);

	/* If not already recovering from an error, report this error.  */
	if (!yyerrstatus)
	{
		++yynerrs;
#if ! YYERROR_VERBOSE
		yyerror(YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
		{
			char const *yymsgp = YY_("syntax error");
			int yysyntax_error_status;
			yysyntax_error_status = YYSYNTAX_ERROR;
			if (yysyntax_error_status == 0)
				yymsgp = yymsg;
			else if (yysyntax_error_status == 1)
			{
				if (yymsg != yymsgbuf)
					YYSTACK_FREE(yymsg);
				yymsg = (char *)YYSTACK_ALLOC(yymsg_alloc);
				if (!yymsg)
				{
					yymsg = yymsgbuf;
					yymsg_alloc = sizeof yymsgbuf;
					yysyntax_error_status = 2;
				}
				else
				{
					yysyntax_error_status = YYSYNTAX_ERROR;
					yymsgp = yymsg;
				}
			}
			yyerror(yymsgp);
			if (yysyntax_error_status == 2)
				goto yyexhaustedlab;
		}
# undef YYSYNTAX_ERROR
#endif
	}



	if (yyerrstatus == 3)
	{
		/* If just tried and failed to reuse lookahead token after an
		   error, discard it.  */

		if (yychar <= YYEOF)
		{
			/* Return failure if at end of input.  */
			if (yychar == YYEOF)
				YYABORT;
		}
		else
		{
			yydestruct("Error: discarding",
				yytoken, &yylval);
			yychar = YYEMPTY;
		}
	}

	/* Else will try to reuse lookahead token after shifting the error
	   token.  */
	goto yyerrlab1;


	/*---------------------------------------------------.
	| yyerrorlab -- error raised explicitly by YYERROR.  |
	`---------------------------------------------------*/
yyerrorlab:

	/* Pacify compilers like GCC when the user code never invokes
	   YYERROR and the label yyerrorlab therefore never appears in user
	   code.  */
	if (/*CONSTCOND*/ 0)
		goto yyerrorlab;

	/* Do not reclaim the symbols of the rule whose action triggered
	   this YYERROR.  */
	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);
	yystate = *yyssp;
	goto yyerrlab1;


	/*-------------------------------------------------------------.
	| yyerrlab1 -- common code for both syntax error and YYERROR.  |
	`-------------------------------------------------------------*/
yyerrlab1:
	yyerrstatus = 3;      /* Each real token shifted decrements this.  */

	for (;;)
	{
		yyn = yypact[yystate];
		if (!yypact_value_is_default(yyn))
		{
			yyn += YYTERROR;
			if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
			{
				yyn = yytable[yyn];
				if (0 < yyn)
					break;
			}
		}

		/* Pop the current state because it cannot handle the error token.  */
		if (yyssp == yyss)
			YYABORT;


		yydestruct("Error: popping",
			yystos[yystate], yyvsp);
		YYPOPSTACK(1);
		yystate = *yyssp;
		YY_STACK_PRINT(yyss, yyssp);
	}

	YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
		*++yyvsp = yylval;
	YY_IGNORE_MAYBE_UNINITIALIZED_END


		/* Shift the error token.  */
		YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

	yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
	/*-------------------------------------------------.
	| yyexhaustedlab -- memory exhaustion comes here.  |
	`-------------------------------------------------*/
	yyexhaustedlab :
				   yyerror(YY_("memory exhausted"));
				   yyresult = 2;
				   /* Fall through.  */
#endif

			   yyreturn:
				   if (yychar != YYEMPTY)
				   {
					   /* Make sure we have latest lookahead translation.  See comments at
						  user semantic actions for why this is necessary.  */
					   yytoken = YYTRANSLATE(yychar);
					   yydestruct("Cleanup: discarding lookahead",
						   yytoken, &yylval);
				   }
				   /* Do not reclaim the symbols of the rule whose action triggered
					  this YYABORT or YYACCEPT.  */
				   YYPOPSTACK(yylen);
				   YY_STACK_PRINT(yyss, yyssp);
				   while (yyssp != yyss)
				   {
					   yydestruct("Cleanup: popping",
						   yystos[*yyssp], yyvsp);
					   YYPOPSTACK(1);
				   }
#ifndef yyoverflow
				   if (yyss != yyssa)
					   YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
				   if (yymsg != yymsgbuf)
					   YYSTACK_FREE(yymsg);
#endif
				   return yyresult;
}
#line 391 "cminus.y" /* yacc.c:1906  */


int yyerror(char * message)
{
	fprintf(listing, "Syntax error at line %d: %s\n", lineno, message);
	fprintf(listing, "Current token: ");
	printToken(yychar, tokenString);
	Error = TRUE;
	return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{
	return getToken();
}

TreeNode * parse(void)
{
	yyparse();
	return savedTree;
}
