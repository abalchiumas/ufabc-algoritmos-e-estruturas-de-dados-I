#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int** matriz = malloc(n * sizeof(int *));

	int counterColuna = 0;
	while (counterColuna < n) {
		int counterLinha = 0, inputLinha;
		int* linha = malloc(n * sizeof(int));
		while (counterLinha < n) {
			scanf("%d", &inputLinha);
			linha[counterLinha] = inputLinha;
			counterLinha++;
		}
		matriz[counterColuna] = linha;
		counterColuna++;
	}

	// TODO: remove later
	printf("Matrix: \n");
    for (int i = 0; i < n; i++) {
		printf("[ ");
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("]\n");
    }

	for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
	free(matriz);
	return 0;
}