#ifndef DEFINITIONS_HEADER__
    #define DEFINITIONS_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define COMMAND_LENGTH 1000
#define FALSE 0
#define TRUE 1

#define MAX_MATRICES 10
#define MAIOR_NOME 10
#define STR_MAIOR_NUMERO 20
#define MAX_LINHAS_matriz 10
#define MAX_COLUNAS_matriz 10

// Structs declaration - Start
struct Q {
    int numerator, denominator;
};

struct MATRIX {
    char nome[MAIOR_NOME];
    int linhas;
    int colunas;
    struct Q matriz[MAX_LINHAS_matriz][MAX_COLUNAS_matriz];
};
// Structs declaration - End

// Global vars declaration - Start
int matrices_qt=0;
struct MATRIX matrizes[MAX_MATRICES];
// Global vars declaration - End

// Functions declaration - Start
struct Q mult_q(struct Q, struct Q);
struct Q quoc_q(struct Q, struct Q);
struct Q soma_q(struct Q, struct Q);
struct Q simplificar_q(struct Q);
// struct MATRIX escal_mat(); what the heck is this?
// Functions declaration - End


// Back-end functions declarations - Start
int find_mat(); // search for a matrix by name
int edit_mat(); // edit the entrances of a matrix
int dump_mat(); // dumb matrix info at exit // what does this really mean?
int somar_linha(); 
// Back-end functions declarations - End

// Front-end functions declaratins - Start
int listar_matrizes();
int mostrar_matriz();
int inserir_matriz();
int editar_matriz();
int deletar_matriz();
int obter_transposta();
int calcular_produto();
int escalonar_matriz();
// Front-end functions declaratins - End

int str_to_q(const char *, struct Q *);
#endif
