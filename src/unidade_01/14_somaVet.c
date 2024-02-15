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

	int sum = 0;
	for (int i = 0; i < counter; i++) {
		sum = sum + vetor[i];
	}

	printf("%d\n", sum);

	free(vetor);
	return 0;
}