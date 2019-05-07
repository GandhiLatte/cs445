/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 19 "pc.y" /* yacc.c:1909  */

    int ival;   /* INUM */
    float rval; /* RNUM */
    int opval;  /* RELOP ADDOP MULOP */     /*value relevant b/w parser and scanner */
    char *sval; /*ID */
    /**********************************/

    arglist_t *aval;    
    tree_t *tval; /* tree struct */         /* syntax tree */

#line 161 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
