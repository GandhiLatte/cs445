%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"
#include "tree.h"
#include "scope.h"
#include "y.tab.h"    

extern int yylex();
extern int yyerror(char *);
extern scope_t *top_scope;
extern void spacing();
extern void leave();

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

/* %token  SUBPROGRAM
%token  IDLIST
%token  DECLARATION
%token  TYPES
%token  ARGS
%token  PARAMLIST
%token  COMPSTMT
%token  OPTSTMT
%token  STMTLIST
%token  STM
%token  PROCSTMT
%token  EXPRLIST
%token  EXPR
%token  SIMPEXPR
%token  TERMAN
%token  FACT

 */

%type <tval>    statement_list
%type <tval>    statement
%type <tval>    compound_statement
%type <tval>    optional_statements
%type <tval>    variable
%type <tval>    procedure_statement
%type <tval>    identifier_list
%type <tval>    type    

%type <tval>    expression
%type <tval>    expression_list
%type <tval>    simple_expression
%type <tval>    term
%type <tval>    factor
 
%type <tval>    declarations
%type <tval>    subprogram_declarations
%type <tval>    subprogram_declaration  
//%type <tval>    subprogram_head




%%

program:
     PROGRAM ID '(' identifier_list ')' ';'
     declarations
     subprogram_declarations
     compound_statement
     '.'
     {
         //mkprog(type,ID, IDlist, declarations, subprogram, compstmt)
         //node_t *name = mknode($2);
         //tree_t *money = mkprog(PROGRAM,name,$4,$7,$8,$9);
         //tree_print(money);
         
     }
    ;

identifier_list: ID
        {
            if(scope_search(top_scope,$1) != NULL)
            {
                yyerror("ID already declared");
                exit(1);
            } else {
                $$ = mkid(scope_insert(top_scope, $1)); 
            }
        }
    | identifier_list ',' ID
        { 
            if(scope_search(top_scope,$3) != NULL)
            {
                yyerror("ID already declared");
                exit(1);
            } else {
                $$ = mktree(COMMA,$1,mkid(scope_insert(top_scope,$3)));
            }
        }
    ;

declarations: declarations VAR identifier_list ':' type ';'
        { /* add_type_information($3,$5); */
            // this is where we are going to add type addressing
            $$ = mktree(VAR, $1, $3);
        }
    | /*empty*/
        { $$ = NULL; }
    ;

type: standard_type
      { $$ = NULL; }
    | ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
      { 
        //makes an tree with array as ID and left and right bounds as leafs
        $$ = mkarray(ARRAY,$3,$5); 
      }
    ;
    
standard_type: INTEGER
    | REAL
    ;

subprogram_declarations: subprogram_declarations subprogram_declaration ';'
    {
        //$$ = mktree(SUBPROGRAM, $1,$2);
        $$ = NULL;
    }
    | /*empty*/
    {
        $$ = NULL;
    }
    ;

/* deleted something here, anotehr thing of subprogram declarations */
subprogram_declaration: subprogram_head declarations compound_statement
    {
        //$$ = mksubprog(PROGRAM,$1,$2,$3);
        $$ = NULL;  
    }
    ;

/* either a function of a procedure */
subprogram_head: FUNCTION ID 

    arguments ':' standard_type ';'

    | PROCEDURE ID
    {
        scope_t *tmp = top_scope;
        top_scope = push_scope(tmp);
    }
    arguments ';'
    ;

arguments:'(' parameter_list ')'
    | /* empty */
    ;

parameter_list: identifier_list ':' type
    | parameter_list ';' identifier_list ':' type
    ;

compound_statement: BBEGIN optional_statements END
        { $$ = $2; }
    ;

optional_statements: statement_list
    { 
        // if there is then we must go deeper    
        $$ = $1;

    }
    | /*empty */ 
    { 
        // if there is nothing b/w begin and end then just pop
        scope_t *tmp = top_scope;
        top_scope = pop_scope(tmp);
        $$ = NULL;
    }
    ;

statement_list: statement 
    {
        $$ = $1;
        scope_t *tmp = top_scope;
        top_scope = pop_scope(tmp);
    }
    | statement_list ';' statement { $$ = mktree(COMMA,$1,$3); }
    ;

statement: variable ASSIGNOP expression 
    {
        $$ = mktree(ASSIGNOP,$1,$3); 
    }
    | procedure_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | IF expression THEN statement ELSE statement
      { $$ = mktree(IF,$2,mktree(THEN,$4,$6)); }
    | WHILE expression DO statement
      { $$ = mktree(WHILE,$2,$4); }
    ;

/* Matched and unmatched statement for dangling else problem
    Example is in Dragon in chapter 3 */

variable: ID
    {
        node_t *tmp = scope_search_all(top_scope,$1);
        if(tmp == NULL)
        {
            yyerror("ID not found");
            exit(1);
        } else {
            $$ = mkid(tmp);
        }
    }
    | ID '[' expression ']' 
    {
        node_t *tmp = scope_search_all(top_scope,$1);
        if(tmp == NULL)
        {
            yyerror("Array ID not found");
            exit(1);
        }
        $$ = mktree(ARRAY_ACCESS,mkid(tmp), $3);
    }
    ;

procedure_statement: ID { $$ = mkid(scope_search_all(top_scope,$1));}
    | ID '(' expression_list ')' { $$ = mktree(PROCEDURE_CALL,mkid(scope_search_all(top_scope,$1)),$3);}
    ;

expression_list: expression { $$ = $1; }
    | expression_list ',' expression { $$ = mktree(COMMA,$1,$3); }
    ;

expression: simple_expression { $$ = $1; }
    | simple_expression RELOP simple_expression 
    {
        $$ = mkop(RELOP,$2,$1,$3);
    }
    ;

simple_expression: term { $$ = $1; }
    | ADDOP term { $$ = mkop(ADDOP,$1,$2,NULL); }
    | simple_expression ADDOP term { $$ = mkop(ADDOP,$2,$1,$3);}
    ;

term: factor { $$ = $1; } 
    | term MULOP factor { $$ = mkop(MULOP,$2,$1,$3); }
    ;

factor: ID { $$ = mkid(scope_search_all(top_scope,$1));}
    | ID '[' expression ']' { $$ = mktree(ARRAY_ACCESS,mkid(scope_search_all(top_scope,$1)),$3); }
    | ID '(' expression_list ')' { $$ = mktree(FUNCTION_CALL,mkid(scope_search_all(top_scope,$1)),$3); }
    | INUM { $$ = mkinum($1); $$->attribute.ival = $1; }
    | RNUM { $$ = mkrnum($1); $$->attribute.rval = $1; }
    | '(' expression ')' { $$ = $2; }
    | NOT factor { $$ = mktree(NOT,$2,NULL);}
    ;


%%
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


