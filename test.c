#include <stdio.h>

int main() {
  unsigned const * n;
  n  = &(unsigned){5};
  printf("%u\n", *n);
  /**n = 10;*/
  /*printf("%u\n", *n);*/
}
