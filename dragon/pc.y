%{
#include <stdio.h>
#include <stdlib0.h>
#include <assert.h>
#include "y.tab.h"    
%}

%token  PROGRAM
%token  BBEGIN END
%token  VAR
%token  PROCEDURE FUNCTION
%token  ARRAY OF
%token 

%%

program 
    :   PROGRAM ID '(' identifier_list ')' ';'  
        declarations
        subprogram_declarations
        compound_statement
        '.'
    ;

identifier_list
    : TD
    | identifier_list ',' ID
    ;

declarations
    : declarations VAR identifier_list ':' type ';'
    | /*empty*/
    ;

type
    : standard_type
    | ARRAY '[' NUM '.' '.' NUM ']' OF standard_type
    ;

%%

int main()
{
    yyparse();
}