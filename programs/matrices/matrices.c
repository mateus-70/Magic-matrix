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

 // funcao de back-end
 // escalona uma matrix
var pivotation(var variable){
    strcpy( variable.data_type, "QM3x4");
    variable.value.Q_m[0][0].numerator = 3;
    variable.value.Q_m[0][0].denominator= 1;

    variable.value.Q_m[1][0].numerator = 1;
    variable.value.Q_m[1][0].denominator= 1;

    variable.value.Q_m[2][0].numerator = 4;
    variable.value.Q_m[2][0].denominator = 1;

    variable.value.Q_m[0][1].numerator = -4;
    variable.value.Q_m[0][1].denominator = 1;

    variable.value.Q_m[1][1].numerator = 2;
    variable.value.Q_m[1][1].denominator = 1;

    variable.value.Q_m[2][1].numerator = 0;
    variable.value.Q_m[2][1].denominator = 1;

    variable.value.Q_m[0][2].numerator = 1;
    variable.value.Q_m[0][2].denominator = 1;

    variable.value.Q_m[1][2].numerator = 2;
    variable.value.Q_m[1][2].denominator = 1;

    variable.value.Q_m[2][2].numerator = -3;
    variable.value.Q_m[2][2].denominator = 1;

    variable.value.Q_m[0][3].numerator = 9;
    variable.value.Q_m[0][3].denominator = 1;

    variable.value.Q_m[1][3].numerator = 3;
    variable.value.Q_m[1][3].denominator = 1;

    variable.value.Q_m[2][3].numerator = -2;
    variable.value.Q_m[2][3].denominator = 1;
    //--------------------------------------------------
    Q q;
    int i, j, x, y;
    char number_type, special_type;
    int dim1, dim2;
    //printf("variable.data_type = %s \n\n\n", variable.data_type);
    sscanf(variable.data_type, "%c%c%dx%d", &number_type, &special_type, &dim1, &dim2);
    printf("The data are: number_type=%c, special=%c, dim1=%d, dim2=%d\n\n", number_type, special_type, dim1, dim2);
    if(number_type == 'Q'){
        printf("Inside level 1\n\n");

        if(special_type == 'M'){
            if(dim1 > 0 && dim2 > 0){
                // Echelon the matrix inside variable'
                for(i=0; i+1<dim1; i++){
                    for(x=1; x+i < dim1; x++){ 
                        // print 'variable'
                        for(int l=0; l<dim1; l++){
                            for(int o=0; o< dim2; o++)
                                printf("%d/%d\t", variable.value.Q_m[l][o].numerator, variable.value.Q_m[l][o].denominator);
                            putchar('\n');
                        }
                        printf("\n\n");
                        if(variable.value.Q_m[i+x][i].numerator == 0 ) continue; 
                        // achar o valor para multiplicar cada elemento da linha para subtrair
                        q = q_quoc(variable.value.Q_m[i+x][i], variable.value.Q_m[i][i]); 
                        q.numerator *= -1;

                        for(y=0; y<dim2; y++){ 
                            variable.value.Q_m[i+x][y] = 
                                q_simplify(\
                                    q_add(variable.value.Q_m[i+x][y], \
                                        q_mult(q, variable.value.Q_m[i][y]) ) );
            
                        }
                    }
                }
            }else {printf("Error dim invalid"); exit(1);}
        }else{printf("Error, that isnot matrix\n\n");exit(1);}
    }else{printf("Error, that isnot Q\n\n");exit(1);}
    
    // print 'variable' in row echelon format
    for(int l=0; l<dim1; l++){
        for(int o=0; o< dim2; o++){
            printf("%d/%d\t", variable.value.Q_m[l][o].numerator, variable.value.Q_m[l][o].denominator);
        }
        putchar('\n');
    }

    Q x[3];
    for(int i=dim1-1; i >= 0; i--)
        for(int j=dim2-2; j >= 0; j--)

    return variable;
}
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
