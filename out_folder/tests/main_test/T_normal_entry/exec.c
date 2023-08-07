

#include "../../CliEntryTest.h"

int main(int argc, char **argv){
    char *entry[]= {"aaa","bbbb"};
    CliEntry *e = newCliEntry(sizeof(entry) / sizeof(char*),entry);
    
    CliEntry_represent(e);
    CliEntry_free(e);

    
}