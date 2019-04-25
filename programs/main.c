// O objetivo desse programa é receber duas matrizes e fazer sua multiplicação: o produto usual de matrizes.
//
// Falta nao deixar inserir nome nao unico para matriz.
// 
// O produto e a soma em Q já estão funcionando corretamente.
// Deve-se então adequar as operacoes nas matrizes para suportar isso também.
// A funcao de inserir está com algum defeito na hora de chamar 'edit_matrix()'


#include "/home/mateus/ban/math/programs/utils/definitions.h"
//#include "/home/mateus/ban/math/programs/matrices/matrices.h"
#include "/home/mateus/ban/math/programs/utils/rationals.h"
//#include "/home/mateus/ban/math/programs/utils/polynomials.h"


// struct func functions[10] ;


int main(){
    char command[COMMAND_LENGTH]; 
    int quit, valid_command;

    system("clear");
    //if(is_rational("-2"))puts("it works");else puts("TOO BAD");
    do{
        printf("\nCommand: ");
        fgets(command, COMMAND_LENGTH-1, stdin);
        command[strcspn(command, "\n")] = '\0';
        quit=FALSE;
        valid_command=TRUE;
        if(!strcmp(command, "insert") ){
            printf("Inserting...\n");
        }else if(!strcmp(command, "list")){
                printf("Listing...\n");
            }else if(!strcmp(command, "show")){
                    printf("Showing...\n");
                }else if(!strcmp(command, "edit")){
                        printf("Editing...\n");
                    }else if(!strcmp(command, "delete")){
                            printf("Deleting...\n");
                        }else if(!strcmp(command, "insert-polynomial")){
                                printf("Still not implemented. Polynomial...\n");
                                // insert_polynomial(functions[0]);
                                }else if(!strcmp(command, "matrix-product")){
                                        printf("Matrix product...\n");
                                    }else if(!strcmp(command, "matrix-transpose")){
                                            printf("Transposing...\n");
                                        }else if(strchr(command, '=') != NULL ){
                                                printf("Handling assignment...\n");
                                                equation_handler(command);

                                            }else if(!strcmp(command, "help") || !strcmp(command, "?")){
                                                    printf("Avaiable commands are:\n\
                                                            \rinsert\n\
                                                            \rinsert-polynomial\n\
                                                            \rlist\n\
                                                            \rshow\n\
                                                            \redit\n\
                                                            \rdelete\n\
                                                            \rmatrix-product\n\
                                                            \rmatrix-transpose\n\
                                                            \rvar=exp\n\
                                                            \rhelp\n\
                                                            \rquit\n");
                                                }else if(!strcmp(command, "quit") || !strcmp(command, "exit") ){
                                                        printf("Quiting...\n"); 
                                                        quit=TRUE;
                                                    }else{
                                                        printf("Command not found.\n");
                                                        valid_command=FALSE;
                                                    }
    }while(valid_command==FALSE || quit==FALSE);

    return 0;
}
