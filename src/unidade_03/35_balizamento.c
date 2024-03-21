#include <stdio.h>
#include <stdlib.h>

typedef struct tAtleta {
	char *nome;
	int centesimosTotal;
} Atleta;

void reordenarAtletas(Atleta *atletas, const int qntdAtletas) {
	for (int j = 1; j < qntdAtletas; j++) {
		Atleta chave = atletas[j];
		int i = j - 1;
		while ((i >= 0) && (atletas[i].centesimosTotal > chave.centesimosTotal)) {
			atletas[i + 1] = atletas[i];	
			i--;
		}
		atletas[i + 1] = chave;
	}
}

Atleta *mergeAtletas(Atleta *atletasComBalizamento, const int qntdAtletasComBalizamento, Atleta *atletasSemBalizamento, const int qntdAtletasSemBalizamento) {
	Atleta *atletasMerge = malloc((qntdAtletasComBalizamento + qntdAtletasSemBalizamento) * sizeof(Atleta));
	for (int i = 0; i < qntdAtletasComBalizamento; i++) { atletasMerge[i] = atletasComBalizamento[i]; }
    for (int i = 0; i < qntdAtletasSemBalizamento; i++) { atletasMerge[qntdAtletasComBalizamento + i] = atletasSemBalizamento[i]; }
	free(atletasComBalizamento);
	free(atletasSemBalizamento);
	return atletasMerge;
}

void checkMinimumAtletas(Atleta **balizamentoAtletas, const int qntdSeries, const int qntdRaias) {
	int countPrimeiraSerie = 0;
	for (int i = 0; i < qntdRaias; i++)	{
		if (balizamentoAtletas[0][i].nome != NULL) {
			countPrimeiraSerie++;
		}
	}
	if (countPrimeiraSerie < 3) {
		for (int j = qntdRaias - 1; j > 0; j--) {
			balizamentoAtletas[0][j] = balizamentoAtletas[0][j - 1];
		}
		balizamentoAtletas[0][0] = balizamentoAtletas[1][qntdRaias - 1];
		balizamentoAtletas[1][qntdRaias - 1].nome = NULL;
	}	
}

void balizamento(const Atleta *atletas, const int qntdSeries, const int qntdRaias, const int qntdAtletas) {
	Atleta **balizamentoAtletas = malloc(qntdSeries * sizeof(Atleta *));
	int atletaIndex = 0;
	for (int serie = qntdSeries - 1; serie >= 0; serie--) {
		balizamentoAtletas[serie] = malloc(qntdRaias * sizeof(Atleta));
		int qntdNadadoresPorSerie;		
		for (int i = 0; i < qntdRaias; i++) {		
			if (atletaIndex < qntdAtletas) { 
				balizamentoAtletas[serie][i] = atletas[atletaIndex++];
				qntdNadadoresPorSerie++;
			}
		}
	}

	if (qntdSeries == 2 || qntdSeries > 2) { checkMinimumAtletas(balizamentoAtletas, qntdSeries, qntdRaias); }

	for (int serie = 0; serie < qntdSeries; serie++) {
		printf("%da. serie:\n", serie + 1);
		int raiaAtletaInicial = (qntdRaias + (qntdRaias % 2)) / 2, modificadorNumeroRaia = 1, contadorRaia = 1;
		for (int j = 0; j < qntdRaias; j++)	{
			if (balizamentoAtletas[serie][j].nome != NULL) {
				printf("Raia %d: %s\n", raiaAtletaInicial, balizamentoAtletas[serie][j].nome);
				raiaAtletaInicial = raiaAtletaInicial + (modificadorNumeroRaia * contadorRaia), modificadorNumeroRaia = modificadorNumeroRaia * -1, contadorRaia++;
			}
		}		
    	free(balizamentoAtletas[serie]);
	}
	free(balizamentoAtletas);
}

int main(void) {
	int qntdRaias, qntdAtletas, counter, qntdAtletasSemBalizamento, qntdAtletasComBalizamento;;
	scanf("%d", &qntdRaias);
	scanf("%d", &qntdAtletas);
	Atleta *atletasComBalizamento = NULL, *atletasSemBalizamento = NULL;
	while (counter < qntdAtletas) {
		Atleta atletaTmp;
		atletaTmp.nome = malloc(100 * sizeof(char));

		int min, seg, cent;
		scanf("%s %d %d %d", atletaTmp.nome, &min, &seg, &cent);
		
		atletaTmp.centesimosTotal = (((min * 60) + seg) * 100) + cent;
		if (atletaTmp.centesimosTotal == 0) {
			atletasSemBalizamento = realloc(atletasSemBalizamento, (qntdAtletasSemBalizamento + 1) * sizeof(Atleta));
			atletasSemBalizamento[qntdAtletasSemBalizamento++] = atletaTmp;
		} else {
			atletasComBalizamento = realloc(atletasComBalizamento, (qntdAtletasComBalizamento + 1) * sizeof(Atleta));
			atletasComBalizamento[qntdAtletasComBalizamento++] = atletaTmp;
		}
		counter++;
	}
	reordenarAtletas(atletasComBalizamento, qntdAtletasComBalizamento);
	Atleta *atletas = mergeAtletas(atletasComBalizamento, qntdAtletasComBalizamento, atletasSemBalizamento, qntdAtletasSemBalizamento);

	int qntdSeries = 1;
	if (qntdRaias < qntdAtletas) { qntdSeries = (qntdAtletas % qntdRaias) == 0 ? (qntdAtletas / qntdRaias) : (qntdAtletas / qntdRaias) + 1; }	
	if (qntdSeries == 1) { printf("\n%d serie\n", qntdSeries); } 
	else { printf("\n%d series\n", qntdSeries); }

	balizamento(atletas, qntdSeries, qntdRaias, qntdAtletas);

	for (int j = 0; j < qntdAtletas; j++) {
		free(atletas[j].nome);
	}	
	free(atletas);	
	return 0;
}