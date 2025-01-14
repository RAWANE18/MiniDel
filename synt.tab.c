
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "synt.y"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"
void yyerror(const char *s);
extern char *yytext;
int yylex();
int nb_ligne=1;
int Col=1;
char tempval[20];
char svtype[20];
char svcst[20];
char svcst2[20];
char svop[20];
char svtaille[20];
int Fin_if=0,deb_else=0;
char tmp [20]; 
int tete = -1; 
int deb_else_pile[100];



/* Line 189 of yacc.c  */
#line 98 "synt.tab.c"

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
     mc_PROGRAM = 258,
     mc_VAR = 259,
     mc_begin = 260,
     mc_END = 261,
     mc_CONST = 262,
     mc_INTEGER = 263,
     mc_FLOAT = 264,
     mc_IF = 265,
     mc_ELSE = 266,
     mc_FOR = 267,
     mc_WHILE = 268,
     mc_READLN = 269,
     mc_WRITELN = 270,
     op_ADD = 271,
     op_SUB = 272,
     op_MUL = 273,
     op_DIV = 274,
     op_AND = 275,
     op_OR = 276,
     op_NOT = 277,
     op_EQ = 278,
     op_NEG = 279,
     op_INF = 280,
     op_INF_E = 281,
     op_SUP = 282,
     op_SUP_E = 283,
     op_AFF = 284,
     PO = 285,
     PF = 286,
     OB = 287,
     FB = 288,
     ALO = 289,
     ALF = 290,
     VIR = 291,
     PVIR = 292,
     DPOINT = 293,
     IDF = 294,
     ERR = 295,
     STR = 296,
     REEL = 297,
     INT = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "synt.y"

    char *str; 



