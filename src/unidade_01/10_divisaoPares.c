#include <stdio.h>

int main(void) {
	int natural;
	scanf("%d", &natural);

	int counterTotal = 1, counterNaturais = 0;
	while (counterTotal <= natural) {
		if (natural % counterTotal == 0 && counterTotal % 2 == 0) {
			counterNaturais++;
		}
		counterTotal++;
	}

	printf("%d", counterNaturais);
	return 0;
}