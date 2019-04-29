/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
*/

#include "/home/mateus/ban/math/programs/utils/definitions.h"

// int matrices_qt=0; // quantity
// double matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS] = { 0 };

// ************************ Functions definitions *************************
//


// funcao de front-end
// int matrices_list(){
//     int k, j, i;
//     for(k=0; i<var_qt && strcmp(variables[k].data_type, "M"); i++)
//         ;
//     if(k == var_qt)
//     {
//         if(strcmp(variables[i].data_type, MATRIX_TYPE))
//             printf("Only the matrix \n%s\n", variables[i].name);
//         for(i=0; i< variables[i].pt->rows)
//         {
//             for(j=0; j< variables[i].pt->columns)
//                 printf("%lf ",variables[i].pt[i][j])
//             printf("\n");
//         }
//     }
// 
// 
// 
//     if(matrices_qt == 0){
//         puts("There is no matrices in the program.");
//     }else{
//         puts("The matrices in \'matrices[]\' are: ");
//         for(i=0; i < matrices_qt; i++){
//             printf("Matrix %d: %s\n", i+1, matrices[i].name);
//         }
//     }
//     printf("\n\n");
//     return 0;
// }
// 
// // funcao de back-end
// int dump_mat(struct MATRIX mat){
//     int i, j;
//     printf("Matrix's name: %s\n", mat.name);
//     printf("Matrix order: %d X %d\n", mat.rows, mat.columns);
//     printf("Matrix entries:\n");
//     for(i=0; i < mat.rows; i++){
//         for(j=0; j < mat.columns; j++){
//             printf("%3d/%-3d\t\t", mat.matrix[i][j].numerator, mat.matrix[i][j].denominator);
//         }
//         putchar('\n');
//     }
//     return 0;
// }
// 
// // IMPREMENTACAO FUTURA
// // retorna -1 se nao encontrar o name da matrix, ou
// // returna (int) que é posicao da matrix no array 'matrices[]'
// 
// int find_matrix(const char name[]){
//     int i, matrix_pos=-1;
//     
//     for(i=0; i < matrices_qt; i++){
//         if(strcmp(name, matrices[i].name) == 0 ){
//             matrix_pos = i;
//             break;
//         }
//     }
//     return matrix_pos;
// }
// 
// // Mostra uma única matrix do array matrices[] da função 'main'
// // O name da matrix a mostrar é coletado nesta função.
// // Essa função é de front-end, para back-end tem-se dump_mat()
// int show_matrix(){
//     char name[MAX_NAME];
//     int i;
//     int matrix_pos; // Iremos mostrar uma matrix que está na posição 'matrix_pos' no array de matrices
//     printf("\n\nMatrix's name to show: ");
//     scanf(" %s", name);
// 
//     // Comparar o 'name' da matrix que deseja-se mostrar, com os names das matrices do array
//     for(i=0, matrix_pos=-1; i < matrices_qt; i++){
//         if(strcmp(name, matrices[i].name) == 0 ){
//             matrix_pos = i;
//             break;
//         }
//     }
// 
//     if(matrix_pos == -1){
//         printf("Invalid name!\n");
//     }else{
//         dump_mat(matrices[matrix_pos]);
//     }
// 
//     printf("\n");
//     return 0;
// }
// 
// int matrix_insert(){
//     int i, j;
//     //char info_correta; // as informacoes referentes à matrix estao corretas? (s/n)
//     char str_rational[STR_MAX_NUMBER]; //aux so para obter as strings que sao numeros racionais
// 
//     printf("\n\n \t *** Matrix insertion *** \n");
//     printf("Letter to represent (name): ");
//     scanf(" %s", matrices[matrices_qt].name); 
// 
//     printf("Number of rows: ");
//     scanf(" %d", &matrices[matrices_qt].rows);
//     printf("Number of colums: ");
//     scanf(" %d", &matrices[matrices_qt].columns);
// 
//     printf("Insira as entradas da matrix %s.\n", matrices[matrices_qt].name);
//     printf("Insert the matrix's '%s' entries.\n", matrices[matrices_qt].name);
//     for(j=0; j < matrices[matrices_qt].rows; j++){
//         for(i=0; i < matrices[matrices_qt].columns; i++){
//             printf("%s[%d][%d]: ", matrices[matrices_qt].name, j+1, i+1);
//             scanf(" %s", str_rational);
//             str_to_q(str_rational, &matrices[matrices_qt].matrix[j][i]);
//         }
//     }
// 
// 
//     printf("\n");
//     return 0;
// }
// 
// int edit_matrix(struct MATRIX *mat){
//     char alterar,  terminar, str_rational[STR_MAX_NUMBER];
//     int linha_alterar, coluna_alterar;
//     do{
//         dump_mat(*mat);
//         printf("What do you want to change?\n");
//         printf("Name  |  Entry ::\n");
//         scanf(" %c", &alterar);
//         switch(alterar){
//             case 'n': case 'N':{
//                 printf("New name: ");
//                 scanf(" %s", &mat->name[0]);
//             }break;
//             case 'e': case 'E':{
//                 printf("Row to change: ");
//                 scanf("%d", &linha_alterar);
//                 printf("Colum to change: ");
//                 scanf("%d", &coluna_alterar);
//                 printf("Insert the new value: ");
//                 scanf(" %s", str_rational);
//                 str_to_q(str_rational, &mat->matrix[linha_alterar-1][coluna_alterar-1] );
//                 //scanf("%d", &mat->matrix[linha_alterar-1][coluna_alterar-1] );
//             }break;
//         }
//         putchar('\n');
//         dump_mat(*mat);
//         printf("Do you want to finish this matrix's edition? (y/n): ");
//         scanf(" %c", &terminar);
//     }while( toupper(terminar) != 'Y' );
//     return 0;
// }
// 
// 
// 
// // Função de front-end
// // Para back-end veja edit_matrix();
// int editar_matrix(){
//     char name[MAX_NAME], voltar; //name da matrix, voltar para o menu principal
//     int matrix_pos;
//     printf(" \n\n \t *** Matrix update *** \n");
//     do{
//         printf("Write the matrix's name to update: ");
//         scanf(" %s", name);
// 
//         matrix_pos = find_matrix(name);
//     
//         if(matrix_pos == -1){
//             printf("Invalid name");
//         }else{
//             puts("Data: ");
//             edit_matrix(&matrices[matrix_pos]); //posicao da matrix no matrices[]
//         }
//         printf("Do you want to back to main menu? (y/n)");
//         scanf(" %c", &voltar);
//     }while(toupper(voltar) != 'Y' || matrix_pos == -1);
//     
//     return 0;
// }
// 
// 
// // funcao de front-end
// //
// int remove_matrix(){
//     int matrix_pos;
//     char name[MAX_NAME];
//     printf("Matrix name to delete: ");
//     scanf(" %s", name);
//     matrix_pos = find_matrix(name);
// 
//     if(matrix_pos >= 0){
//         // deletar matrix
//         matrices[matrix_pos].rows=0;
//         matrices[matrix_pos].columns=0;
//         strcpy(matrices[matrix_pos].name, "DELETED");
//     }
//     return matrix_pos;
// }
// 
// // funcao de front-end
// int matrix_product(){
//     char leftSide_name[MAX_NAME], rightSide_name[MAX_NAME];
//     int i, j, k;
//     int leftSide_position, rightSide_position; // posicao das matrices esq e dir no array matrices[]
//     Q entrada, aux_rational; //entrada da matrix
//     struct MATRIX produto;
// 
//     printf("Name of left side matrix: ");
//     scanf(" %s", leftSide_name);
//     printf("Name of right side matrix:");
//     scanf(" %s", rightSide_name);
//     
//     leftSide_position = find_matrix(leftSide_name);
//     rightSide_position = find_matrix(rightSide_name);
// 
//     if(rightSide_position == -1 || leftSide_position == -1)
//         printf("Some matrix name is wrong.\n");
//     else{
//         if(matrices[leftSide_position].columns != matrices[rightSide_position].rows){
//             printf("Impossible to calculate the product. Format should be: (mXn * nXp) \n\n");
//         }else{
//             // calcula a mult usual de matrices e armazena em 'produto.matrix'
//             for(i=0; i < matrices[leftSide_position].rows; i++ ){
//                 for(j=0; j < matrices[rightSide_position].columns; j++){
//                     entrada.numerator = 0 ;
//                     entrada.denominator = 1 ;
//                     for(k=0; k < matrices[leftSide_position].columns; k++){
//                         aux_rational = q_mult(matrices[leftSide_position].matrix[i][k], matrices[rightSide_position].matrix[k][j]);
//                         entrada = q_add(entrada, aux_rational);
// 
//                         //entrada += matrices[leftSide_position].matrix[i][k] * matrices[rightSide_position].matrix[k][j];
//                     }
//                     entrada = q_simplify(entrada);
//                     produto.matrix[i][j]=entrada;
//                 }
//             }
// 
//             produto.rows = matrices[leftSide_position].rows;
//             produto.columns = matrices[rightSide_position].columns;
//             strcpy(produto.name, matrices[leftSide_position].name);
//             strcat(produto.name, matrices[rightSide_position].name);
//         
//             if(matrices_qt < MAX_MATRICES){
//                 // copia para 'matrices[]'
//                 matrices[matrices_qt].rows = produto.rows;
//                 matrices[matrices_qt].columns = produto.columns;
//                 strcpy(matrices[matrices_qt].name, produto.name);
//                 
//                 for(i=0; i<matrices[matrices_qt].rows; i++){
//                     for(j=0; j<matrices[matrices_qt].columns; j++){
//                         matrices[matrices_qt].matrix[i][j] = produto.matrix[i][j];
//                     }
//                 }
//                 matrices_qt++;
//             }
//     
//             // mostra o produto de matrices
//             puts("The product is: \n");
//             dump_mat(produto);
//         }
//     }
// 
//     return 0;
// }
// 
// 
// // funcao de front-end
// int matrix_sum(){
//     char leftSide_name[MAX_NAME], rightSide_name[MAX_NAME];
//     int i, j;
//     int leftSide_position, rightSide_position; // posicao das matrices esq e dir no array matrices[]
//     Q entrada; //entrada da matrix
//     struct MATRIX soma;
// 
//     printf("Name of left side matrix: ");
//     scanf(" %s", leftSide_name);
//     printf("Name of right side matrix: ");
//     scanf(" %s", rightSide_name);
//     
//     leftSide_position = find_matrix(leftSide_name);
//     rightSide_position = find_matrix(rightSide_name);
// 
//     if(rightSide_position == -1 || leftSide_position == -1)
//         printf("Some matrix name is wrong.\n");
//     else{
//         if( \
//                 matrices[leftSide_position].rows != matrices[rightSide_position].rows  \
//                 || \
//                 matrices[leftSide_position].columns != matrices[rightSide_position].columns)
//         {
//             printf("Impossible to calculate sum. Format should be: (mXn + mXn) \n\n");
//         }else
//         {
//             // calcula a soma usual de matrices e armazena em 'soma.matrix'
//             for(i=0; i < matrices[leftSide_position].rows; i++ ){
//                 for(j=0; j < matrices[leftSide_position].columns; j++){
//                     entrada = q_add(matrices[leftSide_position].matrix[i][j], matrices[rightSide_position].matrix[i][j]);
//                     soma.matrix[i][j] = q_simplify(entrada);
//                 }
//         }
// 
//         soma.rows = matrices[leftSide_position].rows;
//         soma.columns = matrices[leftSide_position].columns;
// 
//             printf("Letter to represent (name): ");
//             scanf(" %s", soma.name); 
//         
//             if(matrices_qt < MAX_MATRICES){
//                 // copia para 'matrices[]'
//                 matrices[matrices_qt].rows = soma.rows;
//                 matrices[matrices_qt].columns = soma.columns;
//                 strcpy(matrices[matrices_qt].name, soma.name);
//                 
//                 for(i=0; i<matrices[matrices_qt].rows; i++){
//                     for(j=0; j<matrices[matrices_qt].columns; j++){
//                         matrices[matrices_qt].matrix[i][j] = soma.matrix[i][j];
//                     }
//                 }
//                 matrices_qt++;
//             }
//     
//             // mostra a soma de matrices
//             puts("The sum is: \n");
//             dump_mat(soma);
//         }
//     }
// 
//     return 0;
// }
// 
// 
// // funcao de front-end
// int matrix_trans(){
//     int i, j;
//     int matrix_pos;
//     char name[MAX_NAME];
// 
//     printf("\n\n \t *** Transposing matrix *** \n");
//     printf("Nome da matrix referencia: ");
//     printf("Name of matrix of reference: ");
//     scanf(" %s", name); 
// 
//     matrix_pos = find_matrix(name);
// 
//     if(matrix_pos == -1){
//         printf("Wrong name!\n");
//     }else{
//         if(matrices_qt < MAX_MATRICES){
//             printf("Name of transposed: ");
//             scanf(" %s", matrices[matrices_qt].name);
// 
//             matrices[matrices_qt].rows = matrices[matrix_pos].columns;
//             matrices[matrices_qt].columns = matrices[matrix_pos].rows;
// 
//             for(i=0; i < matrices[matrices_qt].rows; i++ )
//                 for(j=0; j< matrices[matrices_qt].columns; j++)
//                     matrices[matrices_qt].matrix[i][j] = matrices[matrix_pos].matrix[j][i];
//             dump_mat(matrices[matrices_qt]); //nesse caso é a matrix recem inserida
//             matrices_qt++;
//         }
//     }
//     return matrix_pos;
// }
// 
// int add_line(const Q q, struct MATRIX *matrix, const int line_result, const int line_sum ){
//     int j;
//     for(j=0; j < matrix->columns; j++){
//         matrix->matrix[line_result][j] = \
//                                          q_simplify( \
//                                              q_add( \
//                                                  matrix->matrix[line_result][j], \
//                                                  q_mult(q, matrix->matrix[line_sum][j]) ) );
//     }
//     return 0;
// }
// 
// // funcao de back-end
// // escalona uma matrix
// struct MATRIX echelon_mat(struct MATRIX mat){
//     struct MATRIX echeloned;
//     Q q;
//     int i, j, x, y;
// 
//     // copia os dados para a echeloned
//     echeloned.rows = mat.rows;
//     echeloned.columns = mat.columns;
//     for(i=0; i < mat.rows; i++ )
//         for(j=0; j<mat.columns; j++)
//             echeloned.matrix[i][j] = mat.matrix[i][j];
// 
//     // Escalona a matrix 'echeloned'
//     for(i=0; i+1<echeloned.rows; i++){
//         for(x=1; x+i < echeloned.rows; x++){ 
//             if(echeloned.matrix[i+x][i].numerator == 0 ) continue; 
//             // achar o valor para multiplicar cada elemento da linha para subtrair
//             q = q_quoc(echeloned.matrix[i+x][i], echeloned.matrix[i][i]); 
//             q.numerator *= -1;
//             add_line(q, &echeloned, i+x, i);
//             /*
//             for(y=0; y<echeloned.columns; y++){ 
//                 echeloned.matrix[i+x][y] = q_simplify(\
//                     q_add(echeloned.matrix[i+x][y], \
//                     q_mult(q, echeloned.matrix[i][y]) ) );
// 
//             }*/
//         }
//     }
//     return echeloned;
// }
// 
// // Escalona e reduz uma matrix
// // o escalonamento é feito por outra funcao
// /*
// Seria melhor que a outra funcao tivesse uma opcao para reduzir, com argc argv
//    struct MATRIX escal_red_mat(struct MATRIX mat){
//     struct MATRIX row_echelon;
//     
//     row_echelon = echelon_mat(mat);
//     
// 
//     return escalonada_reduzida;
// }
// */
// 
// // funcao de front-end
// int matrix_echelon(){
//     int matrix_pos;
//     // int i, j, x, y;
//     char name[MAX_NAME];
//     // Q q, rational;
// 
//     printf("Name of matrix of reference: ");
//     scanf(" %s", name); 
// 
//     matrix_pos = find_matrix(name);
//     if(matrix_pos == -1){
//         printf("Wrong name!\n");
//     }else{
//         if(matrices_qt < MAX_MATRICES){
//             /*
//             matrices[matrices_qt].rows = matrices[matrix_pos].rows;
//             matrices[matrices_qt].columns = matrices[matrix_pos].columns;
// 
//             for(i=0; i < matrices[matrices_qt].rows; i++ )
//                 for(j=0; j<matrices[matrices_qt].columns; j++)
//                     matrices[matrices_qt].matrix[i][j] = matrices[matrix_pos].matrix[i][j];
// */
//             // Escalona a matrix
//             matrices[matrices_qt] = echelon_mat(matrices[matrix_pos]);
//             printf("Name of echelon: ");
//             scanf(" %s", matrices[matrices_qt].name);
//             /*
//             for(i=0; i+1<matrices[matrices_qt].rows; i++){
//                 //for(j=i; j<matrices[matrices_qt].columns; ){// SUSPEITAR DESTA PARTE RSRSRS, j serve para quẽ?
//                     for(x=1; x+i < matrices[matrices_qt].rows; x++){ 
//                         if(matrices[matrices_qt].matrix[i+x][i].numerator == 0 ) continue; // j --> i
//                         // achar o valor para multiplicar cada elemento da linha para subtrair
//                         q = q_quoc(matrices[matrices_qt].matrix[i+x][i], matrices[matrices_qt].matrix[i][i]); // j--> i
//                         q.numerator *= -1;
// 
//                         printf("\n\n\n q=%d/%d\n\n\n",q.numerator,q.denominator);
// 
//                         for(y=0; y<matrices[matrices_qt].columns; y++){ // j --> i
//                             matrices[matrices_qt].matrix[i+x][y] = q_simplify(\
//                                 q_add(matrices[matrices_qt].matrix[i+x][y], \
//                                        rational = q_mult(q, matrices[matrices_qt].matrix[i][y]) ) );
//                             //printf("RACIONAL %d/%d\n\n",rational.numerator, rational.denominator);
// 
//                         }
//                     }
//                 //}
//             }*/
// 
// 
//             dump_mat(matrices[matrices_qt]); //nesse caso é a matrix recem inserida
//             matrices_qt++;
//         }
//     }
// 
//     return 0;
// }
// 
