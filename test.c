#include <stdio.h>

double f(int a, int b) {
	return a+b;
}

int main() {
	int a = 1;
	int b = 1;
	double c = f(a,b);
	printf("%lu \n", sizeof(c));
	printf("%f \n", c);
}

