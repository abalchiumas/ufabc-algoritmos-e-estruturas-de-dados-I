#include <stdio.h>

int main(void) {
	int anoAtual, anoNascimento;
	char nome[50];	
	scanf("%d %s %d", &anoAtual, &nome, &anoNascimento);
	printf("%s, voce completa %d anos de idade neste ano.",
		nome,
		anoAtual - anoNascimento);
	return 0;
}