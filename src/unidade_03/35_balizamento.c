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
	for (int i = 0; i < qntdAtletasComBalizamento; i++) {
        atletasMerge[i] = atletasComBalizamento[i];
    }
    for (int i = 0; i < qntdAtletasSemBalizamento; i++) {
        atletasMerge[qntdAtletasComBalizamento + i] = atletasSemBalizamento[i];
    }
	free(atletasComBalizamento);
	free(atletasSemBalizamento);
	return atletasMerge;	
}

void balizamento(Atleta *atletas, const int qntdSeries, const int qntdRaias, const int qntdAtletas) {
	int endIndex = qntdAtletas, startIndex = (qntdAtletas - (1 - (qntdAtletas % 2)) - (qntdAtletas % qntdRaias)); // funciona para (qntdRaias, qntdAtletas) = (8, 10), (7, 11), (8, 18), (8, 5)
	for (int serie = 0; serie < qntdSeries; serie++) {
		printf("%da. serie:\n", serie + 1);
		int raiaAtletaInicial = (qntdRaias + (qntdRaias % 2)) / 2, modificadorNumeroRaia = 1, contadorRaia = 1;
		for (int k = startIndex; k < endIndex; k++) {
			printf("Raia %d: %s\n", raiaAtletaInicial, atletas[k].nome);
			raiaAtletaInicial = raiaAtletaInicial + (modificadorNumeroRaia * contadorRaia);
			modificadorNumeroRaia = modificadorNumeroRaia * -1;
			contadorRaia++;
		}
		endIndex = startIndex;
		startIndex = startIndex - qntdRaias + (1 - (qntdAtletas % 2)); 
	}	
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

	printf("\nLista ordenada pelo tempo de balizamento:\n");
	for (int j = 0; j < qntdAtletas; j++) {
		printf("%d) %s | %d\n", j, atletas[j].nome, atletas[j].centesimosTotal);
		free(atletas[j].nome);
	}	
	free(atletas);	
	return 0;
}