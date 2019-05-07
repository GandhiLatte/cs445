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
        if(tree->type == ID)
        {
            return tree->attribute.sval->id_type;
        } else
        {
            return tree->type;
        }
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
    if (tree == NULL)
    {
        return NULL;
    }

    return NULL;
}

arglist_t *mkarglist(tree_t *params, tree_t *argt)
{
    int i;
    int numargs = 0;


    arglist_t *args = (arglist_t *)malloc(sizeof(arglist_t));
    assert(params != NULL);
    arglist_t *tmp;
    args->next = NULL;
    args->type = argt->type;

    numargs = get_arg_num(params, 0);

    //this needs to be updated
    for (i = 1; i < numargs; i++)
    {
        tmp = args->next;
        tmp->next = NULL;
        tmp->type = argt->type;
        args = tmp;
    }
    args->num = numargs;
    return args;
}

// don't know if we need this
int get_arg_num(tree_t *params, int numargs)
{
    if ((params->left == NULL) && (params->right == NULL))
    {
        return numargs + 1;
    }
    else if (params->left == NULL || params->right == NULL)
        if (params->left == NULL)
        {
            get_arg_num(params->right, numargs);
        }
        else
        {
            return get_arg_num(params->left, numargs);
        }
    else
    {
        return get_arg_num(params->left, numargs) + get_arg_num(params->right, numargs);
    }
}

//function && procedures
arglist_t *merge_list(arglist_t *first, arglist_t *last)
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

//function return
node_t *has_return(tree_t *func)
{
    if (func == NULL)
    {
        return NULL;
    }
    else
    {
        /* code */
    }
}

void add_typing(scope_t *topscope, tree_t *idlist, tree_t *typer)
{
    int type = typer->type;
    tree_t *tmp;

    assert(idlist != NULL);
    while(idlist != NULL)
    {
        tmp = idlist->left;
        if(idlist->left == NULL && idlist->right == NULL)
        {
            if(idlist->type == ID)
            {
                edit_scope_id(topscope,idlist->attribute.sval->name,type);
            } else
            {
                printf("BIG ERROR NULL?!?!?!!");
            }
        } else if(idlist->type == COMMA)
        {
            edit_scope_id(topscope,idlist->right->attribute.sval->name,type);
        }
        idlist = tmp;
    }
}


// sematnics 5. something
arglist_t *list_from_expr(tree_t *expr)
{
    arglist_t *argv;
    arglist_t *tmp_arg;
    tree_t *tmp;

    assert(expr != NULL);
    while(expr != NULL)
    {
        tmp_arg = argv;
        tmp = expr->left;
        if(expr->left == NULL && expr->right == NULL)
        {
            argv = add_type_list(typechecker(expr), tmp_arg);
        } else if(expr->type == COMMA)
        {
            argv = add_type_list(typechecker(expr->right), tmp_arg);
        } else
        {
            fprintf(stderr,"Big broke");
        }
        expr = tmp;
    }
}

int compare_lists(arglist_t  *expr, arglist_t *func)
{
    
    return 1;
}


arglist_t *add_type_list(int type, arglist_t *arg)
{
    arglist_t *tmp;
    if(arg->next == NULL)
    {
        arg->type = type;
        return arg;
    } else 
    {
        tmp->next = arg;
        tmp->type = type;
        return tmp;
    }
}