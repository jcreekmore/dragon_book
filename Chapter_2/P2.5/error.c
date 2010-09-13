#include <stdlib.h>
#include "global.h"

void error(char *m)   /* generates all error messages */
{
	fprintf(stderr, "line %d: %s\n", lineno, m);

	do {
		lookahead = lexan();
	} while (lookahead != ';');

	lookahead = lexan();
}