/* Line 214 of yacc.c  */
#line 183 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "synt.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    13,    24,    26,    28,    30,    32,    34,
      36,    38,    40,    42,    44,    46,    48,    50,    52,    54,
      59,    64,    69,    73,    77,    81,    83,    85,    90,    92,
      96,    98,   102,   104,   108,   110,   112,   116,   120,   122,
     124,   128,   131,   133,   136,   138,   140,   142,   145,   148,
     162,   167,   172,   175,   178,   180,   182,   188,   190,   195,
     200,   205,   209,   216,   218,   222,   228,   234,   236,   238,
     240,   245,   250,   255,   257,   259,   261,   263,   266,   270,
     274,   276,   280,   284,   288,   292,   296,   300
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,     3,    39,     4,    34,    48,    35,     5,
      58,     6,    -1,     3,    39,     4,    34,    48,    35,     5,
      58,     6,    47,    -1,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,
      46,    -1,    70,    -1,    49,    56,    37,    48,    -1,    49,
      52,    37,    48,    -1,     7,    53,    37,    48,    -1,    49,
      56,    37,    -1,     7,    53,    37,    -1,    49,    52,    37,
      -1,     8,    -1,     9,    -1,    39,    32,    51,    33,    -1,
      43,    -1,    50,    36,    52,    -1,    50,    -1,    54,    36,
      53,    -1,    54,    -1,    39,    29,    55,    -1,    43,    -1,
      42,    -1,    39,    36,    56,    -1,    57,    36,    56,    -1,
      39,    -1,    57,    -1,    39,    29,    55,    -1,    59,    58,
      -1,    59,    -1,    68,    37,    -1,    64,    -1,    71,    -1,
      60,    -1,    61,    37,    -1,    62,    37,    -1,    12,    30,
      39,    38,    43,    38,    43,    38,    39,    31,    34,    58,
      35,    -1,    14,    30,    39,    31,    -1,    15,    30,    63,
      31,    -1,    41,    63,    -1,    39,    63,    -1,    41,    -1,
      39,    -1,    65,    11,    34,    58,    35,    -1,    66,    -1,
      67,    34,    58,    35,    -1,    67,    34,    58,    35,    -1,
      10,    30,    74,    31,    -1,    39,    29,    69,    -1,    39,
      32,    43,    33,    29,    69,    -1,    70,    -1,    70,    73,
      69,    -1,    30,    69,    31,    73,    69,    -1,    70,    73,
      30,    69,    31,    -1,    39,    -1,    43,    -1,    42,    -1,
      39,    32,    43,    33,    -1,    72,    34,    58,    35,    -1,
      13,    30,    74,    31,    -1,    17,    -1,    16,    -1,    19,
      -1,    18,    -1,    22,    74,    -1,    74,    20,    74,    -1,
      74,    21,    74,    -1,    75,    -1,    75,    27,    75,    -1,
      75,    28,    75,    -1,    75,    25,    75,    -1,    75,    26,
      75,    -1,    75,    23,    75,    -1,    75,    24,    75,    -1,
      69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    52,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    60,
      61,    62,    63,    64,    65,    67,    68,    70,    72,    74,
      75,    77,    78,    80,    82,    83,    85,    86,    87,    88,
      89,    92,    93,    95,    96,    97,    98,    99,   100,   104,
     111,   116,   118,   119,   122,   123,   130,   133,   135,   143,
     150,   157,   168,   173,   174,   188,   202,   217,   218,   219,
     220,   224,   225,   229,   230,   231,   232,   234,   237,   245,
     252,   256,   261,   266,   271,   276,   281,   286
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_PROGRAM", "mc_VAR", "mc_begin",
  "mc_END", "mc_CONST", "mc_INTEGER", "mc_FLOAT", "mc_IF", "mc_ELSE",
  "mc_FOR", "mc_WHILE", "mc_READLN", "mc_WRITELN", "op_ADD", "op_SUB",
  "op_MUL", "op_DIV", "op_AND", "op_OR", "op_NOT", "op_EQ", "op_NEG",
  "op_INF", "op_INF_E", "op_SUP", "op_SUP_E", "op_AFF", "PO", "PF", "OB",
  "FB", "ALO", "ALF", "VIR", "PVIR", "DPOINT", "IDF", "ERR", "STR", "REEL",
  "INT", "$accept", "S", "MC", "AFTER_END", "declarationV", "type",
  "ARRAY", "taille", "listeT", "listeC", "AFFVALCST", "val", "listeV",
  "AFFVAL", "corps", "instruction", "instFOR", "instREADLN", "instWRITELN",
  "string", "instIF", "Belse", "B", "A", "instAFF", "expression", "term",
  "instWHILE", "E", "operation", "cond", "expC", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    51,    52,
      52,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    60,
      61,    62,    63,    63,    63,    63,    64,    64,    65,    66,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    71,    72,    73,    73,    73,    73,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,    10,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     3,     3,     3,     1,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     3,     1,     1,
       3,     2,     1,     2,     1,     1,     1,     2,     2,    13,
       4,     4,     2,     2,     1,     1,     5,     1,     4,     4,
       4,     3,     6,     1,     3,     5,     5,     1,     1,     1,
       4,     4,     4,     1,     1,     1,     1,     2,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    32,     0,    38,    30,     0,     0,
      39,     0,    23,     0,     0,     0,     0,     0,     0,    24,
      22,     0,    35,    34,    33,    21,    31,     0,     0,     0,
       0,     0,     0,     0,    42,    46,     0,     0,    44,     0,
      57,     0,     0,    45,     0,    40,    28,     0,    38,    36,
       0,    29,    20,    19,    37,     0,     0,     0,     0,     0,
       0,     0,     2,    41,    47,    48,     0,     0,    43,     0,
      27,     0,     0,    67,    69,    68,    87,    63,     0,    80,
       0,     0,     0,    55,    54,     0,    61,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     3,    18,     0,     0,     0,    77,     0,     0,
      74,    73,    76,    75,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,    72,    50,    53,    52,    51,
       0,     0,    59,    71,     0,     0,     0,    64,    78,    79,
      85,    86,    83,    84,    81,    82,     0,     0,    56,     0,
      70,     0,     0,    62,    65,    66,     0,     0,     0,     0,
       0,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   111,   112,    10,    11,    17,    57,    18,    13,
      14,    34,    19,    20,    43,    44,    45,    46,    47,    95,
      48,    49,    50,    51,    52,    86,    87,    53,    54,   159,
      88,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int8 yypact[] =
{
      12,   -30,    54,    58,   -70,    32,    77,    29,   -70,   -70,
      41,    48,    60,    66,    68,   100,    35,    70,    71,    72,
      74,    57,    77,    29,    -7,    57,    64,    73,    75,    77,
      77,    73,   -70,   -70,   -70,   -70,   -70,    83,    85,    86,
      87,    88,     5,   105,    -7,   -70,    82,    84,   -70,   109,
     -70,    89,    90,   -70,    91,   -70,   -70,    95,    10,   -70,
      92,   -70,   -70,   -70,   -70,     8,    93,     8,    94,    24,
       1,    79,    14,   -70,   -70,   -70,    96,    -7,   -70,    -7,
     -70,     8,     1,    97,   -70,   -70,   -70,    56,    21,    55,
      98,    38,   103,    24,    24,   104,   -70,   106,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,    -7,   102,   107,    81,   110,   101,
     -70,   -70,   -70,   -70,     6,     8,     8,   -70,     1,     1,
       1,     1,     1,     1,   108,   -70,   -70,   -70,   -70,   -70,
     111,   112,   120,   -70,    56,   113,     1,   -70,   -70,   118,
     -70,   -70,   -70,   -70,   -70,   -70,   114,     1,   -70,     1,
     -70,   117,   115,   -70,   -70,    56,   116,   121,   119,   122,
      -7,   124,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -18,   -70,   -70,   -70,   125,   126,
     -70,   130,   -17,   -70,   -44,   -70,   -70,   -70,   -70,     4,
     -70,   -70,   -70,   -70,   -70,   -69,    99,   -70,   -70,    76,
     -65,   -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      73,    96,    91,    37,    35,    38,    39,    40,    41,     3,
      59,    62,    63,   118,    64,     1,   117,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      81,    82,    42,   115,    70,   116,   146,    71,    82,    25,
      83,   125,   126,    84,    85,    83,    27,    83,    84,    85,
      84,    85,   127,    83,     4,   147,    84,    85,   125,   126,
     148,   149,     5,    93,    25,    94,     6,    26,    12,   135,
     141,    27,   120,   121,   122,   123,    15,   161,   128,   129,
     130,   131,   132,   133,     7,     8,     9,    16,   163,    21,
     164,   150,   151,   152,   153,   154,   155,   137,   138,    32,
      33,   125,   126,    22,    23,    24,    28,    56,    29,    30,
      31,    72,    58,    65,    60,    66,    67,    68,    69,    74,
      76,    75,    97,    77,    26,    79,   171,    78,    80,   119,
     114,   -58,    90,    92,   136,   139,   134,   142,   125,   140,
     157,   144,   143,     0,   145,     0,   160,   158,   165,    36,
     169,   156,   162,    61,   167,    55,   170,     0,   166,   172,
     168,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,   113
};

