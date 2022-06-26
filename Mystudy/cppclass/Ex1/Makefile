CC = g++
# CFLAGS= -lm -Wall -g
src=$(wildcard ./*.cpp)
obj=$(patsubst %.cpp, %.o, $(src))
# obj=$(src: %.c=%.o)
target=main

$(target): $(src)
	$(CC) $(CFLAGS) $(src) -o $(target)


.PHONY: clean

clean:
	rm *.o main