
typedef struct CliFlag{

    CTextArray  *elements;
    bool exist;
    privateCliGarbage *private_garbage;
    int size;



}CliFlag;

CliFlag *private_cli_newCliFlag();
void private_cli_CliFlag_free(CliFlag *self);

int CliFlag_typeof_arg(CliFlag *self, int position);
const char *CliFlag_type_of_arg_in_str(CliFlag *self, int position);
char* CliFlag_get_string(CliFlag *self, int position,bool case_sensitive);
long  CliFlag_get_long(CliFlag *self, int position);
double CliFlag_get_double(CliFlag *self, int position);
double CliFlag_get_bool(CliFlag *self, int position);

