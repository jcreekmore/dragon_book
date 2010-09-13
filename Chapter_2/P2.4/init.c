#include "global.h"

struct entry keywords[] = {
	{"not", NOT},
	{"div", DIV},
	{"mod", MOD},
	{"and", AND},
	{"or", OR},
	{"in", IN},
	{0, 0}
};

void init(void)         /* loads keywords into symtable */
{
	struct entry *p;
	for (p = keywords; p->token; p++) {
		insert(p->lexptr, p->token);
	}
}
