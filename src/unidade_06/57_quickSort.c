#include <stdio.h>
#include <stdlib.h>

// Imprime o conteudo do vetor v[e..d-1].
void imprimir(const int *vetor, const int e, const int d) {
	for (int i = e; i < d; i++) {
        if (i > e) { printf(" "); }
        printf("%d", vetor[i]);
    }
    printf("\n");
}

// Troca os elementos v[i] <-> v[j].
void troca(int *vetor, const int i, const int j) {
	int tmp = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = tmp;	
}

// Recebe um vetor v[e..d-1] e indice do Pivo(= v[p]).
// Rearranja o vetor de modo que:
// v[e..i-1] <= Pivo <= v[i+1..d-1]
// Devolve o indice atualizado do Pivo.
int particiona(int *vetor, const int e, const int d, const int indexPivo) {
    int chavePivo = vetor[indexPivo];
    troca(vetor, indexPivo, (d - 1));
    int i = (e - 1);
    for (int j = e; j < (d - 1); j++) { if (vetor[j] <= chavePivo) { troca(vetor, ++i, j); } }
    troca(vetor, (i + 1), (d - 1));
    printf("Pivo: [%d] %d\n", (i + 1), chavePivo);
    imprimir(vetor, e, d);
    return (i + 1);
}

// Recebe um vetor v[e..d-1] e ordena recursivamente.
void quickSortR(int *vetor, const int e, const int d) {
    if (e < (d - 1)) {
        int novoIndexPivo = particiona(vetor, e, d, d - 1);
        quickSortR(vetor, e, novoIndexPivo);
        quickSortR(vetor, novoIndexPivo + 1, d);
    }
}

// Recebe o vetor e o seu tamanho e ordena o vetor com o algoritmo QuickSort.
void quickSort(int *vetor, const int tamanhoVetor) { quickSortR(vetor, 0, tamanhoVetor); }

int main() {
    int tamanhoVetor;
    scanf("%d", &tamanhoVetor);
    int *vetor = malloc(tamanhoVetor * sizeof(int));
    for(int i = 0; i < tamanhoVetor; i++) { scanf("%d", &vetor[i]); }
    quickSort(vetor, tamanhoVetor);
    imprimir(vetor, 0, tamanhoVetor);
    free(vetor);
    return 0;
}