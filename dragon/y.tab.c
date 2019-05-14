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
#line 1 "pc.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"
#include "tree.h"
#include "scope.h"
#include "semantics.h"
#include "y.tab.h"    

extern int yylex();
extern int yyerror(char *);
extern scope_t *top_scope;
extern void spacing();
extern void leave();


#line 84 "y.tab.c" /* yacc.c:339  */

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
    PROGRAM = 258,
    BBEGIN = 259,
    END = 260,
    VAR = 261,
    PROCEDURE = 262,
    FUNCTION = 263,
    ARRAY = 264,
    OF = 265,
    INTEGER = 266,
    REAL = 267,
    DOTDOT = 268,
    NOT = 269,
    COMMA = 270,
    ID = 271,
    INUM = 272,
    RNUM = 273,
    BOUND = 274,
    ASSIGNOP = 275,
    RELOP = 276,
    EQ = 277,
    NE = 278,
    LT = 279,
    LE = 280,
    GT = 281,
    GE = 282,
    ADDOP = 283,
    PLUS = 284,
    MINUS = 285,
    OR = 286,
    MULOP = 287,
    STAR = 288,
    SLASH = 289,
    AND = 290,
    EXP = 291,
    CARROT = 292,
    IF = 293,
    THEN = 294,
    ELSE = 295,
    WHILE = 296,
    DO = 297,
    FOR = 298,
    TO = 299,
    ARRAY_ACCESS = 300,
    FUNCTION_CALL = 301,
    PROCEDURE_CALL = 302,
    PARAMLIST = 303
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define BBEGIN 259
#define END 260
#define VAR 261
#define PROCEDURE 262
#define FUNCTION 263
#define ARRAY 264
#define OF 265
#define INTEGER 266
#define REAL 267
#define DOTDOT 268
#define NOT 269
#define COMMA 270
#define ID 271
#define INUM 272
#define RNUM 273
#define BOUND 274
#define ASSIGNOP 275
#define RELOP 276
#define EQ 277
#define NE 278
#define LT 279
#define LE 280
#define GT 281
#define GE 282
#define ADDOP 283
#define PLUS 284
#define MINUS 285
#define OR 286
#define MULOP 287
#define STAR 288
#define SLASH 289
#define AND 290
#define EXP 291
#define CARROT 292
#define IF 293
#define THEN 294
#define ELSE 295
#define WHILE 296
#define DO 297
#define FOR 298
#define TO 299
#define ARRAY_ACCESS 300
#define FUNCTION_CALL 301
#define PROCEDURE_CALL 302
#define PARAMLIST 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "pc.y" /* yacc.c:355  */

    int ival;   /* INUM */
    float rval; /* RNUM */
    int opval;  /* RELOP ADDOP MULOP */     /*value relevant b/w parser and scanner */
    char *sval; /*ID */
    /**********************************/

    arglist_t *aval;    
    tree_t *tval; /* tree struct */         /* syntax tree */

