#include <stdio.h>
#include <stdlib.h>

int IF_EXECUTED_COUNTER = 0;
int IF_SATISFIED_COUNTER = 0;

void printVector(const int *vector, const int n) {
	for (int i = 0; i < n; i++)	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}

void bubbleSort(int *vetor, const int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < (n - 1 - i); j++) {
			if (vetor[j] > vetor[j + 1]) {
				int aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
				printVector(vetor, n);
				IF_SATISFIED_COUNTER++;
			}
			IF_EXECUTED_COUNTER++;
		}		
	}	
}

int main(void) {
	int n;
	scanf("%d", &n);
	int *vetor = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}
	bubbleSort(vetor, n);
	printf("Total de IFs executados: %d\n", IF_EXECUTED_COUNTER);
	printf("Total de IFs satisfeitos: %d\n", IF_SATISFIED_COUNTER);
	free(vetor);
	return 0;
}