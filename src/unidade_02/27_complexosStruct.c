#include <stdio.h>
#include <stdlib.h>

typedef struct tComplex {
	int a, b;
} Complexo;

Complexo complexo(int a, int b) {
	Complexo z = { a, b };
	return z;
}

Complexo soma(Complexo z1, Complexo z2) {
	Complexo z = { z1.a + z2.a, z1.b + z2.b };
	return z;
}

Complexo multiplica(Complexo z1, Complexo z2) {
	Complexo z = { (z1.a * z2.a) - (z1.b * z2.b), (z1.a * z2.b) + (z1.b * z2.a) };
	return z;
}

Complexo divide(Complexo z1, Complexo z2) {
	Complexo z = { ((z1.a * z2.a) + (z1.b * z2.b)) / ((z2.a * z2.a) + (z2.b * z2.b)), ((z1.b * z2.a) - (z1.a * z2.b)) / ((z2.a * z2.a) + (z2.b * z2.b)) };
	return z;
}

Complexo complexosOperation(int a1, int b1, char ops, int a2, int b2) {
	Complexo z;
	Complexo z1 = complexo(a1, b1);
	Complexo z2 = complexo(a2, b2);
	switch (ops) {
		case '+':
			z = soma(z1, z2);
			break;
		case '-':
			z2.a *= -1, z2.b *= -1;
			z = soma(z1, z2);
			break;
		case '*':
			z = multiplica(z1, z2);
			break;
		case '/':
			z = divide(z1, z2);
			break;
	}
	return z;
}

int main(void) {
	int a1, b1, a2, b2;
	char ops;

	Complexo* complexos = malloc(2 * sizeof(int));
	int counter = 0;
	while(scanf("%d %di %c %d %di\n", &a1, &b1, &ops, &a2, &b2) != EOF) {
		complexos = realloc(complexos, (counter + 1) * 2 * sizeof(int));
		complexos[counter] = complexosOperation(a1, b1, ops, a2, b2);
		counter++;
	}

	for (int i = 0; i < counter; i++) {
		printf("%d %di\n", complexos[i].a, complexos[i].b);
	}
	free(complexos);
	return 0;
}