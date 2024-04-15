#include <stdio.h>
#include <stdlib.h>

// Recebe dois vetores ordenados, vetor1 e vetor2, e os seus respectivos tamanhos, tamanhoVetor1 e tamanhoVetor2.
// Devolve um novo vetor ordenado com a intercalacao de vetor1 e vetor2.
int *intercala(int *vetor1, int *vetor2, const int tamanhoVetor1, const int tamanhoVetor2) {
	int *vetorResultante = malloc((tamanhoVetor1 + tamanhoVetor2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < tamanhoVetor1 && j < tamanhoVetor2) {
        if (vetor1[i] < vetor2[j]) { vetorResultante[k++] = vetor1[i++]; } 
		else { vetorResultante[k++] = vetor2[j++]; }
    }
    while (i < tamanhoVetor1) { vetorResultante[k++] = vetor1[i++]; }
    while (j < tamanhoVetor2) { vetorResultante[k++] = vetor2[j++]; }
    return vetorResultante;
}

void imprime (const int *vetor, const int tamanhoVetor) {
    printf ("[");
    for (int i = 0; i < tamanhoVetor; i++) { printf ("%d ", vetor[i]); }
    printf ("]\n");
}

int main () {
    int tamanhoVetor1, tamanhoVetor2;
    scanf("%d", &tamanhoVetor1);
    scanf("%d", &tamanhoVetor2);
    int *vetor1 = malloc(tamanhoVetor1 * sizeof(int)), *vetor2 = malloc(tamanhoVetor2 * sizeof(int));
    for (int i = 0; i < tamanhoVetor1; i++) { scanf("%d", &vetor1[i]); }
    for (int i = 0; i < tamanhoVetor2; i++) { scanf("%d", &vetor2[i]); }
    int *vetorResultante = intercala(vetor1, vetor2, tamanhoVetor1, tamanhoVetor2);
    imprime(vetorResultante, (tamanhoVetor1 + tamanhoVetor2));
    free(vetor1);
    free(vetor2);
    free(vetorResultante);
    return 0;
}