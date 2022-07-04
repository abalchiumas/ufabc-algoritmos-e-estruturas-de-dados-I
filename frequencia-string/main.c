#include <stdio.h>
#include <stdlib.h>

int main() {

    char str[] = "     so            R T           ";
    char texto[] = "Alguns algoritmos de ordenacao: mergesort, quicksort, heapsort, countingsort, radixsort, shellsort.";

    int *qtd = (int*) malloc(sizeof(int));
    *qtd = 0;

    //TRATAMENTO TEXTO
    int a = 0;
    char copiaTexto[256];
    while (texto[a] != '\0') {
        copiaTexto[a] = texto[a];
        a++;
    }
    copiaTexto[a] = '\0';
    printf("\ncopia do texto: '%s'\n",copiaTexto);

    int b = 0;
    char copiaTextoSemCap[256];
    while (copiaTexto[b] != '\0') {
        if ((copiaTexto[b] >= 'A') && (copiaTexto[b] <= 'Z')) {
            copiaTexto[b] += 'a' - 'A';
        }
        copiaTextoSemCap[b] = copiaTexto[b];
        b++;
    }
    copiaTextoSemCap[b] = '\0';
    printf("copia do texto, sem caps: '%s'\n",copiaTextoSemCap);

    int c = 0, d = 0;
    char copiaTextoSemEspaco[256];
    while (copiaTextoSemCap[c] != '\0') {
        if (copiaTextoSemCap[c] != ' ') {
            copiaTextoSemEspaco[d] = copiaTextoSemCap[c];
            d++;
        }
        c++;
    }
    copiaTextoSemEspaco[d] = '\0';
    printf("copia do texto, sem espaços: '%s'\n",copiaTextoSemEspaco);

    int tamanhoTexto = 0;
    while (copiaTextoSemEspaco[tamanhoTexto] != '\0') {
        tamanhoTexto++;
    }
    printf("tamanho do texto: %d\n",tamanhoTexto);

    //TRATAMENTO STRING
    int e = 0;
    char copiaStr[256];
    while (str[e] != '\0') {
        copiaStr[e] = str[e];
        e++;
    }
    copiaStr[e] = '\0';
    printf("\ncopia da string: '%s'\n",copiaStr);

    int f = 0;
    char copiaStrSemCap[256];
    while (copiaStr[f] != '\0') {
        if ((copiaStr[f] >= 'A') && (copiaStr[f] <= 'Z')) {
            copiaStr[f] += 'a' - 'A';
        }
        copiaStrSemCap[f] = copiaStr[f];
        f++;
    }
    copiaStrSemCap[f] = '\0';
    printf("copia da string, sem caps: '%s'\n",copiaStrSemCap);

    int g = 0, h = 0;
    char copiaStrSemEspaco[256];
    while (copiaStrSemCap[g] != '\0') {
        if (copiaStrSemCap[g] != ' ') {
            copiaStrSemEspaco[h] = copiaStrSemCap[g];
            h++;
        }
        g++;
    }
    copiaStrSemEspaco[h] = '\0';
    printf("copia da string, sem espaços: '%s'\n",copiaStrSemEspaco);

    int tamanhoStr = 0;
    while (copiaStrSemEspaco[tamanhoStr] != '\0') {
        tamanhoStr++;
    }
    printf("tamanho da string: %d\n",tamanhoStr);

    int i = 0;
    while (copiaTextoSemEspaco[i] != '\0') {
        int k = 1;
        for (int j = 0; j < tamanhoStr; ++j) {
            if (copiaTextoSemEspaco[i+j] != copiaStrSemEspaco[j]) {
                k = 0;
                break;
            }
        }
        if (k == 1) {
            (*qtd)++;
        }
        i++;
    }

    printf("\nqtd: %d\n", *qtd);
    return 0;
}