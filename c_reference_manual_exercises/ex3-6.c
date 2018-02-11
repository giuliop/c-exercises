#define SIZE 0

#if !defined(SIZE) 
#error "SIZE not defined"
#elif SIZE < 1 || SIZE > 10 
#error "SIZE must be a value between 1 and 10"
#endif

int main () {}
