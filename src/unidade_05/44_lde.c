#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *proximoItem;  // ponteiro para proximo da lista
} Item;

typedef struct tLista {
    Item *inicio;     // ponteiro para o inicio da lista
    int quantidade;   // qtde de elementos na lista
} Lista;

// Aloca memoria para criar uma lista inicialmente vazia.
// Devolve o ponteiro para a lista alocada, com os campos inicializados:
// inicio vazio e quantidade zero.
Lista *criaListaVazia() {
	Lista *listaNova = malloc(sizeof(Lista));
	listaNova->inicio = NULL;
	listaNova->quantidade = 0;
	return listaNova;
}

// Recebe um inteiro x.
// Aloca memoria para criar um novo item.
// Inicializa o valor da chave com x e o ponteiro prox com vazio.
Item *criaItem(const int chave) {
	Item *itemNovo = malloc(sizeof(Item));
	itemNovo->chave = chave;
	itemNovo->proximoItem = NULL;
	return itemNovo;
}

// Deve-se liberar primeiro a cadeia de itens.
// Depois, no final, liberar o ponteiro da lista.
void liberaLista(Lista *lista) {
	Item *itemAtual = lista->inicio;
	while (itemAtual != NULL) {
		Item *itemTemporario = itemAtual;
        itemAtual = itemAtual->proximoItem;
        free(itemTemporario);
	}
	free(lista);
}

// Recebe um ponteiro para uma lista.
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia(const Lista *lista) { return lista->inicio == NULL; }

// Imprime o conteudo da lista.
void imprimir(const Lista *lista) {
	Item *itemAtual = lista->inicio;
	while (itemAtual != NULL) {
		printf("%d ", itemAtual->chave);
		itemAtual = itemAtual->proximoItem;
	}
	printf("\n");
}

// Recebe o ponteiro da lista e uma chave x.
// Devolve 1 se a lista contem a chave x, ou 0 caso contrario.
int buscar(const Lista *lista, const int chave) {
	Item *itemAtual = lista->inicio;
    while (itemAtual != NULL) {
        if (itemAtual->chave == chave) { return 1; }
        itemAtual = itemAtual->proximoItem;
    }
    return 0;
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
void inserir(Lista *lista, int chave) {
	if (!buscar(lista, chave)) {
        Item *itemNovo = criaItem(chave);
        if (vazia(lista)) { lista->inicio = itemNovo; } 
		else {
            Item *itemAtual = lista->inicio, *itemAnterior = NULL;
            while ((itemAtual != NULL) && (itemAtual->chave < chave)) {
                itemAnterior = itemAtual;
                itemAtual = itemAtual->proximoItem;
            }
            if (itemAnterior == NULL) {
                itemNovo->proximoItem = lista->inicio;
                lista->inicio = itemNovo;
            } else {
                itemNovo->proximoItem = itemAnterior->proximoItem;
                itemAnterior->proximoItem = itemNovo;
            }
        }
        lista->quantidade++;
    }
}

// Recebe um ponteiro para uma lista e uma chave x.
// Se a lista nao estiver vazia, remove x da lista, caso exista.
// Deve tratar os 3 casos:
// (1) remocao do inicio da lista;
// (2) remocao do fim da lista;
// (3) remocao do meio da lista.
void remover(Lista *lista, int chave) {
	Item *itemAtual = lista->inicio, *itemAnterior = NULL;
    while (itemAtual != NULL && itemAtual->chave != chave) {
        itemAnterior = itemAtual;
        itemAtual = itemAtual->proximoItem;
    }
    if (itemAtual != NULL) {
        if (itemAnterior == NULL) { lista->inicio = itemAtual->proximoItem; } 
		else { itemAnterior->proximoItem = itemAtual->proximoItem; }
        free(itemAtual);
        lista->quantidade--;
    }
}

int main(void) {
	char operacao;
	Lista *lista = criaListaVazia();
	int chave;
	while (scanf(" %c", &operacao) != EOF) {
		switch (operacao) {
			case 'I':
				scanf("%d", &chave);
				inserir(lista, chave);
				break;
			case 'R':
				scanf("%d", &chave);
				remover(lista, chave);
				break;
			case 'B':
				scanf("%d", &chave);
				printf("%s\n", buscar(lista, chave) ? "SIM" : "NAO");
				break;
			case 'L':
				imprimir(lista);
				break;
		}
	}
	liberaLista(lista);
	return 0;
}