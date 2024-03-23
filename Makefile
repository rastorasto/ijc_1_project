CC = gcc
CFLAGS = -O2 -std=c11 -Wall -pedantic
TARGETS = primes no-comment primes-i
LDFLAGS = -lm

all: $(TARGETS)

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
primes.o: primes.c bitset.h error.h eratosthenes.h
primes-i.o: eratosthenes.c bitset.h error.h
no-comment.o: no-comment.c bitset.h error.h

eratosthenes-i.o: eratosthenes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c -o $@ $<

primes: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

primes-i: primes.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) $(STACKFLAG) -DUSE_INLINE -o $@ $^ $(LDFLAGS)

no-comment: error.o no-comment.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: all
	ulimit -s 100000 && ./primes
	ulimit -s 100000 && ./primes-i

clean:
	rm -f $(TARGETS) *.o

zip:
	zip xuhliar00.zip *.c *.h Makefile
