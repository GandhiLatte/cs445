#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "node.h"

/* CONSTRUCTOR */
node_t *mknode(char *s)
{
    node_t *p = (node_t *)malloc(sizeof(node_t));
    assert(p != NULL);
    p->name = strdup(s);
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
    node_t *p = mknode(name);
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
node_t *node_insert_func(arglist_t *arglist, node_t *top, int type, int args)
{
    top->arglist = arglist;
    top->numargs = args;
    top->return_type = type;
    return NULL;
}

node_t *create_type( node_t *name, int type)
{
    name->id_type = type;
    return name;
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
