#include <stdio.h>
#include <stdlib.h>

typedef struct tFilaCircular {
    int *itens;       // ponteiro (vetor) de inteiros
    int inicio, fim;  // fila: acesso sempre pelo inicio e fim
    int tamanho;      // tamanho maximo alocado
} FilaCircular;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para FilaCircular.
FilaCircular *criaFilaCircularVazia(const int tamanho) {
	FilaCircular *fila = malloc(sizeof(FilaCircular));
	fila->itens = malloc(tamanho * sizeof(int));
	fila->inicio = -1, fila->fim = -1, fila->tamanho = tamanho - 1;
	return fila;
}

// Libera memoria: liberar fila->itens primeiro, depois a fila.
void liberaFilaCircular(FilaCircular *fila) {
	free(fila->itens);
	free(fila);
}

// Devolve 1 se FilaCircular cheia, 0 caso contrario.
int cheia(const FilaCircular *fila) { return ((fila->fim + 1) % fila->tamanho) == fila->inicio; }

// Devolve 1 se FilaCircular vazia, 0 caso contrario.
int vazia(const FilaCircular *fila) { return fila->inicio == -1; }

// Insere uma chave x no fim da FilaCircular, caso nao esteja cheia.
void enfileirar(FilaCircular *fila, const int item) {
	if (!cheia(fila)) {
        if (fila->inicio == -1) { fila->inicio = 0; }
        fila->fim = (fila->fim + 1) % fila->tamanho;
        fila->itens[fila->fim] = item;
    }
}

// Remove uma chave do inicio da FilaCircular, caso nao esteja vazia.
// Devolve a chave removida, ou -1 caso contrario.
int desenfileirar(FilaCircular *fila) {
	if (!vazia(fila)) {
        int item = fila->itens[fila->inicio];
        if (fila->inicio == fila->fim) {
            fila->inicio = -1;
            fila->fim = -1;
        } else { fila->inicio = (fila->inicio + 1) % fila->tamanho; }
        printf("%d\n", item);
        return item;
    }
    return -1; 
}

int main(void) {
	int tamanhoFila, item;
	scanf ("%d", &tamanhoFila);
	FilaCircular *fila = criaFilaCircularVazia(tamanhoFila);
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
	liberaFilaCircular(fila);
    return 0;
}