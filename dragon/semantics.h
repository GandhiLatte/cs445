#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "node.h"
#include "tree.h"
#include "scope.h"

int typechecker(tree_t *);
tree_t *getReturnType(tree_t *);
//node_t retnode();
arglist_t *mkarglist(tree_t *, int);

int get_arg_num(tree_t *, int);

arglist_t *mergelist(arglist_t *, arglist_t*);


#endif