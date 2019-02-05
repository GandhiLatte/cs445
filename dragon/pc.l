%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
%}

number      [0-9]+
ident       [A-Za-z][A-Za-z0-9]*

%%


"program"   {return PROGRAM; }
"var"       {return VAR; }
"array"     {return ARRAY; }
"of"        {return OF; }
"procedure" {return PROCEDURE; }
"function"  {return FUNCTION; }
"begin"     {return BBEGIN; }
"end"       {return END; }

".."        {return DOTDOT; }
{number}    {return NUM; }
{ident}     {return ID; }

";"         {return yytext[0];}
.           {return yytext[0];}

%%

int yyerror( char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
}