#ifndef HEADER_MATRICES__
    #define HEADER_MATRICES__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#include "/home/mateus/ban/math/programs/utils/definitions.h"


// ************************ Functions definitions *************************
//


// funcao de front-end
int listar_matrizes(){
    int i;
    if(matrices_qt == 0){
        puts("There is no matrices in the program.");
    }else{
        puts("The matrices in \'matrizes[]\' are: ");
        for(i=0; i < matrices_qt; i++){
            printf("Matrix %d: %s\n", i+1, matrizes[i].nome);
        }
    }
    printf("\n\n");
    return 0;
}

// funcao de back-end
int dump_mat(struct MATRIX mat){
    int i, j;
    printf("Matrix's name: %s\n", mat.nome);
    printf("Matrix order: %d X %d\n", mat.linhas, mat.colunas);
    printf("Matrix entries:\n");
    for(i=0; i < mat.linhas; i++){
        for(j=0; j < mat.colunas; j++){
            printf("%3d/%-3d\t\t", mat.matriz[i][j].numerator, mat.matriz[i][j].denominator);
        }
        putchar('\n');
    }
    return 0;
}

// IMPREMENTACAO FUTURA
// retorna -1 se nao encontrar o nome da matriz, ou
// returna (int) que é posicao da matriz no array 'matrizes[]'

int find_mat(const char nome[]){
    int i, matrix_pos=-1;
    
    for(i=0; i < matrices_qt; i++){
        if(strcmp(nome, matrizes[i].nome) == 0 ){
            matrix_pos = i;
            break;
        }
    }
    return matrix_pos;
}

// Mostra uma única matriz do array matrizes[] da função 'main'
// O nome da matriz a mostrar é coletado nesta função.
// Essa função é de front-end, para back-end tem-se dump_mat()
int mostrar_matriz(){
    char nome[MAIOR_NOME];
    int i;
    int matrix_pos; // Iremos mostrar uma matriz que está na posição 'matrix_pos' no array de matrizes
    printf("\n\nMatrix's name to show: ");
    scanf(" %s", nome);

    // Comparar o 'nome' da matriz que deseja-se mostrar, com os nomes das matrizes do array
    for(i=0, matrix_pos=-1; i < matrices_qt; i++){
        if(strcmp(nome, matrizes[i].nome) == 0 ){
            matrix_pos = i;
            break;
        }
    }

    if(matrix_pos == -1){
        printf("Invalid name!\n");
    }else{
        dump_mat(matrizes[matrix_pos]);
    }

    printf("\n");
    return 0;
}

int inserir_matriz(){
    int i, j;
    //char info_correta; // as informacoes referentes à matriz estao corretas? (s/n)
    char str_racional[STR_MAIOR_NUMERO]; //aux so para obter as strings que sao numeros racionais

    printf("\n\n \t *** Matrix insertion *** \n");
    printf("Letter to represent (name): ");
    scanf(" %s", matrizes[matrices_qt].nome); 

    printf("Number of rows: ");
    scanf(" %d", &matrizes[matrices_qt].linhas);
    printf("Number of colums: ");
    scanf(" %d", &matrizes[matrices_qt].colunas);

    printf("Insira as entradas da matriz %s.\n", matrizes[matrices_qt].nome);
    printf("Insert the matrix's '%s' entries.\n", matrizes[matrices_qt].nome);
    for(j=0; j < matrizes[matrices_qt].linhas; j++){
        for(i=0; i < matrizes[matrices_qt].colunas; i++){
            printf("%s[%d][%d]: ", matrizes[matrices_qt].nome, j+1, i+1);
            scanf(" %s", str_racional);
            str_to_q(str_racional, &matrizes[matrices_qt].matriz[j][i]);
        }
    }


    printf("\n");
    return 0;
}

