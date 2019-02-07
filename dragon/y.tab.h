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
    ASSIGNOP = 270,
    ID = 271,
    INUM = 272,
    RNUM = 273,
    RELOP = 274,
    EQ = 275,
    NE = 276,
    LT = 277,
    LE = 278,
    GT = 279,
    GE = 280,
    ADDOP = 281,
    PLUS = 282,
    MINUS = 283,
    OR = 284,
    MULOP = 285,
    STAR = 286,
    SLASH = 287,
    AND = 288,
    IF = 289,
    THEN = 290,
    ELSE = 291,
    WHILE = 292,
    DO = 293
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
#define ASSIGNOP 270
#define ID 271
#define INUM 272
#define RNUM 273
#define RELOP 274
#define EQ 275
#define NE 276
#define LT 277
#define LE 278
#define GT 279
#define GE 280
#define ADDOP 281
#define PLUS 282
#define MINUS 283
#define OR 284
#define MULOP 285
#define STAR 286
#define SLASH 287
#define AND 288
#define IF 289
#define THEN 290
#define ELSE 291
#define WHILE 292
#define DO 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "pc.y" /* yacc.c:1909  */

    int ival;   /* INUM */
    float rval; /* RNUM */
    int opval;  /* RELOP ADDOP MULOP */
    char *sval; /*ID */

#line 137 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
