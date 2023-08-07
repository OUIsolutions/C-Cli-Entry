

#include "CLinEntry/CliEntryMain.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(argc,argv);
    
    printf("%s", CliEntry_typeof_arg_in_str(e,1));
    CliEntry_free(e);

    
}
