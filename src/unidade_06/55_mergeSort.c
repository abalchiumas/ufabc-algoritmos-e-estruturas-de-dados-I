#include <stdio.h>
#include <stdlib.h>

// Recebe um vetor e o seu tamanho.
// Imprime o conteudo do vetor.
void imprimir(const int *vetor, const int tamanhoVetor) {
    for (int i = 0; i < tamanhoVetor; i++) { printf("%d ", vetor[i]); }
    printf("\n");
}

// Recebe um vetor bipartido: v[e..m-1] e v[m..d-1] ordenados.
// Intercala os elementos de modo que v[e..d-1] fique ordenado.
// Usa um vetor auxiliar de tamanho n = d-e.
// Imprima o conteudo do vetor auxiliar antes de liberar a memoria e finalizar o procedimento.
void intercala(int *vetor, const int e, const int m, const int d) {
    int tamanhoVetorAuxiliar = d - e;
    int *vetorAuxiliar = malloc(tamanhoVetorAuxiliar * sizeof(int));
    int i = e, j = m, k = 0;
    while (i < m && j < d) {
        if (vetor[i] < vetor[j]) { vetorAuxiliar[k++] = vetor[i++]; }
        else { vetorAuxiliar[k++] = vetor[j++]; }
    }
    while (i < m) { vetorAuxiliar[k++] = vetor[i++]; }
    while (j < d) { vetorAuxiliar[k++] = vetor[j++]; }
    for (i = e, k = 0; i < d; i++, k++) { vetor[i] = vetorAuxiliar[k]; }
    imprimir(vetorAuxiliar, tamanhoVetorAuxiliar);
    free(vetorAuxiliar);
}

// Recebe um vetor v[e..d-1] e ordena recursivamente.
void mergeSortR(int *vetor, const int e, const int d) {
    if ((d - e) > 1) {
        int m = ((e + d) / 2);
        mergeSortR(vetor, e, m);
        mergeSortR(vetor, m, d);
        intercala(vetor, e, m, d);
    }
}

// Recebe um vetor e o seu tamanho.
// Ordena o vetor com o algoritmo mergeSort.
void mergeSort(int *vetor, const int tamanhoVetor) { mergeSortR(vetor, 0, tamanhoVetor); }

int main() {
    int tamanhoVetor;
    scanf("%d", &tamanhoVetor);
    int *vetor = malloc(tamanhoVetor * sizeof(int));
    for(int i = 0; i < tamanhoVetor; i++) { scanf("%d", &vetor[i]); }
    mergeSort(vetor, tamanhoVetor);
    free(vetor);
    return 0;
}
