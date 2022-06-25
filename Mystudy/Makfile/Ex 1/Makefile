CC = g++
CFLAGS= -lm -Wall -g

main: main.cpp bar.o foo.o
	$(CC) $(CFLAGS) main.cpp bar.o foo.o -o main

bar.o: bar.cpp
	$(CC) $(CFLAGS) -c bar.cpp

foo.o: foo.cpp
	$(CC) $(CFLAGS) -c foo.cpp

clean:
	rm *.o main


