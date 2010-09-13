#include "global.h"

void emit(int t, int tval)      /* generates output */
{
	switch(t) {
	case '+':
	case '-':
	case '*':
	case '/':
		printf("%c\n", t);
		break;
	case DIV:
		printf("div\n");
		break;
	case MOD:
		printf("mod\n");
		break;
	case AND:
		printf("and\n");
		break;
	case OR:
		printf("or\n");
		break;
	case NOT:
		printf("not\n");
		break;
	case IN:
		printf("in\n");
		break;
	case EQ:
		printf("=\n");
		break;
	case NE:
		printf("<>\n");
		break;
	case LE:
		printf("<=\n");
		break;
	case LT:
		printf("<\n");
		break;
	case GT:
		printf(">\n");
		break;
	case GE:
		printf(">=\n");
		break;
	case NUM:
		printf("push %d\n", tval);
		break;
	case ID:
		printf("rvalue %s\n", symtable[tval].lexptr);
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	}
}
