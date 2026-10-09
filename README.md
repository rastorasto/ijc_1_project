# IJC — Homework 1

FIT VUT course *Jazyk C* (IJC) homework #1, graded out of 15 points.

## What it does

- **`primes.c`** — Eratosthenes' sieve over a 666,000,000-bit bitset, printing
  the last 10 primes below the bound. `primes-i` is the same task built with
  the compiler-inlined macro variant, used to measure the speedup.
- **`no-comment.c`** — a filter that strips `//` and `/* */` comments from C
  source (file or stdin) with an explicit state machine, preserving string and
  character literals.

## Stack

C11 (`-std=c11 -pedantic -Wall -Wextra`), hand-written bit-vector macros in
`bitset.h`, `eratosthenes.*` for the sieve and `error.*` for diagnostics.

## Build & run

```bash
make
./primes            # last 10 primes below 666·10⁶
./no-comment main.c # strips comments from a file (or stdin)
```

Assignment (Czech): [ASSIGNMENT.md](ASSIGNMENT.md)
