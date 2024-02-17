#include <stdio.h>
#include <stdlib.h>

// esqueci da existência do Algoritmo de Euclides durante a implementação
// solução não otimizada a seguir:
int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	int* multiplosA = malloc(b * sizeof(int));
	for (int i = 1; i <= b; i++) {
		multiplosA[i - 1] = a * i;
	}
	int* multiplosB = malloc(a * sizeof(int));
	for (int j = 1; j <= a; j++) {
		multiplosB[j - 1] = b * j;
	}

	int mmc = a * b;
	int found = 0;
	for (int k = 0; k < a; k++)	{
		for (int l = 0; l < b; l++)	{
			if (multiplosA[k] == multiplosB[l]) {
				found = 1;
				mmc = multiplosA[k];
				break;
			}						
		}
		if (found == 1)	{
			break;
		}		
	}

	free(multiplosA);
	free(multiplosB);	
	printf("%d\n", mmc);
	return 0;
}