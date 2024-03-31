#include <stdio.h>
#include <stdlib.h>

typedef struct tPilha {
    int *itens;     // ponteiro (vetor) de inteiros
    int topo;       // pilha: acesso sempre pelo topo
    int tamanho;    // tamanho maximo alocado
} Pilha;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Pilha.
Pilha *criaPilhaVazia (const int tamanho) {
	Pilha *pilha = malloc(sizeof(Pilha));
	pilha->itens = malloc(tamanho * sizeof(int));
	pilha->topo = 0;
	pilha->tamanho = tamanho;	
	return pilha;
}

// Libera memoria: liberar pilha->itens primeiro, depois a pilha.
void liberaPilha (Pilha *pilha) {
	free(pilha->itens);
	free(pilha);
}

// Devolve 1 se Pilha cheia, 0 caso contrario.
int cheia (const Pilha *pilha) { return pilha->topo == pilha->tamanho; }

// Devolve 1 se Pilha vazia, 0 caso contrario.
int vazia (const Pilha *pilha) { return pilha->tamanho == 0; }

// Insere uma chave x no topo da Pilha, caso nao esteja cheia.
void empilha (Pilha *pilha, int item) {
	if (!cheia(pilha)) {
        pilha->itens[pilha->topo++] = item;
    }
}

// Remove uma chave do topo da Pilha, caso nao esteja vazia.
// Devolve a chave removida, ou -1 caso contrario.
int desempilha (Pilha *pilha) {
	if (!vazia(pilha)) {
        return pilha->itens[--pilha->topo];
    }
    return -1;
}

// Imprime os elementos da pilha, um por linha, do topo para a base.
void imprimePilhaTopo (Pilha *pilha) {
	for (int i = pilha->topo - 1; i >= 0; i--) {
        printf("%d\n", pilha->itens[i]);
    }
}

// Imprime os elementos da pilha, um por linha, da base para o topo.
void imprimePilhaBase (Pilha *pilha) {
	for (int i = 0; i < pilha->topo; i++) {
        printf("%d\n", pilha->itens[i]);
    }
}

int main(void) {
	int tamanhoPilha, item;
	scanf ("%d", &tamanhoPilha);
	Pilha *pilha = criaPilhaVazia(tamanhoPilha);
	char operacao;
    while (scanf (" %c", &operacao) != EOF) {
        switch (operacao) {
            case 'E':
				scanf ("%d", &item);
				empilha(pilha, item);
				break;
            case 'D':
				desempilha(pilha);
			    break;
            case 'T':
				imprimePilhaTopo(pilha);
				break;
            case 'B':
				imprimePilhaBase(pilha);
			    break;
        }
    }
	liberaPilha(pilha);
    return 0;
}