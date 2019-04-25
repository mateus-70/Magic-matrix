#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>

double delta, epsilon;

double f(double x){
    double y;
    y = 5*cos( exp(x)) +  exp(-3* pow(x,2));
return y;
}

double df(double x){
    double y;
    y = -5*exp(x)*sin( exp(x)) -  6*x*exp(-3* pow(x,2));
    return y;
}


double myabs(double x){
    double y;
    if (x > 0)
        y= x;
    else y= -1*x;
    return y;
}


int main(void){

    double x_anterior, x_atual, aux;
    int iteracoes_max, i=0;

    delta = epsilon = pow(10, -6);
    printf("Digite o máximo de iteracoes: ");
    scanf("%d", &iteracoes_max);

    printf("Escolhendo o ponto 0 como inicial.\n");
    x_anterior = -1000;
    x_atual= 0;

    while(i < iteracoes_max && myabs(x_anterior -x_atual) > delta ){
        i++;
        x_anterior = x_atual;
        x_atual = x_anterior - f(x_anterior)/df(x_anterior);
    }

    //printf("fx=%lf, dfx=%lf\n\n", f(-1), df(-1));
    if(iteracoes_max <= i)
        printf("Limite de iteracoes atingido, intervalo obtido e'\n (%lf, %lf)",x_anterior, x_atual);
    else
        printf("O intervalo (%lf, %lf) contem uma raiz.\n\n", x_anterior, x_atual);

    return 0;
}
