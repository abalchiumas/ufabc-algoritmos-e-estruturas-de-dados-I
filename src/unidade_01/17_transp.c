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

int** transposeMatrix(int** matrix, int numberOfRows, int numberOfColumns) {
	int** transposedMatrix = malloc(numberOfColumns * sizeof(int *));
	for (int i = 0; i < numberOfColumns; i++) {
		transposedMatrix[i] = malloc(numberOfRows * sizeof(int));
		for (int j = 0; j < numberOfRows; j++) {\
			transposedMatrix[i][j] = matrix[j][i];
		}		
	}
	return transposedMatrix;
}

int main(void) {
	int numberOfRows, numberOfColumns;
	scanf("%d\n", &numberOfRows); // n
	scanf("%d\n", &numberOfColumns); // m

	int** matrix = createMatrix(numberOfRows, numberOfColumns);
	int** transposedMatrix = transposeMatrix(matrix, numberOfRows, numberOfColumns);
	
    for (int i = 0; i < numberOfColumns; i++) {
        for (int j = 0; j < numberOfRows; j++) {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numberOfRows; i++) {
        free(matrix[i]);
    }
	for (int i = 0; i < numberOfColumns; i++) {
        free(transposedMatrix[i]);
    }
    free(matrix);
	free(transposedMatrix);
	return 0;
}