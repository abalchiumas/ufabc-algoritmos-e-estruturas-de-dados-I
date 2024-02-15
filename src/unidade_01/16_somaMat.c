#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int n) {
	int** matrix = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		matrix[i] = malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {\
			scanf("%d", &matrix[i][j]);
		}		
	}
	return matrix;
}

int** sumMatrices(int** matrix1, int** matrix2, int n) {
	int** summedMatrix = malloc(n * sizeof(int *));
		for (int i = 0; i < n; i++) {
			summedMatrix[i] = malloc(n * sizeof(int));
			for (int j = 0; j < n; j++) {
				summedMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
	return summedMatrix;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int** matrix1 = createMatrix(n);
	int** matrix2 = createMatrix(n);
	int** summedMatrix = sumMatrices(matrix1, matrix2, n);
	
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", summedMatrix[i][j]);
        }
		printf("\n");
    }

	for (int i = 0; i < n; i++) {
        free(matrix1[i]);
		free(matrix2[i]);
		free(summedMatrix[i]);
    }
    free(matrix1);
	free(matrix2);
	free(summedMatrix);
	return 0;
}