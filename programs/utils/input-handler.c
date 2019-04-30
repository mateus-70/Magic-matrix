#include "/home/mateus/ban/math/programs/utils/definitions.h"
#include <regex.h>


var variables[MAX_VARIABLES] = {};
const var reset_var = {};

// It will handle inputs like
// a=1
// b=5.4
// A=[3 2; 3 45]
// ofcourse functions
// var=exp or var1=var2=exp
int equation_handler(const char *command_)
{
    char command[COMMAND_LENGTH];
    
    // Will hold the pointer to the command exploded in '=' symbol, 
    // example: the entry: ABC = [3 2; 3 1]
    // we will get &"ABC" and we will get &"[3 2; 3 1]
    char* pt_part[MAX_ASSIGNMENTS] = { NULL }; 

    strcpy(command, command_);

    int i=0;
    pt_part[i++]=strtok(command, "=");
    for(; NULL != ( pt_part[i]=strtok(NULL, "=") ); i++)
        ;

    int j;
    for(j=0; j<i; j++)
        printf("String[%d]: %s\n",j ,pt_part[j]);

    i--; // To positionate i on the last element
    char type_exp;
    Bool vars_name=VALID;
    if( (type_exp = validate_expression(pt_part[i])) != INVALID )
    {
        for(j=0; j<i-1;j++)
        {
            if(INVALID == is_varname(pt_part[j]))
                vars_name = INVALID;
        }
    }
    else vars_name=INVALID;
     
    // If name is valid, store the data on the variables
    if(INVALID != vars_name)
    {
        /// colocar dentro do for para outras variaveis
        //

        strcpy(variables[0].name, pt_part[0]); // store name

        // Store accordling to its type
        if(type_exp == 'R'){
            strcpy(variables[0].data_type, "R"); //store type of the data
            variables[0].value.r = strtold(pt_part[1]); //assign value pointed by pt of the right side exp
        }else if(type_exp == 'M'){
            strcpy(variables[0].data_type, "R"); //store type of the data
            // todo: explode the string of matrix and store its data

            variables[0].value.r = strtold(pt_part[1]); //assign value pointed by pt of the right side exp
        }
    }


    // var = exp
    // checkout to see if exp is valid
    // checkout to see if var has valid name
    //
    // check if var is still undeclared, then declare
    // assign value

    return 0;
}


int is_real(const char *number_)
{
    int reti, status; //return integer

    char number[STR_MAX_NUMBER];

    regex_t regex;
    
    strcpy(number, number_);
    reti = regcomp( &regex, "^[-+]?[0-9]+(.[0-9]*)?$", REG_EXTENDED);
    if(reti)
    {
        printf("Failure (in is_rational): Cannot compile regular expression!\n\n");
        exit(1);
    }

    reti = regexec(&regex, number, 0, NULL, 0);
    if(!reti)
    {
        status = 1;
    }else
        if(reti == REG_NOMATCH)
            status = 0;
        else
        {
            regerror(reti, &regex, number, sizeof(number));
            fprintf(stderr, "Regex match failed: %s\n", number);
            status = 0;
            exit(1);
        }

	regfree(&regex);
    return status;
}


int is_rational(const char *number_)
{
    int reti, status; //return integer

    char number[STR_MAX_NUMBER];

    regex_t regex;
    
    strcpy(number, number_);
    reti = regcomp( &regex, "^[-+]?[0-9]+(/[0-9]*[1-9][0-9]*)?$", REG_EXTENDED);
    if(reti)
    {
        printf("Failure (in is_rational): Cannot compile regular expression!\n\n");
        exit(1);
    }

    reti = regexec(&regex, number, 0, NULL, 0);
    if(!reti)
    {
        status = 1;
    }else
        if(reti == REG_NOMATCH)
            status = 0;
        else
        {
            regerror(reti, &regex, number, sizeof(number));
            fprintf(stderr, "Regex match failed: %s\n", number);
            status = 0;
            exit(1);
        }

	regfree(&regex);
    return status;
}

int is_integer(const char *number_)
{
    int reti, status; //return integer

    char number[STR_MAX_NUMBER];

    regex_t regex;
    
    strcpy(number, number_);
    reti = regcomp( &regex, "^[0-9]+$", REG_EXTENDED);
    if(reti)
    {
        printf("Failure (in is_integer): Cannot compile regular expression!\n\n");
        exit(1);
    }

    reti = regexec(&regex, number, 0, NULL, 0);
    if(!reti)
    {
        status = 1;
    }else
        if(reti == REG_NOMATCH)
            status = 0;
        else
        {
            regerror(reti, &regex, number, sizeof(number));
            fprintf(stderr, "Regex match failed: %s\n", number);
            status = 0;
            exit(1);
        }

	regfree(&regex);
    return status;
}

int is_natural(const char *number_)
{
    int reti, status; //return integer

    char number[STR_MAX_NUMBER];

    regex_t regex;
    
    strcpy(number, number_);
    reti = regcomp( &regex, "^[0-9]+$", REG_EXTENDED);
    if(reti)
    {
        printf("Failure (in is_natural): Cannot compile regular expression!\n\n");
        exit(1);
    }

    reti = regexec(&regex, number, 0, NULL, 0);
    if(!reti)
    {
        status = 1;
    }else
        if(reti == REG_NOMATCH)
            status = 0;
        else
        {
            regerror(reti, &regex, number, sizeof(number));
            fprintf(stderr, "Regex match failed: %s\n", number);
            status = 0;
            exit(1);
        }

	regfree(&regex);
    return status;
}

int is_matrix(const char *str_)
{
    int reti, status; //return integer

    char str[STR_MAX_MATRIX];

    regex_t regex;
    
    strcpy(str, str_);
    reti = regcomp( &regex, "^\[.*]$", REG_EXTENDED);
    if(reti)
    {
        printf("Failure (in is_matrix): Cannot compile regular expression!\n\n");
        exit(1);
    }

    reti = regexec(&regex, str, 0, NULL, 0);
    if(!reti)
        status = 1;
    else
        if(reti == REG_NOMATCH)
            status = 0;
        else
        {
            regerror(reti, &regex, str, sizeof(str));
            fprintf(stderr, "Regex match failed: %s\n", str);
            status = 0;
            exit(1);
        }

	regfree(&regex);
    return status;
}

int is_varname(const char *str_)
{
    int reti, status; //return integer

    char str[STR_MAX_MATRIX];

    regex_t regex;
    
    strcpy(str, str_);
    reti = regcomp( &regex, "^[a-zA-Z_][a-zA-Z0-9_]*$", REG_EXTENDED);
    if(reti)
    {
        printf("Failure (in is_varname): Cannot compile regular expression!\n\n");
        exit(1);
    }

    reti = regexec(&regex, str, 0, NULL, 0);
    if(!reti)
        status = 1;
    else
        if(reti == REG_NOMATCH)
            status = 0;
        else
        {
            regerror(reti, &regex, str, sizeof(str));
            fprintf(stderr, "Regex match failed: %s\n", str);
            status = 0;
            exit(1);
        }

	regfree(&regex);
    return status;
}

char validate_expression(const char *str)
{
    char status;
    if(is_natural(str))
        status='N';
    else if( is_integer(str))
            status='Z';
    else if( is_rational(str))
            status='Q';
    else if(is_real(str))
            status='R';
    else if(is_matrix(str))
            status='M';
    else if(is_varname(str))
            status='V';
    else
        status=0;
    return status;
}


