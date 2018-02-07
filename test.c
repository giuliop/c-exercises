#include <stdio.h>
#include <stddef.h>

int main() {
  int c1 = 'c';
  char c2 = 'c';
  char * s1 = "ciao";
  char * s2 = &(s1[0]);
  char * s3 = &c2;
  printf("%d", c1);
  printf("\n");
  printf("%c",c2);
  printf("\n");
  printf("%s", s1);
  printf("\n");
  printf("%s", s2);
  printf("\n");
  printf("%c", *s3);
  printf("\n");
  /*printf("%lU\n", sizeof(int));*/
  /*printf("%lU\n", sizeof(int));*/
  /*printf("%lU\n", sizeof(char));*/
  /*printf("%lU\n", sizeof(wchar_t));*/
}
