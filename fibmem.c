#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>

#define CACHE_BLOCK_SIZE 100

size_t * cache = NULL;

// return fib(n)
size_t fib(long n)
{
	assert(n > 0);

	if (n < 3)
		return 1;

	size_t c = cache[n];
	if (! c) {
		c = fib(n-2) + fib(n-1);
		cache[n] = c;
	}

	// check for overflow
	if (c < fib(n-2)) {
		printf("Input was too big\n");
		exit(EXIT_FAILURE);
	}

	return c;
}

int main(int argc, char * argv[argc + 1])
{
	if (argc != 2) {
		printf("usage: %s <positive number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
		
	long n = strtol(argv[1], NULL, 10);

	if ((n <= 0) || (n > INT_MAX)) {
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}

	cache = calloc(n+1, sizeof(size_t));
	printf("fib %ld = %lu\n", n, fib(n));

	exit(EXIT_SUCCESS);
}
