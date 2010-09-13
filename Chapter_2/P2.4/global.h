#include <stdio.h>      /* load i/o routines */
#include <ctype.h>      /* load character test routines */

#define BSIZE  128		/* buffer size */
#define NONE   -1
#define EOS	   '\0'

#define NUM	   256
#define DIV	   257
#define MOD	   258
#define ID	   259
#define DONE   260
#define IN	   261
#define NOT    262
#define AND    263
#define OR     264
#define EQ     265
#define NE     266
#define LT     267
#define GT     268
#define LE     269
#define GE     270

int tokenval;      /* value of token attribute */
int lineno;
int lookahead;

struct entry {     /* form of symbol table entry */
	char *lexptr;
	int token;
};

extern struct entry symtable[];


extern int lexan(void);
extern void parse(void);
extern void emit(int t, int tval);
extern int lookup(char s[]);
extern int insert(char s[], int tok);
extern void init(void);
extern void error(char *m);
