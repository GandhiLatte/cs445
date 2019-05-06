#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "semantics.h"
#include "node.h"
#include "tree.h"
#include "y.tab.h"

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
        if(left == right)
        {
            return left;
        }
        else {
            return 0;
        }
    }
}

arglist_t *argtypes(tree_t *args)
{
}