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

### Retriving Args
<!--codeof:exemples/retriving_args.c-->
~~~c

#include "CliEntry.h"


int main(int argc, char **argv){

    CliNamespace cli = newCliNamespace();


    CliEntry *entry = newCliEntry(argc,argv);
    //get the flag
    int position = 1;
    int element1_type = cli.entry.typeof_arg(entry,position);
    
    if(element1_type == CLI_DOUBLE){
        double element1_value = cli.entry.get_double(entry,position);
        printf("element 1 its a double: %lf\n",element1_value);    
    }
    if(element1_type == CLI_LONG){
        long  element1_value = cli.entry.get_long(entry,position);
        printf("element 1 its a long: %ld\n",element1_value);     
    }
    if(element1_type == CLI_STRING){
        char *  element1_value = cli.entry.get_str(entry,position,CLI_NOT_CASE_SENSITIVE);
        printf("element 1 its a string: %s\n",element1_value);     
    }
    if(element1_type == CLI_NOT_EXIST){
        printf("element 1 not exist\n");     
    }

    cli.entry.free(entry);
    return 0;
}

~~~
### Retriving flags 
<!--codeof:exemples/output_flag.c-->
~~~c
#include "CliEntry.h"


int main(int argc, char **argv){

    CliNamespace cli = newCliNamespace();


    CliEntry *entry = newCliEntry(argc,argv);
    //get the flag
    CliFlag *output_flag = cli.entry.get_flag(entry,"o | out | output",CLI_NOT_CASE_SENSITIVE);
   
    //verify if exist
    if(output_flag->exist == false){
        printf("you didint passed the output\n");
        cli.entry.free(entry);
        return 1;
    }
    //verifying the size
    if(output_flag->size == 0){
        printf("the output flag its empty\n");
        cli.entry.free(entry);
        return 1;
    }
    int position = 0;
    char *output_content = cli.flag.get_str(output_flag,position,CLI_CASE_SENSITIVE);
    printf("content of output:%s\n",output_content);

    //do stuff here 

    cli.entry.free(entry);
    return 0;
}
~~~



### An Basic Calculator
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

## Dependencies

### CTextEngine 

https://github.com/OUIsolutions/CTextEngine


MIT License

Copyright (c) 2023 OUI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.