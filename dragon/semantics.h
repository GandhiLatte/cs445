#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "node.h"
#include "tree.h"
#include "scope.h"

int typechecker(tree_t *);
tree_t *getReturnType(tree_t *);
//node_t retnode();
arglist_t *mkarglist(tree_t *, tree_t *);

int get_arg_num(tree_t *, int);


void add_typing(scope_t*, tree_t*,tree_t*);
arglist_t *merge_list(arglist_t *, arglist_t*);


#endif