#include <stdio.h>
#include <stdlib.h>

int* createVector(int numberOfElementsInVector) {
	int* vector = malloc(numberOfElementsInVector * sizeof(int));
	for (int i = 0; i < numberOfElementsInVector; i++)	{
		scanf("%d", &vector[i]);
	}
	return vector;
}

int* invertVector(int sizeOfVectorToBeInverted, int* vectorToBeInverted) {
	int* invertedVector = malloc(sizeOfVectorToBeInverted * sizeof(int));
	for (int h = 0; h < sizeOfVectorToBeInverted; h++) {
		invertedVector[h] = vectorToBeInverted[sizeOfVectorToBeInverted - h - 1];
	}	
	return invertedVector;
}

int* combina(int *v, int *w, int n, int m) {
	int* z = malloc((n + m) * sizeof(int));
	for (int j = 0; j < n; j++) {
		z[j] = v[j];
	}
	for (int k = 0; k < m; k++) {
		z[k + n] = w[k];
	}
	return z;
}

int main(void) {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	int* vetor1 = createVector(n);
	int* vetor2 = createVector(m);
	int* vetor2Invertido = invertVector(m, vetor2);
	int* vetorCombinado = combina(vetor1, vetor2Invertido, n, m);
	for (int l = 0; l < (n + m); l++) {
		printf("%d ", vetorCombinado[l]);
	}
	printf("\n");
	
	free(vetor1);
	free(vetor2);
	free(vetor2Invertido);
	free(vetorCombinado);
	return 0;
}