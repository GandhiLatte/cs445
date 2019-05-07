#ifndef NODE_H
#define NODE_H

typedef struct arglist_s
{
    int type;
    int num;
    struct arglist_s *next;
} arglist_t;

typedef struct node_s
{
    char *name;
    int id_type;
    int return_type;
    int numargs;
    arglist_t *arglist;

    struct node_s *next;
} node_t;




/* constructor */
/* int, int, arglist_t * */
node_t *mknode(char *);

/* helpers */
node_t *node_search(node_t *, char *);
node_t *node_insert(node_t *, char *);
node_t *create_type(node_t *, int);
node_t *node_insert_func( arglist_t *, node_t *, char *, int, int);
void node_print(node_t *);
#endif