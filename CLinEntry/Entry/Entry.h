
#define CLI_CASE_SENSITIVE true
#define CLI_NOT_CASE_SENSITIVE false


typedef struct CliEntry{

    CTextArray * elements;
    char *flag_identifiers;

    

    CliFlag *(*get_flag)(struct CliEntry *self,const char *flags,bool case_sensitive);
    char*   (*get_str)(struct CliEntry *self, int position, bool case_sensitive);

    long    (*get_long)(struct CliEntry *self, int position);
    double  (*get_double)(struct CliEntry *self, int position);
    double  (*get_bool)(struct CliEntry *self, int position);
    void (*free)(struct CliEntry *self);

}CliEntry;

CliEntry * newCliEntry(int argc, char **argv);

CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive);
char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive);

long    CliEntry_get_long(CliEntry *self, int position);
double  CliEntry_get_double(CliEntry *self, int position);
double  CliEntry_get_bool(CliEntry *self, int position);
void CliEntry_free(struct CliEntry *self);


