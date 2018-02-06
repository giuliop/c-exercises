/*
 Computer Dating
 When will the time_t's wrap around? Write a program to find out.
 1. Look at the definition of time_t. This is in file /usr/include/time.h.
 2. Code a program to place the highest value into a variable of type time_t, then
    pass it to ctime() to convert it into an ASCII string. Print the string.
    Note that ctime has nothing to do with the language C,
    it just means "convert time."
 */

#include <limits.h>
#include <time.h>
#include <stdbool.h>

/* on Ubuntu time_t is defined as long int, let's make sure */
bool check_time_t() {
  long int max = LONG_MAX;
  time_t time_max = max;
  return (max == time_max) && ((max + 1) < 0);
}

int main() {
  printf("time_t size known? -> %b", check_time_t());
}

