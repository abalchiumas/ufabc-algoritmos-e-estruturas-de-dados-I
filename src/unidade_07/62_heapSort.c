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
// Se a chave do pai eh menor que a de algum filho,
// faz a troca e chama recursivamente.
// A troca deve ser feita pela chave do maior filho.
// No caso de empate, prefira trocar com o filho esquerdo.
void peneirar(Heap *heap, const int pai) {
    int filhoDireito = filhoDir(pai), filhoEsquerdo = (filhoDireito - 1), maior = pai;
    if ((filhoEsquerdo < heap->quantidade) && (heap->vetor[filhoEsquerdo] > heap->vetor[maior])) { maior = filhoEsquerdo; }
    if ((filhoDireito < heap->quantidade) && (heap->vetor[filhoDireito] > heap->vetor[maior])) { maior = filhoDireito; }
    if (maior != pai) {
        int tmp = heap->vetor[pai];
        heap->vetor[pai] = heap->vetor[maior];
        heap->vetor[maior] = tmp;
        peneirar(heap, maior);
    }
}

// Recebe um ponteiro para um heap.
// Constroi um heap, chamando peneirar() para 
// cada um dos pais, do ultimo pai ate a raiz.
void constroiHeap(Heap *heap) { for (int i = pai(heap->quantidade - 1); i >= 0; i--) { peneirar(heap, i); } }

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
// Ordena as chaves pelo algoritmo HeapSort.
// Imprime o vetor apos chamar constroiHeap().
// A cada iteracao, imprime o vetor apos peneirar().
void heapSort(Heap *heap) {
    int tamanhoOriginal = heap->quantidade;
    constroiHeap(heap);
    imprime(heap->vetor, tamanhoOriginal);
    for (int i = heap->quantidade - 1; i > 0; i--) {
        int tmp = heap->vetor[0];
        heap->vetor[0] = heap->vetor[i];
        heap->vetor[i] = tmp;
        heap->quantidade--;
        peneirar(heap, 0);        
        imprime(heap->vetor, tamanhoOriginal);
    }
}

int main() {
    int tamanhoHeap;
    scanf("%d", &tamanhoHeap);
    Heap *heap = criaHeapVazio(tamanhoHeap);
    for (int i = 0; i < tamanhoHeap; i++) { scanf("%d", &heap->vetor[i]); }
    heap->quantidade = tamanhoHeap;
    heapSort(heap);
    liberaHeap(heap);
    return 0;
}