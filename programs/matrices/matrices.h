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
    if(num_matrizes == 0){
        puts("There is no matrices in the program.");
    }else{
        puts("The matrices in \'matrizes[]\' are: ");
        for(i=0; i < num_matrizes; i++){
            printf("Matrix %d: %s\n", i+1, matrizes[i].nome);
        }
    }
    printf("\n\n");
    return 0;
}

// funcao de back-end
int dump_mat(struct MATRIZ mat){
    int i, j;
    printf("Nome da matriz: %s\n", mat.nome);
    printf("Tamanho da matriz: %d X %d\n", mat.linhas, mat.colunas);
    printf("Entradas da matriz:\n");
    for(i=0; i < mat.linhas; i++){
        for(j=0; j < mat.colunas; j++){
            printf("%3d/%-3d\t\t", mat.matriz[i][j].numerador, mat.matriz[i][j].denominador);
        }
        putchar('\n');
    }
    return 0;
}

// IMPREMENTACAO FUTURA
// retorna -1 se nao encontrar o nome da matriz, ou
// returna (int) que é posicao da matriz no array 'matrizes[]'

int find_mat(const char nome[]){
    int i, pos_matriz=-1;
    
    for(i=0; i < num_matrizes; i++){
        if(strcmp(nome, matrizes[i].nome) == 0 ){
            pos_matriz = i;
            break;
        }
    }
    return pos_matriz;
}

// Mostra uma única matriz do array matrizes[] da função 'main'
// O nome da matriz a mostrar é coletado nesta função.
// Essa função é de front-end, para back-end tem-se dump_mat()
int mostrar_matriz(){
    char nome[MAIOR_NOME];
    int i;
    int pos_matriz; // Iremos mostrar uma matriz que está na posição 'pos_matriz' no array de matrizes
    printf("\n\nNome da matriz a mostrar: ");
    scanf(" %s", nome);

    // Comparar o 'nome' da matriz que deseja-se mostrar, com os nomes das matrizes do array
    for(i=0, pos_matriz=-1; i < num_matrizes; i++){
        if(strcmp(nome, matrizes[i].nome) == 0 ){
            pos_matriz = i;
            break;
        }
    }

    if(pos_matriz == -1){
        printf("Nome inválido!\n");
    }else{
        dump_mat(matrizes[pos_matriz]);
    }

    printf("\n");
    return 0;
}

int inserir_matriz(){
    int i, j;
    //char info_correta; // as informacoes referentes à matriz estao corretas? (s/n)
    char str_racional[STR_MAIOR_NUMERO]; //aux so para obter as strings que sao numeros racionais

    printf("\n\n \t *** INSERIR MATRIZ *** \n");
    printf("Letra representante (nome): ");
    scanf(" %s", matrizes[num_matrizes].nome); 

    printf("Número de linhas: ");
    scanf(" %d", &matrizes[num_matrizes].linhas);
    printf("Número de colunas: ");
    scanf(" %d", &matrizes[num_matrizes].colunas);

    printf("Insira as entradas da matriz %s.\n", matrizes[num_matrizes].nome);
    for(j=0; j < matrizes[num_matrizes].linhas; j++){
        for(i=0; i < matrizes[num_matrizes].colunas; i++){
            printf("%s[%d][%d]: ", matrizes[num_matrizes].nome, j+1, i+1);
            scanf(" %s", str_racional);
            str_to_q(str_racional, &matrizes[num_matrizes].matriz[j][i]);
        }
    }


    printf("\n");
    return 0;
}

int edit_mat(struct MATRIZ *mat){
    char alterar,  terminar, str_racional[STR_MAIOR_NUMERO];
    int linha_alterar, coluna_alterar;
    do{
        dump_mat(*mat);
        printf("O que deseja alterar?\n");
        printf("Nome  |  Entrada ::\n");
        scanf(" %c", &alterar);
        switch(alterar){
            case 'n': case 'N':{
                printf("Novo nome: ");
                scanf(" %s", &mat->nome[0]);
            }break;
            case 'e': case 'E':{
                printf("Linha a alterar? ");
                scanf("%d", &linha_alterar);
                printf("Coluna a alterar? ");
                scanf("%d", &coluna_alterar);
                printf("Insira o novo valor: ");
                scanf(" %s", str_racional);
                str_to_q(str_racional, &mat->matriz[linha_alterar-1][coluna_alterar-1] );
                //scanf("%d", &mat->matriz[linha_alterar-1][coluna_alterar-1] );
            }break;
        }
        putchar('\n');
        dump_mat(*mat);
        printf("Terminar a edicao desta matriz? (s/n): ");
        scanf(" %c", &terminar);
    }while( toupper(terminar) != 'S' );
    return 0;
}



