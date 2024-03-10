#include <stdio.h>
#include <stdlib.h>

int IF_COUNTER = 0;

void printVector(const int *vector, const int n) {
	for (int i = 0; i < n; i++)	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}

int *selectionSort(int *vetor, const int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (vetor[j] < vetor[min]) {
				min = j;
			}
			IF_COUNTER++;	
		}
		int tmp = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = tmp;
		printVector(vetor, n);
	}
	return vetor;
}

int main(void) {
	int n;
	scanf("%d", &n);
	int *vetor = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}
	vetor = selectionSort(vetor, n);
	printf("Total de IFs executados: %d\n", IF_COUNTER);
	free(vetor);
	return 0;
}