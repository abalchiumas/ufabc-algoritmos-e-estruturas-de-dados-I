#include <stdio.h>

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

Data checkForFirstDayOfMonth(Data dt, int lastDayOfPreviousMonth) {
	if (dt.dia == 1) {
		dt.dia = lastDayOfPreviousMonth;
		dt.mes -= 1;
	} else {
		dt.dia -= 1;
	}
	return dt;
}

Data getPreviousDay(int dia, int mes, int ano) {
	Data dt = { dia, mes, ano };
	switch (dt.mes)	{
		case 1:
			if (dt.dia == 1) {
				dt.dia = 31;
				dt.mes = 12;
				dt.ano -= 1;
			} else {
				dt.dia -= 1;
			}
			break;
		case 2:
			dt = checkForFirstDayOfMonth(dt, 31);
			break;
		case 3:
			dt = checkForFirstDayOfMonth(dt, 28 + isBissexto(dt.ano));
			break;
		case 4:
			dt = checkForFirstDayOfMonth(dt, 31);
			break;
		case 5:
			dt = checkForFirstDayOfMonth(dt, 30);
			break;
		case 6:
			dt = checkForFirstDayOfMonth(dt, 31);
			break;
		case 7:
			dt = checkForFirstDayOfMonth(dt, 30);
			break;
		case 8:
			dt = checkForFirstDayOfMonth(dt, 31);
			break;
		case 9:
			dt = checkForFirstDayOfMonth(dt, 31);
			break;
		case 10:
			dt = checkForFirstDayOfMonth(dt, 30);
			break;
		case 11:
			dt = checkForFirstDayOfMonth(dt, 31);
			break;
		case 12:
			dt = checkForFirstDayOfMonth(dt, 30);
			break;
	}
	return dt;
}

int main(void) {
	int dia, mes, ano;
	scanf("%d %d %d\n", &dia, &mes, &ano);
	Data dt = getPreviousDay(dia, mes, ano);
	printf("%d %d %d\n", dt.dia, dt.mes, dt.ano);
	return 0;
}