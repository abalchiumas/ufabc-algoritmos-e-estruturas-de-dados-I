#include <stdio.h>
#include <stdlib.h>

int DESLOC_COUNTER = 0;

void printVector(const int *vector, const int n) {
	for (int i = 0; i < n; i++)	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}

int *insertionSort(int *vetor, const int n) {
	int i = 0;
	for (int j = 1; j < n; j++)	{
		int key = vetor[j];
		i = j - 1;
		while (i >= 0 && vetor[i] > key) {
			vetor[i + 1] = vetor[i];
			printVector(vetor, n);
			DESLOC_COUNTER++;	
			i--;
		}
		vetor[i + 1] = key;
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
	vetor = insertionSort(vetor, n);
	printf("Deslocamentos: %d\n", DESLOC_COUNTER);
	free(vetor);
	return 0;
}