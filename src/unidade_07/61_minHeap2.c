#include <stdio.h>
#include <stdlib.h>

typedef struct tHeap {
    int *vetor;
    int tamanho;    // tamanho do vetor alocado
    int quantidade; // qtde elementos inseridos
} Heap;

// Recebe o tamanho do vetor para o heap.
// Aloca um heap, aloca o vetor do heap, ajusta o tamanho,
// a quantidade inicia com zero.
// Devolve um ponteiro para o heap recem-criado.
Heap *criaHeapVazio(const int tamanhoHeap) {
	Heap *novoHeap = malloc(sizeof(Heap));
	novoHeap->vetor = malloc(tamanhoHeap * sizeof(int));
	novoHeap->tamanho = tamanhoHeap ,novoHeap->quantidade = 0;
	return novoHeap;
}

// Recebe um ponteiro para um heap.
// Libera o vetor e depois o ponteiro do heap.
void liberaHeap(Heap *heap) {
    free(heap->vetor);
	free(heap);
}

// Devolve o indice do pai de i.
int pai(const int i) { return((i - 1) / 2); }

// Devolve o indice do filho direito de i.
int filhoDir(const int i) { return((2 * i) + 2); }

// Recebe um ponteiro para um heap.
// Devolve o indice do ultimo pai: chao(n/2)-1,
// onde n é a quantidade de elementos do heap.
int ultimoPai(const Heap *heap) { return pai(heap->quantidade - 1); }

// Recebe um ponteiro para um heap e um indice pai.
// Se a chave do pai eh maior que a de algum filho,
// faz a troca e chama recursivamente.
// A troca deve ser feita pela chave do menor filho.
// No caso de empate, prefira trocar com o filho esquerdo.
void desceChave(Heap *heap, const int pai) {
    int filhoDireito = filhoDir(pai), filhoEsquerdo = (filhoDireito - 1), menor = pai;
    if ((filhoEsquerdo < heap->quantidade) && (heap->vetor[filhoEsquerdo] < heap->vetor[menor])) { menor = filhoEsquerdo; }
    if ((filhoDireito < heap->quantidade) && (heap->vetor[filhoDireito] < heap->vetor[menor])) { menor = filhoDireito; }
    if (menor != pai) {
        int tmp = heap->vetor[pai];
        heap->vetor[pai] = heap->vetor[menor];
        heap->vetor[menor] = tmp;
        desceChave(heap, menor);
    }
}

// Recebe um ponteiro para um heap.
// Constroi um heap, chamando desceChave() para 
// cada um dos pais, do ultimo pai ate a raiz.
void constroiHeap(Heap *heap) { for (int i = ((heap->quantidade / 2) - 1); i >= 0; i--) { desceChave(heap, i); } }

// Recebe um vetor e o seu tamanho.
// Imprime o conteudo do vetor.
void imprime(const int *vetor, const int tamanhoVetor) {
	for (int i = 0; i < tamanhoVetor; i++) {
        if (i > 0) { printf(" "); }
        printf("%d", vetor[i]);
    }
    printf("\n");
}

// Recebe um ponteiro para um heap.
// Devolve 1 se heap vazio, 0 caso contrario.
int vazio(const Heap *heap) { return heap->quantidade == 0; }

// Recebe um ponteiro para um heap.
// Devolve 1 se heap cheio, 0 caso contrario.
int cheio(const Heap *heap) { return heap->quantidade == heap->tamanho; }

// Apos inserir uma nova chave em um heap, pode ser necessario 
// "subir" esta nova chave para manter a propriedade estrutural do heap.
// Este procedimento recursivo recebe o ponteiro para o heap e o indice i.
void sobeChave(Heap *heap, int index) {
    while (index != 0 && heap->vetor[pai(index)] > heap->vetor[index]) {
        int tmp = heap->vetor[index];
        heap->vetor[index] = heap->vetor[pai(index)];
        heap->vetor[pai(index)] = tmp;
        index = pai(index);
    }
}

// Recebe um ponteiro para um heap e uma chave x.
// Insere a chave no fim do vetor e chama sobeChave().
void inserir(Heap *heap, const int chave) {
    if (!cheio(heap)) {
        heap->vetor[heap->quantidade++] = chave;
        sobeChave(heap, (heap->quantidade - 1));
    }
}

// Recebe um ponteiro para um heap.
// Assume que o heap nao estah vazio.
// Remove a chave da raiz e devolve o seu valor.
// Para remover a raiz, troque as chaves da raiz com o ultimo elemento.
// Depois, chame desceChave() para a nova raiz.
int extraiMinimo(Heap *heap) {
    if (!vazio(heap)) {
        int minimo = heap->vetor[0];
        heap->vetor[0] = heap->vetor[heap->quantidade - 1];
        heap->quantidade--;
        desceChave(heap, 0);
        return minimo;
    }
    return -1;
}

// Recebe um ponteiro para um heap e uma chave x.
// Procura o indice i da chave x.
// Se encontrar, remove x do heap.
// Para remover x, troque as chaves de i com o ultimo elemento.
// Depois, chame desceChave() para i.
void remover(Heap *heap, int chave) {
    for (int i = 0; i < heap->quantidade; i++) {
        if (heap->vetor[i] == chave) {
            heap->vetor[i] = heap->vetor[heap->quantidade - 1];
            heap->quantidade--;
            if ((i == 0) || (heap->vetor[pai(i)] < heap->vetor[i])) { desceChave(heap, i); }
            else { sobeChave(heap, i); }
            break;
        }
    }
}

int main() {
    int tamanhoHeap;
    scanf("%d", &tamanhoHeap);
    Heap *heap = criaHeapVazio(tamanhoHeap);
    char operacao;
    int chave;
    while(scanf(" %c", &operacao) != EOF) {
        switch(operacao) {
            case 'I':
                scanf("%d", &chave); 
                inserir(heap, chave);
                break;
            case 'R': 
                scanf("%d", &chave); 
                remover(heap, chave);
                break;
            case 'E': 
                if (!vazio(heap)) {
                    chave = extraiMinimo(heap);
                    printf("[%d]\n", chave);
                }
                break;
            case 'P': 
                if (!vazio(heap)) { imprime(heap->vetor, heap->quantidade); }
                break;
        }
    }
    liberaHeap(heap);
    return 0;
}