static const yytype_int16 yycheck[] =
{
      44,    70,    67,    10,    22,    12,    13,    14,    15,    39,
      27,    29,    30,    82,    31,     3,    81,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      22,    30,    39,    77,    29,    79,    30,    32,    30,    29,
      39,    20,    21,    42,    43,    39,    36,    39,    42,    43,
      42,    43,    31,    39,     0,   124,    42,    43,    20,    21,
     125,   126,     4,    39,    29,    41,    34,    32,    39,    31,
     114,    36,    16,    17,    18,    19,    35,   146,    23,    24,
      25,    26,    27,    28,     7,     8,     9,    39,   157,    29,
     159,   128,   129,   130,   131,   132,   133,    93,    94,    42,
      43,    20,    21,    37,    36,     5,    36,    43,    37,    37,
      36,     6,    39,    30,    39,    30,    30,    30,    30,    37,
      11,    37,    43,    34,    32,    34,   170,    37,    33,    32,
      34,    11,    39,    39,    31,    31,    38,    35,    20,    33,
      29,    31,    35,    -1,    43,    -1,    33,    35,    31,    23,
      31,    43,    38,    28,    38,    25,    34,    -1,    43,    35,
      39,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    45,    39,     0,     4,    34,     7,     8,     9,
      48,    49,    39,    53,    54,    35,    39,    50,    52,    56,
      57,    29,    37,    36,     5,    29,    32,    36,    36,    37,
      37,    36,    42,    43,    55,    48,    53,    10,    12,    13,
      14,    15,    39,    58,    59,    60,    61,    62,    64,    65,
      66,    67,    68,    71,    72,    55,    43,    51,    39,    56,
      39,    52,    48,    48,    56,    30,    30,    30,    30,    30,
      29,    32,     6,    58,    37,    37,    11,    34,    37,    34,
      33,    22,    30,    39,    42,    43,    69,    70,    74,    75,
      39,    74,    39,    39,    41,    63,    69,    43,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    46,    47,    70,    34,    58,    58,    74,    69,    32,
      16,    17,    18,    19,    73,    20,    21,    31,    23,    24,
      25,    26,    27,    28,    38,    31,    31,    63,    63,    31,
      33,    58,    35,    35,    31,    43,    30,    69,    74,    74,
      75,    75,    75,    75,    75,    75,    43,    29,    35,    73,
      33,    69,    38,    69,    69,    31,    43,    38,    39,    31,
      34,    58,    35
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 49 "synt.y"
    { printf("\t ___________________________________\n");
printf("\t |Programme syntaxiquement correcte| \n");    printf("\t |_________________________________|\n");
 YYACCEPT;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 53 "synt.y"
    {
        printf("\t | Erreur: Texte supplementaire apres END ! |\n");
        YYERROR;
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 67 "synt.y"
    {strcpy(svtype,(yyvsp[(1) - (1)].str));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 68 "synt.y"
    {strcpy(svtype,(yyvsp[(1) - (1)].str));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 70 "synt.y"
    {if(declarer((yyvsp[(1) - (4)].str))!=1){int idx; idx=rechercher((yyvsp[(1) - (4)].str),"Identificateur",svtype,"Tableau","", 0);}else{yyerror("declared");YYABORT; };}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 72 "synt.y"
    {strcpy(svtaille,(yyvsp[(1) - (1)].str));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 80 "synt.y"
    {if(declarer((yyvsp[(1) - (3)].str))!=1){int idx; idx=rechercher((yyvsp[(1) - (3)].str), "Identificateur",svtype,"CONSTANTE", tempval, 0);}else{yyerror("declared");YYABORT; };}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 82 "synt.y"
    {strcpy(tempval,(yyvsp[(1) - (1)].str));strcpy(svtype,"INTEGER");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 83 "synt.y"
    {strcpy(tempval,(yyvsp[(1) - (1)].str));strcpy(svtype,"FLOAT");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 85 "synt.y"
    {if(declarer((yyvsp[(1) - (3)].str))!=1){int idx; idx=rechercher((yyvsp[(1) - (3)].str), "Identificateur",svtype,svtype, "", 0);}else{yyerror("declared");YYABORT; };}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 87 "synt.y"
    {if(declarer((yyvsp[(1) - (1)].str))!=1){int idx; idx=rechercher((yyvsp[(1) - (1)].str), "Identificateur", svtype, svtype,"", 0);}else{ yyerror("declared");YYABORT;};}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 89 "synt.y"
    {if(declarer((yyvsp[(1) - (3)].str))!=1){int pos; pos=rechercher((yyvsp[(1) - (3)].str), "Identificateur",svtype, svtype,tempval, 0);}else{yyerror("declared");YYABORT; };}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 104 "synt.y"
    {if(declarer((yyvsp[(3) - (13)].str))!=1){  
       printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (13)].str), nb_ligne,Col);
       YYABORT;}
       else if(declarer((yyvsp[(9) - (13)].str))!=1){
              printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",(yyvsp[(9) - (13)].str), nb_ligne,Col);
              YYABORT;};}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 111 "synt.y"
    {if(declarer((yyvsp[(3) - (4)].str))!=1){
        printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",(yyvsp[(3) - (4)].str), nb_ligne,Col);
        YYABORT;};}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 119 "synt.y"
    {if(declarer((yyvsp[(1) - (2)].str))!=1){ 
               printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (2)].str), nb_ligne,Col);
               YYABORT;};}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 123 "synt.y"
    {if(declarer((yyvsp[(1) - (1)].str))!=1){ 
               printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (1)].str), nb_ligne,Col);
               YYABORT;};}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 130 "synt.y"
    { 
     sprintf(tmp,"%d",qc);  
                              ajour_quad(Fin_if,1,tmp);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 135 "synt.y"
    {  
				   Fin_if=qc;
                   quadr("BR", "","vide", "vide"); 
				   sprintf(tmp,"%d",qc); 
                   ajour_quad(deb_else,1,tmp);
				   ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 143 "synt.y"
    { 
    sprintf(tmp, "%d", qc); 
    ajour_quad(deb_else_pile[tete], 1, tmp); 
    tete--; 
;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 150 "synt.y"
    { 
    deb_else_pile[++tete] = qc; 
    quadr("BZ", "", (yyvsp[(3) - (4)].str), "");
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 157 "synt.y"
    {
           if(declarer((yyvsp[(1) - (3)].str))!=1){ printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (3)].str), nb_ligne,Col);YYABORT;}
           if(div_zero(svcst,svop)!=0){printf("erreur Semantique: Division par '0' a la ligne %d a la colonne %d\n", nb_ligne,Col);YYABORT;} 
           if(verefier_cst((yyvsp[(1) - (3)].str))==1){printf("erreur Semantique: changement de valeur de constante a la ligne %d a la colonne %d\n", nb_ligne,Col);YYABORT;}
         if(areTypesCompatible((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str))==1){
             printf("Warning: conversion implicite vers un type superieur : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (3)].str), nb_ligne,Col);
             
        }if(areTypesCompatible((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str))==-1){
             printf("erreur Semantique: Type non compatyble : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (3)].str), nb_ligne,Col);
             
        } quadr("=", (yyvsp[(3) - (3)].str), "", (yyvsp[(1) - (3)].str));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 168 "synt.y"
    {quadr("=", (yyvsp[(6) - (6)].str), "", (yyvsp[(1) - (6)].str)); if(strtol((yyvsp[(3) - (6)].str), NULL, 10) > strtol(svtaille, NULL, 10)){printf("erreur Semantique: depassement de taille:%s a la ligne %d a la colonne %d\n",(yyvsp[(1) - (6)].str), nb_ligne,Col);YYABORT;};}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 173 "synt.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 175 "synt.y"
    {
         if(areTypesCompatible((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str))==0){
            strcpy(svtype,(yyvsp[(1) - (3)].str));
        }else{
             printf("Warning: Type non compatyble : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (3)].str), nb_ligne,Col);
               strcpy(svtype,"FLOAT");
        }
          char* temp = newTempVar();
          quadr((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp); 
          (yyval.str) = temp;
          
       
        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 189 "synt.y"
    {
           if(areTypesCompatible((yyvsp[(2) - (5)].str),(yyvsp[(5) - (5)].str))==0){
            strcpy(svtype,(yyvsp[(1) - (5)].str));
        }else{
             printf("Warning: Type non compatyble : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (5)].str), nb_ligne,Col);
               strcpy(svtype,"FLOAT");
        }
          char* temp = newTempVar();
          quadr((yyvsp[(4) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(5) - (5)].str), temp);
          (yyval.str) = temp;
          
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 203 "synt.y"
    {
         if(areTypesCompatible((yyvsp[(1) - (5)].str),(yyvsp[(4) - (5)].str))==0){
            strcpy(svtype,(yyvsp[(1) - (5)].str));
        }else{
             printf("Warning: Type non compatyble : %s, a la ligne %d a la colonne %d\n",(yyvsp[(1) - (5)].str), nb_ligne,Col);
               strcpy(svtype,"FLOAT");
        }char* temp = newTempVar();
          quadr((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(1) - (5)].str), temp);
          (yyval.str) = temp;
          ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 217 "synt.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);   strcpy(svcst,(yyvsp[(1) - (1)].str));strcpy(svtype,(yyvsp[(1) - (1)].str));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 218 "synt.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);   strcpy(svcst,(yyvsp[(1) - (1)].str)); strcpy(svtype,"INTEGER");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 219 "synt.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);   strcpy(svcst,(yyvsp[(1) - (1)].str));strcpy(svtype,"FLOAT");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 220 "synt.y"
    { (yyval.str) = (yyvsp[(1) - (4)].str);   strcpy(svcst,(yyvsp[(1) - (4)].str));strcpy(svtype,(yyvsp[(1) - (4)].str));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 225 "synt.y"
    { quadr("BR", "", (yyvsp[(3) - (4)].str), "");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 229 "synt.y"
    { (yyval.str) = "-"; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 230 "synt.y"
    { (yyval.str) = "+"; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 231 "synt.y"
    { (yyval.str) = "/"; strcpy(svop,(yyvsp[(1) - (1)].str)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 232 "synt.y"
    { (yyval.str) = "*"; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 234 "synt.y"
    {char* temp = newTempVar(); 
            quadL(1, (yyvsp[(2) - (2)].str),"", temp); 
            (yyval.str) = temp;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 238 "synt.y"
    {
    quadr("BZ", " ", (yyvsp[(1) - (3)].str)," ");        
    quadr("BZ", " ", (yyvsp[(3) - (3)].str)," ");   
     char* temp = newTempVar(); 
            quadL(2, (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;     
     ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 245 "synt.y"
    {
    quadr("BZ", "", (yyvsp[(1) - (3)].str)," ");        
    quadr("BZ", " ", (yyvsp[(3) - (3)].str)," ");   
     char* temp = newTempVar(); 
            quadL(3, (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;     
     ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 256 "synt.y"
    {
            char* temp = newTempVar(); 
            quadC(1, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;
        ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 261 "synt.y"
    {
            char* temp = newTempVar(); 
            quadC(2, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;
        ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 266 "synt.y"
    {
            char* temp = newTempVar(); 
            quadC(3, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;
        ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 271 "synt.y"
    {
            char* temp = newTempVar(); 
            quadC(4, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;
        ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 276 "synt.y"
    {
            char* temp = newTempVar(); 
            quadC(5, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;
        ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 281 "synt.y"
    {
            char* temp = newTempVar(); 
            quadC(6, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp); 
            (yyval.str) = temp;
        ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 286 "synt.y"
    {
            (yyval.str) = (yyvsp[(1) - (1)].str); 
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 1969 "synt.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 292 "synt.y"

int main()
{yyparse();
afficher();
afficher_qdr();
  return 0;
}

int yywrap()
{
return 1;
}


void yyerror(const char *s){
printf("Error: %s ligne %d colonne %d sur l'entite %s\n",s,nb_ligne, Col, yytext ? yytext :"unknown");
}
