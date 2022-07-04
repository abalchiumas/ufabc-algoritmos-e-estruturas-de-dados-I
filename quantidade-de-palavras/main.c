#include <stdio.h>

int main() {
    char texto[] = "Algoritmos   e   Estruturas de Dados I. Nessa disciplina,     serao vistas estruturas de dados como   listas, pilhas, filas e arvores  .   Tambem serao vistos algoritmos de  busca  e  ordenacao.";

    int contagemDeChar = 0, i = 0;
    while (texto[i+1] != '\0') {
        if (texto[i] == '.') {
            printf("%d\n",contagemDeChar+1);
            contagemDeChar = -1;
            i++;
            continue;
        }
        if ((texto[i] == ' ') &&
        ((texto[i+1] >= 'a' && texto[i+1] <= 'z') ||
        (texto[i+1] >= 'A' && texto[i+1] <= 'Z') ||
        (texto[i+1] >= '0' && texto[i+1] <= '9'))) {
            contagemDeChar++;
        }
        i++;
    }
    printf("%d",contagemDeChar+1);
    return 0;
}
