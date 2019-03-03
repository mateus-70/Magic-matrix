// Mateus S Silva
// 2018-09-21
// 2018-09-30 - v1 funcional, para numeros inteiros
// O objetivo desse programa é receber duas matrizes e fazer sua multiplicação: o produto usual de matrizes.
//
//
//
// Falta nao deixar inserir nome nao unico para matriz.
// 
// O produto e a soma em Q já estão funcionando corretamente.
// Deve-se então adequar as operacoes nas matrizes para suportar isso também.
// A funcao de inserir está com algum defeito na hora de chamar 'edit_mat()'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_MATRIZES 10
#define MAIOR_NOME 10
#define STR_MAIOR_NUMERO 20
#define MAX_LINHAS_matriz 10
#define MAX_COLUNAS_matriz 10


struct Q {
    int numerador, denominador;
};

struct MATRIZ {
    char nome[MAIOR_NOME];
    int linhas;
    int colunas;
    struct Q matriz[MAX_LINHAS_matriz][MAX_COLUNAS_matriz];
};


// funcoes de back-end
int find_mat(); // acha uma matriz pelo nome
int edit_mat(); // edita nome e entradas de uma matriz
int dump_mat(); // despeja informacoes de uma matriz na saída
struct Q mult_q();
struct Q quoc_q();
struct Q soma_q();
struct Q simplificar_q();
struct MATRIZ escal_mat();
int somar_linha(); 

// funcoes de front-end
int listar_matrizes();
int mostrar_matriz();
int inserir_matriz();
int editar_matriz();
int deletar_matriz();
int obter_transposta();
int calcular_produto();
int escalonar_matriz();

// variaveis globais
int num_matrizes=0;
struct MATRIZ matrizes[MAX_MATRIZES];

// ******** inicio dos corpos de funcoes ***********




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
        menor = sqrt(menor+1.);
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

// funcao de front-end
int listar_matrizes(){
    int i;
    if(num_matrizes == 0){
        puts("Não há matrizes no programa.");
    }else{
        puts("As matrizes em \'matrizes[]\' sao: ");
        for(i=0; i < num_matrizes; i++){
            printf("Matriz %d: %s\n", i+1, matrizes[i].nome);
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

int main(){
    // Variaveis
    int cont_acao=0;
    char acao, acao_valida; //acao=inserir (I), mostrar (M)...  acao_valida: s/n

    //char str_racional1[STR_MAIOR_NUMERO], str_racional2[STR_MAIOR_NUMERO];
    struct Q A, B;

    system("clear");

    A.numerador = 5;
    A.denominador= 3;
    B.numerador = 13;
    B.denominador= 2;

    A = quoc_q(A, B);

    printf("A: NUMERADOR: %d\n Denom: %d\n\n",A.numerador, A.denominador);
    printf(" ***** PROGRAMA PARA MULTIPLICAR MATRIZES *****\n\n");
    // menu
    do{
        do{
            cont_acao++;
            //depuracao only
            // printf("Acao n: %d\n", cont_acao);
            puts("Inserir  |  Listar  |  Mostrar  |  Editar  |  Deletar ");
            puts("Produto  |  Soma  | Transposta |  esCalonada  | (Q, +, *) |  Quit");
            printf("Acao: ");
            scanf(" %c", &acao);
            switch (acao){
                case 'I': case 'i': 
                case 'L': case 'l':
                case 'M': case 'm':
                case 'E': case 'e':
                case 'D': case 'd':
                case 'P': case 'p':
                case 'S': case 's':
                case 'T': case 't':
                case 'C': case 'c':
                case 'Q': case 'q': 
                    acao_valida = 's'; break;
            default: acao_valida = 'n';
            }
        }while(acao_valida != 's');
        switch (acao){
            case 'I': 
            case 'i': 
                if(num_matrizes < MAX_MATRIZES){
                    // Se i.g. num_matrizes=2, ela vai inserir a prox matriz em matrizes[2],
                    //  que é a terceira entrada do array >matrizes<
                    inserir_matriz(); 
                    num_matrizes++;
                }
                break;
            case 'L': 
            case 'l': 
                listar_matrizes();
                break;
            case 'M': 
            case 'm': 
                mostrar_matriz(num_matrizes);
                break;
            case 'E': 
            case 'e': 
                editar_matriz(matrizes);
                break;
            case 'D': 
            case 'd': 
                deletar_matriz();
                break;
            case 'P': 
            case 'p': 
                calcular_produto();
                break;
            case 'S': 
            case 's': 
                calcular_soma();
                break;
            case 'C': 
            case 'c': 
                escalonar_matriz();
                break;
            case 'T': 
            case 't': 
                obter_transposta();
                break;
            /*case 'q': 
            case 'Q': 
                printf("1 num racional: ");
                scanf(" %s", str_racional1);
                printf("2 num racional: ");
                scanf(" %s", str_racional2);

                str_to_q(str_racional1, &num_racional1);
                str_to_q(str_racional2, &num_racional2);
                
                resultado = soma_q(num_racional1, num_racional2);
                printf("------->SOMA = %2d/%d\n", resultado.numerador, resultado.denominador);
                mult_q(num_racional1, num_racional2, &resultado);
                printf("------->PRODUTO = %2d/%d\n", resultado.numerador, resultado.denominador);


                break;*/
            case 'Q': 
            case 'q': 
                puts("\n\nQuitting!\n\n");
                break;
        }
    }while(toupper(acao) != 'Q');

    return 0;
}
