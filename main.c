

#include "CliEntry/CliEntryMain.h"


int main(int argc, char **argv){

    CliNamespace cli = newCliNamespace();

    CliEntry *entry = newCliEntry(argc,argv);

    CliFlag *numbers = cli.entry.get_flag(entry,"n | numbers | values",CLI_NOT_CASE_SENSITIVE);

    cli.flag.represent(numbers);

    if(!numbers->exist){
        printf("numbers not found\n");
        cli.entry.free(entry);
        return 0;
    }
    
    if(numbers->size != 2){
        printf("two numbers is required \n");
        cli.entry.free(entry);
        return 0; 
    }

    if(!cli.flag.is_numeric(numbers,0)){
        printf("the first number is not an num\n");
        cli.entry.free(entry);
        return 0; 
    }
    if(!cli.flag.is_numeric(numbers,1)){
        printf("the second number is not an num\n");
        cli.entry.free(entry);
        return 0; 
    }
    double n1 = cli.flag.get_double(numbers,0);
    double n2 = cli.flag.get_double(numbers,1);

    CliFlag *operation_flag  = cli.entry.get_flag(entry,"op | operation | calculation | calc",CLI_NOT_CASE_SENSITIVE);
    
    if(!operation_flag->exist){
        printf("operation not found\n");
        cli.entry.free(entry);
        return 0;
    }
    
    if(operation_flag->size == 0){
        printf("operation canot be empty");
        cli.entry.free(entry);
        return 0;  
    }
    char *operation = cli.flag.get_str(operation_flag,1,CLI_NOT_CASE_SENSITIVE);

    double  result;
    if(strcmp(operation,"add") == 0){
        result = n1+n2;
    }
    else if(strcmp(operation,"sub") == 0){
        result = n1-n2;
    }
    else if(strcmp(operation,"mul") == 0){
        result = n1*n2;
    }
    else if(strcmp(operation,"div") == 0){
        result = n1/n2;
    }
    else{
        printf("operation %s is invalid\n",operation);
        cli.entry.free(entry);
        return 0;
    }
    printf("result: %lf\n",result);
    cli.entry.free(entry);
    return 0;


}