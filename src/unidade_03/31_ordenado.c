#include <stdio.h>
#include <stdlib.h>

typedef struct tVector {
	int *vector;
	int vectorLength;
} Vector;

void checkOrdered(Vector v) {
	int decreasingCount = 0, increasingCount = 0;
	for (int j = 0; j < (v.vectorLength - 1); j++) {
		if (v.vector[j] >= v.vector[j + 1]) { // decrescente
			decreasingCount++;
		} 
		if (v.vector[j] <= v.vector[j + 1]) { // crescente
			increasingCount++;
		}		
	}
	if ((decreasingCount == (v.vectorLength - 1)) ||
	    (increasingCount == (v.vectorLength - 1)) ||
		 v.vectorLength <= 1) {
		printf("S\n");
	} else {
		printf("N\n");
	}
}

int main(void) {
	int n;
	Vector *vetores = NULL;
	int counter = 0;
	while (scanf("%d", &n) != EOF) {
		int *vTmp = malloc(n * sizeof(int)); // aloca espaço pro vTmp
		vetores = realloc(vetores, (counter + 1) * sizeof(Vector)); // realoca dinamicamente espaço
		for (int i = 0; i < n; i++) {
			scanf("%d", &vTmp[i]); // escrever os valores inputados no vetor vTmp
		}
		Vector v = { vTmp, n }; // cria a struct Vector com base no vTmp
		vetores[counter] = v; // adiciona o vetor criado na lista de vetores inputados
		counter++;
	}
	
    for (int k = 0; k < counter; k++) {
		checkOrdered(vetores[k]);
        free(vetores[k].vector);
    }
	free(vetores);
	return 0;
}