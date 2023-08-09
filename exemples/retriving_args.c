
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