// Função de front-end
// Para back-end veja edit_mat();
int editar_matriz(){
    char nome[MAIOR_NOME], voltar; //nome da matriz, voltar para o menu principal
    int pos_matriz;
    printf(" \n\n \t *** EDITAR MATRIZ *** \n");
    do{
        printf("Digite o nome da matriz a editar: ");
        scanf(" %s", nome);

        pos_matriz = find_mat(nome);
    
        if(pos_matriz == -1){
            printf("Nome inválido");
        }else{
            puts("Dados: ");
            edit_mat(&matrizes[pos_matriz]); //posicao da matriz no matrizes[]
        }
        printf("Voltar ao menu principal? (s/n)");
        scanf(" %c", &voltar);
    }while(toupper(voltar) != 'S' || pos_matriz == -1);
    
    return 0;
}


// funcao de front-end
//
int deletar_matriz(){
    int pos_matriz;
    char nome[MAIOR_NOME];
    printf("Nome da matriz a deletar: ");
    scanf(" %s", nome);
    pos_matriz = find_mat(nome);

    if(pos_matriz >= 0){
        // deletar matriz
        matrizes[pos_matriz].linhas=0;
        matrizes[pos_matriz].colunas=0;
        strcpy(matrizes[pos_matriz].nome, "DELETADO");
    }
    return pos_matriz;
}

