#include <stdio.h>

struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};
typedef struct Disciplina Disciplina;

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {
    Disciplina *requisito_inicial = NULL;
    *qtd = 0; int qntd =0;

    if (disciplina -> requisito != NULL){
        while (disciplina -> requisito != NULL){
            requisito_inicial = disciplina -> requisito;
            disciplina = requisito_inicial;
            qntd = qntd+1;
        }
        *qtd = qntd;
        return requisito_inicial;
    }
    return NULL;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
