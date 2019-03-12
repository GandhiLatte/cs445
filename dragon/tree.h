#ifndef TREE_H
#define TREE_H

/* tree type structure */
typedef struct tree_s
{
	int type; /* token type: INUM RNUM ID RELOP ADDOP MULOP NUM--- */
	union {
		int		ival;	/* INUM */
		float	rval;	/* RNUM */
		char	*sval;	/* ID */
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
tree_t *mkid(char* type);
tree_t *mkinum(int);
tree_t *mkrnum(float);
tree_t *mkop(int, int, tree_t *, tree_t *);

/*auxiliary*/
int tree_eval( tree_t *);
void tree_print(tree_t *);

#endif
