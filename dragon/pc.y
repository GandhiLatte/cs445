%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "y.tab.h"    

extern int yylex();
extern int yyerror(char *);

%}

%union {
    int ival;   /* INUM */
    float rval; /* RNUM */
    int opval;  /* RELOP ADDOP MULOP */     /*value relevant b/w parser and scanner */
    char *sval; /*ID */
    /**********************************/

    
    tree_t *tval; /* tree struct */         /* syntax tree */
}

%token  PROGRAM
%token  BBEGIN END
%token  VAR
%token  PROCEDURE FUNCTION
%token  ARRAY OF
%token  INTEGER REAL
%token  DOTDOT
%token  NOT
%token  COMMA

%token  <sval> ID
%token  <ival> INUM
%token  <rval> RNUM

%token  ASSIGNOP

%token  <opval> RELOP
%token  EQ NE LT LE GT GE

%token  <opval> ADDOP
%token  PLUS MINUS OR

%token  <opval> MULOP
%token  STAR SLASH AND

%token  IF THEN ELSE WHILE DO
%token  ARRAY_ACCESS
%token  FUNCTION_CALL
%token  PROCEDURE_CALL

%type <tval>    statement_list
%type <tval>    statement
%type <tval>    compound_statement
%type <tval>    optional_statements
%type <tval>    variable
%type <tval>    procedure_statement
%type <tval>    

%type <tval>    expression
%type <tval>    expression_list
%type <tval>    simple_expression
%type <tval>    term
%type <tval>    factor
 

%%

program:
    | PROGRAM ID '(' identifier_list ')' ';'
     declarations
     subprogram_declarations
     compound_statement
     '.'
    ;

identifier_list:
    | ID
      { $$ = mkid(scope_insert($1)); }
    | identifier_list ',' ID
      { $$ = mktree(COMMA,$1,mkid(scope_insert($3))); }
    ;

declarations:
    | declarations VAR identifier_list ':' type ';'
      { /* add_type_information($3,$5); */ }
    | /*empty*/
    ;

type:
    | standard_type
      { $$ = NULL; }
    | ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
      { $$ = NULL; }
    | ARRAY '[' RNUM DOTDOT RNUM ']' OF standard_type
    ;
    
standard_type:
    | INTEGER
    | REAL
    ;

subprogram_declarations:
    | subprogram_declarations subprogram_declaration ';'
    | /*empty*/
    ;

subprogram_declaration:     
    | subprogram_head declarations subprogram_declarations  compound_statement
    ;

subprogram_head:
    | FUNCTION ID arguments ':' standard_type ';'
    | PROCEDURE ID arguments ';'
    ;

arguments:
    | '(' parameter_list ')'
    | /* empty */
    ;

parameter_list:
    | identifier_list ':' type
    | parameter_list ';' identifier_list ':' type
    ;

compound_statement:
    | BBEGIN optional_statements END { $$ = $2; }
    ;

optional_statements:
    | statement_list { $$ = $1; }
    | /*empty */ { $$ = NULL; }
    ;

statement_list:
    | statement { $$ = $1;}
    | statement_list ';' statement { $$ = mktree(COMMA,$1,$3); }
    ;

statement:
    | variable ASSIGNOP expression { $$ = mktree(ASSIGNOP,$1,$3); }
    | procedure_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | IF expression THEN statement ELSE statement
      { $$ = mktree(IF,$2,mktree(THEN,$4,$6)); }
    | WHILE expression DO statement
      { $$ = mktree(WHILE,$2,$4); }
    ;

/* Matched and unmatched statement for dangling else problem
    Example is in Dragon in chapter 3 */

variable:
    | ID { $$ = mkid(scope_search_all(top_scope,$1));}
    | ID '[' expression ']' { $$ = mktree(ARRAY_ACCESS,mkid(scope_search_all(top_scope,$1)), $3);}
    ;

procedure_statement:
    | ID { $$ = mkid(scope_search_all(top_scope,$1));}
    | ID '(' expression_list ')' { $$ = mktree(PROCEDURE_CALL,mkid(scope_search_all(top_scope,$1)),$3);}
    ;

expression_list:
    | expression { $$ = $1; }
    | expression_list ',' expression { $$ = mktree(COMMA,$1,$3); }
    ;

expression:
    | simple_expression { $$ = $1; }
    | simple_expression RELOP simple_expression { $$ = mkop(RELOP,$2,$1,$3);}
    ;

simple_expression:
    | term { $$ = $1; }
    | ADDOP term { $$ = mkop(ADDOP,$1,$2,NULL); }
    | simple_expression ADDOP term { $$ = mkop(ADDOP,$2,$1,$3);}
    ;

term:
    | factor { $$ = $1; } 
    | term MULOP factor { $$ = mkop(MULOP,$2,$1,$3) }
    ;

factor:
    | ID { $$ = mkid(scope_search_all(top_scope,$1));}
    | ID '[' expression ']' { $$ = mktree(ARRAY_ACCESS,mkid(scope_search_all(top_scope,$1)),$3); }
    | ID '(' expression_list ')' { $$ = mktree(FUNCTION_CALL,mkid(scope_search_all(top_scope,$1)),$3); }
    | INUM { $$ = mkinum($1); $$->attribute.ival = $1; }
    | RNUM { $$ = mkrnum($1); $$->attribute.rval = $1; }
    | '(' expression ')' { $$ = $2; }
    | NOT factor { $$ = mktree(NOT,$2,NULL)''}
    ;

%%

int main()
{
    yyparse();
}


