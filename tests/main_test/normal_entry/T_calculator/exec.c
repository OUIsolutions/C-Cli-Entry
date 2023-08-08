

#include "CliEntry/CliEntryMain.h"


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
    return 0;


}