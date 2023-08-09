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