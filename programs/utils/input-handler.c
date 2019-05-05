#include "/home/mateus/ban/math/programs/utils/definitions.h"
#include <regex.h>


var variables[MAX_VARIABLES] = {};
const var reset_var = { };

char input_handler(const char * command_){
    char state=0;
	const char commands_avaiable[][COMMAND_LENGTH] = {"insert", "edit", "delete", "list", "help", "quit"};
    const int commands_count = 6;
    Bool manual_command = FALSE;

    char command[COMMAND_LENGTH];
    strcpy(command, command_);
    if(wantto_edit(command_)){
        puts("Edit, Match.\n\n");
        state='E';
    }else if(wantto_delete(command_)){
        puts("Delete, Match.\n\n");
        state='D';
    }else if(wantto_setmode(command_)){
        puts("Set mode, Match.\n\n");
        state='S';
    }else if(wantto_list(command_)){
        puts("List, Match.\n\n");
        state='L';
        list_user_variables();
    }else if(wantto_help(command_)){
        puts("Help, Match.\n\n");
        state='H';
    }else if(wantto_insert(command_)){
        puts("Insert, Match.\n\n");
        state='I';
    }else if(wantto_quit(command_)){
        puts("Quit, Match.\n\n");
        state = 'Q';
    }
    else{
    puts("Didnt match any elementar action.\n\n");
    }

// --    // Check to see if the command is like some value of 'commands_avaiable'
// --    for(int i=0; i < commands_count; i++){
// --        if(!strcmp(commands_avaiable[i], argv[0])){
// --            manual_command = TRUE;
// --            break;
// --        }
// --    }

//    if(manual_command == TRUE){
//        manual_cmd_handler(){
//            
//        }
//    }

	return state;
}


// It will handle inputs like
// a=1
// b=5.4
// A=[3 2; 3 45]
// ofcourse functions
// var=exp or var1=var2=exp
//int equation_handler(const char *command_)
//{
//    char command[COMMAND_LENGTH];
//    
//    // Will hold the pointer to the command exploded in '=' symbol, 
//    // example: the entry: ABC = [3 2; 3 1]
//    // we will get &"ABC" and we will get &"[3 2; 3 1]
//    char* pt_part[MAX_ASSIGNMENTS] = { NULL }; 
//
//    strcpy(command, command_);
//
//    int i=0;
//    pt_part[i++]=strtok(command, "=");
//    for(; NULL != ( pt_part[i]=strtok(NULL, "=") ); i++)
//        ;
//
//    int j;
//    for(j=0; j<i; j++)
//        printf("String[%d]: %s\n",j ,pt_part[j]);
//
//    i--; // To positionate i on the last element
//    char type_exp;
//    Bool vars_name;
//    if( (type_exp = validate_expression(pt_part[i])) != INVALID )
//    {
//        for(j=0; j<i-1;j++)
//        {
//            if(INVALID == is_varname(pt_part[j]))
//                vars_name = INVALID;
//        }
//    }
//    else vars_name=INVALID;
//     
//    // If name is valid, store the data on the variables
//    if(INVALID != vars_name)
//    {
//        /// colocar dentro do for para outras variaveis
//        //
//
//        strcpy(variables[0].name, pt_part[0]); // store name
//
//        // Store accordling to its type
//        if(type_exp == 'R'){
//            strcpy(variables[0].data_type, "R"); //store type of the data
//            variables[0].value.r = strtold(pt_part[1]); //assign value pointed by pt of the right side exp
//        }else if(type_exp == 'M'){
//            strcpy(variables[0].data_type, "R"); //store type of the data
//            // todo: explode the string of matrix and store its data
//
//            variables[0].value.r = strtold(pt_part[1]); //assign value pointed by pt of the right side exp
//        }
//    }
//
//
//    // var = exp
//    // checkout to see if exp is valid
//    // checkout to see if var has valid name
//    //
//    // check if var is still undeclared, then declare
//    // assign value
//
//    return 0;
//}


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

int evaluate_expression(){
    return 0;
}

