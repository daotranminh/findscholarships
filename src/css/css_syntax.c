/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "css_syntax.y"

#include <stdio.h>
#include <string.h>
#include "css/css_lex.h"
#include "css/parser.h"

#define YYPARSE_PARAM yyparam
#define YYERROR_VERBOSE 1
//#define YYDEBUG 1



/* Line 268 of yacc.c  */
#line 84 "css_syntax.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IMPORT_SYM = 258,
     IMPORTANT_SYM = 259,
     IDENT = 260,
     STRING = 261,
     NUMBER = 262,
     PERCENTAGE = 263,
     LENGTH = 264,
     EMS = 265,
     EXS = 266,
     LINK_PSCLASS_AFTER_IDENT = 267,
     VISITED_PSCLASS_AFTER_IDENT = 268,
     ACTIVE_PSCLASS_AFTER_IDENT = 269,
     FIRST_LINE_AFTER_IDENT = 270,
     FIRST_LETTER_AFTER_IDENT = 271,
     HASH_AFTER_IDENT = 272,
     CLASS_AFTER_IDENT = 273,
     LINK_PSCLASS = 274,
     VISITED_PSCLASS = 275,
     ACTIVE_PSCLASS = 276,
     FIRST_LINE = 277,
     FIRST_LETTER = 278,
     HASH = 279,
     CLASS = 280,
     URL = 281,
     RGB = 282,
     CDO = 283,
     CDC = 284,
     CSL = 285
   };
#endif
/* Tokens.  */
#define IMPORT_SYM 258
#define IMPORTANT_SYM 259
#define IDENT 260
#define STRING 261
#define NUMBER 262
#define PERCENTAGE 263
#define LENGTH 264
#define EMS 265
#define EXS 266
#define LINK_PSCLASS_AFTER_IDENT 267
#define VISITED_PSCLASS_AFTER_IDENT 268
#define ACTIVE_PSCLASS_AFTER_IDENT 269
#define FIRST_LINE_AFTER_IDENT 270
#define FIRST_LETTER_AFTER_IDENT 271
#define HASH_AFTER_IDENT 272
#define CLASS_AFTER_IDENT 273
#define LINK_PSCLASS 274
#define VISITED_PSCLASS 275
#define ACTIVE_PSCLASS 276
#define FIRST_LINE 277
#define FIRST_LETTER 278
#define HASH 279
#define CLASS 280
#define URL 281
#define RGB 282
#define CDO 283
#define CDC 284
#define CSL 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 15 "css_syntax.y"

	char *lexeme;
	char letter;
	struct property_t *property;
	struct selector_t *selector;
	struct selector_list_t *selector_list;
	int pseudo_class;
	int pseudo_element;



