#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_compactado = 6;
    int vetor[] = {1, 2, 3, 5, 2, 8};

    int n_expandido = 0;

    for (int a = 1; a < n_compactado; a+=2) {
        n_expandido += vetor[a];
    }

    int *expandir_vetor = (int*) calloc(n_expandido, sizeof(int));

    int guardaIndex = 0;
    for (int b = 0; b < n_compactado; b+=2) {
        for (int c = 0; c < vetor[b+1]; ++c) {
            expandir_vetor[guardaIndex] = vetor[b];
            guardaIndex++;
        }
    }

    for (int i = 0; i < n_expandido; ++i) {
        printf("expandir_vetor[%d] = %d\n", i, expandir_vetor[i]);
    }

    return 0;
}
