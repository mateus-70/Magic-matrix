#ifndef RATIONALS_HEADER__
    #define RATIONALS_HEADER__

// #include "/home/mateus/ban/math/programs/matrices/matrices.h"


#include "/home/mateus/ban/math/programs/utils/definitions.h"



// Functions definitions
struct Q simplificar_q(struct Q racional){
    int i, menor;

    if (racional.denominator == 0){
        puts("\n\n\nsimplifica_q: DIVISAO POR ZERO\n\n\n\n");
        exit(1);
    }
    if(racional.numerator == 0){
        racional.denominator = 1;
    }else{
        if(racional.denominator < 0){
            racional.denominator *= -1;
            racional.numerator *= -1;
        }
    
        if(racional.numerator < racional.denominator)
            menor = racional.numerator;
        else
            menor = racional.denominator;
        
        // É provavel que o menor tenha menos divisores, por isso usamos o menor deles.
        // sqrt(menor + 1) porque não quero enfrentar problemas com arredondamentos com float.
        // começa por 2, porque numero racional com numerator =1 não é simplificável.
         menor = round(sqrt(menor+1.));
        for(i=2; i < menor; ){
            if( racional.numerator % i == 0){
                if( racional.denominator % i == 0){
                    racional.numerator /= i;
                    racional.denominator /= i;
                }else{
                    i++;
                }
            }else{
                i++;
            }
        }
    }

    return racional;
}

// multiplicacao em Q - racionais
struct Q quoc_q(struct Q rac1, struct Q rac2){
    struct Q resultado;
    
    if(rac2.numerator == 0 || rac2.denominator == 0){
        printf("\n\nDivisão por zero.\n\n");
        exit(0);
    }

    resultado.numerator = rac1.numerator * rac2.denominator;
    resultado.denominator = rac1.denominator * rac2.numerator;
    return resultado;
}

// multiplicacao em Q - racionais
struct Q mult_q(struct Q rac1, struct Q rac2){
    struct Q resultado;
    resultado.numerator = rac1.numerator * rac2.numerator;
    resultado.denominator = rac1.denominator * rac2.denominator;
    return resultado;
}

// soma em Q
struct Q soma_q(const struct Q rac1, const struct Q rac2){
    struct Q resultado;
    resultado.denominator = rac1.denominator * rac2.denominator;
    resultado.numerator = rac1.numerator*rac2.denominator + rac2.numerator*rac1.denominator;
    return resultado;
}

// Nao deve ser usado para imprimir matrizes, mas ficará aqui para testes e dev.
int print_q(const struct Q racional){
    printf("%2d/%2d", racional.numerator, racional.denominator);
    return 0;
}

int str_to_q(const char * str_racional, struct Q *num_racional){
    int numerator, denominator;
    char tmp_str_racional[STR_MAIOR_NUMERO], *ch;

    //puts(str_racional);

    ch = tmp_str_racional;
    strcpy(tmp_str_racional, str_racional);

    ch = strtok(ch, "/");
    numerator = atoi(ch);
    ch = strtok(NULL, "/");
    if(ch != NULL)
        denominator = atoi(ch);
    else
        denominator = 1;

    num_racional->numerator = numerator;
    num_racional->denominator = denominator;
    // printf("Numerador %d\nDenominador%d\n",numerator,denominator);
    return 0;
}

#endif
