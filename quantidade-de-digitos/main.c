#include <stdio.h>

int main() {
    unsigned int n = 0;
    scanf("%d", &n);
    unsigned int contador = 0;
    while (n != 0) {
        n = n/10;
        contador++;
    }
    printf("%d",contador);
    return 0;
}
