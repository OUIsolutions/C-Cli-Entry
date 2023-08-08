

#include "CliEntry/CliEntryMain.h"
void execute_code(int argc,char **argv){
    CliNamespace cli = newCliNamespace();

    CliEntry *entry = newCliEntry(argc,argv);



    if(entry->size < 2){
        printf("number 1 not exist\n");
        cli.entry.free(entry);
        return;
    }

    if(!cli.entry.is_numeric(entry,2)){
        printf("number 1 is not an number\n");
        cli.entry.free(entry);
    }

    if(entry->size < 3){
        printf("number 2 not exist\n");
        cli.entry.free(entry);
        return;
    }

    if(!cli.entry.is_numeric(entry,3)){
        printf("number 2 is not an number\n");
        cli.entry.free(entry);
    }
    double n1 = cli.entry.get_double(entry,2);
    double n2 = cli.entry.get_double(entry,3);
    char *operation = cli.entry.get_str(entry,1,CLI_NOT_CASE_SENSITIVE);

    if(!operation){
        printf("operation not found\n");
        cli.entry.free(entry);
        return;
    }
    double  result;
    if(strcmp(operation,"add") == 0){
        result = n1+n2;
    }
    else if(strcmp(operation,"sub") == 0){
        result = n1-n2;
    }
    else if(strcmp(operation,"mull") == 0){
        result = n1*n2;
    }
    else if(strcmp(operation,"div") == 0){
        result = n1/n2;
    }
    else{
        printf("operation %s is invalid\n",operation);
        cli.entry.free(entry);
        return;
    }
    printf("result: %lf\n",result);

}

int main(int argc, char **argv){

    argv = (char*[]){"./a.out","add","20","30"};
    argc = sizeof(argv) / sizeof(char*);
    execute_code(argc,argv);
    return 0;






}