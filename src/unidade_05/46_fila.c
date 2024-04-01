#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *proximoItem;  // ponteiro para proximo na lista
} Item;

typedef struct tFila {
    Item *inicio, *fim;   // ponteiro para o inicio e fim da fila
} Fila;

// Aloca memoria para criar uma fila inicialmente vazia.
// Devolve o ponteiro para a fila alocada, com os campos inicializados:
// inicio e fim vazios.
Fila *criaFilaVazia() {
	Fila *novaFila = malloc(sizeof(Fila));
	novaFila->inicio = NULL, novaFila->fim = NULL;
	return novaFila;
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
// Depois, no final, liberar o ponteiro da fila.
void liberaFila(Fila *fila) {
	Item *itemAtual = fila->inicio;
    while (itemAtual != NULL) {
        Item *itemTemporario = itemAtual;
        itemAtual = itemAtual->proximoItem;
        free(itemTemporario);
    }
    free(fila);
}

// Recebe um ponteiro para uma fila.
// Devolve 1 se fila vazia, 0 caso contrario.
int vazia(const Fila *fila) { return fila->inicio == NULL; }

// Imprime o conteudo da fila, do topo para a base.
void imprimir(const Fila *fila) {
	Item *itemAtual = fila->inicio;
    while (itemAtual != NULL) {
        printf("%d ", itemAtual->chave);
        itemAtual = itemAtual->proximoItem;
    }
	printf("\n");
}

// Recebe um ponteiro para uma fila e uma chave x.
// Insere x no fim da fila.
void enfileirar(Fila *fila, const int chave) {
	Item *itemNovo = criaItem(chave);
	if (vazia(fila)) { 
		fila->inicio = itemNovo;
		fila->fim = itemNovo;
	} else {
		fila->fim->proximoItem = itemNovo;
		fila->fim = itemNovo;
	}	
}

// Recebe um ponteiro para uma fila.
// Se fila nao vazia, remove elemento do inicio da fila.
// Devolve a chave removida.
// Devolve -1 se fila vazia.
int desenfileirar(Fila *fila) {
	if (vazia(fila)) { return -1; }
	Item *itemAntigo = fila->inicio;
	int chaveParaRemover = itemAntigo->chave;
	fila->inicio = fila->inicio->proximoItem;
	if (fila->inicio == NULL) { fila->fim = fila->inicio; }
	free(itemAntigo);
	printf("[ %d ]\n", chaveParaRemover);
	return chaveParaRemover;
}

int main(void) {
	Fila *fila = criaFilaVazia();

	int tamanhoFila, chave;
	scanf ("%d", &tamanhoFila);

	char operacao;
    while (scanf (" %c", &operacao) != EOF) {
        switch (operacao) {
            case 'E':
				scanf ("%d", &chave);
				enfileirar(fila, chave);
				break;
            case 'D':
				desenfileirar(fila);
			    break;
			case 'M':
				imprimir(fila);
				break;
        }
    }
	liberaFila(fila);
	return 0;
}