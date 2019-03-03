// Mateus S Silva
// 2018-09-21
// Objetivo: imprimir uma sequencia, dado um número natural.
// f(x+1) = f(x)/2, se f(x) é par
// f(x+1) = 3 * f(x) + 1, se f(x) é ímpar
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variaveis
    long long unsigned i=1, n, aux; // n é uma entrada e não será alterada
    //
    // Corpo
    //
    //
    //
    puts("Digite \'n\': ");
    scanf("%llu", &n);
    aux=n;
    printf("%10llu - %10llu \n", i, aux);
    while(aux != 1)
    {
        if(aux % 2 == 0)
            aux = aux/2;
        else
            aux = 3*aux+1;
        i++;
        printf("%10llu - %10llu \n", i, aux);
    }
    

    return 0;
}
