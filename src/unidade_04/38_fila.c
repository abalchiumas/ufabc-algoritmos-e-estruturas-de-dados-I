#include <stdio.h>
#include <stdlib.h>

typedef struct tFila {
    int *itens;       // ponteiro (vetor) de inteiros
    int inicio, fim;  // fila: acesso sempre pelo inicio e fim
    int tamanho;      // tamanho maximo alocado
} Fila;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Fila.
Fila * criaFilaVazia (const int tamanho) {
	Fila *fila = malloc(sizeof(Fila));
	fila->itens = malloc(tamanho * sizeof(int));
	fila->inicio = -1, fila->fim = -1, fila->tamanho = tamanho;
	return fila;
}

// Libera memoria: liberar fila->itens primeiro, depois a fila.
void liberaFila (Fila *fila) {
	free(fila->itens);
	free(fila);	
}

// Devolve 1 se Fila cheia, 0 caso contrario.
int cheia (const Fila *fila) { return fila->fim  == fila->tamanho - 1; }

// Devolve 1 se Fila vazia, 0 caso contrario.
int vazia (const Fila *fila) { return fila->inicio == -1; }

// Insere uma chave x no fim da Fila, caso nao esteja cheia.
void enfileirar (Fila *fila, const int item) { 
	if (!cheia(fila)) { 
		if (vazia(fila)) { fila->inicio = 0; }
		fila->itens[++fila->fim] = item; 
	}
}

// Remove uma chave do inicio da Fila, caso nao esteja vazia.
// Devolve a chave removida, ou -1 caso contrario.
int desenfileirar (Fila *fila) {
	if (!vazia(fila)) {
        int item = fila->itens[fila->inicio];
        if (fila->inicio == fila->fim) {
            fila->inicio = -1;
            fila->fim = -1;
        } else {
            fila->inicio++;
        }
		printf("%d\n", item);
        return item;
    }
    return -1;
}

int main(void) {
	int tamanhoFila, item;
	scanf ("%d", &tamanhoFila);
	Fila *fila = criaFilaVazia(tamanhoFila);
	char operacao;
    while (scanf (" %c", &operacao) != EOF) {
        switch (operacao) {
            case 'E':
				scanf ("%d", &item);
				enfileirar(fila, item);
				break;
            case 'D':
				desenfileirar(fila);
			    break;
        }
    }
	liberaFila(fila);
    return 0;
}