int edit_mat(struct MATRIX *mat){
    char alterar,  terminar, str_racional[STR_MAIOR_NUMERO];
    int linha_alterar, coluna_alterar;
    do{
        dump_mat(*mat);
        printf("What do you want to change?\n");
        printf("Name  |  Entry ::\n");
        scanf(" %c", &alterar);
        switch(alterar){
            case 'n': case 'N':{
                printf("New name: ");
                scanf(" %s", &mat->nome[0]);
            }break;
            case 'e': case 'E':{
                printf("Row to change: ");
                scanf("%d", &linha_alterar);
                printf("Colum to change: ");
                scanf("%d", &coluna_alterar);
                printf("Insert the new value: ");
                scanf(" %s", str_racional);
                str_to_q(str_racional, &mat->matriz[linha_alterar-1][coluna_alterar-1] );
                //scanf("%d", &mat->matriz[linha_alterar-1][coluna_alterar-1] );
            }break;
        }
        putchar('\n');
        dump_mat(*mat);
        printf("Do you want to finish this matrix's edition? (y/n): ");
        scanf(" %c", &terminar);
    }while( toupper(terminar) != 'Y' );
    return 0;
}



// Função de front-end
// Para back-end veja edit_mat();
int editar_matriz(){
    char nome[MAIOR_NOME], voltar; //nome da matriz, voltar para o menu principal
    int matrix_pos;
    printf(" \n\n \t *** Matrix update *** \n");
    do{
        printf("Write the matrix's name to update: ");
        scanf(" %s", nome);

        matrix_pos = find_mat(nome);
    
        if(matrix_pos == -1){
            printf("Invalid name");
        }else{
            puts("Data: ");
            edit_mat(&matrizes[matrix_pos]); //posicao da matriz no matrizes[]
        }
        printf("Do you want to back to main menu? (y/n)");
        scanf(" %c", &voltar);
    }while(toupper(voltar) != 'Y' || matrix_pos == -1);
    
    return 0;
}


// funcao de front-end
//
int deletar_matriz(){
    int matrix_pos;
    char nome[MAIOR_NOME];
    printf("Matrix name to delete: ");
    scanf(" %s", nome);
    matrix_pos = find_mat(nome);

    if(matrix_pos >= 0){
        // deletar matriz
        matrizes[matrix_pos].linhas=0;
        matrizes[matrix_pos].colunas=0;
        strcpy(matrizes[matrix_pos].nome, "DELETED");
    }
    return matrix_pos;
}

// funcao de front-end
int calcular_produto(){
    char nome_esquerda[MAIOR_NOME], nome_direita[MAIOR_NOME];
    int i, j, k;
    int pos_esquerda, pos_direita; // posicao das matrizes esq e dir no array matrizes[]
    struct Q entrada, aux_racional; //entrada da matriz
    struct MATRIX produto;

    printf("Name of left side matrix: ");
    scanf(" %s", nome_esquerda);
    printf("Name of right side matrix:");
    scanf(" %s", nome_direita);
    
    pos_esquerda = find_mat(nome_esquerda);
    pos_direita = find_mat(nome_direita);

    if(pos_direita == -1 || pos_esquerda == -1)
        printf("Some matrix name is wrong.\n");
    else{
        if(matrizes[pos_esquerda].colunas != matrizes[pos_direita].linhas){
            printf("Impossible to calculate the product. Format should be: (mXn * nXp) \n\n");
        }else{
            // calcula a mult usual de matrizes e armazena em 'produto.matriz'
            for(i=0; i < matrizes[pos_esquerda].linhas; i++ ){
                for(j=0; j < matrizes[pos_direita].colunas; j++){
                    entrada.numerator = 0 ;
                    entrada.denominator = 1 ;
                    for(k=0; k < matrizes[pos_esquerda].colunas; k++){
                        aux_racional = mult_q(matrizes[pos_esquerda].matriz[i][k], matrizes[pos_direita].matriz[k][j]);
                        entrada = soma_q(entrada, aux_racional);

                        //entrada += matrizes[pos_esquerda].matriz[i][k] * matrizes[pos_direita].matriz[k][j];
                    }
                    entrada = simplificar_q(entrada);
                    produto.matriz[i][j]=entrada;
                }
            }

            produto.linhas = matrizes[pos_esquerda].linhas;
            produto.colunas = matrizes[pos_direita].colunas;
            strcpy(produto.nome, matrizes[pos_esquerda].nome);
            strcat(produto.nome, matrizes[pos_direita].nome);
        
            if(matrices_qt < MAX_MATRICES){
                // copia para 'matrizes[]'
                matrizes[matrices_qt].linhas = produto.linhas;
                matrizes[matrices_qt].colunas = produto.colunas;
                strcpy(matrizes[matrices_qt].nome, produto.nome);
                
                for(i=0; i<matrizes[matrices_qt].linhas; i++){
                    for(j=0; j<matrizes[matrices_qt].colunas; j++){
                        matrizes[matrices_qt].matriz[i][j] = produto.matriz[i][j];
                    }
                }
                matrices_qt++;
            }
    
            // mostra o produto de matrizes
            puts("The product is: \n");
            dump_mat(produto);
        }
    }

    return 0;
}


