#ifndef NODE_H
#define NODE_H

typedef struct node_s {
    char *name;
    struct node_s *next;
} node_t;

/* constructor */
node_t *mknode( char *);

/* helpers */
node_t *node_search( node_t *, char * );
node_t *node_insert( node_t *, char * );
void node_print( node_t *);
#endif