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
	lista->quantidade = 0;
	lista->tamanho = tamanho;	
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

// Insere uma chave x na lista, caso ja nao exista na lista.
// (Ou seja, nao pode inserir chaves repetidas na lista.)
void inserir (Lista *lista, int x) {
    if (cheia(lista)) { return; }
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->itens[i] == x) { return; }
    }
    lista->itens[lista->quantidade] = x;
    lista->quantidade++;
}

// Remove uma chave x da lista, caso exista.
void remover (Lista *lista, int x) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->itens[i] == x) {
            for (int j = i; j < lista->quantidade - 1; j++) {
                lista->itens[j] = lista->itens[j + 1];
            }
            lista->quantidade--;
            return;
        }
    }
}

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

int main(void) {
	int quantidadeEntradas, entrada;
    scanf ("%d", &quantidadeEntradas); //quantidade e operacoes na lista
    Lista *lista = criaListaVazia(quantidadeEntradas);
    char operacao;
    for (int i = 0; i < quantidadeEntradas; i++) {
        scanf (" %c", &operacao);  // ler com espaco na frente para dar certo!
        scanf ("%d", &entrada);
        switch (operacao) {
            case 'I':
                inserir(lista, entrada);
                break;
            case 'E':
                remover(lista, entrada);
                break;
        }
    }
    reordenarLista(lista);
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d\n", lista->itens[i]);
    }
    liberaLista(lista);
    return 0;
}