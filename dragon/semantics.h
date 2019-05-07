#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "node.h"
#include "tree.h"
#include "scope.h"

int typechecker(tree_t *);
tree_t *getReturnType(tree_t *);
//node_t retnode();

//function typing
arglist_t *mkarglist(tree_t *, tree_t *);

int get_arg_num(tree_t *, int);


//function typing
void add_typing(scope_t*, tree_t*,tree_t*);
arglist_t *merge_list(arglist_t *, arglist_t*);


//function stuff
arglist_t *list_from_expr(tree_t*);
arglist_t *add_type_list(int, arglist_t *);
int compare_lists(arglist_t *, arglist_t *);

#endif