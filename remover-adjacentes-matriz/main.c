#include <stdio.h>

int main() {
    int l = 0, c = 0;
    int n_linhas = 5, n_colunas = 5;
    int m[5][5] = {{11,22,33,22,55},
                   {22,22,22,11,11},
                   {22,22,33,44,11},
                   {11,22,22,22,22},
                   {11,11,11,22,55}};


    int matrizCopia[n_linhas][n_colunas];
    for (int x = 0; x < n_linhas; ++x) {
        for (int y = 0; y < n_colunas; ++y) {
            matrizCopia[x][y] = m[x][y];
        }
    }

    int segurarNum = m[l][c];
    for (int i = 0; i < n_linhas; ++i) {
        for (int j = 0; j < n_colunas; ++j) {
            int posAbaixo= matrizCopia[i-1][j], posAcima = matrizCopia[i+1][j], posEsquerda = matrizCopia[i][j-1], posDireita = matrizCopia[i][j+1];
            if ((m[i][j] == segurarNum) && (posAbaixo == segurarNum || posAcima == segurarNum || posEsquerda == segurarNum || posDireita == segurarNum)) {
                m[i][j] = 0;
            }
        }
    }

    printf("Matriz inicial\n");
    for (int g = 0; g < 5; ++g) {
        printf("{%02d, %02d, %02d, %02d, %02d}\n",matrizCopia[g][0],matrizCopia[g][1],matrizCopia[g][2],matrizCopia[g][3],matrizCopia[g][4]);
    }

    printf("\n");

    printf("Matriz final\n");
    for (int p = 0; p < 5; ++p) {
        printf("{%02d, %02d, %02d, %02d, %02d}\n",m[p][0],m[p][1],m[p][2],m[p][3],m[p][4]);
    }
    return 0;
}

//#include "numeros_matriz.h"
//
//void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas]) {
//    int segurarNum = m[l][c];
//    m[l][c] = 0;
//    if (c < n_colunas-1)
//        if (m[l][c+1] == segurarNum)
//            remover_numeros_matriz(l,c+1,n_linhas,n_colunas,m);
//    if (c > 0)
//        if (m[l][c-1] == segurarNum)
//            remover_numeros_matriz(l,c-1,n_linhas,n_colunas,m);
//    if (l > 0)
//        if (m[l-1][c] == segurarNum)
//            remover_numeros_matriz(l-1,c,n_linhas,n_colunas,m);
//    if (l < n_linhas-1)
//        if (m[l+1][c] == segurarNum)
//            remover_numeros_matriz(l+1,c,n_linhas,n_colunas,m);
//}