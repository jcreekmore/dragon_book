#include "global.h"

int lookahead;
int label;

static void stmt(void);
static void opt_stmt(void);
static void stmt_list(void);
static void relation(void);
static void expr(void);
static void term(void);
static void factor(void);
static void match(int t);

void parse(void)        /* parses and translates expression list */
{
	label = 0;
	lookahead = lexan();
	while (lookahead != DONE) {
		stmt_list(); 
	}
}

void stmt(void)
{
	int l1, l2;
	int t;
	switch (lookahead) {
	case ID:
		emit_l(ID, tokenval); match(ID); match(ASSN); relation(); emit(ASSN, NONE);
		break;
	case IF:
		l1 = label++;
		match(IF); relation(); emit(IF, l1); match(THEN); stmt(); emit(THEN, l1);
		break;
	case WHILE:
		l1 = label++; l2 = label++;
		match(WHILE); emit_label(l1); relation(); emit(WHILE, l2); match(DO); stmt(); emit_do(l1, l2);
		break;
	case BEGIN:
		match(BEGIN); opt_stmt(); match(END);
		break;
	default:
		return;
	};
}

void opt_stmt(void)
{
	switch (lookahead) {
	case ID:
	case IF:
	case WHILE:
	case BEGIN:
		stmt_list();
	default:
		return;
	};
}

void stmt_list(void)
{
	while (1) {
		stmt();
		if (lookahead = ';') {
			match(';');
		} else {
			return;
		}
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
