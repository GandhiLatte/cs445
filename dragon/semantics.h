#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "node.h"
#include "tree.h"

int typechecker(tree_t *);
//node_t retnode();
arglist_t *argtypes(tree_t *);

#endif