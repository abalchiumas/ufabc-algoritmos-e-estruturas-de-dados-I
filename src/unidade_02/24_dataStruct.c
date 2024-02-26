#include <stdio.h>
#include <stdlib.h>

typedef struct tData {
	int dia, mes, ano;
} Data;

int isBissexto (int ano) {
	if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))	{
		return 1;
	} else {
		return 0;
	}	
}

int validateDay(int day, int endOfMonthDay) {
	if (day < 1 || day > endOfMonthDay) {
		return 0;
	}
	return 1;
}

int isValida (Data dt) {
	switch (dt.mes)	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return validateDay(dt.dia, 31);
		case 2:
			return validateDay(dt.dia, 28 + isBissexto(dt.ano));
		case 4:
		case 6:
		case 9:
		case 11:
			return validateDay(dt.dia, 30);
		default:
			return 0;
	}			
}

int main(void) {
	int n, dia, mes, ano;
	scanf("%d\n", &n);

	int* validacaoDatas = malloc(sizeof(int));

	int counter = 0;
	while(counter < n) {
		scanf("%d %d %d\n", &dia, &mes, &ano);
		validacaoDatas = realloc(validacaoDatas, (counter + 1) * sizeof(int));
		Data dt = { dia, mes, ano };
		validacaoDatas[counter] = isValida(dt);
		counter++;
	}

	for (int i = 0; i < counter; i++) {
		if (validacaoDatas[i] == 1) {
			printf("DATA VALIDA\n");
		} else {
			printf("DATA INVALIDA\n");
		}
	}
	free(validacaoDatas);
	return 0;
}