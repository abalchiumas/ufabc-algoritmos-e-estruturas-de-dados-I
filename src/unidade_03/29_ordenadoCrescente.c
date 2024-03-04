#include <stdio.h>
#include <stdlib.h>

typedef struct tVector {
	int *vector;
	int vectorLength;
} Vector;

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
        int j;
		for (j = 0; j < (vetores[k].vectorLength - 1); j++) {
			if (vetores[k].vector[j] > vetores[k].vector[j + 1]) {
				printf("N\n");
				break;
			}			
		}
		if (j == (vetores[k].vectorLength - 1) || vetores[k].vectorLength == 0) {
			printf("S\n");
		}		
        free(vetores[k].vector);
    }
	free(vetores);
	return 0;
}