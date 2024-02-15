#include <stdio.h>

int main(void) {
	int input, min;
	int counter = 0;
	while (1) {
		scanf("%d", &input);
		if (input < 0) {
			break;
		}
		if (counter == 0 || input < min) {
			min = input;
		}
		counter++;
	}

	if (counter > 0) {
		printf("%d\n", min);
	} else {
		printf("nenhum numero informado");
	}
	
	return 0;
}