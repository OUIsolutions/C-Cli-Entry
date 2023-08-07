

#include "CliEntry/CliEntryMain.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(1,entry_argv);
    

    CliEntry_free(e);

    
}