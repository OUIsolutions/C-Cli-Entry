

#include "CLinEntry/CliEntryMain.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(argc,argv);
 
    char *r2 = CliEntry_get_str(e,1,CLI_NOT_CASE_SENSITIVE);
    printf("%s",r2);

    CliEntry_free(e);
    
}