// funcao de front-end
int calcular_soma(){
    char nome_esquerda[MAIOR_NOME], nome_direita[MAIOR_NOME];
    int i, j;
    int pos_esquerda, pos_direita; // posicao das matrizes esq e dir no array matrizes[]
    struct Q entrada; //entrada da matriz
    struct MATRIX soma;

    printf("Name of left side matrix: ");
    scanf(" %s", nome_esquerda);
    printf("Name of right side matrix: ");
    scanf(" %s", nome_direita);
    
    pos_esquerda = find_mat(nome_esquerda);
    pos_direita = find_mat(nome_direita);

    if(pos_direita == -1 || pos_esquerda == -1)
        printf("Some matrix name is wrong.\n");
    else{
        if(matrizes[pos_esquerda].linhas != matrizes[pos_direita].linhas || matrizes[pos_esquerda].colunas != matrizes[pos_direita].colunas){
            printf("Impossible to calculate sum. Format should be: (mXn + mXn) \n\n");
        }else{
            // calcula a soma usual de matrizes e armazena em 'soma.matriz'
            for(i=0; i < matrizes[pos_esquerda].linhas; i++ ){
                for(j=0; j < matrizes[pos_esquerda].colunas; j++){
                    entrada = soma_q(matrizes[pos_esquerda].matriz[i][j], matrizes[pos_direita].matriz[i][j]);
                    soma.matriz[i][j] = simplificar_q(entrada);
                }
            }

            soma.linhas = matrizes[pos_esquerda].linhas;
            soma.colunas = matrizes[pos_esquerda].colunas;

            printf("Letter to represent (name): ");
            scanf(" %s", soma.nome); 
        
            if(matrices_qt < MAX_MATRICES){
                // copia para 'matrizes[]'
                matrizes[matrices_qt].linhas = soma.linhas;
                matrizes[matrices_qt].colunas = soma.colunas;
                strcpy(matrizes[matrices_qt].nome, soma.nome);
                
                for(i=0; i<matrizes[matrices_qt].linhas; i++){
                    for(j=0; j<matrizes[matrices_qt].colunas; j++){
                        matrizes[matrices_qt].matriz[i][j] = soma.matriz[i][j];
                    }
                }
                matrices_qt++;
            }
    
            // mostra a soma de matrizes
            puts("The sum is: \n");
            dump_mat(soma);
        }
    }

    return 0;
}


// funcao de front-end
int obter_transposta(){
    int i, j;
    int matrix_pos;
    char nome[MAIOR_NOME];

    printf("\n\n \t *** Transposing matrix *** \n");
    printf("Nome da matriz referencia: ");
    printf("Name of matrix of reference: ");
    scanf(" %s", nome); 

    matrix_pos = find_mat(nome);

    if(matrix_pos == -1){
        printf("Wrong name!\n");
    }else{
        if(matrices_qt < MAX_MATRICES){
            printf("Name of transposed: ");
            scanf(" %s", matrizes[matrices_qt].nome);

            matrizes[matrices_qt].linhas = matrizes[matrix_pos].colunas;
            matrizes[matrices_qt].colunas = matrizes[matrix_pos].linhas;

            for(i=0; i < matrizes[matrices_qt].linhas; i++ )
                for(j=0; j< matrizes[matrices_qt].colunas; j++)
                    matrizes[matrices_qt].matriz[i][j] = matrizes[matrix_pos].matriz[j][i];
            dump_mat(matrizes[matrices_qt]); //nesse caso é a matriz recem inserida
            matrices_qt++;
        }
    }
    return matrix_pos;
}

int somar_linha(const struct Q q, struct MATRIX *matriz, const int linha_resultado, const int linha_soma ){
    int j;
    for(j=0; j < matriz->colunas; j++){
        matriz->matriz[linha_resultado][j] = \
                                             simplificar_q( \
                                                     soma_q( \
                                                         matriz->matriz[linha_resultado][j], \
                                                         mult_q(q, matriz->matriz[linha_soma][j]) ) );
    }
    return 0;
}

