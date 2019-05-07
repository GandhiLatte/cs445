%{
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

%}

%union {
    int ival;   /* INUM */
    float rval; /* RNUM */
    int opval;  /* RELOP ADDOP MULOP */     /*value relevant b/w parser and scanner */
    char *sval; /*ID */
    /**********************************/

    arglist_t *aval;    
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

%token  <opval> EXP
%token  CARROT

%token  IF THEN ELSE WHILE DO 
%token  FOR TO
%token  ARRAY_ACCESS
%token  FUNCTION_CALL
%token  PROCEDURE_CALL

%token  PARAMLIST

/* %token  SUBPROGRAM
%token  IDLIST
%token  DECLARATION
%token  TYPES
%token  ARGS

%token  COMPSTMT%type <aval>   
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
//%type <tval>    type       
%type <tval>    expression
%type <tval>    expression_list
%type <tval>    simple_expression
%type <tval>    term
%type <tval>    factor
 
// %type <tval>    declarations
%type <aval>    parameter_list
%type <aval>    arguments
%type <tval>    subprogram_declarations
%type <tval>    subprogram_declaration  
%type <tval>    subprogram_head
%type <tval>    standard_type
%type <tval>    type
 




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
            //$$ = mktree(VAR, $1, $3);
            /* 
            for identfiier list
                add type to each members node or tree? def not tree
            call func passing tree and type;
                func finds each ID in scope
                sets node->type->type */
            add_typing(top_scope,$3,$5);
        }
    | /*empty*/
    ;

type: standard_type
      { $$ = $1; }
    | ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
      { 
        //makes an tree with array as ID and left and right bounds as leafs
        //probably should add 4th argument to array to accept type*
        int type;
        tree_t *st = $8;
        type = st->type;
        // arrays have two inums on the bottom left
        tree_t *tree = mkarray(type,$3,$5); 
        $$ = tree;
      }
    ;
    
standard_type: INTEGER
    {
        $$ = mktree(INUM,NULL,NULL);
    }
    | REAL
    {
        $$ = mktree(RNUM,NULL,NULL);
    }
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
        tree_t *t = $1;
        if(t->type = FUNCTION)
        {

        }
        else if(t->type = PROCEDURE)
        {

        }
        else {
            yyerror("Error in Suprogram Head");
        }

        scope_t *tmp = top_scope;
        top_scope = pop_scope(tmp);
        $$ = NULL;  
    }
    ;

/* either a function of a procedure */
subprogram_head: FUNCTION ID
    {
        if(scope_search(top_scope,$2) != NULL)
        {
            yyerror("Variable Redclared (Function)");
            exit(1);
        }
        mkid(scope_insert(top_scope,$2));
        scope_t *tmp = top_scope;
        top_scope = push_scope(tmp);
    } 
    arguments ':' standard_type ';'
    {
        // how to enter in the types and the other stuff to thing in a scope that we can't see.
        // could just go next scope and look at that.
        //
        
        arglist_t *args = $4;
        int num = args->num;
        tree_t *type_tree = $6;
        int type = type_tree->type;

        scope_insert_func(top_scope->next,$2,type,num,args);


        $$ = mktree(FUNCTION, NULL, NULL);
    }
    | PROCEDURE ID 
    {
        if(scope_search(top_scope,$2) != NULL)
        {
            yyerror("Variable Redclared (Procedure)");
            exit(1);
        }
        mkid(scope_insert(top_scope,$2));
        scope_t *tmp = top_scope;
        top_scope = push_scope(tmp);
        //argumetns is returning arglist_t
        $$ = mktree(PROCEDURE, NULL,NULL);
    }
    ;


/* return arglist type */
arguments:'(' parameter_list ')'
    {
        $$ = $2;
    }
    | /* empty */
    {
        $$ = NULL;
    }
    ;

/* returning a arglist type */
parameter_list: identifier_list ':' type
    {
        $$ = mkarglist($1,$3);
    }
    | parameter_list ';' identifier_list ':' type
    {
        $$ = merge_list($1,mkarglist($3,$5));
    }
    ;

compound_statement: BBEGIN optional_statements END
        {
            $$ = $2;
        }

    ;

