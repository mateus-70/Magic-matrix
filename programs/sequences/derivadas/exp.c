// Mateus S Silva
// 2020-05-13
// Objetivo: imprimir uma sequencia de pontos (10, por causa de o lf ser pequeno...)
// para aproximar a derivada, sem garantia de convergencia
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double a, h=1, aprox;
    printf("[ a^h - 1 ] / h" );
    printf("Valores a inserir: 'a'" );
    printf("Valor para \'a\':" );
    scanf("%lf", &a);
    for(int i=0; i<10; i++){
        printf("approx ~= %10lf, h=%lf.\n", (pow(a, h) - 1)/h, h );
        h = h/10;
    }
    printf("\n");
    return 0;
}
