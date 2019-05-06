#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scope.h"

#define TABLE_SIZE	211
#define EOS		'\0'

int hashpjw ( char * ); 

/* constructor */
scope_t *mkscope()
{
    scope_t *p = (scope_t *)malloc(sizeof(scope_t));
    assert(p != NULL);
    for( int i = 0; i < TABLE_SIZE; i++)
        p->table[i] = NULL;
    p->next = NULL;
    return p;
}

void *free_scope(scope_t *top )
{
    assert(top != NULL);
    //free(top->table);
    free(top);   
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
node_t *scope_search_all( scope_t *top, char *name )
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
    int index = hashpjw(name);
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

node_t *scope_insert_func( scope_t *top, char *name, int type, int args, arglist_t *arglist)
{
    int index = hashpjw(name);
    node_t *tmp = top->table[index];
    top->table[index] = node_insert_func(arglist,tmp,name,type,args);
    return top->table[index];
}

/* indcluded in here the Peter J. Weinberger hash function */
/* ----------------------------------------------------------------------------- 
 * hashpjw
 * Peter J. Weinberger's hash function 
 * Source: Aho, Sethi, and Ullman, "Compilers", Addison-Wesley, 1986 (page 436).
 */
int hashpjw( char *s )
{
	char *p; 
	unsigned h = 0, g; 
	
	for ( p = s; *p != EOS; p++ ) 
	{ 
		h = (h << 4) + (*p); 
		if ( g = h & 0xf0000000 ) 
		{ 
			h = h ^ ( g >> 24 ); 
			h = h ^ g; 
		} 
	} 
	return h % TABLE_SIZE; 
}


