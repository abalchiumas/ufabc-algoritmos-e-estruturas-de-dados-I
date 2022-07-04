#include <stdio.h>
#include <math.h>

struct ponto {
    int x, y;
};

double distancia(struct ponto p1, struct ponto p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    struct ponto p1, p2;
    p1.x = 3;
    p1.y = 4;
    p2.x = 1;
    p2.y = 2;
    printf("%.2lf\n", distancia(p1, p2));
    return 0;
}