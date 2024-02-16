#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int numberOfRows, int numberOfColumns) {
	int** matrix = malloc(numberOfRows * sizeof(int *));
	for (int i = 0; i < numberOfRows; i++) {
		matrix[i] = malloc(numberOfColumns * sizeof(int));
		for (int j = 0; j < numberOfColumns; j++) {\
			scanf("%d", &matrix[i][j]);
		}		
	}
	return matrix;
}

double sumMatrixBelowDiagonal(int** matrix, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) {
				sum += matrix[i][j];
			}
		}		
	}
	return sum;
}

double medianMatrixBelowDiagonal(int** matrix, int n) {
	// para uma matriz Aij, temos que i = j = n
	// total de elementos da matriz = i x j = n x n 
	// total - 1 termo (elemento na diagonal) de cada linha = i x (j-1) = n x (n -1)
	// se quisermos somente a quantidade de elementos abaixo da diagonal: (n x (n - 1)) / 2
	return sumMatrixBelowDiagonal(matrix, n) / ((n * (n - 1)) / 2);
}

int main(void) {
	char operation;
	int n;
	scanf("%c", &operation);
	scanf("%d", &n);

	int** matrix = createMatrix(n, n);
	if (operation == 'S') {
		printf("%0.1lf\n", sumMatrixBelowDiagonal(matrix, n));
	}
	if (operation == 'M') {
		printf("%0.1lf\n", medianMatrixBelowDiagonal(matrix, n));
	}

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
	}
    free(matrix);
	return 0;
}