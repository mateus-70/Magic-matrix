/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
*/

#include "/home/mateus/ban/math/programs/utils/definitions.h"


// ************************ Functions definitions *************************
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
// 
// 
// 
// 
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
