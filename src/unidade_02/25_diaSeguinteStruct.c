#include <stdio.h>
#include <stdlib.h>

typedef struct tData {
	int dia, mes, ano;
} Data;

int isBissexto(int ano) {
	if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))	{
		return 1;
	} else {
		return 0;
	}	
}

Data getNextDay(int dia, int mes, int ano) {
	Data dt = { dia, mes, ano };
	switch (dt.mes)	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (dt.dia == 31) {
				dt.dia = 1;
				dt.mes += 1;
			} else {
				dt.dia += 1;
			}
			break;
		case 12:
			if (dt.dia == 31) {
				dt.dia = 1;
				dt.mes = 1;
				dt.ano += 1;
			} else {
				dt.dia += 1;
			}
			break;
		case 2:
			if (dt.dia == 28 + isBissexto(dt.ano)) {
				dt.dia = 1;
				dt.mes += 1;
			} else {
				dt.dia += 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (dt.dia == 30) {
				dt.dia = 1;
				dt.mes += 1;
			} else {
				dt.dia += 1;
			}
			break;
	}
	return dt;
}

int main(void) {
	int dia, mes, ano;
	scanf("%d %d %d\n", &dia, &mes, &ano);
	Data dt = getNextDay(dia, mes, ano);
	printf("%d %d %d\n", dt.dia, dt.mes, dt.ano);
	return 0;
}