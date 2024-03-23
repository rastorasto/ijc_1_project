CC = gcc
M32FLAG =  
CFLAGS = -O2 -std=c11 -Wall -pedantic $(M32FLAG)
TARGETS = primes no-comment

all: primes no-comment

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
error.o: error.c error.h
primes.o: primes.c bitset.h error.h eratosthenes.h
bitset.o: bitset.c bitset.h error.h

primes: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

no-comment: error.o no-comment.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o