/* Line 293 of yacc.c  */
#line 192 "css_syntax.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 204 "css_syntax.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  99

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,    35,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    11,    12,    16,    17,    20,    21,
      23,    25,    27,    31,    33,    35,    37,    39,    41,    43,
      44,    46,    51,    53,    57,    59,    63,    66,    69,    71,
      73,    76,    78,    80,    83,    88,    92,    96,   100,   103,
     106,   109,   111,   115,   118,   121,   123,   126,   128,   130,
     132,   134,   136,   138,   140,   142,   144,   146,   148,   150,
     152,   154,   156,   158,   160,   165,   169,   171,   172,   174,
     176,   180,   183,   186,   188,   190,   192,   194,   196,   198,
     200,   202,   204,   206,   208,   210
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    43,    42,    41,    -1,    50,    43,    41,
      -1,    -1,    45,    43,    42,    -1,    -1,    43,    44,    -1,
      -1,    28,    -1,    29,    -1,    30,    -1,     3,    46,    31,
      -1,     6,    -1,    26,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    -1,     5,    -1,    51,    36,    52,    37,
      -1,    53,    -1,    53,    35,    51,    -1,    65,    -1,    65,
      31,    52,    -1,    54,    61,    -1,    54,    62,    -1,    54,
      -1,    62,    -1,    53,     1,    -1,     1,    -1,    55,    -1,
      55,    54,    -1,    56,    63,    59,    57,    -1,    56,    63,
      57,    -1,    56,    59,    57,    -1,    56,    63,    59,    -1,
      56,    63,    -1,    56,    59,    -1,    56,    57,    -1,    56,
      -1,    64,    59,    57,    -1,    64,    59,    -1,    64,    57,
      -1,    64,    -1,    60,    57,    -1,    60,    -1,    58,    -1,
       5,    -1,    12,    -1,    13,    -1,    14,    -1,    19,    -1,
      20,    -1,    21,    -1,    18,    -1,    25,    -1,    16,    -1,
      15,    -1,    23,    -1,    22,    -1,    17,    -1,    24,    -1,
      49,    38,    67,    66,    -1,    49,    38,    67,    -1,     1,
      -1,    -1,     4,    -1,    68,    -1,    67,    48,    68,    -1,
      67,     1,    -1,    47,    69,    -1,    69,    -1,     7,    -1,
       6,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
       5,    -1,    70,    -1,    26,    -1,    27,    -1,    24,    -1,
      17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   102,   114,   118,   119,   123,   124,   128,
     129,   130,   134,   138,   139,   163,   164,   168,   169,   170,
     174,   178,   194,   204,   219,   222,   233,   241,   249,   250,
     251,   252,   256,   257,   270,   280,   290,   300,   310,   320,
     330,   340,   350,   360,   370,   380,   390,   400,   410,   423,
     427,   428,   429,   433,   434,   435,   439,   443,   447,   448,
     452,   462,   479,   483,   487,   496,   505,   506,   512,   516,
     517,   527,   531,   539,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   560,   565
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT_SYM", "IMPORTANT_SYM", "IDENT",
  "STRING", "NUMBER", "PERCENTAGE", "LENGTH", "EMS", "EXS",
  "LINK_PSCLASS_AFTER_IDENT", "VISITED_PSCLASS_AFTER_IDENT",
  "ACTIVE_PSCLASS_AFTER_IDENT", "FIRST_LINE_AFTER_IDENT",
  "FIRST_LETTER_AFTER_IDENT", "HASH_AFTER_IDENT", "CLASS_AFTER_IDENT",
  "LINK_PSCLASS", "VISITED_PSCLASS", "ACTIVE_PSCLASS", "FIRST_LINE",
  "FIRST_LETTER", "HASH", "CLASS", "URL", "RGB", "CDO", "CDC", "CSL",
  "';'", "'-'", "'+'", "'/'", "','", "'{'", "'}'", "':'", "$accept",
  "stylesheet", "rulesets", "imports", "comments", "comment", "import",
  "string_or_url", "unary_operator", "operator", "property", "ruleset",
  "selectors", "declarations", "selector", "simple_selectors",
  "simple_selector", "element_name", "pseudo_class",
  "solitary_pseudo_class", "class", "solitary_class", "pseudo_element",
  "solitary_pseudo_element", "id", "solitary_id", "declaration", "prio",
  "expr", "term", "value", "hexcolor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    59,    45,    43,    47,    44,   123,   125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    57,    57,    58,    58,    58,    59,    60,    61,    61,
      62,    62,    63,    64,    65,    65,    65,    65,    66,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     3,     0,     2,     0,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     0,
       1,     4,     1,     3,     1,     3,     2,     2,     1,     1,
       2,     1,     1,     2,     4,     3,     3,     3,     2,     2,
       2,     1,     3,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     1,     0,     1,     1,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     6,     1,     0,     9,    10,    11,     0,     7,
       8,    13,    14,     0,    31,    49,    53,    54,    55,    61,
      60,    63,    57,     2,     8,     0,     0,    28,    32,    41,
      48,    47,    29,    45,     6,    12,     0,     0,    30,     0,
      59,    58,    26,    27,    33,    50,    51,    52,    62,    56,
      40,    39,    38,    46,    44,    43,     5,     3,    66,    20,
       0,     0,    24,    23,    36,    35,    37,    42,     0,    21,
       0,    34,    80,    75,    74,    76,    77,    78,    79,    85,
      84,    82,    83,    15,    16,     0,     0,    69,    73,    81,
      25,    72,    71,    68,    17,    18,     0,    64,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    23,     8,     2,     9,    10,    13,    85,    96,
      60,    24,    25,    61,    26,    27,    28,    29,    50,    30,
      51,    31,    42,    32,    52,    33,    62,    97,    86,    87,
      88,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -37
