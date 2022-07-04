#include <stdio.h>

struct Fracao {
    int numerador, denominador;
};
typedef struct Fracao Fracao;

int maiorDivisorComum(Fracao fracaoAux) {
    unsigned int mdc = 1;
    for (int i = 1; i <= fracaoAux.numerador && i <= fracaoAux.denominador; ++i) {
        if ((fracaoAux.numerador % i == 0) && (fracaoAux.denominador % i == 0)) {
            mdc = i;
        }
    }
    return mdc;
}

Fracao somar(Fracao f1, Fracao f2) {
    Fracao resultado;
    resultado.numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador);
    resultado.denominador = (f1.denominador * f2.denominador);

    int mdc = maiorDivisorComum(resultado);
    resultado.numerador = resultado.numerador / mdc;
    resultado.denominador = resultado.denominador / mdc;
    return resultado;
}

Fracao somar_vetor(Fracao f[], int n_fracoes) {
    Fracao resultado;
    resultado.numerador = 0;
    resultado.denominador = 1;
    for (int i = 0; i < n_fracoes; ++i) {
        int auxSoma = f[i].numerador;
        for (int j = 0; j < n_fracoes; ++j) {
            if (j != i) {
                auxSoma = auxSoma * f[j].denominador;
            }
        }
        resultado.numerador = resultado.numerador + auxSoma;
        resultado.denominador = resultado.denominador * f[i].denominador;
    }
    int mdc = maiorDivisorComum(resultado);
    resultado.numerador = resultado.numerador / mdc;
    resultado.denominador = resultado.denominador / mdc;
    return resultado;
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    Fracao resultado;
    resultado.numerador = (f1.numerador * f2.numerador);
    resultado.denominador = (f1.denominador * f2.denominador);

    int mdc = maiorDivisorComum(resultado);
    resultado.numerador = resultado.numerador / mdc;
    resultado.denominador = resultado.denominador / mdc;
    return resultado;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    Fracao resultado;
    resultado.numerador = 1;
    resultado.denominador = 1;
    for (int i = 0; i < n_fracoes; ++i) {
        resultado.numerador = resultado.numerador * f[i].numerador;
        resultado.denominador = resultado.denominador * f[i].denominador;
    }

    int mdc = maiorDivisorComum(resultado);
    resultado.numerador = resultado.numerador / mdc;
    resultado.denominador = resultado.denominador / mdc;
    return resultado;
}

int main() {
    Fracao teste1;
    teste1.numerador = 1800;
    teste1.denominador = 20000;

    Fracao teste2;
    teste2.numerador = 4;
    teste2.denominador = 27;
    Fracao aaaa = somar(teste1,teste2);
    printf("%d / %d\n", aaaa.numerador, aaaa.denominador);
    return 0;
}
