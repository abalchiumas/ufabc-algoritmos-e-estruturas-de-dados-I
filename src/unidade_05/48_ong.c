#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tItem {
    char *palavra;
	int contagem;
    struct tItem *itemAnterior, *proximoItem;
} Item;

typedef struct tLista {
    Item *primeiroItem, *ultimoItem;
} Lista;

Lista *criaListaVazia() {
	Lista *novaLista = malloc(sizeof(Lista));
	novaLista->primeiroItem = NULL, novaLista->ultimoItem = NULL;
	return novaLista;
}

Item *criaItem(const char *palavra) {
	Item *novoItem = malloc(sizeof(Item));
	novoItem->palavra = malloc((strlen(palavra) + 1) * sizeof(char));
	strcpy(novoItem->palavra, palavra);
	novoItem->contagem = 1;
	novoItem->itemAnterior = NULL, novoItem->proximoItem = NULL;
	return novoItem;
}

void liberaLista(Lista *lista) {
	Item *itemAtual = lista->primeiroItem;
    while (itemAtual != NULL) {
        Item *itemTemporario = itemAtual;
        itemAtual = itemAtual->proximoItem;
        free(itemTemporario->palavra);
        free(itemTemporario);  
    }
    free(lista);
}

void imprimir(const Lista *lista) {
	Item *itemAtual = lista->primeiroItem;
    while (itemAtual != NULL) {
        printf("%s [%d]\n", itemAtual->palavra, itemAtual->contagem);
        itemAtual = itemAtual->proximoItem;
    }
    printf("\n");
}

void atualizarLista(Lista *lista, const char *palavra) {
Item *atual = lista->primeiroItem;
    Item *anterior = NULL;

    while ((atual != NULL) && (strcmp(atual->palavra, palavra) != 0)) {
        anterior = atual;
        atual = atual->proximoItem;
    }

    if (atual == NULL) {
        Item *novoItem = criaItem(palavra);

        if (lista->primeiroItem == NULL) { lista->primeiroItem = lista->ultimoItem = novoItem; }
		else {
            lista->ultimoItem->proximoItem = novoItem;
            novoItem->itemAnterior = lista->ultimoItem;
            lista->ultimoItem = novoItem;
        }
    } else {
        atual->contagem++;
        while ((atual->itemAnterior != NULL) && (atual->itemAnterior->contagem < atual->contagem)) {
            Item *anterior = atual->itemAnterior;

            if (anterior->itemAnterior != NULL) { anterior->itemAnterior->proximoItem = atual; } 
			else { lista->primeiroItem = atual; }

            if (atual->proximoItem != NULL) { atual->proximoItem->itemAnterior = anterior; }
			else { lista->ultimoItem = anterior; }

            anterior->proximoItem = atual->proximoItem;
            atual->proximoItem = anterior;
            atual->itemAnterior = anterior->itemAnterior;
            anterior->itemAnterior = atual;
        }
    }
}

int main(void) {
	Lista *lista = criaListaVazia();
    char *palavra = malloc(101 * sizeof(char));
    while (scanf(" %s", palavra) != EOF) { atualizarLista(lista, palavra); }
    imprimir(lista);
    liberaLista(lista);
    return 0;
}