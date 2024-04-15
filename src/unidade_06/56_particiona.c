#include <stdio.h>
#include <stdlib.h>

int rearranjaVetor(int *vetor, const int tamanhoVetor, const int indexPivo) {
    int pivo = vetor[indexPivo];
    vetor[indexPivo] = vetor[tamanhoVetor - 1];
    vetor[tamanhoVetor - 1] = pivo;
    int counter = 0;
    for (int j = 0; j < (tamanhoVetor - 1); j++) {
        if (vetor[j] <= pivo) {
            int tmp = vetor[counter];
            vetor[counter] = vetor[j];
            vetor[j] = tmp;
            counter++;
        }
    }
    vetor[tamanhoVetor - 1] = vetor[counter];
    vetor[counter] = pivo;
    return counter;
}

void imprime(const int *vetor, const int tamanhoVetor) {
	for (int i = 0; i < tamanhoVetor; i++) { printf("%d ", vetor[i]); }
    printf("\n");
}

int main(void) {
	int tamanhoVetor, indexPivo;
    scanf("%d %d", &tamanhoVetor, &indexPivo);
	int *vetor = malloc(tamanhoVetor * sizeof(int));
	for (int i = 0; i < tamanhoVetor; i++) { scanf("%d ", &vetor[i]); }
	printf("%d\n", rearranjaVetor(vetor, tamanhoVetor, indexPivo));
	imprime(vetor, tamanhoVetor);
    free(vetor);
	return 0;
}