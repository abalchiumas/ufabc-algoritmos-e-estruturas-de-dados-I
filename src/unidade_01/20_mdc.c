#include <stdio.h>


// esqueci da existência do Algoritmo de Euclides durante a implementação
// solução não otimizada a seguir:
int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

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

	printf("%d\n", mdc)	;

	return 0;
}