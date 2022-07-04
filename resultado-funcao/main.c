#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 2, b = 3;

    int *resultado = (int*) calloc(1,sizeof(int));
    int *somaInterna = (int*) calloc(1,sizeof(int));
    int *somaExterna = (int*) calloc(1,sizeof(int));

    if ((resultado == NULL) || (somaInterna == NULL) || (somaExterna == NULL)) {
        printf("Exception thrown: null pointer.\n");
    } else {
        for (int i = 1; i <= a; ++i) {
            *somaInterna = 0;
            for (int j = 1; j <= b; ++j) {
                *somaInterna = *somaInterna + (i*j + 10);
            }
            *somaExterna = *somaExterna + ((5 * i) * (*somaInterna));
        }
        free(somaInterna);

        *resultado = *somaExterna;
        free(somaExterna);

        printf("resultado = %d\n", *resultado);
        free(resultado);
    }
    return 0;
}
