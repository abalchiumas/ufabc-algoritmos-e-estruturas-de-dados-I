#include <stdio.h>

int main(void) {
	int natural;
	scanf("%d", &natural);

	int counterTotal = 1, total = 0;
	while (counterTotal < natural) {
		if (natural % counterTotal == 0) {
			total = total + counterTotal;
		}
		counterTotal++;
	}

	if (natural == total) {
		printf("SIM\n");
	} else {
		printf("NAO\n");
	}
	
	return 0;
}