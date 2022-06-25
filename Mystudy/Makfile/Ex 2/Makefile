CC = g++
CFLAGS= -lm -Wall -g
all: main_max main_min

main_max: main_max.cpp max.o
	$(CC) $(CFLAGS) main_max.cpp max.o -o main_max

main_min: main_min.cpp min.o
	$(CC) $(CFLAGS) main_min.cpp min.o -o main_min

max.o: max.cpp
	$(CC) $(CFLAGS) -c max.cpp

min.o: min.cpp
	$(CC) $(CFLAGS) -c min.cpp

clean:
	rm *.o main_max main_min