#line 231 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "y.tab.c" /* yacc.c:358  */

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
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      49,    50,     2,     2,    53,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   132,   142,   154,   166,   169,   171,   187,
     191,   197,   203,   209,   252,   251,   280,   279,   306,   311,
     317,   321,   327,   334,   340,   346,   350,   353,   366,   367,
     368,   370,   372,   391,   402,   419,   420,   426,   427,   430,
     449,   465,   466,   467,   470,   471,   474,   475,   478,   487,
     496,   516,   517,   518,   519
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BBEGIN", "END", "VAR",
  "PROCEDURE", "FUNCTION", "ARRAY", "OF", "INTEGER", "REAL", "DOTDOT",
  "NOT", "COMMA", "ID", "INUM", "RNUM", "BOUND", "ASSIGNOP", "RELOP", "EQ",
  "NE", "LT", "LE", "GT", "GE", "ADDOP", "PLUS", "MINUS", "OR", "MULOP",
  "STAR", "SLASH", "AND", "EXP", "CARROT", "IF", "THEN", "ELSE", "WHILE",
  "DO", "FOR", "TO", "ARRAY_ACCESS", "FUNCTION_CALL", "PROCEDURE_CALL",
  "PARAMLIST", "'('", "')'", "';'", "'.'", "','", "':'", "'['", "']'",
  "$accept", "program", "identifier_list", "declarations", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "$@1", "$@2", "arguments", "parameter_list",
  "compound_statement", "optional_statements", "statement_list",
  "statement", "variable", "procedure_statement", "expression_list",
  "expression", "simple_expression", "term", "simple_term", "factor", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    40,
      41,    59,    46,    44,    58,    91,    93
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -34

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      23,    15,    48,    12,   -93,    53,   -93,   -17,    24,    61,
     -93,   -93,    70,    53,    49,   -29,     2,    62,    63,    29,
     -93,    30,    51,    -3,    -7,    -7,     2,   -93,    76,    32,
     -93,    66,   -93,   -93,   -93,   -93,    70,   -93,    33,   -93,
     -93,    36,   -93,    -7,    -7,    -2,   -27,   -93,   -93,    -2,
      -7,    50,    -1,    58,    55,   -93,    52,    54,   -93,     2,
      -7,    43,    43,    49,    78,   -93,    -9,   -93,    37,   -93,
      -7,    -7,    58,    46,     2,    -7,    -2,    -2,    -2,     2,
      -7,   -93,   -93,    53,    56,    45,   -93,    84,   -93,    -7,
     -93,     5,    47,   -93,    64,    73,    58,   -93,   -93,   -93,
      67,    11,    16,   -93,    60,    85,   -93,   -93,   -93,     2,
       2,    51,   -93,    53,    57,    59,   -93,   -93,   -93,    20,
     -93,    95,    51,    60,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       6,     4,    12,     0,     0,     0,    24,     0,     0,     0,
       6,     0,     0,    35,     0,     0,     0,    29,     0,    23,
      25,     0,    28,    16,    14,    11,    12,     2,     0,     9,
      10,     0,     7,     0,     0,     0,    48,    51,    52,     0,
       0,     0,    39,    41,    44,    46,     0,     0,    22,     0,
       0,    19,    19,     0,     0,     5,     0,    37,     0,    54,
       0,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,    13,     0,    36,     0,
      34,     0,     0,    53,     0,    40,    43,    45,    47,    31,
       0,     0,     0,    17,     0,     0,    38,    50,    49,     0,
       0,     0,    18,     0,     0,     0,    30,    32,    20,     0,
      15,     0,     0,     0,    21,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -13,    86,   -92,   -91,    74,   -93,   -93,   -93,
     -93,    65,   -93,   -12,   -93,   -93,   -25,   -93,   -93,    41,
     -21,    38,   -41,   -93,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    41,    42,    14,    19,    20,    62,
      61,    84,   102,    27,    28,    29,    30,    31,    32,    66,
      67,    52,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    57,    21,    51,    56,    69,    16,    45,    72,    46,
      47,    48,    45,   114,    46,    47,    48,   -33,    23,   118,
      75,    49,    70,    68,     9,    22,     1,    76,    71,    73,
     124,     3,   125,     8,    81,    96,     9,    97,    98,    82,
      24,    88,    50,    25,    89,    26,    43,    50,     4,    94,
      92,    86,    44,    16,    99,   107,    17,    18,    89,   100,
      38,     5,    39,    40,     9,   111,   112,   113,   106,     6,
     101,    39,    40,     9,   122,    10,    13,    11,    33,    34,
      35,    58,    37,    59,   116,   117,    60,    65,    64,    74,
      77,    78,    83,    90,    79,    87,    93,   105,    80,   104,
     119,    76,   115,   108,   109,   123,    36,   103,   120,   110,
      63,    91,     0,    95,     0,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85
};

