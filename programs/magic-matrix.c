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

int var_qt=0;

void clear_screen(void){
    int i=0;
    while(i++ < 100)
        putchar('\n');
}

int main(){
    char command[COMMAND_LENGTH]; 
    int quit, valid_command;
    clear_screen();
    puts("Magic Matrix\n\n");
    //if(is_rational("-2"))puts("it works");else puts("TOO BAD");
    do{
        printf("\nCommand: ");
        fgets(command, COMMAND_LENGTH-1, stdin);
        if(command[0] == '\n')
            continue;
        command[strcspn(command, "\n")] = '\0';
        quit = input_handler(command);
    }while(quit != 'Q');

    return 0;
}
