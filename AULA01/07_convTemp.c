#include <stdio.h>

int main(void) {
	long duracao;	
	scanf("%ld", &duracao);
	int horas = duracao / 3600;
	int minutos = (duracao % 3600) / 60;
	int segundos = duracao - (horas * 3600) - (minutos * 60);
	printf("%d:%d:%d\n", horas, minutos, segundos);
	return 0;
}