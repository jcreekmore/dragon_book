#include "global.h"

int lookahead;

static void relation(void);
static void expr(void);
static void term(void);
static void factor(void);
static void match(int t);

void parse(void)        /* parses and translates expression list */
{
	lookahead = lexan();
	while (lookahead != DONE) {
		relation(); match(';');
	}
}

static void relation(void)
{
	int t;
	expr();
	while(1) {
		switch (lookahead) {
		case EQ:
		case NE:
		case LT:
		case LE:
		case GT:
		case GE:
		case IN:
			t = lookahead;
			match(lookahead); expr(); emit(t, NONE);
			continue;
		default:
			return;
		}
	}
}

static void expr(void)
{
	int t;
	term();
	while(1) {
		switch (lookahead) {
		case '+':
		case '-':
		case OR:
			t = lookahead;
			match(lookahead); term(); emit(t, NONE);
			continue;
		default:
			return;
		}
	}
}

static void term(void)
{
	int t;
	factor();
	while (1) {
		switch (lookahead) {
		case '*':
		case '/':
		case DIV:
		case MOD:
		case AND:
			t = lookahead;
			match(lookahead); factor(); emit(t, NONE);
			continue;
		default:
			return;
		}
	}
}

static void factor(void)
{
	int t;
	switch (lookahead) {
	case NOT:
		t = lookahead;
		match(lookahead); factor(); emit(t, NONE);
		break;
	case '(':
		match('('); relation(); match(')'); 
		break;
	case NUM:
		emit(NUM, tokenval); match(NUM);
		break;
	case ID:
		emit(ID, tokenval); match(ID);
		break;
	default:
		error("syntax error");
	}
}

void match(int t)
{
	if (lookahead == t)
		lookahead = lexan();
	else
		error("syntax error");
}
