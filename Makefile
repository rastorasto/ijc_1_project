CC = gcc
M32FLAG =  
CFLAGS = -O2 -std=c99 -Wall -pedantic $(M32FLAG)
TARGETS = primes no-comment

all: primes no-comment

primes: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

no-comment: error.o no-comment.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGETS)