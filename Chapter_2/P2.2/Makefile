FINAL = p2.2
SRCS = main.c emitter.c error.c init.c lexer.c parser.c symbol.c
OBJS = $(SRCS:.c=.o)

$(FINAL): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	-$(RM) $(FINAL) $(OBJS)
