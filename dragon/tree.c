#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree.h"
#include "y.tab.h"

extern int yyerror(char *);

/* prototype */
void aux_tree_print(tree_t *, int);

/* constructor */
tree_t *mktree(int type, tree_t *left, tree_t *right)
{
    tree_t *p = (tree_t *)malloc(sizeof(tree_t));
    assert(p != NULL);
    p->type = type;
    p->left = left;
    p->right = right;
    return p;
}

/*specialized constructors */
tree_t *mkid( node_t *name_ptr)
{
    if(name_ptr == NULL)
    {
        yyerror("ID NOT FOUND");
    }
    tree_t *p = mktree(ID, NULL, NULL);
    p->attribute.sval = name_ptr; /* memory leak? */
    return p;
}

tree_t *mkinum(int ival)
{
    tree_t *p = mktree(INUM, NULL, NULL);
    p->attribute.ival = ival;
    return p;
}

tree_t *mkrnum(float rval)
{
    tree_t *p = mktree(RNUM, NULL, NULL);
    p->attribute.rval = rval;
    return p;
}

tree_t *mkop(int type, int op, tree_t *left, tree_t *right)
{
    tree_t *p = mktree(type, left, right);
    p->attribute.opval = op;
    return p;
}

//  have to add mkfor
/* mkfor mkarray mkprog mksubprog */


/*auiliary */
int tree_eval(tree_t *t)
{
    assert(t != NULL);

    switch (t->type)
    {
    case '+':
        return tree_eval(t->left) + tree_eval(t->right);
    case '-':
        if (t->right != NULL)
            return tree_eval(t->left) - tree_eval(t->right);
        else
            return -tree_eval(t->left);
    case '*':
        return tree_eval(t->left) * tree_eval(t->right);
    case '/':
        return tree_eval(t->left) / tree_eval(t->right);
    case NUM:
        return t->attribute;
    default:
        fprintf(stderr, "Tree Eval: unknown type %d\n", t->type);
        exit(1);
    }
}

void tree_print(tree_t *t)
{
    aux_tree_print(t, 0);
}

void aux_tree_print(tree_t *t, int spaces)
{
    if (t == NULL)
        return;

    for (int i = 0; i < spaces; i++)
    {
        fprintf(stderr, " ");
    }

    switch (t->type)
    {
    case ID:
        fprintf(stderr, "[ID:%s]\n", t->attribute.sval);
        break;
    case MULOP:
        fprintf(stderr, "[MULOP:%d]\n", t->attribute.opval);
        break;
    case ADDOP:
        fprintf(stderr, "[ADDOP:%d]\n", t->attribute.opval);
        break;
    case RELOP:
        fprintf(stderr, "[RELOP:%d]\n", t->attribute.opval);
        break;
    case INUM:
        fprintf(stderr, "[INUM:%i]\n", t->attribute.ival);
        break;
    case RNUM:
        fprintf(stderr, "[RNUM:%f]\n", t->attribute.rval);
        break;
    case FUNCTION_CALL:
    case ARRAY_ACCESS:
    case COMMA:
    case IF:
    case THEN:
    case WHILE:
    case ELSE:

    default:
        yyerror("Error in tree_print");
    }

    aux_tree_print(t->left, spaces + 4);
    aux_tree_print(t->right, spaces + 4);
}
