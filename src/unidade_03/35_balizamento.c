#include <stdio.h>
#include <stdlib.h>

typedef struct tAtleta {
	char *nome;
	int centesimosTotal;
} Atleta;

// insertion sort baseado nos centesimos totais de cada atleta
void reordenarAtletas(Atleta *atletas, const int qntdAtletas) {
	for (int j = 1; j < qntdAtletas; j++) {
		Atleta key = atletas[j];
		int i = j - 1;
		while ((i >= 0) && (atletas[i].centesimosTotal > key.centesimosTotal)) {
			atletas[i + 1] = atletas[i];
			i--;
		}
		atletas[i + 1] = key;
	}
}

void balizamento(Atleta *atletas, const int qntdRaias) {
	printf("\n"); // TODO: remove later
	// Atleta *atletasCopy = malloc(m * sizeof(Atleta));
	// for (int k = 0; k < m; k++) { // cria uma cópia do ponteiro recebido
	// 	atletasCopy[k] = atletas[k];
	// }

	int *posicoes = malloc(qntdRaias * sizeof(int));
	int posicao = (qntdRaias - 1) / 2;
	int modificador = 1;
	for (int i = 0; i < qntdRaias; i++) {
		posicoes[posicao] = i + 1;
		posicao = posicao + (modificador * (i + 1));
		modificador = modificador * -1;
	}

	for (int j = 0; j < qntdRaias; j++) {
		printf("%d ", posicoes[j]); // TODO: remove later
	}	
	printf("\n\n");
}

int main(void) {
	int qntdRaias, qntdAtletas;
	scanf("%d", &qntdRaias);
	scanf("%d", &qntdAtletas);
	Atleta *atletas = NULL;
	for (int counter = 0; counter < qntdAtletas; counter++) {
		Atleta atletaTmp;
		atletaTmp.nome = malloc(100 * sizeof(char));
		atletas = realloc(atletas, (counter + 1) * sizeof(Atleta));
		int min, seg, cent;
		scanf("%s %d %d %d", atletaTmp.nome, &min, &seg, &cent);
		atletaTmp.centesimosTotal = (((min * 60) + seg) * 100) + cent;
		atletas[counter] = atletaTmp;
	}

	int qntdSeries = ((qntdAtletas / qntdRaias) == 0) ? (qntdAtletas / qntdRaias) : (qntdAtletas / qntdRaias) + 1;
	if (qntdSeries == 1) { printf("\n%d serie\n", qntdSeries); } 
	else { printf("\n%d series\n", qntdSeries); }

	reordenarAtletas(atletas, qntdAtletas);

	// balizamento(atletas, qntdAtletas);

	for (int j = 0; j < qntdAtletas; j++) {
		printf("%d) %s | %d\n", j, atletas[j].nome, atletas[j].centesimosTotal);
		free(atletas[j].nome);
	}	
	free(atletas);
	
	
	return 0;
}