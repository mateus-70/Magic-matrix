#ifndef RATIONALS_HEADER__
    #define RATIONALS_HEADER__

// #include "/home/mateus/ban/math/programs/matrices/matrices.h"


#include "/home/mateus/ban/math/programs/utils/definitions.h"



// Functions definitions
struct Q simplificar_q(struct Q racional){
    int i, menor;

    if (racional.denominador == 0){
        puts("\n\n\nsimplifica_q: DIVISAO POR ZERO\n\n\n\n");
        exit(1);
    }
    if(racional.numerador == 0){
        racional.denominador = 1;
    }else{
        if(racional.denominador < 0){
            racional.denominador *= -1;
            racional.numerador *= -1;
        }
    
        if(racional.numerador < racional.denominador)
            menor = racional.numerador;
        else
            menor = racional.denominador;
        
        // É provavel que o menor tenha menos divisores, por isso usamos o menor deles.
        // sqrt(menor + 1) porque não quero enfrentar problemas com arredondamentos com float.
        // começa por 2, porque numero racional com numerador =1 não é simplificável.
         menor = round(sqrt(menor+1.));
        for(i=2; i < menor; ){
            if( racional.numerador % i == 0){
                if( racional.denominador % i == 0){
                    racional.numerador /= i;
                    racional.denominador /= i;
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
    
    if(rac2.numerador == 0 || rac2.denominador == 0){
        printf("\n\nDivisão por zero.\n\n");
        exit(0);
    }

    resultado.numerador = rac1.numerador * rac2.denominador;
    resultado.denominador = rac1.denominador * rac2.numerador;
    return resultado;
}

// multiplicacao em Q - racionais
struct Q mult_q(struct Q rac1, struct Q rac2){
    struct Q resultado;
    resultado.numerador = rac1.numerador * rac2.numerador;
    resultado.denominador = rac1.denominador * rac2.denominador;
    return resultado;
}

// soma em Q
struct Q soma_q(const struct Q rac1, const struct Q rac2){
    struct Q resultado;
    resultado.denominador = rac1.denominador * rac2.denominador;
    resultado.numerador = rac1.numerador*rac2.denominador + rac2.numerador*rac1.denominador;
    return resultado;
}

// Nao deve ser usado para imprimir matrizes, mas ficará aqui para testes e dev.
int print_q(const struct Q racional){
    printf("%2d/%2d", racional.numerador, racional.denominador);
    return 0;
}

int str_to_q(const char * str_racional, struct Q *num_racional){
    int numerador, denominador;
    char tmp_str_racional[STR_MAIOR_NUMERO], *ch;

    //puts(str_racional);

    ch = tmp_str_racional;
    strcpy(tmp_str_racional, str_racional);

    ch = strtok(ch, "/");
    numerador = atoi(ch);
    ch = strtok(NULL, "/");
    if(ch != NULL)
        denominador = atoi(ch);
    else
        denominador = 1;

    num_racional->numerador = numerador;
    num_racional->denominador = denominador;
    // printf("Numerador %d\nDenominador%d\n",numerador,denominador);
    return 0;
}

#endif
