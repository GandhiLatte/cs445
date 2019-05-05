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
    ASSIGNOP = 274,
    RELOP = 275,
    EQ = 276,
    NE = 277,
    LT = 278,
    LE = 279,
    GT = 280,
    GE = 281,
    ADDOP = 282,
    PLUS = 283,
    MINUS = 284,
    OR = 285,
    MULOP = 286,
    STAR = 287,
    SLASH = 288,
    AND = 289,
    IF = 290,
    THEN = 291,
    ELSE = 292,
    WHILE = 293,
    DO = 294,
    ARRAY_ACCESS = 295,
    FUNCTION_CALL = 296,
    PROCEDURE_CALL = 297
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
#define ASSIGNOP 274
#define RELOP 275
#define EQ 276
#define NE 277
#define LT 278
#define LE 279
#define GT 280
#define GE 281
#define ADDOP 282
#define PLUS 283
#define MINUS 284
#define OR 285
#define MULOP 286
#define STAR 287
#define SLASH 288
#define AND 289
#define IF 290
#define THEN 291
#define ELSE 292
#define WHILE 293
#define DO 294
#define ARRAY_ACCESS 295
#define FUNCTION_CALL 296
#define PROCEDURE_CALL 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "pc.y" /* yacc.c:1909  */

    int ival;   /* INUM */
    float rval; /* RNUM */
    int opval;  /* RELOP ADDOP MULOP */     /*value relevant b/w parser and scanner */
    char *sval; /*ID */
    /**********************************/

    
    tree_t *tval; /* tree struct */         /* syntax tree */

#line 149 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
