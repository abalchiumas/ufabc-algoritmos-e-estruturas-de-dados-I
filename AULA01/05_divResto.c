#include <stdio.h>

int main(void) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	printf("%ld %ld\n", a / b, a % b);
	return 0;
}