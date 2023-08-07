

#include "CLinEntry/CliEntryMain.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(argc,argv);

    CliEntry_get_flag(e,"help | h ",CLI_NOT_CASE_SENSITIVE);
    CliEntry_free(e);
    
}
