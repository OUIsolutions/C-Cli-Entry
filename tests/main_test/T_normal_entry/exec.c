

#include "../../CliEntryTest.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(1,&(char**){"aaaaaa"});
    
    printf("type:%s\n", CliEntry_typeof_arg_in_str(e,1));
    CliEntry_free(e);

    
}