// funcao de front-end
int calcular_produto(){
    char nome_esquerda[MAIOR_NOME], nome_direita[MAIOR_NOME];
    int i, j, k;
    int pos_esquerda, pos_direita; // posicao das matrizes esq e dir no array matrizes[]
    struct Q entrada, aux_racional; //entrada da matriz
    struct MATRIZ produto;

    printf("Nome da matriz \'a esquerda: ");
    scanf(" %s", nome_esquerda);
    printf("Nome da matriz \'a direita: ");
    scanf(" %s", nome_direita);
    
    pos_esquerda = find_mat(nome_esquerda);
    pos_direita = find_mat(nome_direita);

    if(pos_direita == -1 || pos_esquerda == -1)
        printf("Alguma matriz está com nome errado.\n");
    else{
        if(matrizes[pos_esquerda].colunas != matrizes[pos_direita].linhas){
            printf("Impossível calcular produto deve-se ter: (mXn * nXp) \n\n");
        }else{
            // calcula a mult usual de matrizes e armazena em 'produto.matriz'
            for(i=0; i < matrizes[pos_esquerda].linhas; i++ ){
                for(j=0; j < matrizes[pos_direita].colunas; j++){
                    entrada.numerador = 0 ;
                    entrada.denominador = 1 ;
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
        
            if(num_matrizes < MAX_MATRIZES){
                // copia para 'matrizes[]'
                matrizes[num_matrizes].linhas = produto.linhas;
                matrizes[num_matrizes].colunas = produto.colunas;
                strcpy(matrizes[num_matrizes].nome, produto.nome);
                
                for(i=0; i<matrizes[num_matrizes].linhas; i++){
                    for(j=0; j<matrizes[num_matrizes].colunas; j++){
                        matrizes[num_matrizes].matriz[i][j] = produto.matriz[i][j];
                    }
                }
                num_matrizes++;
            }
    
            // mostra o produto de matrizes
            puts("O produto é: \n");
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
    struct MATRIZ soma;

    printf("Nome da matriz \'a esquerda: ");
    scanf(" %s", nome_esquerda);
    printf("Nome da matriz \'a direita: ");
    scanf(" %s", nome_direita);
    
    pos_esquerda = find_mat(nome_esquerda);
    pos_direita = find_mat(nome_direita);

    if(pos_direita == -1 || pos_esquerda == -1)
        printf("Alguma matriz está com nome errado.\n");
    else{
        if(matrizes[pos_esquerda].linhas != matrizes[pos_direita].linhas || matrizes[pos_esquerda].colunas != matrizes[pos_direita].colunas){
            printf("Impossível calcular soma, deve-se ter: (mXn + mXn) \n\n");
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

            printf("Letra representante (nome): ");
            scanf(" %s", soma.nome); 
        
            if(num_matrizes < MAX_MATRIZES){
                // copia para 'matrizes[]'
                matrizes[num_matrizes].linhas = soma.linhas;
                matrizes[num_matrizes].colunas = soma.colunas;
                strcpy(matrizes[num_matrizes].nome, soma.nome);
                
                for(i=0; i<matrizes[num_matrizes].linhas; i++){
                    for(j=0; j<matrizes[num_matrizes].colunas; j++){
                        matrizes[num_matrizes].matriz[i][j] = soma.matriz[i][j];
                    }
                }
                num_matrizes++;
            }
    
            // mostra a soma de matrizes
            puts("A soma é: \n");
            dump_mat(soma);
        }
    }

    return 0;
}


// funcao de front-end
int obter_transposta(){
    int i, j;
    int pos_matriz;
    char nome[MAIOR_NOME];

    printf("\n\n \t *** OBTER TRANSPOSTA *** \n");
    printf("Nome da matriz referencia: ");
    scanf(" %s", nome); 

    pos_matriz = find_mat(nome);

    if(pos_matriz == -1){
        printf("Nome errado!\n");
    }else{
        if(num_matrizes < MAX_MATRIZES){
            printf("Nome da transposta: ");
            scanf(" %s", matrizes[num_matrizes].nome);

            matrizes[num_matrizes].linhas = matrizes[pos_matriz].colunas;
            matrizes[num_matrizes].colunas = matrizes[pos_matriz].linhas;

            for(i=0; i < matrizes[num_matrizes].linhas; i++ )
                for(j=0; j< matrizes[num_matrizes].colunas; j++)
                    matrizes[num_matrizes].matriz[i][j] = matrizes[pos_matriz].matriz[j][i];
            dump_mat(matrizes[num_matrizes]); //nesse caso é a matriz recem inserida
            num_matrizes++;
        }
    }
    return pos_matriz;
}

int somar_linha(const struct Q q, struct MATRIZ *matriz, const int linha_resultado, const int linha_soma ){
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
struct MATRIZ escal_mat(struct MATRIZ mat){
    struct MATRIZ escalonada;
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
            if(escalonada.matriz[i+x][i].numerador == 0 ) continue; 
            // achar o valor para multiplicar cada elemento da linha para subtrair
            q = quoc_q(escalonada.matriz[i+x][i], escalonada.matriz[i][i]); 
            q.numerador *= -1;
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
struct MATRIZ escal_red_mat(struct MATRIZ mat){
    struct MATRIZ escalonada_reduzida;
    
    escalonada_reduzida = escal_mat(mat);
    

    return escalonada_reduzida;
}

// funcao de front-end
int escalonar_matriz(){
    int pos_matriz;
    // int i, j, x, y;
    char nome[MAIOR_NOME];
    // struct Q q, racional;

    printf("Nome da matriz referencia: ");
    scanf(" %s", nome); 

    pos_matriz = find_mat(nome);
    if(pos_matriz == -1){
        printf("Nome errado!\n");
    }else{
        if(num_matrizes < MAX_MATRIZES){
            /*
            matrizes[num_matrizes].linhas = matrizes[pos_matriz].linhas;
            matrizes[num_matrizes].colunas = matrizes[pos_matriz].colunas;

            for(i=0; i < matrizes[num_matrizes].linhas; i++ )
                for(j=0; j<matrizes[num_matrizes].colunas; j++)
                    matrizes[num_matrizes].matriz[i][j] = matrizes[pos_matriz].matriz[i][j];
*/
            // Escalona a matriz
            matrizes[num_matrizes] = escal_red_mat(matrizes[pos_matriz]);
            printf("Nome da escalonada: ");
            scanf(" %s", matrizes[num_matrizes].nome);
            /*
            for(i=0; i+1<matrizes[num_matrizes].linhas; i++){
                //for(j=i; j<matrizes[num_matrizes].colunas; ){// SUSPEITAR DESTA PARTE RSRSRS, j serve para quẽ?
                    for(x=1; x+i < matrizes[num_matrizes].linhas; x++){ 
                        if(matrizes[num_matrizes].matriz[i+x][i].numerador == 0 ) continue; // j --> i
                        // achar o valor para multiplicar cada elemento da linha para subtrair
                        q = quoc_q(matrizes[num_matrizes].matriz[i+x][i], matrizes[num_matrizes].matriz[i][i]); // j--> i
                        q.numerador *= -1;

                        printf("\n\n\n q=%d/%d\n\n\n",q.numerador,q.denominador);

                        for(y=0; y<matrizes[num_matrizes].colunas; y++){ // j --> i
                            matrizes[num_matrizes].matriz[i+x][y] = simplificar_q(\
                                soma_q(matrizes[num_matrizes].matriz[i+x][y], \
                                       racional = mult_q(q, matrizes[num_matrizes].matriz[i][y]) ) );
                            //printf("RACIONAL %d/%d\n\n",racional.numerador, racional.denominador);

                        }
                    }
                //}
            }*/


            dump_mat(matrizes[num_matrizes]); //nesse caso é a matriz recem inserida
            num_matrizes++;
        }
    }

    return 0;
}

#endif
