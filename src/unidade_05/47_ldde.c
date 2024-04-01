#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *itemAnterior, *proximoItem;  // ponteiros para anterior e proximo na lista
} Item;

typedef struct tLista {
    Item *primeiroItem, *ultimoItem;   // ponteiros para as extremidades a lista
    int quantidade;                    // qtde de elementos na lista
} Lista;

// Aloca memoria para criar uma lista inicialmente vazia.
// Devolve o ponteiro para a lista alocada, com os campos inicializados:
// primeiro e ultimo vazios, e quantidade zero.
Lista * criaListaVazia() {
	Lista *novaLista = malloc(sizeof(Lista));
	novaLista->primeiroItem = NULL, novaLista->ultimoItem = NULL;
	novaLista->quantidade = 0;
	return novaLista;
}

// Recebe um inteiro x.
// Aloca memoria para criar um novo item.
// Inicializa o valor da chave com x e os ponteiros ant e prox com vazio.
Item * criaItem(const int chave) {
	Item *novoItem = malloc(sizeof(Item));
	novoItem->chave = chave;
	novoItem->itemAnterior = NULL, novoItem->proximoItem = NULL;
	return novoItem;
}

// Deve-se liberar primeiro a cadeia de itens.
// Depois, no final, liberar o ponteiro da lista.
void liberaLista(Lista *lista) {
	Item *itemAtual = lista->primeiroItem;
    while (itemAtual != NULL) {
        Item *itemTemporario = itemAtual;
        itemAtual = itemAtual->proximoItem;
        free(itemTemporario);
    }
    free(lista);
}

// Recebe um ponteiro para uma lista.
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia(const Lista *lista) { lista->quantidade == 0; }

// Imprime o conteudo da lista, do incio para o fim.
void imprimir(const Lista *lista) {
	Item *itemAtual = lista->primeiroItem;
    while (itemAtual != NULL) {
        printf("%d ", itemAtual->chave);
        itemAtual = itemAtual->proximoItem;
    }
    printf("\n");
}

// Imprime o conteudo da lista, do fim para o incio.
void imprimirReverso(const Lista *lista) {
	Item *itemAtual = lista->ultimoItem;
    while (itemAtual != NULL) {
        printf("%d ", itemAtual->chave);
        itemAtual = itemAtual->itemAnterior;
    }
    printf("\n");
}

// Recebe um ponteiro para uma lista e uma chave x.
// Insere x na lista, caso ja nao exista.
// Ignora insercao de chaves repetidas.
// Deve tratar os 4 casos:
// (1) insercao em uma lista vazia;
// Se a lista nao estiver vazia, deve-se buscar a posicao de insercao.
// (2) insercao no fim da lista;
// (3) insercao no inicio da lista;
// (4) insercao no meio da lista.
void inserir(Lista *lista, const int chave) {
	
}

// Recebe um ponteiro para uma lista e uma chave x.
// Se a lista nao estiver vazia, remove x da lista, caso exista.
// Deve tratar os 3 casos:
// (1) remocao do inicio da lista;
// (2) remocao do fim da lista;
// (3) remocao do meio da lista.
void remover(Lista *lista, const int chave) {
	
}

int main(void) {
	Lista *lista = criaListaVazia();
	int chave;
	char operacao;
	while (scanf(" %c", &operacao) != EOF) {
		switch (operacao) {
			case 'I':
				scanf(" %d", &chave);
				inserir(lista, chave);
				break;
			case 'E':
				scanf(" %d", &chave);
				remover(lista, chave);
				break;
			case 'M':
				imprimir(lista);
				break;
			case 'R':
				imprimirReverso(lista);
				break;
		}
	}	
	liberaLista(lista);
	return 0;
}