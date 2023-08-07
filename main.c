

#include "CLinEntry/CliEntryMain.h"

int main(int argc, char **argv){
    CliEntry *e = newCliEntry(argc,argv);
    double r = CliEntry_get_double(e,1);
    long r1 =  CliEntry_get_long(e,1);

    printf("%lf",r);
    
}
