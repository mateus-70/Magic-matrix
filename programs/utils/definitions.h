#ifndef DEFINITIONS_HEADER__
    #define DEFINITIONS_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <gmp.h>
#include <locale.h>
#include <limits.h>

#define COMMAND_LENGTH 1000
#define FALSE 0
#define TRUE 1
#define INVALID 0

#define MAX_MATRICES 10
#define MAX_NAME 10
#define STR_MAX_NUMBER 20
#define STR_MAX_MATRIX 20
#define MAX_MATRIX_ROWS 10
#define MAX_MATRIX_COWS 10
#define PATTERN_MAX_LENGTH 1000

#define VARIABLE_MAX_NAME 30
#define MAX_DATA_TYPE 30
#define MAX_VARIABLES 100
#define MAX_ASSIGNMENTS 5

#define MATRIX_TYPE "M"
#define NATURAL_TYPE "N"
#define INTEGER_TYPE "Z"
#define RATIONAL_TYPE "Q"
#define REAL_TYPE "R"

#define ERROR_MESSAGE_LENGTH 300

#define PROGRAM_NAME "Magic Matrix"

// Regex patters 
#define RGX_TYPE "(naturals?|N|integers?|Z|rationals?|Q|reals?|R|matri(x|ces))"
#define RGX_VARNAME "([a-zA-Z_][a-zA-Z0-9_]*)"
#define RGX_NATURAL "([0-9]+)"
#define RGX_INTEGER "([+-]?[0-9]+)"
#define RGX_RATIONAL "([-+]?[0-9]+(/[0-9]*[1-9][0-9]*)?)"
#define RGX_REAL "([-+]?[0-9]+(\\.[0-9]*)?)"

#define ABS(my_val) ((my_val) < 0) ? -(my_val) : (my_val)

typedef int Bool;
typedef unsigned long long int Natural;
typedef long double Real;

// Structs declaration - Start
typedef struct {
    int numerator, denominator;
} Q;

//struct MATRIX {
//    // char name[MAX_NAME];
//    int rows;
//    int columns;
//    Q matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];
//};


typedef struct 
{
    char name[VARIABLE_MAX_NAME];
    char data_type[MAX_DATA_TYPE]; //RMnxn ou RMnnxn RMnnnxnnnn
    char status; 
    // 'a' for avaiable
    // 'n' for non-initialized
    // 'd' for deleted
    // 'b' for blocked
    union 
    {
        Natural n;
        int z;
        Q q;
        Real r;
        Q Q_m[MAX_MATRIX_ROWS][MAX_MATRIX_COWS];
        Real R_m[MAX_MATRIX_ROWS][MAX_MATRIX_COWS];
    } value;
} var;
// Structs declaration - End

// Global vars declaration - Start
extern var variables[MAX_VARIABLES];
// --extern int matrices_qt; // quantity
// --struct MATRIX matrices[MAX_MATRICES];
// Global vars declaration - End

// Functions declaration - Start
Q q_mult(Q, Q);
Q q_quoc(Q, Q);
Q q_add( Q, Q);
Q q_simplify(Q);
// struct MATRIX escal_mat(); what the heck is this?
// Functions declaration - End


// Back-end functions declarations - Start
int find_matrix(); // search for a matrix by name
int edit_matrix(); // edit the entrances of a matrix
int dump_mat(); // dumb matrix info at exit // what does this really mean?
int add_line(); 
int is_natural();
int is_integer();
int is_rational();
int is_real();
int is_matrix();
char validate_expression();
int is_varname();
int equation_handler();
char input_handler();
int list_user_variables();
// Back-end functions declarations - End

// Front-end functions declaratins - Start
int matrices_list();
int show_matrix();
int matrix_insert();
int edit_matrix();
int delete_matrix();
int transpose_matrix();
int matrix_product();
var pivotation();
int wantto_help();
int wantto_insert();
int wantto_list();
int wantto_edit();
int wantto_delete();
int wantto_setmode();
int wantto_quit();
// Front-end functions declaratins - End

int str_to_q(const char *, Q *);

int var_qt;

int generate_fibonacci();
Natural gen_primes_qtty();
Natural gen_primes_max_value();
Natural lowest_common_multiple();
#endif
