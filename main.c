

#include "CLinEntry/CliEntryMain.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(argc,argv);
    
    CliFlag *f = CliEntry_get_flag(e,"help | h ",CLI_NOT_CASE_SENSITIVE);
    
    char *p2 = CliEntry_get_str(e,2,CLI_NOT_CASE_SENSITIVE);
    if(p2){
        printf("posicao 2: %s\n",p2);
    }
    if(f->exist){
        printf("flag exist\n");
    }
    CliEntry_free(e);

    
}
