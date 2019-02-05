#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "y.tab.h"

extern int yyerror( char *);

/* prototype */
void aux_tree_print( tree_t *, int);

/* constructor */
tree_t *mktree (int type, tree_t *left, tree_t *right)
{
    tree_t *p = (tree_t *)malloc(sizeof(tree_t));
    assert( p != NULL);
    p->type = type;
    p->left = left;
    p->right = right;
    return p;
}

/*auiliary */
int tree_eval( tree_t *t)
{
    assert( t != NULL);


    switch( t-> type )
    {
        case '+':
            return tree_eval( t-> left) + tree_eval( t-> right);
        case '-':
            if(t -> right != NULL)
                return tree_eval( t->left) - tree_eval( t-> right);
            else
                return -tree_eval(t->left);
        case '*':
            return tree_eval( t->left) * tree_eval( t-> right);
        case '/':
            return tree_eval( t->left) / tree_eval( t-> right);       
        case NUM:
            return t->attribute;
        default:
            fprintf(stderr, "Tree Eval: unknown type %d\n", t->type);
            exit(1);
    }    
}

void tree_print( tree_t *t)
{
    aux_tree_print(t, 0);
}

void aux_tree_print( tree_t *t, int spaces)
{
    if( t == NULL) return;

    for( int i = 0; i<spaces; i++)
    {
        fprintf(stderr, " ");
    }
    
    switch(t->type)
    {
        case '+':
            fprintf(stderr, "[ADDOP]\n");
            break;
        case '*':
            fprintf(stderr, "[MULOP]\n");
            break;
        case NUM:
            fprintf(stderr, "[NUM:%d]\n" , t->attribute);
            break;


        default:
            yyerror( "Error in tree_print");
    }

    aux_tree_print( t->left, spaces+4 );
    aux_tree_print( t->right, spaces+4 );
}
