#ifndef TREE_H
#define TREE_H

#define NUM 257

/* tree type structure */
typedef struct tree_s
{
	int type; /* token type */
	int attribute; /* token attribute */

	struct tree_s *left;
	struct tree_s *right;
}
tree_t;

/*constructor */
tree_t *mktree(int type, tree_t *left, tree_t *right);

/*auxiliary*/
int tree_eval( tree_t *);

#endif
