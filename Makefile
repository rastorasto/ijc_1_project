CC = gcc
CFLAGS = -O2 -std=c11 -Wall -pedantic
TARGETS = primes no-comment
LDFLAGS = -lm

all: $(TARGETS)

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
primes.o: primes.c bitset.h error.h eratosthenes.h
no-comment.o: no-comment.c bitset.h error.h

primes: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

no-comment: error.o no-comment.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o

zip:
	zip xuhliar00.zip *.c *.h Makefile
