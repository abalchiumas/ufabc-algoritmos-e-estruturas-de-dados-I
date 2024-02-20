#include <stdio.h>
#include <stdlib.h>

typedef struct tRacional {
	int numerador, denominador;
} Racional;

int mdc(int a, int b) {
	a = abs(a);
	b = abs(b);
	int mdc = 1;
	if (a > b) {
		for (int i = 2; i < a; i++)	{
			if (a % i == 0 && b % i == 0) {
				mdc = i;
			}			
		}		
	} else {
		for (int j = 2; j < b; j++)	{
			if (a % j == 0 && b % j == 0) {
				mdc = j;
			}			
		}
	}
	return mdc;
}

Racional racional(int numerador, int denominador) {
	Racional r = { numerador, denominador };
	return r;
}

Racional negativo(Racional r) {
	if (r.denominador < 0) {
		r.numerador *= -1;
		r.denominador *= -1;
	}
	return r;
}

Racional soma(Racional r1, Racional r2) {
	Racional r = { (r1.numerador * r2.denominador) + (r2.numerador * r1.denominador) , r1.denominador * r2.denominador };
	return r;
}

Racional multiplica(Racional r1, Racional r2) {
	Racional r = { r1.numerador * r2.numerador, r1.denominador * r2.denominador };
	return r;
}

Racional divide(Racional r1, Racional r2) {
	Racional r = { r1.numerador * r2.denominador, r1.denominador * r2.numerador };
	return r;
}

Racional reduz(Racional r) {
	int mdcRacional = mdc(r.numerador, r.denominador);
	r.numerador = r.numerador / mdcRacional;
	r.denominador = r.denominador / mdcRacional;	
	return r;
}

Racional parseRacional(int d1, int n1, char ops, int d2, int n2) {
	Racional r;
	Racional r1 = racional(n1, d1);
	Racional r2 = racional(n2, d2);
	switch (ops) {
		case '+':
			r = soma(r1, r2);
			break;
		case '-':
			r2.numerador *= -1;
			r = soma(r1, r2);
			break;
		case '*':
			r = multiplica(r1, r2);
			break;
		case '/':
			r = divide(r1, r2);
			break;
	}
	return negativo(reduz(r));
}

int main(void) {
	int d1, n1, d2, n2;
	char ops;
	Racional* racionais = malloc(2 * sizeof(int));;
	int counter = 0;
	while(scanf("%d %d %c %d %d\n", &n1, &d1, &ops, &n2, &d2) != EOF) {
		racionais = realloc(racionais, (counter + 1) * 2 * sizeof(int));
		Racional r = parseRacional(d1, n1, ops, d2, n2);
		racionais[counter] = r;
		counter++;
	}

	for (int i = 0; i < counter; i++) {
		printf("%d %d\n", racionais[i].numerador, racionais[i].denominador);
	}
	free(racionais);
	return 0;
}