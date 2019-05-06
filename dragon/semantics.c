#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "semantics.h"
#include "node.h"
#include "scope.h"
#include "tree.h"
#include "y.tab.h"

//semantics 2.1 -- 2.3
int typechecker(tree_t *tree)
{
    int left;
    int right;
    assert(tree != NULL);
    //compare type of bottom node to all the way through
    if ((tree->left == NULL) && (tree->right == NULL))
    {
        return tree->type;
    }
    else if (tree->left == NULL || tree->right == NULL)
        if (tree->left == NULL)
        {
            return typechecker(tree->right);
        }
        else
        {
            return typechecker(tree->left);
        }
    else
    {
        left = typechecker(tree->left);
        right = typechecker(tree->right);
        if (left == right)
        {
            return left;
        }
        else
        {
            return 0;
        }
    }
}

tree_t *getReturnType(tree_t *tree)
{
    if(tree == NULL)
    {
        return NULL;
    }
    
    return NULL;
}

arglist_t *mkarglist(tree_t *params, tree_t argt)
{
    int i;
    
    int arg =;


    arglist_t *args;
    arglist_t *tmp;
    args->next = NULL;
    args->type =  argt->type;

    int numargs = 0;
    assert(params != NULL);

    numargs = get_arg_num(params, 0);

    for(i = 1; i < numargs; i++)
    {
        tmp = args;
        args->type = arg;
        args->next = tmp;
    }
    args->num = numargs;
    return args;
}

// don't know if we need this
int get_arg_num(tree_t *params, int numargs)
{
    if ((params->left == NULL) && (params->right == NULL))
    {
        return numargs+1;
    }
    else if (params->left == NULL || params->right == NULL)
        if (params->left == NULL)
        {
            get_arg_num(params->right,numargs);
        }
        else
        {
            return get_arg_num(params->left, numargs);
        }
    else
    {
        return get_arg_num(params->left,numargs) + get_arg_num(params->right,numargs);
    }
}

//function && procedures
arglist_t *mergelist(arglist_t *first, arglist_t *last)
{
    arglist_t *tmp = first;

    if (first == NULL)
    {
        return last;
    }
    else if (last == NULL)
    {
        return first;
    }
    else
    {
        while (first->next != NULL)
        {
            first = first->next;
        }
        tmp->next = last;

        return tmp;
    }
}