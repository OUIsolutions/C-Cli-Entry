

#include "CliEntry/CliEntryMain.h"
void execute_code(int argc,char **argv){
    CliNamespace cli = newCliNamespace();

    CliEntry *entry = newCliEntry(argc,argv);

    char *operation = cli.entry.get_str(entry,1,CLI_NOT_CASE_SENSITIVE);

    if(!operation){
        printf("operation not found\n");
        cli.entry.free(entry);
        return;
    }
    int n1_type = cli.entry.typeof_arg(entry,2);
    if(n1_type == CLI_NOT_EXIST){
        printf("number 1 not exist\n");
        cli.entry.free(entry);
        return;
    }

}

int main(int argc, char **argv){

    argv = (char*[]){"add","20","30"};
    argc = sizeof(argv) / sizeof(char*);
    execute_code(argc,argv);
    return 0;






}