#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct tLista {
    int *itens;       // ponteiro (vetor) de inteiros
    int quantidade;   // qtde de elementos inseridos na lista
    int tamanho;      // tamanho maximo alocado 
} Lista;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Lista.
Lista *criaListaVazia (const int tamanho) {
	Lista *lista = malloc(sizeof(Lista));
	lista->itens = malloc(tamanho * sizeof(int));
	lista->quantidade = 0, lista->tamanho = tamanho;	
	return lista;
}

// Libera memoria: liberar lista->itens primeiro, depois a lista.
void liberaLista (Lista *lista) {
	free(lista->itens);
	free(lista);
}

// Devolve 1 se lista cheia, 0 caso contrario.
int cheia (const Lista *lista) { return lista->quantidade == lista->tamanho; }

// Devolve 1 se lista vazia, 0 caso contrario.
int vazia (const Lista *lista) { return lista->quantidade == 0; }

// insertion sort
void reordenarLista(Lista *lista) {
    int i, j, key;
    for (j = 1; j < lista->quantidade; j++) {
        key = lista->itens[j];
        i = j - 1;
        while (i >= 0 && lista->itens[i] > key) {
            lista->itens[i + 1] = lista->itens[i];
            i = i - 1;
        }
        lista->itens[i + 1] = key;
    }
}

int busca(Lista *lista, const int item) {
    for (int i = 0; i < lista->quantidade; i++) { if (lista->itens[i] == item) { return i; } }
    return -1;
}

// Insere uma chave x na lista, caso ja nao exista na lista.
// (Ou seja, nao pode inserir chaves repetidas na lista.)
void inserir (Lista *lista, const int item) {
	if ((!cheia(lista)) && (busca(lista, item) == -1)) {
        lista->itens[lista->quantidade++] = item;
        reordenarLista(lista);
    }
}

// Remove uma chave x da lista, caso exista.
void remover (Lista *lista, const int item) {
	int indexLista = busca(lista, item);
    if (indexLista != -1) {
        for (int i = indexLista; i < (lista->quantidade - 1); i++) { lista->itens[i] = lista->itens[i + 1]; }
        lista->quantidade--;
    }
}

void printLista(const Lista *lista) {
	for (int i = 0; i < lista->quantidade; i++) {
		printf("%d ", lista->itens[i]);
	}
	printf("\n");
}

int main(void) {
	int totalEntradas, item;
    scanf ("%d", &totalEntradas);
    Lista *lista = criaListaVazia(totalEntradas);
    char operacao;
	while (scanf (" %c", &operacao) != EOF) {
        switch (operacao) {
            case 'I':
				scanf (" %d", &item);
                inserir(lista, item);
                break;
            case 'R':
				scanf (" %d", &item);
                remover(lista, item);
                break;
            case 'B':
				scanf (" %d", &item);
				printf("%s\n", busca(lista, item) != -1 ? "SIM" : "NAO");
                break;
            case 'M':
                printLista(lista);
                break;
        }
    }
    liberaLista(lista);
    return 0;
}