CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra

all: no-comment

no-comment: no-comment.c error.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f no-comment