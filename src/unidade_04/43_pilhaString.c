#include <stdio.h>
#include <stdlib.h>

typedef struct tPilha {
    char **itens;   // ponteiro duplo (strings)
    int topo;       // pilha: acesso sempre pelo topo
    int tamanho;    // tamanho maximo alocado
} Pilha;

// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Pilha.
Pilha *criaPilhaVazia(const int tamanho) {
	Pilha *pilha = malloc(sizeof(Pilha));
	pilha->itens = malloc(tamanho * sizeof(char*));
	for (int i = 0; i < tamanho; i++) { pilha->itens[i] = malloc(100 * sizeof(char)); }
	pilha->topo = 0;
	pilha->tamanho = tamanho;	
	return pilha;
}

// Libera memoria: liberar pilha->itens primeiro, depois a pilha.
void liberaPilha(Pilha *pilha) {
	for (int i = 0; i < pilha->tamanho; i++) { free(pilha->itens[i]); }
	free(pilha->itens);
	free(pilha);
}

// Devolve 1 se Pilha cheia, 0 caso contrario.
int cheia(const Pilha *pilha) { return pilha->topo == pilha->tamanho; }

// Devolve 1 se Pilha vazia, 0 caso contrario.
int vazia(const Pilha *pilha) { return pilha->topo == 0; }

// Insere uma chave x no topo da Pilha, caso nao esteja cheia.
void empilha(Pilha *pilha, const char *item) { 
	if (!cheia(pilha)) {
        int counter;
		for (counter = 0; item[counter] != '\0'; counter++) { pilha->itens[pilha->topo][counter] = item[counter]; }
        pilha->itens[pilha->topo][counter] = '\0';
        pilha->topo++;
    }
 }

// Remove uma chave do topo da Pilha, caso nao esteja vazia.
void desempilha(Pilha *pilha) {	if (!vazia(pilha)) { pilha->topo--; } }

// Imprime o elemento do topo da pilha.
void imprimePilhaTopo(const Pilha *pilha) { if (!vazia(pilha)) { printf("%s\n", pilha->itens[pilha->topo - 1]); } }

// Imprime os elementos da pilha, do topo para a base.
void imprimePilhaTopoBase(const Pilha *pilha) {
    for (int i = pilha->topo - 1; i >= 0; i--) { printf("%s ", pilha->itens[i]); }
    printf("\n");
}

// Imprime os elementos da pilha, da base para o topo.
void imprimePilhaBaseTopo(const Pilha *pilha) {
    for (int i = 0; i < pilha->topo; i++) { printf("%s ", pilha->itens[i]); }
    printf("\n");
}

int main(void) {
	int tamanhoPilha;
	scanf ("%d", &tamanhoPilha);
	Pilha *pilha = criaPilhaVazia(tamanhoPilha);
	char operacao, item[100];
    while (scanf (" %c", &operacao) != EOF) {
        switch (operacao) {
            case 'E':
				scanf (" %s", &item);
				empilha(pilha, item);
				break;
            case 'D':
				desempilha(pilha);
			    break;
            case 'T':
				imprimePilhaTopo(pilha);
				break;
			case 'X':
				imprimePilhaTopoBase(pilha);
				break;
            case 'B':
				imprimePilhaBaseTopo(pilha);
			    break;
        }
    }
	liberaPilha(pilha);
    return 0;
}