static const yytype_int16 yypact[] =
{
     -37,     2,    26,   -37,    -5,   -37,   -37,   -37,    86,   -37,
     -37,   -37,   -37,   -19,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -17,    13,   113,    38,   132,
     -37,    80,   -37,   139,    26,   -37,    45,    10,   -37,    95,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,    80,   139,   -37,   -37,    80,   -37,   -37,   -37,   -37,
     -21,   -15,    -7,   -37,   -37,   -37,    80,   -37,    71,   -37,
      10,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   116,    -1,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,    71,   -37,   -37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,    -8,     1,     3,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,    -2,   -30,   -37,    16,   -37,   -37,   -13,   -37,
      19,   -37,   -37,    24,   -37,   -37,   -37,   -37,   -37,   -36,
     -24,   -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -68
static const yytype_int8 yytable[] =
{
      92,    11,     3,    93,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,    58,    35,    34,    38,    59,   -19,    68,    53,    37,
      54,    12,    69,   -19,    70,   -19,   -19,    36,    57,     4,
     -65,   -19,   -19,    94,    95,    56,   -65,    63,    64,    65,
      90,   -67,    67,    15,    44,    -4,    14,   -67,    39,   -22,
      15,    43,    55,    71,     5,     6,     7,    16,    17,    18,
      98,    91,    21,    22,    16,    17,    18,    19,    20,    21,
      22,    66,     0,     5,     6,     7,    72,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    -4,    14,    79,     0,
       0,    15,    45,    46,    47,    80,    14,    81,    82,     0,
      15,     0,     0,    83,    84,    16,    17,    18,    19,    20,
      21,    22,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    72,    73,    74,    75,    76,    77,    78,    40,    41,
       0,     0,     0,    79,     0,    19,    20,     0,     0,     0,
      80,     0,    81,    82,    45,    46,    47,     0,     0,    48,
      49,    45,    46,    47,     0,     0,     0,    49
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-37))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       1,     6,     0,     4,     5,     6,     7,     8,     9,    10,
      11,     1,    31,    10,     1,     5,    17,    38,    31,    36,
      33,    26,    37,    24,    31,    26,    27,    24,    36,     3,
      31,    32,    33,    34,    35,    34,    37,    39,    51,    52,
      70,    31,    55,     5,    28,     0,     1,    37,    35,    36,
       5,    27,    33,    66,    28,    29,    30,    19,    20,    21,
      96,    85,    24,    25,    19,    20,    21,    22,    23,    24,
      25,    52,    -1,    28,    29,    30,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     0,     1,    17,    -1,
      -1,     5,    12,    13,    14,    24,     1,    26,    27,    -1,
       5,    -1,    -1,    32,    33,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,     5,     6,     7,     8,     9,    10,    11,    15,    16,
      -1,    -1,    -1,    17,    -1,    22,    23,    -1,    -1,    -1,
      24,    -1,    26,    27,    12,    13,    14,    -1,    -1,    17,
      18,    12,    13,    14,    -1,    -1,    -1,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    43,     0,     3,    28,    29,    30,    42,    44,
      45,     6,    26,    46,     1,     5,    19,    20,    21,    22,
      23,    24,    25,    41,    50,    51,    53,    54,    55,    56,
      58,    60,    62,    64,    43,    31,    43,    36,     1,    35,
      15,    16,    61,    62,    54,    12,    13,    14,    17,    18,
      57,    59,    63,    57,    57,    59,    42,    41,     1,     5,
      49,    52,    65,    51,    57,    57,    59,    57,    38,    37,
      31,    57,     5,     6,     7,     8,     9,    10,    11,    17,
      24,    26,    27,    32,    33,    47,    67,    68,    69,    70,
      52,    69,     1,     4,    34,    35,    48,    66,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
