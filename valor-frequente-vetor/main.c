#include <stdio.h>

int main() {
    int n = 17;
    int v[] = {1,1,4,6,4,4,4,4,4,4,4,48,2,132,1,6,8};

    int valorFrequente = 0, contador = 1;
    for (int i = 0; i < n; ++i) {

        int contadorSecundario = 0;
        for (int j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                contadorSecundario++;
            }
            if (contadorSecundario > contador) {
                contador = contadorSecundario;
                valorFrequente = v[i];
            }
        }
    }
    printf("valor mais frequente: %d\n", valorFrequente);
    printf("contagem: %d\n", contador);
    return 0;
}
