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

// we were running into problems when encountering return type variables. need to check a functions return type
/* If its a function, how can we tell. We can tell it the function return type is not 0.
    How else.
    
    We were also getting errors when checking arrays as a parameter. when declared in an expression
    Am I passing the array type. Maybe not.
    I could instead of building a tree when declaring an array, set its ID to its ID type.
    I could also set the functions type as the id_type, getting rid of the return type variable. DUHH
     */
int typechecker(tree_t *tree)
{
    int left;
    int right;
    assert(tree != NULL);
    //compare type of bottom node to all the way through
    if ((tree->left == NULL) && (tree->right == NULL))
    {
        if (tree->type == ID)
        {
            return tree->attribute.sval->id_type;
        }
        else
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
        if (tree->type == ARRAY) // maybe the solution
        {
            return typechecker(tree->right);
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

//error searchinng, can't find.
/* Why don't I just have it use the scope_search.
    If we already have the node name, what can we do. We have the scope and the node.
    Compare it against the node that it finds. If there isn't a node then dont do anything.   */
tree_t *has_return(node_t *head, tree_t *body)
{
    if(body->right == NULL && body->left == NULL)
    {
        if(body->type == ID)
        {
            if(strcmp(head->name,body->attribute.sval->name) != 0)
            {
                return body;
            } else
            {
                return NULL;
            }
        } else
        {
            return NULL;
        }
    } else if(body->right == NULL || body->left == NULL)
    {
        if(body->right == NULL)
        {
            return has_return(head,body->left);
        } else {
            return has_return(head,body->right);
        }
    } else
    {
        tree_t *left = has_return(head,body->left);
        tree_t *right = has_return(head,body->right);
        if(left == NULL && right == NULL)
        {
            return NULL;
        } else {
            if(left == NULL)
            {
                return right;
            } else
            {
                return left;
            }   
        }
    }
}

void add_typing(scope_t *topscope, tree_t *idlist, tree_t *typer)
{
    int type = typer->type;
    tree_t *tmp;

    assert(idlist != NULL);
    while (idlist != NULL)
    {
        tmp = idlist->left;
        if (idlist->left == NULL && idlist->right == NULL)
        {
            if (idlist->type == ID)
            {
                edit_scope_id(topscope, idlist->attribute.sval->name, type);
            }
            else if (idlist->type == ARRAY)
            {
            }
        }
        else if (idlist->type == COMMA)
        {
            if(idlist->right->type == ARRAY)
            {
                edit_scope_array(topscope, idlist->right->right->attribute.sval->name,type);
            } else {
                edit_scope_id(topscope, idlist->right->attribute.sval->name, type);
            }
        } else if(idlist->type == ARRAY)
        {
            edit_scope_array(topscope, idlist->right->attribute.sval->name, type);
        } else
        {
            printf("Done borked");
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
    while (expr != NULL)
    {
        tmp_arg = argv;
        tmp = expr->left;
        if (expr->left == NULL && expr->right == NULL)
        {
            argv = add_type_list(typechecker(expr), tmp_arg);
        }
        else if (expr->type == COMMA)
        {
            argv = add_type_list(typechecker(expr->right), tmp_arg);
        }
        else
        {
            fprintf(stderr, "Big broke");
        }
        expr = tmp;
    }
}

int compare_lists(arglist_t *expr, arglist_t *func)
{
    if (expr->next == NULL && func->next == NULL)
    {
        if (expr->type == func->type)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (expr->next == NULL && func->next != NULL)
    {
        return 0;
    }
    else if (expr->next != NULL && func->next == NULL)
    {
        return 0;
    }
    else if (expr->type == func->type)
    {
        return compare_lists(expr->next, func->next);
    }
    else
    {
        return 0;
    }
}

arglist_t *add_type_list(int type, arglist_t *arg)
{
    arglist_t *tmp;
    if (arg->next == NULL)
    {
        arg->type = type;
        return arg;
    }
    else
    {
        tmp->next = arg;
        tmp->type = type;
        return tmp;
    }
}