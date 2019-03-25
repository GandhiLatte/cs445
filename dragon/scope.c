#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scope.h"


int hashpjw ( char * ); 

/* constructor */
scope_t *mkscope()
{
    scope_t *p = (scope_t *)malloc(sizeof(scope_t));
    assert(p != NULL);
    for( int i = 0, i < HASH_SIZE; i++)
        p->table[i] = NULL;
    p->next = NULL;
    return p;
}

void *free_scope(scope_t *top )
{

}

/* stack routines */
scope_t *push_scope( scope_t *top )
{
    scope_t *p = mkscope();
    p->next = top;
    return p;
}

scope_t *pop_scope( scope_t *top )
{

    scope_t *tmp;
    if( top == NULL) return NULL;
    tmp = top->next;
    free_scope( top );
    return tmp;
}

/* helpers */
node_t *scope_search_all( scope_t top*, char *name )
{
    scope_t *p = top;
    node_t *tmp;
    while ( p != NULL )
    {
        if( (tmp = scope_search(p, name)) != NULL)
            return tmp;
        p = p->next;
    }
    return tmp;
}

node_t *scope_search( scope_t *top, char *name )
{
    int index = hashpj(name);
    node_t *tmp = top->table[index];
    return node_search(tmp, name);
}

node_t *scope_insert( scope_t *top, char *name )
{
    int index = hashpjw(name);
    node_t *tmp = top->table[index];
    top->table[index] = node_insert(tmp,name);
    return top->table[index];

}

/* indcluded in here the Peter J. Weinberger hash function */