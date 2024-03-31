#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *proximoItem;  // ponteiro para proximo na lista
} Item;

typedef struct tPilha {
    Item *topo;        // ponteiro para o topo da pilha
    int quantidade;    // qtde de elementos na pilha
} Pilha;

// Aloca memoria para criar uma pilha inicialmente vazia.
// Devolve o ponteiro para a pilha alocada, com os campos inicializados:
// topo vazio e quantidade zero.
Pilha *criaPilhaVazia() {

}

// Recebe um inteiro x.
// Aloca memoria para criar um novo item.
// Inicializa o valor da chave com x e o ponteiro prox com vazio.
Item *criaItem(int chave) {

}

// Deve-se liberar primeiro a cadeia de itens.
// Depois, no final, liberar o ponteiro da pilha.
void liberaPilha(Pilha *pilha) {

}

// Recebe um ponteiro para uma pilha.
// Devolve 1 se pilha vazia, 0 caso contrario.
int vazia(Pilha *pilha) {

}

// Imprime o conteudo da pilha, do topo para a base.
void imprimir(Pilha *pilha) {

}

// Recebe um ponteiro para uma pilha e uma chave x.
// Insere x no topo da pilha.
void empilha(Pilha *pilha, int chave) {

}

// Recebe um ponteiro para uma pilha.
// Se pilha nao vazia, remove elemento do topo da pilha.
// Devolve a chave removida.
// Devolve -1 se pilha vazia.
int desempilha(Pilha *pilha) {

}

int main(void) {
	printf("Hello!");
	return 0;
}