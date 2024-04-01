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
    Pilha *novaPilha = malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    novaPilha->quantidade = 0;
    return novaPilha;
}

// Recebe um inteiro x.
// Aloca memoria para criar um novo item.
// Inicializa o valor da chave com x e o ponteiro prox com vazio.
Item *criaItem(const int chave) {
    Item *novoItem = malloc(sizeof(Item));
    novoItem->chave = chave;
    novoItem->proximoItem = NULL;
    return novoItem;
}

// Deve-se liberar primeiro a cadeia de itens.
// Depois, no final, liberar o ponteiro da pilha.
void liberaPilha(Pilha *pilha) {
    Item *pilhaTopo = pilha->topo;
	while (pilhaTopo != NULL) {
		Item *itemTemporario = pilhaTopo;
        pilhaTopo = pilhaTopo->proximoItem;
        free(itemTemporario);
	}
	free(pilha);
}

// Recebe um ponteiro para uma pilha.
// Devolve 1 se pilha vazia, 0 caso contrario.
int vazia(const Pilha *pilha) { return pilha->topo == NULL; }

// Imprime o conteudo da pilha, do topo para a base.
void imprimir(const Pilha *pilha) {
    Item *itemAtual = pilha->topo;
    while (itemAtual != NULL) {
        printf("%d ", itemAtual->chave);
        itemAtual = itemAtual->proximoItem;
    }
    printf("\n");
}

// Recebe um ponteiro para uma pilha e uma chave x.
// Insere x no topo da pilha.
void empilha(Pilha *pilha, const int chave) {
    Item *novoItem = criaItem(chave);
    novoItem->proximoItem = pilha->topo;
    pilha->topo = novoItem;
}

// Recebe um ponteiro para uma pilha.
// Se pilha nao vazia, remove elemento do topo da pilha.
// Devolve a chave removida.
// Devolve -1 se pilha vazia.
int desempilha(Pilha *pilha) {
    if (vazia(pilha)) { return -1; }
    else {
        Item *topoAntigo = pilha->topo;
        int chaveParaRemover = topoAntigo->chave;
        pilha->topo = topoAntigo->proximoItem;
        free(topoAntigo);
        printf("[ %d ]\n", chaveParaRemover);
        return chaveParaRemover;
    }   
}

int main(void) {
	Pilha *pilha = criaPilhaVazia();
    char operacao;
    int chave;
    while(scanf(" %c", &operacao) != EOF) {
        switch (operacao) {
            case 'E':
                scanf(" %d", &chave);
                empilha(pilha, chave);
                break;
            case 'D':
                desempilha(pilha);
                break;
            case 'M':
                imprimir(pilha);
                break;
        }
    }
    liberaPilha(pilha);
	return 0;
}