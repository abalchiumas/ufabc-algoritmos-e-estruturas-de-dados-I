#include <stdio.h>

int main(void) {
	double altura, peso;
	scanf("%lf %lf", &altura, &peso);

	double imc = peso / (altura * altura);
	if (imc < 16) {
		printf("Magreza grave\n");
	} else if (16 <= imc && imc < 17) {
		printf("Magreza moderada\n");
	} else if (17 <= imc && imc < 18.5) {
		printf("Magreza leve\n");
	} else if (18.5 <= imc && imc < 25) {
		printf("Saudavel\n");
	} else if (25 <= imc && imc < 30) {
		printf("Sobrepeso\n");
	} else if (30 <= imc && imc < 35) {
		printf("Obesidade Grau I\n");
	} else if (35 <= imc && imc < 40) {
		printf("Obesidade Grau II (severa)\n");
	} else {
		printf("Obesidade Grau III (morbida)\n");
	}

	return 0;
}