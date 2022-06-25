CC = g++
CFLAGS= -lm -Wall -g
obj=bar.o foo.o main.o
target=main

$(target): $(obj)
	$(CC) $(CFLAGS) $(obj) -o $(target)

%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o main


