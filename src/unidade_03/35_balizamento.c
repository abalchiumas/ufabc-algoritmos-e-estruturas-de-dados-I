#include <stdio.h>
#include <stdlib.h>

typedef struct tAtleta {
	char *nome;
	int min, seg, cent;
} Atleta;

int main(void) {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	Atleta *atletas = NULL;
	for (int counter = 0; counter < m; counter++) {
		Atleta atletaTmp;
		atletaTmp.nome = malloc(100 * sizeof(char));
		atletas = realloc(atletas, (counter + 1) * sizeof(Atleta));

		printf("%d) ", counter + 1); // TODO: remove later
		scanf("%s %d %d %d", &atletaTmp.nome, &atletaTmp.min, &atletaTmp.seg, &atletaTmp.cent);
			
		atletas[counter] = atletaTmp;
	}

	for (int j = 0; j < m; j++) {
		printf("%s\n", atletas[j].nome);
		free(atletas[j].nome);
	}	
	free(atletas);
	
	
	return 0;
}