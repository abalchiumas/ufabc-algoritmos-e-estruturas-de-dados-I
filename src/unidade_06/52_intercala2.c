#include <stdio.h>
#include <stdlib.h>

// Recebe um vetor, tal que vetor[0..tamanhoVetor1-1] e vetor[tamanhoVetor1..tamanhoVetor2-1] ordenados.
// Rearranja (por intercalacao) o vetor de modo que ele fique ordenado.
void intercala(int *vetor, const int tamanhoVetor1, const int tamanhoVetor2) {
    int tamanhoTotal = (tamanhoVetor1 + tamanhoVetor2), i = 0, j = tamanhoVetor1, k = 0;;
    int *vetorAuxiliar = malloc(tamanhoTotal * sizeof(int));
    while ((i < tamanhoVetor1) && (j < tamanhoTotal)) {
        if (vetor[i] < vetor[j]) { vetorAuxiliar[k++] = vetor[i++]; } 
        else { vetorAuxiliar[k++] = vetor[j++]; }
    }
    while (i < tamanhoVetor1) { vetorAuxiliar[k++] = vetor[i++]; }
    while (j < tamanhoTotal) { vetorAuxiliar[k++] = vetor[j++]; }
    for (i = 0; i < tamanhoTotal; i++) { vetor[i] = vetorAuxiliar[i]; }
    free(vetorAuxiliar);
}

void imprime(const int *vetor, const int tamanhoVetor1, const int tamanhoVetor2) {
    for (int i = 0; i < (tamanhoVetor1 + tamanhoVetor2); i++) { printf("%d\n", vetor[i]); }
}

int main() {
    int tamanhoVetor1, tamanhoVetor2;
    scanf("%d", &tamanhoVetor1);
    scanf("%d", &tamanhoVetor2);
    int *vetor = malloc((tamanhoVetor1 + tamanhoVetor2) * sizeof(int));    
    for (int i = 0; i < (tamanhoVetor1 + tamanhoVetor2); i++) { scanf("%d", &vetor[i]); }
    intercala(vetor, tamanhoVetor1, tamanhoVetor2);
    imprime(vetor, tamanhoVetor1, tamanhoVetor2);
    free(vetor);
    return 0;
}