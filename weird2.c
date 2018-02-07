#include <limits.h>
#include <stdio.h>

int main() {
  long int max = LONG_MAX;

  printf(" max + 1 == LONG_MIN? \t\t %s\n", max + 1 == LONG_MIN ? "true" : "false");
}
