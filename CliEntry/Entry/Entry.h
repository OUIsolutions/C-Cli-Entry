
#define CLI_CASE_SENSITIVE true
#define CLI_NOT_CASE_SENSITIVE false


typedef struct CliEntry{

    CTextArray * elements;
    int size;
    privateCliGarbage  * private_garbage;

    const char *flag_identifiers;



}CliEntry;

CliEntry * newCliEntry(int argc, char **argv);
int CliEntry_typeof_arg(CliEntry *self,int position);

bool CliEntry_is_numeric(CliEntry *self,int position);

const char *CliEntry_typeof_arg_in_str(CliEntry *self,int position);

CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive);
char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive);

long    CliEntry_get_long(CliEntry *self, int position);

double  CliEntry_get_double(CliEntry *self, int position);

bool  CliEntry_get_bool(CliEntry *self, int position);
void CliEntry_free(struct CliEntry *self);

void  CliEntry_represent(CliEntry *self);