// funcao de back-end
// escalona uma matriz
struct MATRIX escal_mat(struct MATRIX mat){
    struct MATRIX escalonada;
    struct Q q;
    int i, j, x, y;

    // copia os dados para a escalonada
    escalonada.linhas = mat.linhas;
    escalonada.colunas = mat.colunas;
    for(i=0; i < mat.linhas; i++ )
        for(j=0; j<mat.colunas; j++)
            escalonada.matriz[i][j] = mat.matriz[i][j];

    // Escalona a matriz 'escalonada'
    for(i=0; i+1<escalonada.linhas; i++){
        for(x=1; x+i < escalonada.linhas; x++){ 
            if(escalonada.matriz[i+x][i].numerator == 0 ) continue; 
            // achar o valor para multiplicar cada elemento da linha para subtrair
            q = quoc_q(escalonada.matriz[i+x][i], escalonada.matriz[i][i]); 
            q.numerator *= -1;
            somar_linha(q, &escalonada, i+x, i);
            /*
            for(y=0; y<escalonada.colunas; y++){ 
                escalonada.matriz[i+x][y] = simplificar_q(\
                    soma_q(escalonada.matriz[i+x][y], \
                    mult_q(q, escalonada.matriz[i][y]) ) );

            }*/
        }
    }
    return escalonada;
}

// Escalona e reduz uma matriz
// o escalonamento é feito por outra funcao
struct MATRIX escal_red_mat(struct MATRIX mat){
    struct MATRIX escalonada_reduzida;
    
    escalonada_reduzida = escal_mat(mat);
    

    return escalonada_reduzida;
}

// funcao de front-end
int escalonar_matriz(){
    int matrix_pos;
    // int i, j, x, y;
    char nome[MAIOR_NOME];
    // struct Q q, racional;

    printf("Name of matrix of reference: ");
    scanf(" %s", nome); 

    matrix_pos = find_mat(nome);
    if(matrix_pos == -1){
        printf("Wrong name!\n");
    }else{
        if(matrices_qt < MAX_MATRICES){
            /*
            matrizes[matrices_qt].linhas = matrizes[matrix_pos].linhas;
            matrizes[matrices_qt].colunas = matrizes[matrix_pos].colunas;

            for(i=0; i < matrizes[matrices_qt].linhas; i++ )
                for(j=0; j<matrizes[matrices_qt].colunas; j++)
                    matrizes[matrices_qt].matriz[i][j] = matrizes[matrix_pos].matriz[i][j];
*/
            // Escalona a matriz
            matrizes[matrices_qt] = escal_red_mat(matrizes[matrix_pos]);
            printf("Name of echelon: ");
            scanf(" %s", matrizes[matrices_qt].nome);
            /*
            for(i=0; i+1<matrizes[matrices_qt].linhas; i++){
                //for(j=i; j<matrizes[matrices_qt].colunas; ){// SUSPEITAR DESTA PARTE RSRSRS, j serve para quẽ?
                    for(x=1; x+i < matrizes[matrices_qt].linhas; x++){ 
                        if(matrizes[matrices_qt].matriz[i+x][i].numerator == 0 ) continue; // j --> i
                        // achar o valor para multiplicar cada elemento da linha para subtrair
                        q = quoc_q(matrizes[matrices_qt].matriz[i+x][i], matrizes[matrices_qt].matriz[i][i]); // j--> i
                        q.numerator *= -1;

                        printf("\n\n\n q=%d/%d\n\n\n",q.numerator,q.denominator);

                        for(y=0; y<matrizes[matrices_qt].colunas; y++){ // j --> i
                            matrizes[matrices_qt].matriz[i+x][y] = simplificar_q(\
                                soma_q(matrizes[matrices_qt].matriz[i+x][y], \
                                       racional = mult_q(q, matrizes[matrices_qt].matriz[i][y]) ) );
                            //printf("RACIONAL %d/%d\n\n",racional.numerator, racional.denominator);

                        }
                    }
                //}
            }*/


            dump_mat(matrizes[matrices_qt]); //nesse caso é a matriz recem inserida
            matrices_qt++;
        }
    }

    return 0;
}

#endif
