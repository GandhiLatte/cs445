#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "tree.h"

#define EOS 256

int get_next_token();

/* channels connect scanner and parser */
int curr_token, curr_attribute;


tree_t *expr();
tree_t *term();
tree_t *factor();

void match(int);

int main()
{
	tree_t *value;	

	/*intiazlie the first token */
	curr_token = get_next_token();


	/*call the parser to evaluate the token*/
	value = expr();

	assert ( curr_token == EOS );
	
	/*semantic evaluation */
	fprintf(stderr, "Value = %d\n", tree_eval(value));
}

/* syntax analyzer (parser) */



/* E -> T E'
 * E'-> + T E' | E' -> - T E' | empty
 */
tree_t *expr()
{
	tree_t *value = term();
	while (curr_token == '+' || curr_token == '-') {
		if( curr_token == '+')
		{
			match('+');
			value = mktree( '+', value, term());
		} else if( curr_token == '-'){
			match('+');
			value = mktree( '+', value, term());
		} 
	}
	return value;
}

 /* T -> F T' 
 * T'-> * F T' | T' -> / F T' | empty
 */
tree_t *term()
{
	tree_t *value = factor();
	while (curr_token == '*' || curr_token == '/') {
		if ( curr_token == '*')
		{
			match('*');
			value = mktree('*', value, factor());
		} else if( curr_token == '/')
		{
			match('/');
			value = mktree('/', value, factor());
		}
	}
	return value;
}

 /* F -> ( E ) | -F |NUM */
tree_t *factor()
{
	tree_t *value;
	if( curr_token == '('){
		match('(');
		value = expr();
		match(')');
	} else if( curr_token == '-'){
		match('-');
		value = mkrtree('-', factor(), NULL);
	} else if ( curr_token == NUM ) {
		value = mktree(NUM, NULL, NULL);
		value->attribute = curr_attribute;
		match(NUM);
	} else {
		fprintf(stderr, "Error in factor()\n");
		exit(1);
	}
	return value;
}


/* lexical analyzer (tokenizer/scanner) */
int get_next_token()
{
	int c, value, curr_attribute;
	while(1){
		switch(c = getchar()) {
		case ' ': case '\t':
			continue; // if we did break we would go outside the while
		case '\n':
		   	fprintf(stderr, "[EOS]%c" , c); // displays end of stream
			return EOS; // end of stream
		case '+': case '-':   /* addition operator */
			fprintf(stderr, "%c",c);
			return c;
		case '*': case '/': /* subtraction operator */
			fprintf(stderr, "[MULOP:%c]", c);
			return c;
		case '(': case ')':
			fprintf(stderr,"(%c)",c);
			return c;
		default:
			if(isdigit(c)) {
				value = 0;
				do{
					value = 10*value+(c-'0');
				} 
				while(isdigit(c = getchar()));
					ungetc(c,stdin);
			
				curr_attribute = value;
				
				fprintf(stderr, "[NUM:%d]", curr_attribute);
				return NUM;
			} else {
				fprintf(stderr, "{%c}", c);
				//assert(0);
			}
			
		}
		
	}
}


void match( int token )
{
	if ( curr_token == token ) {
		curr_token = get_next_token();
	} else {
		fprintf(stderr, "Bad Expected token: %d\n", curr_token);
		exit(1);
	}
}	
