#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double tolerance;

double f(double x){
    double y;
    y = exp(2*x) - 5;

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

    double a, b, c;

    tolerance = pow(10, -6);

    printf("Give the x-coordinate of the first point: ");
    scanf("%lf", &a);
    
    printf("Give the x-coordinate of the second point: ");
    scanf("%lf", &b);

    if( f(a) * f(b) > 0){
        printf("Erro: f(a) tem mesmo sinal de f(b)! ");
        exit;
    }else{
        while (myabs(a-b) >= tolerance){
            c = (a+b)/2;
            if (f(c) * f(a) <= 0 )
                b = c;
            else
                a=c;
        }
        printf("\nAo final temos o intervalo: (%lf,%lf) contendo uma raiz.\n\n",a,b);
   }
    

    return 0;
}
