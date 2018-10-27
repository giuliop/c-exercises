#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("sizeof(int*): %li\n", sizeof(int*));
    printf("sizeof(float*): %li\n", sizeof(float*));
    printf("sizeof(void*): %li\n", sizeof(void*));
    printf("sizeof(size_t): %li\n", sizeof(void*));
    return 0;
}
