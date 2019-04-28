#include "/home/mateus/ban/math/programs/utils/definitions.h"
#include <regex.h>


var variables[MAX_VARIABLES] = 
{
    "", NULL, ""
};


const var reset_var = 
{
    "", NULL, ""
};

// It will handle inputs like
// a=1
// b=5.4
// A=[3 2; 3 45]
// ofcourse functions
// var=exp or var1=var2=exp
int equation_handler(const char *command_)
{
    char command[COMMAND_LENGTH];
    int command_length, i,j;

    // c_e[0] == *"VAR1_NAME", c_e[...] == *"VAR..._NAME", c_e[n] == *Expression
    char* pt_tok[MAX_ASSIGNMENTS] = { NULL }; // exploded in '='

    strcpy(command, command_);

    i=0;
    pt_tok[i++]=strtok(command, "=");
    for(; NULL != ( pt_tok[i]=strtok(NULL, "=") ); i++)
        ;

    for(j=0; j<i; j++)
        printf("String[%d]: %s\n",j ,pt_tok[j]);

    char type_exp;
    int valid_vars_name=1;
    if(type_exp = is_validexp(pt_tok[i]))
    {
        for(j=0; j<i-1;j++)
        {
            if(!is_varname(pt_tok[j]))
                valid_vars_name=0;
        }
    }
    else valid_vars_name=0;
        
    if(valid_vars_name)
    {
        // Store accordling to its type
        if(type_exp == 'N')
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

int is_validexp(const char *str)
{
    type_exp;

    if(is_natural(str))
        status='N';
    else if( is_integer(str))
            status='Z';
    else if( is_rational(str))
            status='Q';
    else if(is_real(str))
            status='Q';
    else if(is_matrix(str))
            status='M';
    else
        status=0;
    return status;
}


