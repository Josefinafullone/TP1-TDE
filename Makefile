# T.P. 2 Alg y Prog I
CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
all: tp1 clean

tp1: main.o player.o parser.o tournament.o matcher.o
	$(CC) $(CFLAGS) main.o tournament.o matcher.o parser.o player.o -o tp1

main.o: main.cpp matcher.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

matcher.o: matcher.cpp matcher.h player.h tournament.h parser.h
	$(CC) $(CFLAGS) -c matcher.cpp -o matcher.o

parser.o: parser.cpp parser.h player.h
	$(CC) $(CFLAGS) -c parser.cpp -o parser.o

player.o: player.cpp player.h
	$(CC) $(CFLAGS) -c player.cpp -o player.o

tournament.o: tournament.cpp tournament.h player.h
	$(CC) $(CFLAGS) -c tournament.cpp -o tournament.o

clean:
	rm *.o

