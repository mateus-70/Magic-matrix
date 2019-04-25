//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <tgmath.h>
//
//double delta, epsilon;
//
//double f(double x){
    //double y;
    //// y = 5*cos( exp(x)) +  exp(-3* pow(x,2));
    //y = sin(x) + x*exp(x);
//return y;
//}
//
//double df(double x){
    //double y;
    //y = -5*exp(x)*sin( exp(x)) -  6*x*exp(-3* pow(x,2));
    //return y;
//}
//
//// Derivada numerica
//double dnf(double x, double x0){
    //double y;
    //y = (f(x) - f(x0)) /(x-x0);
    //return y;
//}
//
//
//double myabs(double x){
    //double y;
    //if (x > 0)
        //y= x;
    //else y= -1*x;
    //return y;
//}
//
//double root_s_line(double x1, double x0){
    //double x;
//
    //x = ( -f(x1)*(x1-x0) /(f(x1) - f(x0)) ) + x1; // root's approximation of secant
    //return x;
//}
//
//int main(void){
//
    //double x_previous, x_next, x_now;
    //int iteracoes_max, i=0;
//
    //delta = epsilon = pow(10, -6);
    //printf("Digite o máximo de iteracoes: ");
    //scanf("%d", &iteracoes_max);
//
    //x_now = -4;
    //x_next = -3;
//
    //printf("Escolhendo os pontos '%lf', '%lf' como iniciais.\n", x_now, x_next);
//
    //while(i < iteracoes_max && myabs(x_previous -x_now) > delta ){
        //i++;
        //x_previous = x_now;
        //x_now = x_next;
        //x_next = root_s_line(x_now, x_previous);
        //// x_next = x_now - f(x_previous)/dnf(x_now, x_previous);
        //printf("Funcao linear, iteracao=%d, \n\
                //x0=%lf \t f(x0)=%lf\n\
                //x1=%lf \t f(x1)=%lf\n\
                //root=%lf!\n\n", i, x_previous, f(x_previous), x_now, f(x_now), x_next);
    //}
//
    ////printf("fx=%lf, dfx=%lf\n\n", f(-1), df(-1));
    //if(iteracoes_max <= i)
        //printf("Limite de iteracoes atingido, intervalo obtido e'\n (%lf, %lf)",x_now, x_next);
    //else
        //printf("O intervalo (%lf, %lf) contem uma raiz.\n\n", x_now, x_next);
//
    //return 0;
//}
//
//
//
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x)
{
        return(x*x*x-4); // f(x)= x^3-4
}
int main()
{
    float a,b,c,d,e;
    int count=1,n;
    printf("\n\nEnter the values of a and b:\n"); //(a,b) must contain the solution.
    scanf("%f%f",&a,&b);
    printf("Enter the values of allowed error and maximun number of iterations:\n");
    scanf("%f %d",&e,&n);
    do{
        if(f(a)==f(b))
        {
            printf("\nSolution cannot be found as the values of a and b are same.\n");
            return 0;
        }
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        printf("Iteration No-%d    x=%f\n",count,c);
        count++;
        if(count==n)
        {
            break;
        }
    } while(fabs(f(c))>e);
    printf("\n The required solution is %f\n",c);
    return 0;
}