optional_statements: statement_list
    { 
        // if there is then we must go deeper    
        $$ = $1;
    }
    | /*empty */ 
    { 
        // if there is nothing b/w begin and end then just pop
        $$ = NULL;
    }
    ;

statement_list: statement 
    {
        $$ = $1;
    }
    | statement_list ';' statement { $$ = mktree(COMMA,$1,$3); }
    ;

statement: variable ASSIGNOP expression 
    {
        tree_t *var = $1;
        node_t *vartype = var->attribute.sval;
        
        if(vartype->id_type != typechecker($3))
        {
            yyerror("Mismatched Types in ASSIGNOP");
            exit(1);
        }
        $$ = mktree(ASSIGNOP,$1,$3); 
    }
    | procedure_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | IF expression THEN statement ELSE statement
      { $$ = mktree(IF,$2,mktree(THEN,$4,$6)); }
    | WHILE expression DO statement
      { $$ = mktree(WHILE,$2,$4); }
    | FOR statement TO expression DO statement
    {
        if(typechecker($2) != INUM)
        {
            yyerror("Index Requires Integer");
            exit(1);
        } else if(typechecker($4) != INUM)
        {
            yyerror("Index Requires Integer");
            exit(1);
        } else{
            $$ = mktree(FOR,$2,$4);
        }
    }
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
        if(typechecker($3) != INUM)
        {
            yyerror("Array Access expression not an integer");
            exit(1);
        }
        $$ = mktree(ARRAY_ACCESS,mkid(tmp), $3);
    }
    ;

procedure_statement: ID { $$ = mkid(scope_search_all(top_scope,$1));}
    | ID '(' expression_list ')' 
    {
        $$ = mktree(PROCEDURE_CALL,mkid(scope_search_all(top_scope,$1)),$3);
    }
    ;

expression_list: expression { $$ = $1; }
    | expression_list ',' expression { $$ = mktree(COMMA,$1,$3); }
    ;

expression: simple_expression 
    {
        int type;
        tree_t *tmp = $1;
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
            $$ = tmp; 
        }

    }
    | simple_expression RELOP simple_expression 
    {
        if(typechecker($1) == 0 || typechecker($3) == 0)
        {
            yyerror("Mismatched Type in Simple Expression");
        }
        if(typechecker($1) == typechecker($3))
        {
            $$ = mkop(RELOP,$2,$1,$3);
        } else
        {
            yyerror("Mismatched Types at relation");
        }
    }
    ;

simple_expression: term { $$ = $1; }
    | ADDOP term { $$ = mkop(ADDOP,$1,$2,NULL); }
    | simple_expression ADDOP term { $$ = mkop(ADDOP,$2,$1,$3);}
    ;

term: factor { $$ = $1; } 
    | term MULOP factor { $$ = mkop(MULOP,$2,$1,$3); }
    ;

factor: ID
    {
        if(scope_search_all(top_scope,$1) == NULL)
        {
            yyerror("ID not declared in Expression");
            exit(1);
        }
        $$ = mkid(scope_search_all(top_scope,$1));
    }
    | ID '[' expression ']' 
    {  
        if(scope_search_all(top_scope,$1) == NULL)
        { 
            yyerror("ID not declared for Array access");
            exit(1);
        }
        $$ = mktree(ARRAY_ACCESS,mkid(scope_search_all(top_scope,$1)),$3); 
    }
    | ID '(' expression_list ')' 
    {
        node_t *name = scope_search_all(top_scope,$1);
        tree_t *expr_list = $3;
        arglist_t *expr_args = list_from_expr(expr_list);
        arglist_t *func_args = name->arglist;
        int winner = compare_lists(expr_args, func_args);
        if(winner == 0)
        {
            yyerror("Type mismatch in function call argmuments");
            exit(1);
        }
        // we have our expr list data 

        // call create arglist  from expr list

        //compare expr list to func id expected list


        if(scope_search_all(top_scope,$1) == NULL)
        {
            yyerror("ID not declared for Function Call");
            exit(1);
        }
        $$ = mktree(FUNCTION_CALL,mkid(scope_search_all(top_scope,$1)),$3); 
    }
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


