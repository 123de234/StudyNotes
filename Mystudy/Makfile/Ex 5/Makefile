CC = g++
CFLAGS= -lm -Wall -g
src=$(wildcard ./*.cpp)
obj=$(patsubst %.cpp, %.o, $(src))
# obj=$(src: %.c=%.o)
target=main

$(target): $(obj)
	$(CC) $(CFLAGS) $(obj) -o $(target)

%.o: %.cpp
	$(cc) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o main


