#include <stdio.h>
#include <stdlib.h>

// TODO/WIP
typedef struct tInteiro {
	
} Inteiro;

Inteiro inteiro(char* a) {

}

Inteiro soma(Inteiro i1, Inteiro i2) {

}

Inteiro subtrai(Inteiro i1, Inteiro i2) {

}

Inteiro multiplica(Inteiro i1, Inteiro i2) {

}

int stringLength(char *array) {
	int length = 0;
	while(array[length] != '\0') {
		length++;
	}
	return length;
}

int *asciiConverter(char *array) {
	int *asciiCollector = malloc(100 * sizeof(int));
	int arrayLength = stringLength(array);
	for (int i = 0; i < arrayLength; i++) {
		switch (array[i]) {
			case '0':
				asciiCollector[i] = 48;
				break;
			case '1':
				asciiCollector[i] = 49;
				break;
			case '2':
				asciiCollector[i] = 50;
				break;
			case '3':
				asciiCollector[i] = 51;
				break;
			case '4':
				asciiCollector[i] = 52;
				break;
			case '5':
				asciiCollector[i] = 53;
				break;
			case '6':
				asciiCollector[i] = 54;
				break;
			case '7':
				asciiCollector[i] = 55;
				break;
			case '8':
				asciiCollector[i] = 56;
				break;
			case '9':
				asciiCollector[i] = 57;
				break;		
		}	
	}
	return asciiCollector;
}

// a     =          409728389126183810910
// b     = 918371973891671891720974093781
// a + b = 918371974301400280847157904691
int main(void) {
	char *a = malloc(100 * sizeof(char)), ops, *b = malloc(100 * sizeof(char));
	scanf("%s %c %s\n", a, &ops, b);

	int aLength = stringLength(a);
	int *aToAscii = asciiConverter(a);
	printf("A) ");
	for (int j = 0; j < aLength; j++) {
		printf("%d ", aToAscii[j]);
	}
	printf("\n");
	
	int bLength = stringLength(b);
	int *bToAscii = asciiConverter(b);
	printf("B) ");
	for (int k = 0; k < bLength; k++) {
		printf("%d ", bToAscii[k]);
	}
	printf("\n");
	
	free(a);
	free(b);
	return 0;
}