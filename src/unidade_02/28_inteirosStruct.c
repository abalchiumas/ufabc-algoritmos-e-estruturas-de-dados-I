#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE_FOR_EACH_BIGINT = 100;

typedef struct tInteiro {
	char *array;
	int arrayLength;
} Inteiro;

Inteiro inteiro(char *array) {
	int length = 0;
	while(array[length] != '\0') {
		length++;
	}
	Inteiro result = { array, length };
	return result;
}

Inteiro insertZeroesLeftPadding(const Inteiro i, int size) {
	Inteiro result;
	result.array = malloc(size * sizeof(char));
	result.arrayLength = size;
	int counter = 0;
	while (counter < size) {
		if ((size - counter) > i.arrayLength) {
			result.array[counter] = '0';
		} else {
			result.array[counter] = i.array[i.arrayLength - (size - counter)];
		}
		counter++;
	}
	return result;
}

Inteiro removeZeroesLeftPadding(const Inteiro i) {
    Inteiro result;
    int counter = 0;
    while (counter < i.arrayLength && i.array[counter] == '0') {
        counter++;
    }
    for (int k = counter; k < i.arrayLength; k++) {
        result.array[k - counter] = i.array[k];
    }
    result.arrayLength = i.arrayLength - counter;
    return result;
}

Inteiro soma(const Inteiro i1, const Inteiro i2) {
	char *resultArray = malloc((MAX_SIZE_FOR_EACH_BIGINT + 1) * sizeof(char));
	int carry = 0;
	for (int k = MAX_SIZE_FOR_EACH_BIGINT - 1; k >= 0; k--) {
		int sum = (i1.array[k] - '0') + (i2.array[k] - '0') + carry;
		if (sum >= 10) {
			resultArray[k] = (sum - 10) + '0';
			carry = 1;
		} else {
			resultArray[k] = sum + '0';
			carry = 0;
		}
	}
	return removeZeroesLeftPadding(inteiro(resultArray));
}

Inteiro subtrai(const Inteiro i1, const Inteiro i2) {
	char *resultArray = malloc(MAX_SIZE_FOR_EACH_BIGINT * sizeof(char));
	int borrow = 0;
	for (int k = MAX_SIZE_FOR_EACH_BIGINT - 1; k >= 0; k--) {
		int sub = (i1.array[k] - '0') - (i2.array[k] - '0') - borrow;
		if (sub < 0) {
			sub += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}
		resultArray[k] = sub + '0';
	}	
	return removeZeroesLeftPadding(inteiro(resultArray));
}

Inteiro multiplica(const Inteiro i1, const Inteiro i2) {
	int newSize = i1.arrayLength + i2.arrayLength;
	char *tmpArray = malloc(newSize * sizeof(char));
	tmpArray[0] = '0';
	Inteiro result = insertZeroesLeftPadding(inteiro(tmpArray), newSize);
	int k, j;
    for (k = i1.arrayLength - 1; k >= 0; k--) {
        int carry = 0;
        for (j = i2.arrayLength - 1; j >= 0; j--) {
            int multi = ((i1.array[k] - '0') * (i2.array[j] - '0')) + (result.array[k + j + 1] - '0') + carry;
            result.array[k + j + 1] = (multi % 10) + '0';
            carry = multi / 10;
        }
        if (k + j + 1 >= 0) {
			result.array[k] += carry;
		}
    }
	return removeZeroesLeftPadding(result);
}

void printBigInteger(const Inteiro i) {
	if (i.arrayLength == 0)	{
		printf("0");
	} else {
		for (int j = 0; j < i.arrayLength; j++) {
			printf("%c", i.array[j]);
		}
	}
}

int main(void) {
	char *a = malloc(MAX_SIZE_FOR_EACH_BIGINT * sizeof(char)), ops, *b = malloc(MAX_SIZE_FOR_EACH_BIGINT * sizeof(char));
	Inteiro *result = malloc(sizeof(Inteiro));
	int counter = 0;
	while(scanf("%s %c %s\n", a, &ops, b) != EOF) {
		Inteiro aZeroesLeftPadding = insertZeroesLeftPadding(inteiro(a), MAX_SIZE_FOR_EACH_BIGINT);
		Inteiro bZeroesLeftPadding = insertZeroesLeftPadding(inteiro(b), MAX_SIZE_FOR_EACH_BIGINT);
		result = realloc(result, (counter + 1) * sizeof(Inteiro));
		switch (ops) {
			case '+':
				result[counter] = soma(aZeroesLeftPadding, bZeroesLeftPadding);
				break;
			case '-':
				result[counter] = subtrai(aZeroesLeftPadding, bZeroesLeftPadding);
				break;
			case '*':
				result[counter] = multiplica(aZeroesLeftPadding, bZeroesLeftPadding);
				break;
		}
		counter++;
	}
	for (int i = 0; i < counter; i++) {
		printBigInteger(result[i]);
		printf("\n");
		free(result[i].array);
	}
	free(result);
	free(b);
	free(a);
	return 0;
}