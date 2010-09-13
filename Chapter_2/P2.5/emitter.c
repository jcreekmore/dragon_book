#include "global.h"

void emit_l(int t, int tval)
{
	switch(t) {
	case ID:
		printf("lvalue %s\n", symtable[tval].lexptr);
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	}
}

void emit_label(int l)
{
	printf("label l_%d\n", l);
}

void emit_do(int l1, int l2)
{
	printf("goto l_%d\n", l1);
	emit_label(l2);
}

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
	case ASSN:
		printf(":=\n");
		break;
	case IF:
		printf("gofalse l_%d\n", tval);
		break;
	case THEN:
		printf("label l_%d\n", tval);
		break;
	case WHILE:
		printf("gofalse l_%d\n", tval);
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	}
}
