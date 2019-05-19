#ifndef RATIONALS_HEADER__
    #define RATIONALS_HEADER__

// #include "/home/mateus/ban/math/programs/matrices/matrices.h"


#include "/home/mateus/ban/math/programs/utils/definitions.h"



// Functions definitions
Q q_simplify(Q rational){
    int i, menor;

    //printf("inicio rational.numerator=%d, denominator=%d.\n", rational.numerator, rational.denominator);
    if (rational.denominator == 0){
        puts("\n\n\nsimplifica_q: DIVISAO POR ZERO\n\n\n\n");
        exit(1);
    }
    if(rational.numerator == 0){
        rational.denominator = 1;
    }else{
        if(rational.denominator < 0){
            rational.denominator *= -1;
            rational.numerator *= -1;
        }
    
        if(ABS(rational.numerator) < ABS(rational.denominator))
            menor = ABS(rational.numerator);
        else
            menor = ABS(rational.denominator);
        
        // É provavel que o menor tenha menos divisores, por isso usamos o menor deles.
        // sqrt(menor + 1) porque não quero enfrentar problemas com arredondamentos com float.
        // começa por 2, porque numero rational com numerator = 1 não é simplificável.
         menor = round(sqrt(menor+1.));
        for(i=2; i < menor; ){
            if( rational.numerator % i == 0){
                if( rational.denominator % i == 0){
                    rational.numerator /= i;
                    rational.denominator /= i;
                }else{
                    i++;
                }
            }else{
                i++;
            }
        }
    }

    //printf("final rational.numerator=%d, denominator=%d.\n", rational.numerator, rational.denominator);
    return rational;
}

// multiplicacao em Q - racionais
Q q_quoc(Q rac1, Q rac2){
    Q result;
    
    if(rac2.numerator == 0 || rac2.denominator == 0){
        printf("\n\nDivisão por zero.\n\n");
        exit(0);
    }

    result.numerator = rac1.numerator * rac2.denominator;
    result.denominator = rac1.denominator * rac2.numerator;
    return result;
}

// multiplicacao em Q - racionais
Q q_mult(Q rac1, Q rac2){
    Q result;
    result.numerator = rac1.numerator * rac2.numerator;
    result.denominator = rac1.denominator * rac2.denominator;
    return result;
}

// soma em Q
Q q_add(const Q rac1, const Q rac2){
    Q result;
    result.denominator = rac1.denominator * rac2.denominator;
    result.numerator = rac1.numerator*rac2.denominator + rac2.numerator*rac1.denominator;
    return result;
}

// Nao deve ser usado para imprimir matrizes, mas ficará aqui para testes e dev.
int q_print(const Q rational){
    printf("%2d/%2d", rational.numerator, rational.denominator);
    return 0;
}

int str_to_q(const char * str_rational, Q *num_rational){
    int numerator, denominator;
    char tmp_str_rational[STR_MAX_NUMBER], *ch;

    //puts(str_rational);

    ch = tmp_str_rational;
    strcpy(tmp_str_rational, str_rational);

    ch = strtok(ch, "/");
    numerator = atoi(ch);
    ch = strtok(NULL, "/");
    if(ch != NULL)
        denominator = atoi(ch);
    else
        denominator = 1;

    num_rational->numerator = numerator;
    num_rational->denominator = denominator;
    // printf("Numerador %d\nDenominador%d\n",numerator,denominator);
    return 0;
}

#endif