int wantto_edit(const char* str_){
    int reti, status; //return integer

    // --char str[STR_MAX_MATRIX];

    regex_t regex;
    char error_message[300];
    char str[COMMAND_LENGTH];
    strcpy(str, str_);
    char pattern[300]={0};
    strcat(pattern, "^edit [a-zA-Z][a-zA-Z0-9]{0,");
    char aux[300]={};
    sprintf(aux, "%d", VARIABLE_MAX_NAME);
    strcat(pattern, aux);
    strcat(pattern, "}$");
    reti = regcomp( &regex, pattern, REG_EXTENDED);
    if(reti)
    {
        // strcpy(error_message, "Failure (in " __FUNCTION__ "): Cannot compile regular expression!\n\n");

        printf(error_message);
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


int wantto_delete(const char* str_){
    int reti, status; //return integer

    // --char str[STR_MAX_MATRIX];

    regex_t regex;
    char error_message[300];
    char str[COMMAND_LENGTH];
    strcpy(str, str_);
    char pattern[300]={0};
    strcat(pattern, "^delete [a-zA-Z][a-zA-Z0-9]{0,");
    char aux[300]={};
    sprintf(aux, "%d", VARIABLE_MAX_NAME);
    strcat(pattern, aux);
    strcat(pattern, "}$");
    reti = regcomp( &regex, pattern, REG_EXTENDED);
    if(reti)
    {
        // strcpy(error_message, "Failure (in " __FUNCTION__ "): Cannot compile regular expression!\n\n");

        printf(error_message);
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



int wantto_setmode(const char* str_){
    int reti, status; //return integer

    // --char str[STR_MAX_MATRIX];

    regex_t regex;
    char error_message[300];
    char str[COMMAND_LENGTH];
    strcpy(str, str_);
    char pattern[300]= "^set-mode (-INT|-NNT|-NT|-NC|-A)";
    reti = regcomp( &regex, pattern, REG_EXTENDED);
    if(reti)
    {
        // strcpy(error_message, "Failure (in " __FUNCTION__ "): Cannot compile regular expression!\n\n");
        printf(error_message);
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


int wantto_list(const char* str_){
    int reti, status; //return integer

    // --char str[STR_MAX_MATRIX];

    regex_t regex;
    char error_message[ERROR_MESSAGE_LENGTH];
    char str[COMMAND_LENGTH];
    strcpy(str, str_);
    char pattern[300]= "^[[:blank:]]*list([[:blank:]]+(--naturals?|-N|--integers?|-Z|--rationals?|-Q|--reals?|-R|--number|--num|--variables?|--var|--all|--any|-a)?)*$";
    reti = regcomp( &regex, pattern, REG_EXTENDED);
    if(reti)
    {
        snprintf(error_message, ERROR_MESSAGE_LENGTH, "%s%s%s", "Failure (in ", __FUNCTION__, "): Cannot compile regular expression!\n\n");
        printf(error_message);
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

int wantto_help(const char* str_){

    int reti, status; //return integer
    regex_t regex;
    char error_message[300];
    char str[COMMAND_LENGTH];
    strcpy(str, str_);
    for(int i=0; i< strlen(str); i++ )
        str[i]=toupper(str[i]);
    char pattern[300]= "^help (MODES|VARIABLES|INTERNAL-COMMANDS|DATA-TYPES|VERSION)[:blank:]$";
    reti = regcomp( &regex, pattern, REG_EXTENDED);
    if(reti)
    {
        //strcpy(error_message, "Failure (in " __FUNCTION__ "): Cannot compile regular expression!\n\n");
        printf(error_message);
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
//     if(argc == 0){
//         // usage, internal commands
//         printf(PROGRAM_NAME" \n");
//         printf("For specific help:\n");
//         printf("help --about \n");
//         printf("\t general info about this program. \n");
//         printf("help --internal-commands \n");
//         printf("\tList internal commands avaiable.\n");
//         printf("help --variable \n");
//         printf("\tShow info about variables.\n");
//         printf("help --modes \n");
//         printf("Show info about operational modes.\n");
//     }else{
//         printf("Show specific help.\n");
//     }
//     return 0;
// }

int wantto_insert(){
   return 0; 
}


int wantto_quit(const char* str_){
    int reti, status; //return integer

    // --char str[STR_MAX_MATRIX];

    regex_t regex;
    char error_message[ERROR_MESSAGE_LENGTH];
    char str[COMMAND_LENGTH];
    strcpy(str, str_);
    char pattern[300]= "^[:blank:]*quit[:blank:]*$";
    reti = regcomp( &regex, pattern, REG_EXTENDED);
    if(reti)
    {
        snprintf(error_message, ERROR_MESSAGE_LENGTH, "%s%s%s", "Failure (in ", __FUNCTION__, "): Cannot compile regular expression!\n\n");
        printf(error_message);
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

int list_user_variables(){
    printf(__FUNCTION__);
    return 0;
}
