#include <stdio.h>
#include <stdlib.h>

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante) {

    int *qntd = (int*) calloc(4,sizeof(int));

    for (int i = 0; i < n_discos; ++i) {
        if (discos[i][7] == 'A') {
            (qntd[0])++;
        }
        if (discos[i][7] == 'B') {
            (qntd[1])++;
        }
        if (discos[i][7] == 'C') {
            (qntd[2])++;
        }
        if (discos[i][7] == 'D') {
            (qntd[3])++;
        }
    }
    *quantidade_por_fabricante = qntd;
    return qntd;
}

int main() {

    int *quantidade_por_fabricante;

    char *discos[] = {"Modelo_A1","Modelo_A11",
                     "Modelo_A3","Modelo_B1",
                     "Modelo_C6","Modelo_D2",
                     "Modelo_D1","Modelo_B22"};
    int n_discos = 8;

    quantidade_discos(discos,n_discos,&quantidade_por_fabricante);

    printf("Modelo A: %d\n",quantidade_por_fabricante[0]);
    printf("Modelo B: %d\n",quantidade_por_fabricante[1]);
    printf("Modelo C: %d\n",quantidade_por_fabricante[2]);
    printf("Modelo D: %d\n",quantidade_por_fabricante[3]);

    return 0;
}
