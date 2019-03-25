#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "node.h"



/* CONSTRUCTOR */
node_t *mknode( char *)
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
    return NULL:
}

node_t *node_insert( node_t top, char *name )
{
    node_t *p = mknode( name );
    p->next = top;
    return p;
}

void node_print( node_t *top)
{
    node_t *p = top;
    fprintf("BEGIN LIST PRINT \n");
    while ( p != NULL )
    {
        fprintf(stderr, "[%s]", p->name);
        p = p->next;
    }
    fprintf(stderr, "END LIST PRINT\n");
    
}
