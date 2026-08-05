OBJ := $(patsubst %.c,%.o,$(wildcard *.c))

calc: $(OBJ)
	gcc -o $@ $^

%.o: %.c
	gcc -c $<

clean:
	rm -f *.o calc *.exe