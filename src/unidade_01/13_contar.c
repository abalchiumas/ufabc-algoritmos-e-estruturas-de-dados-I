#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int* vetor = malloc(n * sizeof(int));

	int counter = 0, input;
	while(counter < n ) {
		scanf("%d", &input);
		vetor[counter] = input;
		counter++;
	}

	int x;
	scanf("%d", &x);
	int countHigher = 0;
	for (int i = 0; i < counter; i++) {
		if (vetor[i] >= x) {
			countHigher++;
		}
	}

	printf("%d\n", countHigher);

	free(vetor);
	return 0;
}