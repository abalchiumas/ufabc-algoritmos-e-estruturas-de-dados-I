#include <stdio.h>
#include <stdlib.h>

// Recebe dois vetores ordenados, vetor1 e vetor2, e os seus respectivos tamanhos, tamanhoVetor1 e tamanhoVetor2.
// Devolve um novo vetor ordenado com a intercalacao de vetor1 e vetor2.
char *intercala(const char *vetor1, const char *vetor2, const int tamanhoVetor1, const int tamanhoVetor2) {
	char *vetorResultante = malloc((tamanhoVetor1 + tamanhoVetor2) * sizeof(char));
    int i = 0, j = 0, k = 0;
    while ((i < tamanhoVetor1) && (j < tamanhoVetor2)) {
        if (vetor1[i] < vetor2[j]) { vetorResultante[k++] = vetor1[i++]; } 
		else { vetorResultante[k++] = vetor2[j++]; }
    }
    while (i < tamanhoVetor1) { vetorResultante[k++] = vetor1[i++]; }
    while (j < tamanhoVetor2) { vetorResultante[k++] = vetor2[j++]; }
    return vetorResultante;
}

void imprime(const char *vetor, const int tamanhoVetor) {
    for (int i = 0; i < tamanhoVetor; i++) { printf("%c", vetor[i]); }
    printf("\n");
}

int main () {
    int tamanhoVetor1, tamanhoVetor2, i;

    scanf ("%d", &tamanhoVetor1);
    char *vetor1 = malloc(tamanhoVetor1 * sizeof(char));
    for (i = 0; i < tamanhoVetor1; i++) { scanf (" %c", &vetor1[i]); }

    scanf ("%d", &tamanhoVetor2);
    char *vetor2 = malloc (sizeof (char) * tamanhoVetor2);
    for (i = 0; i < tamanhoVetor2; i++) { scanf (" %c", &vetor2[i]); }

	char *vetorResultante = intercala(vetor1, vetor2, tamanhoVetor1, tamanhoVetor2);
    imprime (vetorResultante, (tamanhoVetor1 + tamanhoVetor2));

    free (vetor1);
    free (vetor2);
	free (vetorResultante);
    return 0;
}