static const yytype_int8 yycheck[] =
{
      13,    26,    14,    24,    25,    45,     4,    14,    49,    16,
      17,    18,    14,   104,    16,    17,    18,    20,    16,   111,
      21,    28,    49,    44,    53,    54,     3,    28,    55,    50,
     122,    16,   123,    50,    59,    76,    53,    77,    78,    60,
      38,    50,    49,    41,    53,    43,    49,    49,     0,    74,
      71,    63,    55,     4,    79,    50,     7,     8,    53,    80,
       9,    49,    11,    12,    53,    54,    50,    51,    89,    16,
      83,    11,    12,    53,    54,    51,     6,    16,    16,    16,
      51,     5,    52,    51,   109,   110,    20,    51,    55,    39,
      32,    36,    49,    56,    42,    17,    50,    13,    44,    54,
     113,    28,    17,    56,    40,    10,    20,    51,    51,    42,
      36,    70,    -1,    75,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    58,    16,     0,    49,    16,    59,    50,    53,
      51,    16,    60,     6,    63,    59,     4,     7,     8,    64,
      65,    70,    54,    16,    38,    41,    43,    70,    71,    72,
      73,    74,    75,    16,    16,    51,    60,    52,     9,    11,
      12,    61,    62,    49,    55,    14,    16,    17,    18,    28,
      49,    77,    78,    79,    80,    81,    77,    73,     5,    51,
      20,    67,    66,    63,    55,    51,    76,    77,    77,    81,
      49,    55,    79,    77,    39,    21,    28,    32,    36,    42,
      44,    73,    77,    49,    68,    68,    70,    17,    50,    53,
      56,    76,    77,    50,    73,    78,    79,    81,    81,    73,
      77,    59,    69,    51,    54,    13,    77,    50,    56,    40,
      42,    54,    50,    51,    62,    17,    73,    73,    61,    59,
      51,    56,    54,    10,    61,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    66,    65,    67,    65,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    81,    81,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     3,     0,     4,     0,     7,     0,     5,     3,     0,
       3,     5,     3,     1,     0,     1,     3,     3,     1,     1,
       6,     4,     6,     1,     4,     1,     4,     1,     3,     1,
       3,     1,     2,     3,     1,     3,     1,     3,     1,     4,
       4,     1,     1,     3,     2
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
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
yystrlen (const char *yystr)
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
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
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
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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
yyparse (void)
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

  YYDPRINTF ((stderr, "Starting parse\n"));

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
      yychar = yylex ();
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
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 123 "pc.y" /* yacc.c:1646  */
    {
         //mkprog(type,ID, IDlist, declarations, subprogram, compstmt)
         //node_t *name = mknode($2);
         //tree_t *money = mkprog(PROGRAM,name,$4,$7,$8,$9);
         //tree_print(money);
         
     }
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 133 "pc.y" /* yacc.c:1646  */
    {
            if(scope_search(top_scope,(yyvsp[0].sval)) != NULL)
            {
                yyerror("ID already declared");
                exit(1);
            } else {
                (yyval.tval) = mkid(scope_insert(top_scope, (yyvsp[0].sval))); 
            }
        }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "pc.y" /* yacc.c:1646  */
    { 
            if(scope_search(top_scope,(yyvsp[0].sval)) != NULL)
            {
                yyerror("ID already declared");
                exit(1);
            } else {
                (yyval.tval) = mktree(COMMA,(yyvsp[-2].tval),mkid(scope_insert(top_scope,(yyvsp[0].sval))));
            }
        }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 155 "pc.y" /* yacc.c:1646  */
    { /* add_type_information($3,$5); */
            // this is where we are going to add type addressing
            //$$ = mktree(VAR, $1, $3);
            /* 
            for identfiier list
                add type to each members node or tree? def not tree
            call func passing tree and type;
                func finds each ID in scope
                sets node->type->type */
            add_typing(top_scope,(yyvsp[-3].tval),(yyvsp[-1].tval));
        }
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 170 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 172 "pc.y" /* yacc.c:1646  */
    { 
        //makes an tree with array as ID and left and right bounds as leafs
        //probably should add 4th argument to array to accept type*
/*         int type;
        tree_t *st = $8;
        type = st->type;
        // arrays have two inums on the bottom left
        tree_t *tree = mkarray(type,$3,$5); 
        $$ = tree; */


        (yyval.tval) = mkarray((yyvsp[-5].ival),(yyvsp[-3].ival),(yyvsp[0].tval));
      }
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 188 "pc.y" /* yacc.c:1646  */
    {
        (yyval.tval) = mktree(INUM,NULL,NULL);
    }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 192 "pc.y" /* yacc.c:1646  */
    {
        (yyval.tval) = mktree(RNUM,NULL,NULL);
    }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 198 "pc.y" /* yacc.c:1646  */
    {
        //$$ = mktree(SUBPROGRAM, $1,$2);
        (yyval.tval) = NULL;
    }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 203 "pc.y" /* yacc.c:1646  */
    {
        (yyval.tval) = NULL;
    }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "pc.y" /* yacc.c:1646  */
    {
        tree_t *cmp = (yyvsp[0].tval);
        //$$ = mksubprog(PROGRAM,$1,$2,$3);
        tree_t *t = (yyvsp[-3].tval);
        if(t->type == FUNCTION)
        {   
            tree_t *t = (yyvsp[-3].tval);
            node_t *n = t->right->attribute.sval;
            tree_t *ret_type = has_return(top_scope,n,(yyvsp[0].tval));
            if(ret_type == NULL)
            {
                yyerror("No return found");
                exit(1);
            }
        }
        else if(t->type == PROCEDURE)
        {
   
            if(cmp != NULL)
            {
                tree_t *t = (yyvsp[-3].tval);
                node_t *n = t->right->attribute.sval;
                tree_t *ret_type = has_return(top_scope,n,(yyvsp[0].tval));
                if( ret_type != NULL)
                {
                    yyerror("Return found in Procedure");
                }
            }

        }
        else {
            yyerror("Error in Suprogram Head");
            exit(1);
        }
        scope_t *tmp = top_scope;
        top_scope = pop_scope(tmp);
        (yyval.tval) = NULL;  
    }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 252 "pc.y" /* yacc.c:1646  */
    {
        if(scope_search(top_scope,(yyvsp[0].sval)) != NULL)
        {
            yyerror("Variable Redclared (Function)");
            exit(1);
        }
        mkid(scope_insert(top_scope,(yyvsp[0].sval)));
        scope_t *tmp = top_scope;
        top_scope = push_scope(tmp);
    }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 263 "pc.y" /* yacc.c:1646  */
    {
        // how to enter in the types and the other stuff to thing in a scope that we can't see.
        // could just go next scope and look at that.
        //
        arglist_t *args = (yyvsp[-3].aval);
        tree_t *type_tree = (yyvsp[-1].tval);
        int type = type_tree->type;

        scope_t *ts = top_scope;
        node_t *node = scope_insert_func(top_scope->next,(yyvsp[-5].sval),type,args);

        top_scope = ts;


        (yyval.tval) = mktree(FUNCTION, NULL, mkid(node));
    }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 280 "pc.y" /* yacc.c:1646  */
    {
        if(scope_search(top_scope,(yyvsp[0].sval)) != NULL)
        {
            yyerror("Variable Redclared (Procedure)");
            exit(1);
        } 
        mkid(scope_insert(top_scope,(yyvsp[0].sval)));
        scope_t *tmp = top_scope;
        top_scope = push_scope(tmp);

        //argumetns is returning arglist_t
        
    }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 293 "pc.y" /* yacc.c:1646  */
    {
        arglist_t *args = (yyvsp[-1].aval);   

        scope_t *tmps = top_scope;
        node_t *node = scope_insert_proc(top_scope->next,(yyvsp[-3].sval),args);
        top_scope = tmps;

        (yyval.tval) = mktree(PROCEDURE, NULL,mkid(node));
    }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 307 "pc.y" /* yacc.c:1646  */
    {
        (yyval.aval) = (yyvsp[-1].aval);
    }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 311 "pc.y" /* yacc.c:1646  */
    {
        (yyval.aval) = NULL;
    }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 318 "pc.y" /* yacc.c:1646  */
    {
        (yyval.aval) = mkarglist((yyvsp[-2].tval),(yyvsp[0].tval));
    }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 322 "pc.y" /* yacc.c:1646  */
    {
        (yyval.aval) = merge_list((yyvsp[-4].aval),mkarglist((yyvsp[-2].tval),(yyvsp[0].tval)));
    }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 328 "pc.y" /* yacc.c:1646  */
    {
            (yyval.tval) = (yyvsp[-1].tval);
        }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 335 "pc.y" /* yacc.c:1646  */
    { 
        // if there is then we must go deeper    
        (yyval.tval) = (yyvsp[0].tval);
    }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 340 "pc.y" /* yacc.c:1646  */
    { 
        // if there is nothing b/w begin and end then just pop
        (yyval.tval) = NULL;
    }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 347 "pc.y" /* yacc.c:1646  */
    {
        (yyval.tval) = (yyvsp[0].tval);
    }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 350 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mktree(COMMA,(yyvsp[-2].tval),(yyvsp[0].tval)); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 354 "pc.y" /* yacc.c:1646  */
    {
        tree_t *var = (yyvsp[-2].tval);
        node_t *vartype = var->attribute.sval;
        
        if(vartype->id_type != typechecker((yyvsp[0].tval)))
        {
            
            yyerror("Mismatched Types in ASSIGNOP");
            exit(1);
        }
        (yyval.tval) = mktree(ASSIGNOP,(yyvsp[-2].tval),(yyvsp[0].tval)); 
    }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 366 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 367 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 369 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mktree(IF,(yyvsp[-4].tval),mktree(THEN,(yyvsp[-2].tval),(yyvsp[0].tval))); }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 371 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mktree(WHILE,(yyvsp[-2].tval),(yyvsp[0].tval)); }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 373 "pc.y" /* yacc.c:1646  */
    {
        if(typechecker((yyvsp[-4].tval)) != INUM)
        {
            yyerror("Index Requires Integer");
            exit(1);
        } else if(typechecker((yyvsp[-2].tval)) != INUM)
        {
            yyerror("Index Requires Integer");
            exit(1);
        } else{
            (yyval.tval) = mktree(FOR,(yyvsp[-4].tval),(yyvsp[-2].tval));
        }
    }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 392 "pc.y" /* yacc.c:1646  */
    {
        node_t *tmp = scope_search_all(top_scope,(yyvsp[0].sval));
        if(tmp == NULL)
        {
            yyerror("ID not found");
            exit(1);
        } else {
            (yyval.tval) = mkid(tmp);
        }
    }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 403 "pc.y" /* yacc.c:1646  */
    {
        node_t *tmp = scope_search_all(top_scope,(yyvsp[-3].sval));
        if(tmp == NULL)
        {
            yyerror("Array ID not found");
            exit(1);
        }
        if(typechecker((yyvsp[-1].tval)) != INUM)
        {
            yyerror("Array Access expression not an integer");
            exit(1);
        }
        (yyval.tval) = mktree(ARRAY_ACCESS,mkid(tmp), (yyvsp[-1].tval));
    }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mkid(scope_search_all(top_scope,(yyvsp[0].sval)));}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 421 "pc.y" /* yacc.c:1646  */
    {
        (yyval.tval) = mktree(PROCEDURE_CALL,mkid(scope_search_all(top_scope,(yyvsp[-3].sval))),(yyvsp[-1].tval));
    }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 426 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 427 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mktree(COMMA,(yyvsp[-2].tval),(yyvsp[0].tval)); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 431 "pc.y" /* yacc.c:1646  */
    {
        int type;
        tree_t *tmp = (yyvsp[0].tval);
        type = typechecker(tmp);
        if(type == 0)
        {
            yyerror("Mismatched Type in Simple Expression");
            exit(1);
        } /* else if(scope_search_expr(top_scope,tmp) == NULL)
        {
            yyerror("Non-declared var in expression");
            exit(1);
        } */ else{
            tmp->type = type;
            (yyval.tval) = tmp; 
        }

    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 450 "pc.y" /* yacc.c:1646  */
    {
        if(typechecker((yyvsp[-2].tval)) == 0 || typechecker((yyvsp[0].tval)) == 0)
        {
            yyerror("Mismatched Type in Simple Expression");
        }
        if(typechecker((yyvsp[-2].tval)) == typechecker((yyvsp[0].tval)))
        {
            (yyval.tval) = mkop(RELOP,(yyvsp[-1].opval),(yyvsp[-2].tval),(yyvsp[0].tval));
        } else
        {
            yyerror("Mismatched Types at relation");
        }
    }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 465 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 466 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mkop(ADDOP,(yyvsp[-1].opval),(yyvsp[0].tval),NULL); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 467 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mkop(ADDOP,(yyvsp[-1].opval),(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 470 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 471 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mkop(MULOP,(yyvsp[-1].opval),(yyvsp[-2].tval),(yyvsp[0].tval)); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 474 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 475 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mkop(EXP,(yyvsp[-1].opval),(yyvsp[-2].tval),(yyvsp[0].tval)); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 479 "pc.y" /* yacc.c:1646  */
    {
        if(scope_search_all(top_scope,(yyvsp[0].sval)) == NULL)
        {
            yyerror("ID not declared in Expression");
            exit(1);
        }
        (yyval.tval) = mkid(scope_search_all(top_scope,(yyvsp[0].sval)));
    }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 488 "pc.y" /* yacc.c:1646  */
    {  
        if(scope_search_all(top_scope,(yyvsp[-3].sval)) == NULL)
        { 
            yyerror("ID not declared for Array access");
            exit(1);
        } 
        (yyval.tval) = mktree(ARRAY_ACCESS,mkid(scope_search_all(top_scope,(yyvsp[-3].sval))),(yyvsp[-1].tval)); 
    }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 497 "pc.y" /* yacc.c:1646  */
    {
        node_t *name = scope_search_all(top_scope,(yyvsp[-3].sval));
        tree_t *expr_list = (yyvsp[-1].tval);
        arglist_t *expr_args = list_from_expr(expr_list);
        arglist_t *func_args = name->arglist;
        int winner = compare_lists(expr_args, func_args);
        if(winner == 0)
        {
            yyerror("Type mismatch in function call argmuments");
            exit(1);
        }

        if(scope_search_all(top_scope,(yyvsp[-3].sval)) == NULL)
        {
            yyerror("ID not declared for Function Call");
            exit(1);
        }
        (yyval.tval) = mktree(FUNCTION_CALL,mkid(scope_search_all(top_scope,(yyvsp[-3].sval))),(yyvsp[-1].tval)); 
    }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 516 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mkinum((yyvsp[0].ival)); (yyval.tval)->attribute.ival = (yyvsp[0].ival); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 517 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mkrnum((yyvsp[0].rval)); (yyval.tval)->attribute.rval = (yyvsp[0].rval); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 518 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[-1].tval); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 519 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = mktree(NOT,(yyvsp[0].tval),NULL);}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1983 "y.tab.c" /* yacc.c:1646  */
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 523 "pc.y" /* yacc.c:1906  */

scope_t *top_scope;

int main()
{
    top_scope = mkscope();
    yyparse();
}

void spacing()
{
    printf("\n\n\n");
}

void leave()
{
    printf("...Exiting\n\n");
}


