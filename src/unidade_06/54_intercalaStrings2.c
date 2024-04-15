#include <stdio.h>
#include <stdlib.h>

char *intercala(const char *su, int inicioVetor1, int fimVetor1, int inicioVetor2, int fimVetor2) {
    int tamanhoVetor1 = (fimVetor1 - inicioVetor1 + 1);
    int tamanhoVetor2 = (fimVetor2 - inicioVetor2 + 1);
    char *vetorResultante = malloc((tamanhoVetor1 + tamanhoVetor2) * sizeof(char));
    int i = inicioVetor1, j = inicioVetor2, k = 0;
    while ((i <= fimVetor1) && (j <= fimVetor2)) {
        if (su[i] < su[j]) { vetorResultante[k++] = su[i++]; } 
        else { vetorResultante[k++] = su[j++]; }
    }
    while (i <= fimVetor1) { vetorResultante[k++] = su[i++]; }
    while (j <= fimVetor2) { vetorResultante[k++] = su[j++]; }
    return vetorResultante;
}

int main () {
    int tamanhoVetor1, tamanhoVetor2;
    scanf("%d %d", &tamanhoVetor1, &tamanhoVetor2);
    char *su = malloc((tamanhoVetor1 + tamanhoVetor2) * sizeof(char));
    scanf("%s", su);
    char *vetorResultante = intercala(su, 0, (tamanhoVetor1 - 1), tamanhoVetor1, (tamanhoVetor1 + tamanhoVetor2 - 1));
    printf("%s\n", vetorResultante);
    free(su);
    free(vetorResultante);
    return 0;
}