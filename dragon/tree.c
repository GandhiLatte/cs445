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
tree_t *mkid(node_t *name_ptr)
{
    if (name_ptr == NULL)
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
tree_t *mkfor(tree_t assignop, tree_t bleh)
{
    tree_t *bottom;
    tree_t *top;

    return top;
}

tree_t *mkarray()
{

}

tree_t *mkprog()
{

}

tree_t *mksubprog()
{

}

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
    case INUM:
        return t->attribute.ival;
    case RNUM:
        return t->attribute.rval;
    
    default:
        fprintf(stderr, "Tree Eval: unknown type %d\n", t->type);
        exit(1);
    }
}
         

void tree_print(tree_t *t)
{
    aux_tree_print(t, 0);
}

void aux_tree_print(tree_t *tree, int spaces)
{
    if (tree == NULL)
        return;

    for (int i = 0; i < spaces; i++)
    {
        fprintf(stderr, " ");
    }

    switch (tree->type)
    {
    case ID:
        fprintf(stderr, "[ID:%s]\n", tree->attribute.sval->name);
        break;
    case MULOP:
        fprintf(stderr, "[MULOP:%d]\n", tree->attribute.opval);
        break;
    case ADDOP:
        fprintf(stderr, "[ADDOP:%d]\n", tree->attribute.opval);
        break;
    case RELOP:
        fprintf(stderr, "[RELOP:%d]\n", tree->attribute.opval);
        break;
    case INUM:
        fprintf(stderr, "[INUM:%d]\n", tree->attribute.ival);
        break;
    case RNUM:
        fprintf(stderr, "[RNUM:%f]\n", tree->attribute.rval);
        break;
    case FUNCTION:
        fprintf(stderr, "[FUNCTION]");
        break;
    case PROGRAM:
        fprintf(stderr, "[PROGRAM]");
        break;
    case VAR:
        fprintf(stderr, "[VAR]");
        break;
    case ARRAY:
        fprintf(stderr, "[ARRAY]");
        break;
    case OF:
        fprintf(stderr, "[OF]");
        break;
    case PROCEDURE:
        fprintf(stderr, "[PROCEDURE]");
        break;
    case BBEGIN:
        fprintf(stderr, "[BEGIN]");
        break;
    case END:
        fprintf(stderr, "[END]");
        break;
    case INTEGER:
        fprintf(stderr, "[INTEGER]");
        break;
    case REAL:
        fprintf(stderr, "[REAL]");
        break;
    case IF:
        fprintf(stderr, "[IF]");
        break;
    case THEN:
        fprintf(stderr, "[THEN]");
        break;
    case ELSE:
        fprintf(stderr, "[ELSE]");
        break;
    case WHILE:
        fprintf(stderr, "[WHILE]");
        break;
    case DO:
        fprintf(stderr, "[DO]");
        break;
    case NOT:
        fprintf(stderr, "[NOT]");
        break;
    case DOTDOT:
        fprintf(stderr, "[DOTDOT]");
        break;
    case ASSIGNOP:
        fprintf(stderr, "[ASSIGNOP]");
        break;
    case ARRAY_ACCESS:
        fprintf(stderr, "[ARRAY_ACCESS]");
        break;
    case SLASH:
        fprintf(stderr, "[/]");
        break;
    case FUNCTION_CALL:
        fprintf(stderr, "[FUNCTION_CALL]");
        break;
    case PROCEDURE_CALL:
        fprintf(stderr, "[PROCEDURE_CALL]");
        break;

    default:
        fprintf(stderr, "Error Type: %d", tree->type);
        yyerror("Error in tree_print");
    }

    aux_tree_print(tree->left, spaces + 4);
    aux_tree_print(tree->right, spaces + 4);
}
