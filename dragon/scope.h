#ifndef SCOPE_H
#define SCOPE_H

#include "node.h"

#define HASH_SIZE 211
#define EOS_SIZE 212


typedef struct scope_s {
    node_t *table[HASH_SIZE];
    struct scope_s *next;
} scope_t;

/* constructor */
scope_t *mkscope();
void *free_scope(scope_t * );


/* stack routines */
scope_t *push_scope( scope_t * );
scope_t *pop_scope( scope_t * );



/* helpers */
node_t *scope_search_all( scope_t *, char * );
node_t *scope_search( scope_t *, char * );
node_t *scope_insert( scope_t *, char * );
node_t *edit_scope_id( scope_t *, char *, int);
#endif