#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "node.h"

/* CONSTRUCTOR */
node_t *mknode( char *s, int type, int numargs, arglist_t *arglist )
{
    node_t *p = (node_t *)malloc(sizeof(node_t));
    assert(p != NULL);
    p->name = strdup(s);
    p->type = type;
    p->numargs = numargs;
    p->arglist = arglist;
    p->next = NULL;
    return p;
}

/*  HELPERS */
node_t *node_search( node_t *top, char *name )
{   
    node_t *p = top;

    while( p != NULL) {
        if(!strcmp(p->name, name))
            return p;
        p = p->next;
    }
    return NULL;
}
/*  */
node_t *node_insert( node_t *top, char *name)
{
    node_t *p = mknode(name, 0, 0, NULL);
    p->next = top;
    return p;
}

// don't know if this works
/* node_t *insert_type(node_t *curr, int type)
{
    curr->type = type;
    return curr;
}
 */
node_t *node_insert_func(arglist_t *arglist, node_t *top, char *name, int type, int args)
{
    node_t *p = mknode(name, type, args, arglist);
    p->next = top;
    return p;
}

void node_print( node_t *top)
{
    node_t *p = top;
    fprintf(stderr, "BEGIN LIST PRINT \n");
    while ( p != NULL )
    {
        fprintf(stderr, "[%s]", p->name);
        p = p->next;
    }
    fprintf(stderr, "END LIST PRINT\n");
}
