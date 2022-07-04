#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int vetor[n];
    for (int i = 0; i < n; ++i) {
        int x = 0;
        scanf("%d", &x);
        vetor[i] = x;
    }

    int janelaStart1 = 0, janelaStart2= 0, janelaEnd1= 0, janelaEnd2= 0;
    int tamanhoJanela1 = -1;
    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            int tamanhoJanela2 = janelaEnd1 - janelaStart1;
            if (tamanhoJanela1 < tamanhoJanela2){
                janelaStart2 = janelaStart1;
                janelaEnd2 = janelaEnd1;
            }
            break;
        }

        if (vetor[i] < vetor[i+1]) {
            janelaEnd1 = i+1;
        }

        else if (vetor[i] > vetor[i+1]) {
            int tamanhoJanela2 = janelaEnd1 - janelaStart1;
            if (tamanhoJanela1 < tamanhoJanela2){
                tamanhoJanela1 = tamanhoJanela2;
                janelaStart2 = janelaStart1;
                janelaEnd2 = janelaEnd1;
            }
            janelaStart1 = janelaEnd1 = i+1;
        }
    }

    for (int i = janelaStart2; i <= janelaEnd2; i++ ) {
        printf("%d ", vetor[i]);
    }

    return 0;
}