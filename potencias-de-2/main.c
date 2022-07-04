# include <stdio.h>

int main() {
    unsigned int n = 0;
    unsigned int contador = 0;

    scanf("%d",&n);
    for (unsigned int i = 0; i < n; ++i) {
        unsigned int x = 0;
        scanf("%d",&x);
        while (x % 2 == 0) {
            if (x == 2) {
                contador++;
                break;
            }
            x = x / 2;
        }
    }
    printf("%d\n",contador);
    return 0;
}