#include <limits.h>
#include <stdio.h>

int main() {
  long int max = LONG_MAX;
	long int max_plus_one = max + 1;

  printf(" max \t\t %lx\n LONG_MAX \t %lx\n", max, LONG_MAX);
  printf(" max_plus_one \t %lx\n max + 1 \t %lx\n LONG_MIN \t %lx\n\n",\
			max_plus_one, max + 1, LONG_MIN);

  printf(" max == LONG_MAX? \t\t %s\n", max == LONG_MAX ? "true" : "false");
  printf(" max_plus_one == LONG_MIN ? \t %s\n",\
			max_plus_one == LONG_MIN ? "true" : "false");
  printf(" max + 1 == max_plus_one? \t %s\n",\
			max + 1 == max_plus_one ? "true" : "false");
  printf(" max + 1 == LONG_MIN? \t\t %s\n", max + 1 == LONG_MIN ? "true" : "false");
}
