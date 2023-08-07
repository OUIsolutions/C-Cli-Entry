

#include "CLinEntry/CliEntryMain.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(argc,argv);

    CliFlag *f = CliEntry_get_flag(e,"help | h ",CLI_NOT_CASE_SENSITIVE);
    if(f){
        CTextArray_represent(f->elements);

    }
    CliEntry_free(e);

    
}
