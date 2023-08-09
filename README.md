# C-Cli-Entry
CCli-Entry Its an Single Header lib to deal with argv and argc
in C, its projected to be friendly user, and portable 


# Instalation
## Single File

As Others OUI Products, these lib is made to bee dumb as possible,so for instalation
you can just copy the **CliEntry.h** file  to your project and start using

if these runs, it means it working
~~~c
#include "CliEntry.h"

int main(){
    
}
~~~


## Full Folder
You also can run by full folder, just copy the entire folder i **CliEntry** in your project
than run with:
~~~c
#include "CliEntry/CliEntryMain.h"

int main(){

}
~~~

## Quick Usage

### An Simple Calculator
<!--codeof:exemples/calc.c-->
~~~c
#include "CliEntry.h"



int main(int argc, char **argv){

    CliNamespace cli = newCliNamespace();

    CliEntry *entry = newCliEntry(argc,argv);



    if(entry->size < 2){
        printf("number 1 not exist\n");
        cli.entry.free(entry);
        return 0;
    }

    if(!cli.entry.is_numeric(entry,2)){
        printf("number 1 is not an number\n");
        cli.entry.free(entry);
        return 0;
    }

    if(entry->size < 3){
        printf("number 2 not exist\n");
        cli.entry.free(entry);
        return 0;
    }

    if(!cli.entry.is_numeric(entry,3)){
        printf("number 2 is not an number\n");
        cli.entry.free(entry);
        return 0;
    }
    double n1 = cli.entry.get_double(entry,2);
    double n2 = cli.entry.get_double(entry,3);
    char *operation = cli.entry.get_str(entry,1,CLI_NOT_CASE_SENSITIVE);

    if(!operation){
        printf("operation not found\n");
        cli.entry.free(entry);
        return 0;
    }
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
~~~

### A Calculator With Flags
<!--codeof:exemples/calc_flags.c-->
~~~c

#include "CliEntry.h"


int main(int argc, char **argv){

    CliNamespace cli = newCliNamespace();


    CliEntry *entry = newCliEntry(argc,argv);

    CliFlag *help = cli.entry.get_flag(entry,"h | help",CLI_NOT_CASE_SENSITIVE);
    if(help->exist){
        printf("flags:\n");
        printf("\tn:(the 2 numbers for te operation)\n");
        printf("\top:(the operation (add,mull,div,sub))\n");
        printf("exemples:\n");
        printf("\t-op add -n 10 20\n");
        printf("\t-op sub -n 10 20\n");

        cli.entry.free(entry);
        return 0;
    }

    CliFlag *numbers = cli.entry.get_flag(entry,"n | numbers | values",CLI_NOT_CASE_SENSITIVE);


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
        printf("operation canot be empty\n");
        cli.entry.free(entry);
        return 0;  
    }
    char *operation = cli.flag.get_str(operation_flag,0,CLI_NOT_CASE_SENSITIVE);
    
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
        printf("operation %s is invalid valids:(add,mul,div,sub)\n",operation);
        cli.entry.free(entry);
        return 0;
    }

    printf("result: %lf\n",result);
    cli.entry.free(entry);
    return 0;


}
~~~