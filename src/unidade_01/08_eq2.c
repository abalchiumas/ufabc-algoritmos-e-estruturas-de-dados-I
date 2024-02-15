#include <stdio.h>
#include <math.h>

int main(void) {
	long a, b, c;
	scanf("%ld %ld %ld", &a, &b, &c);
	printf("%.4lf %.4lf\n", (- b + sqrt((b * b) - (4 * a * c))) / 2, (- b - sqrt((b * b) - (4 * a * c))) / 2);
	return 0;
}