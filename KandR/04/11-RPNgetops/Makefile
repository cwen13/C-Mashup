objects := main.o myio.o stack.o tokenizer.o variables.o
CFLAGS = -g -lm 


calc: $(objects)
	$(CC)  $(CPPFLAGS) $(CFLAGS) $^ -o $@

%.c: $(wildcard *.c)
