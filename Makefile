# T.P. 2 Alg y Prog I
CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
all: tp1 clean

tp1: main.o player.o safeStream.o tournament.o matcher.o
	$(CC) $(CFLAGS) main.o tournament.o matcher.o safeStream.o player.o -o tp1

main.o: main.cpp matcher.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

matcher.o: matcher.cpp matcher.h player.h tournament.h safeStream.h
	$(CC) $(CFLAGS) -c matcher.cpp -o matcher.o

safeStream.o: safeStream.cpp safeStream.h player.h
	$(CC) $(CFLAGS) -c safeStream.cpp -o safeStream.o

player.o: player.cpp player.h
	$(CC) $(CFLAGS) -c player.cpp -o player.o

tournament.o: tournament.cpp tournament.h player.h
	$(CC) $(CFLAGS) -c tournament.cpp -o tournament.o

clean:
	rm *.o

