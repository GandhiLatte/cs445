#ifndef TREE_H
#define TREE_H

#include "node.h"


/* tree type structure */
typedef struct tree_s
{
	int type; /* token type: INUM RNUM ID RELOP ADDOP MULOP NUM--- */
	union {
		int		ival;	/* INUM */
		float	rval;	/* RNUM */
		node_t	*sval;	/* ID */
		int		opval;	/* RELOP: LT LE GT GE EQ NE */
						/* ADDOP: PLUS MINUS OR */
						/* MULOP: STAR SLASH AND */
	} attribute; /* token attribute */

	struct tree_s *left;
	struct tree_s *right;
}
tree_t;

/*constructor */
tree_t *mktree(int type, tree_t *left, tree_t *right);
/* specialized constructors */
tree_t *mkid(node_t *);
tree_t *mkinum(int);
tree_t *mkrnum(float);
tree_t *mkop(int, int, tree_t *, tree_t *);
tree_t *mkarray(int, int, int);
tree_t *mkprog(int, node_t *, tree_t *,tree_t *, tree_t *, tree_t *);
tree_t *mkdecl(tree_t *, tree_t *, tree_t *);
tree_t *mksubprog(int, tree_t *, tree_t *, tree_t*);



/*auxiliary*/
void tree_print(tree_t *);

#endif