yytnamerr (char *yyres, const char *yystr)
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
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      if (!yypact_value_is_default (yyn))
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
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
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
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 96 "css_syntax.y"
    {
						*(struct selector_list_t**) yyparam = (yyvsp[(3) - (3)].selector_list);
					}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 102 "css_syntax.y"
    {
								struct selector_list_t *pos = (yyvsp[(1) - (3)].selector_list);
								if (pos != NULL) {
									while (pos->next != NULL) {
										pos = pos->next;
									}
									pos->next = (yyvsp[(3) - (3)].selector_list);
								} else {
									(yyvsp[(1) - (3)].selector_list) = (yyvsp[(3) - (3)].selector_list);
								}
								(yyval.selector_list) = (yyvsp[(1) - (3)].selector_list);
							}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 114 "css_syntax.y"
    { (yyval.selector_list) = NULL;  }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 138 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 139 "css_syntax.y"
    {
			char *begin = (yyvsp[(1) - (1)].lexeme);
			char *end = (yyvsp[(1) - (1)].lexeme) + strlen((yyvsp[(1) - (1)].lexeme));

			/* Skip url( */
			begin += 4;
			/* skip whitespace */
			while (*begin == ' ')
				++begin;

			/* Skip ) */
			end -= 2;
			/* skip whitespace */
			while (*end == ' ')
				--end;

			end[1] = 0;

			(yyval.lexeme) = strdup(begin);
			free((yyvsp[(1) - (1)].lexeme));
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 163 "css_syntax.y"
    { (yyval.letter) = '-'; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 164 "css_syntax.y"
    { (yyval.letter) = '+'; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 168 "css_syntax.y"
    { (yyval.letter) = '/'; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 169 "css_syntax.y"
    { (yyval.letter) = ','; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 170 "css_syntax.y"
    {(yyval.letter) = ' '; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 174 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 178 "css_syntax.y"
    {
										struct selector_list_t *pos = (yyvsp[(1) - (4)].selector_list);
										while (pos != NULL) {
											struct property_t *i = (yyvsp[(3) - (4)].property);
											while (i != NULL) {
												i->count++;
												i = i->next;
											}
											pos->selector->property = (yyvsp[(3) - (4)].property);
											pos = pos->next;
										}
										(yyval.selector_list) = (yyvsp[(1) - (4)].selector_list);
									}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 194 "css_syntax.y"
    {
				if ((yyvsp[(1) - (1)].selector) != NULL) {
					(yyval.selector_list) = (struct selector_list_t*)
						malloc (sizeof(struct selector_list_t));
					(yyval.selector_list)->selector = (yyvsp[(1) - (1)].selector);
					(yyval.selector_list)->next = NULL;
				} else {
					(yyval.selector_list) = NULL;
				}
			}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 204 "css_syntax.y"
    {
								if ((yyvsp[(1) - (3)].selector) != NULL) {
									struct selector_list_t *new;
									new = (struct selector_list_t*)
										malloc (sizeof(struct selector_list_t));
									new->selector = (yyvsp[(1) - (3)].selector);
									new->next = (yyvsp[(3) - (3)].selector_list);
									(yyval.selector_list) = new;
								} else {
									(yyval.selector_list) = (yyvsp[(3) - (3)].selector_list);
								}
							}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 219 "css_syntax.y"
    {
									(yyval.property) = (yyvsp[(1) - (1)].property);
								}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 222 "css_syntax.y"
    {
									if ((yyvsp[(1) - (3)].property) != NULL) {
										(yyvsp[(1) - (3)].property)->next = (yyvsp[(3) - (3)].property);
										(yyval.property) = (yyvsp[(1) - (3)].property);
									} else {
										(yyval.property) = (yyvsp[(3) - (3)].property);
									}
								}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 233 "css_syntax.y"
    {
										struct selector_t *pos = (yyvsp[(1) - (2)].selector);
										while (pos->next != NULL) {
											pos = pos->next;
										}
										pos->pseudo_element = (yyvsp[(2) - (2)].pseudo_element);
										(yyval.selector) = (yyvsp[(1) - (2)].selector);
									}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 241 "css_syntax.y"
    {
												struct selector_t *pos = (yyvsp[(1) - (2)].selector);
												while (pos->next != NULL) {
													pos = pos->next;
												}
												pos->next = (yyvsp[(2) - (2)].selector);
												(yyval.selector) = (yyvsp[(1) - (2)].selector);
											}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 249 "css_syntax.y"
    { (yyval.selector) = (yyvsp[(1) - (1)].selector); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 250 "css_syntax.y"
    { (yyval.selector) = (yyvsp[(1) - (1)].selector); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 251 "css_syntax.y"
    { (yyval.selector) = NULL; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 252 "css_syntax.y"
    { (yyval.selector) = NULL; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 256 "css_syntax.y"
    { (yyval.selector) = (yyvsp[(1) - (1)].selector); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 257 "css_syntax.y"
    {
										(yyvsp[(1) - (2)].selector)->next = (yyvsp[(2) - (2)].selector);
										(yyval.selector) = (yyvsp[(1) - (2)].selector);
									}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 270 "css_syntax.y"
    {
										(yyval.selector) = (struct selector_t*)
											malloc(sizeof(struct selector_t));
										(yyval.selector)->element_name = (yyvsp[(1) - (4)].lexeme);
										(yyval.selector)->id = (yyvsp[(2) - (4)].lexeme);
										(yyval.selector)->e_class = (yyvsp[(3) - (4)].lexeme);
										(yyval.selector)->pseudo_class = (yyvsp[(4) - (4)].pseudo_class);
										(yyval.selector)->pseudo_element = 0;
										(yyval.selector)->next = NULL;
									 }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 280 "css_syntax.y"
    {
									(yyval.selector) = (struct selector_t*)
										malloc(sizeof(struct selector_t));
									(yyval.selector)->element_name = (yyvsp[(1) - (3)].lexeme);
									(yyval.selector)->id = (yyvsp[(2) - (3)].lexeme);
									(yyval.selector)->e_class = NULL;
									(yyval.selector)->pseudo_class = (yyvsp[(3) - (3)].pseudo_class);
									(yyval.selector)->pseudo_element = 0;
									(yyval.selector)->next = NULL;
								}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 290 "css_syntax.y"
    {
										(yyval.selector) = (struct selector_t*)
											malloc(sizeof(struct selector_t));
										(yyval.selector)->element_name = (yyvsp[(1) - (3)].lexeme);
										(yyval.selector)->id = NULL;
										(yyval.selector)->e_class = (yyvsp[(2) - (3)].lexeme);
										(yyval.selector)->pseudo_class = (yyvsp[(3) - (3)].pseudo_class);
										(yyval.selector)->pseudo_element = 0;
										(yyval.selector)->next = NULL;
									}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 300 "css_syntax.y"
    {
							(yyval.selector) = (struct selector_t*)
								malloc(sizeof(struct selector_t));
							(yyval.selector)->element_name = (yyvsp[(1) - (3)].lexeme);
							(yyval.selector)->id = (yyvsp[(2) - (3)].lexeme);
							(yyval.selector)->e_class = (yyvsp[(3) - (3)].lexeme);
							(yyval.selector)->pseudo_class = 0;
							(yyval.selector)->pseudo_element = 0;
							(yyval.selector)->next = NULL;
						}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 310 "css_syntax.y"
    {
						(yyval.selector) = (struct selector_t*)
							malloc(sizeof(struct selector_t));
						(yyval.selector)->element_name = (yyvsp[(1) - (2)].lexeme);
						(yyval.selector)->id = (yyvsp[(2) - (2)].lexeme);
						(yyval.selector)->e_class = NULL;
						(yyval.selector)->pseudo_class = 0;
						(yyval.selector)->pseudo_element = 0;
						(yyval.selector)->next = NULL;
					}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 320 "css_syntax.y"
    {
							(yyval.selector) = (struct selector_t*)
								malloc(sizeof(struct selector_t));
							(yyval.selector)->element_name = (yyvsp[(1) - (2)].lexeme);
							(yyval.selector)->id = NULL;
							(yyval.selector)->e_class = (yyvsp[(2) - (2)].lexeme);
							(yyval.selector)->pseudo_class = 0;
							(yyval.selector)->pseudo_element = 0;
							(yyval.selector)->next = NULL;
						}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 330 "css_syntax.y"
    {
								(yyval.selector) = (struct selector_t*)
									malloc(sizeof(struct selector_t));
								(yyval.selector)->element_name = (yyvsp[(1) - (2)].lexeme);
								(yyval.selector)->id = NULL;
								(yyval.selector)->e_class = NULL;
								(yyval.selector)->pseudo_class = (yyvsp[(2) - (2)].pseudo_class);
								(yyval.selector)->pseudo_element = 0;
								(yyval.selector)->next = NULL;
							}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 340 "css_syntax.y"
    {
					(yyval.selector) = (struct selector_t*)
						malloc(sizeof(struct selector_t));
					(yyval.selector)->element_name = (yyvsp[(1) - (1)].lexeme);
					(yyval.selector)->id = NULL;
					(yyval.selector)->e_class = NULL;
					(yyval.selector)->pseudo_class = 0;
					(yyval.selector)->pseudo_element = 0;
					(yyval.selector)->next = NULL;
				}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 350 "css_syntax.y"
    {
										(yyval.selector) = (struct selector_t*)
											malloc(sizeof(struct selector_t));
										(yyval.selector)->element_name = NULL;
										(yyval.selector)->id = (yyvsp[(1) - (3)].lexeme);
										(yyval.selector)->e_class = (yyvsp[(2) - (3)].lexeme);
										(yyval.selector)->pseudo_class = (yyvsp[(3) - (3)].pseudo_class);
										(yyval.selector)->pseudo_element = 0;
										(yyval.selector)->next = NULL;
									}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 360 "css_syntax.y"
    {
						(yyval.selector) = (struct selector_t*)
							malloc(sizeof(struct selector_t));
						(yyval.selector)->element_name = NULL;
						(yyval.selector)->id = (yyvsp[(1) - (2)].lexeme);
						(yyval.selector)->e_class = (yyvsp[(2) - (2)].lexeme);
						(yyval.selector)->pseudo_class = 0;
						(yyval.selector)->pseudo_element = 0;
						(yyval.selector)->next = NULL;
					}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 370 "css_syntax.y"
    {
								(yyval.selector) = (struct selector_t*)
									malloc(sizeof(struct selector_t));
								(yyval.selector)->element_name = NULL;
								(yyval.selector)->id = (yyvsp[(1) - (2)].lexeme);
								(yyval.selector)->e_class = NULL;
								(yyval.selector)->pseudo_class = (yyvsp[(2) - (2)].pseudo_class);
								(yyval.selector)->pseudo_element = 0;
								(yyval.selector)->next = NULL;
							}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 380 "css_syntax.y"
    {
					(yyval.selector) = (struct selector_t*)
						malloc(sizeof(struct selector_t));
					(yyval.selector)->element_name = NULL;
					(yyval.selector)->id = (yyvsp[(1) - (1)].lexeme);
					(yyval.selector)->e_class = NULL;
					(yyval.selector)->pseudo_class = 0;
					(yyval.selector)->pseudo_element = 0;
					(yyval.selector)->next = NULL;
				}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 390 "css_syntax.y"
    {
									(yyval.selector) = (struct selector_t*)
										malloc(sizeof(struct selector_t));
									(yyval.selector)->element_name = NULL;
									(yyval.selector)->id = NULL;
									(yyval.selector)->e_class = (yyvsp[(1) - (2)].lexeme);
									(yyval.selector)->pseudo_class = (yyvsp[(2) - (2)].pseudo_class);
									(yyval.selector)->pseudo_element = 0;
									(yyval.selector)->next = NULL;
								}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 400 "css_syntax.y"
    {
						(yyval.selector) = (struct selector_t*)
							malloc(sizeof(struct selector_t));
						(yyval.selector)->element_name = NULL;
						(yyval.selector)->id = NULL;
						(yyval.selector)->e_class = (yyvsp[(1) - (1)].lexeme);
						(yyval.selector)->pseudo_class = 0;
						(yyval.selector)->pseudo_element = 0;
						(yyval.selector)->next = NULL;
					}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 410 "css_syntax.y"
    {
							(yyval.selector) = (struct selector_t*)
								malloc(sizeof(struct selector_t));
							(yyval.selector)->element_name = NULL;
							(yyval.selector)->id = NULL;
							(yyval.selector)->e_class = NULL;
							(yyval.selector)->pseudo_class = (yyvsp[(1) - (1)].pseudo_class);
							(yyval.selector)->pseudo_element = 0;
							(yyval.selector)->next = NULL;
						}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 423 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 427 "css_syntax.y"
    { (yyval.pseudo_class) = PS_CLASS_LINK; }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 428 "css_syntax.y"
    { (yyval.pseudo_class) = PS_CLASS_VISITED; }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 429 "css_syntax.y"
    { (yyval.pseudo_class) = PS_CLASS_ACTIVE; }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 433 "css_syntax.y"
    { (yyval.pseudo_class) = PS_CLASS_LINK; }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 434 "css_syntax.y"
    { (yyval.pseudo_class) = PS_CLASS_VISITED; }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 435 "css_syntax.y"
    { (yyval.pseudo_class) = PS_CLASS_ACTIVE; }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 439 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 443 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 447 "css_syntax.y"
    { (yyval.pseudo_element) = PS_ELEMENT_FIRST_LETTER; }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 448 "css_syntax.y"
    { (yyval.pseudo_element) = PS_ELEMENT_FIRST_LINE; }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 452 "css_syntax.y"
    {
					(yyval.selector) = (struct selector_t*)
						malloc(sizeof(struct selector_t));
					(yyval.selector)->element_name = NULL;
					(yyval.selector)->id = NULL;
					(yyval.selector)->e_class = NULL;
					(yyval.selector)->pseudo_class = 0;
					(yyval.selector)->pseudo_element = PS_ELEMENT_FIRST_LETTER;
					(yyval.selector)->next = NULL;
				}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 462 "css_syntax.y"
    {
					(yyval.selector) = (struct selector_t*)
						malloc(sizeof(struct selector_t));
					(yyval.selector)->element_name = NULL;
					(yyval.selector)->id = NULL;
					(yyval.selector)->e_class = NULL;
					(yyval.selector)->pseudo_class = 0;
					(yyval.selector)->pseudo_element = PS_ELEMENT_FIRST_LINE;
					(yyval.selector)->next = NULL;
				}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 479 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 483 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 487 "css_syntax.y"
    {
								(yyval.property) = (struct property_t*)
									malloc(sizeof(struct property_t));
								(yyval.property)->name = (yyvsp[(1) - (4)].lexeme);
								(yyval.property)->val = (yyvsp[(3) - (4)].lexeme);
								(yyval.property)->important = 1;
								(yyval.property)->count = 0;
								(yyval.property)->next = NULL;
							}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 496 "css_syntax.y"
    {
								(yyval.property) = (struct property_t*)
									malloc(sizeof(struct property_t));
								(yyval.property)->name = (yyvsp[(1) - (3)].lexeme);
								(yyval.property)->val = (yyvsp[(3) - (3)].lexeme);
								(yyval.property)->important = 0;
								(yyval.property)->count = 0;
								(yyval.property)->next = NULL;
							}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 505 "css_syntax.y"
    { (yyval.property) = NULL; }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 506 "css_syntax.y"
    {
								(yyval.property) = NULL;
							}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 512 "css_syntax.y"
    { }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 516 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 517 "css_syntax.y"
    {
							char *s = (char*) malloc (strlen((yyvsp[(1) - (3)].lexeme))+strlen((yyvsp[(3) - (3)].lexeme))+2);
							strcpy(s, (yyvsp[(1) - (3)].lexeme));
							s[strlen(s)+1] = 0;
							s[strlen(s)] = (yyvsp[(2) - (3)].letter);
							strcat(s, (yyvsp[(3) - (3)].lexeme));
							free((yyvsp[(1) - (3)].lexeme));
							free((yyvsp[(3) - (3)].lexeme));
							(yyval.lexeme) = s;
						}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 527 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (2)].lexeme); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 531 "css_syntax.y"
    {
							char *s = (char*) malloc(strlen((yyvsp[(2) - (2)].lexeme))+2);
							s[0] = (yyvsp[(1) - (2)].letter);
							s[1] = 0;
							strcat(s, (yyvsp[(2) - (2)].lexeme));
							free((yyvsp[(2) - (2)].lexeme));
							(yyval.lexeme) = s;
						}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 539 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 543 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 544 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 545 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 546 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 547 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 548 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 549 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 550 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 551 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 552 "css_syntax.y"
    { (yyval.lexeme) = (yyvsp[(1) - (1)].lexeme); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 560 "css_syntax.y"
    { 
			(yyval.lexeme) = (char*) malloc (strlen((yyvsp[(1) - (1)].lexeme))+2);
			sprintf((yyval.lexeme), "#%s", (yyvsp[(1) - (1)].lexeme));
			free((yyvsp[(1) - (1)].lexeme));
		}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 565 "css_syntax.y"
    { 
						(yyval.lexeme) = (char*) malloc (strlen((yyvsp[(1) - (1)].lexeme))+2);
						sprintf((yyval.lexeme), "#%s", (yyvsp[(1) - (1)].lexeme));
						free((yyvsp[(1) - (1)].lexeme));
					}
    break;



/* Line 1806 of yacc.c  */
#line 2365 "css_syntax.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
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
	  yydestruct ("Error: discarding",
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

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 572 "css_syntax.y"


int yyerror(char *s) {
#if YYDEBUG
	fprintf(stderr, "Error: %s\n", s);
#endif
	return 0;
}

struct selector_list_t* css_parse(const char *buffer, int buf_len) {
	struct selector_list_t *ret = NULL;
	//yydebug = 1;
	init_yylex(buffer, buf_len);
	yyparse(&ret);
	end_yylex();
	return ret;
}

