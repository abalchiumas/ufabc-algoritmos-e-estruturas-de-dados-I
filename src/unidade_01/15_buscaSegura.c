#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int* vetor = malloc(n * sizeof(int));

	int counterLista = 0, inputLista;
	while(counterLista < n ) {
		scanf("%d", &inputLista);
		vetor[counterLista] = inputLista;
		counterLista++;
	}

	int counterBusca = 0, inputBusca;
	while(scanf("%d", &inputBusca) != EOF) {
		int checker = 0;
		for (int i = 0; i < counterLista; i++) {
			if (inputBusca == vetor[i]) {
				checker = 1;
				break;
			}
		}

		if (checker == 1) {
			printf("SIM\n");
		} else {
			printf("CHAVE NAO ENCONTRADA\n");
		}
		
		counterBusca++;
	}

	free(vetor);
	return 0;
}