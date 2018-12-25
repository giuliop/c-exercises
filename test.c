#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main()
{
    printf("sizeof(int*): %li\n", sizeof(int));
    printf("sizeof(int *): %li\n", sizeof(int *));
    printf("sizeof(sem_t): %li\n", sizeof(sem_t));
    return 0;
}
