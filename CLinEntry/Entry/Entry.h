

typedef struct CliEntry{
    CliStringArray * elements;
    char *flag_identifiers;
    bool case_sensitive_for_flags;
    bool case_sensitive_for_args;


    CliStringArray * (*get_args)(CliStringArray *self, char *flags);
    char *  (*get_arg)(CliStringArray *self, char *flags);
    long  (*get_long)(CliStringArray *self, char *flags);
    double  (*get_double)(CliStringArray *self, char *flags);
    bool (*exist)(CliStringArray *self, char *flags);

}CliEntry;

CliEntry * newCliEntry(int argc, char **argv);


CliStringArray * CliStringArray_get_args(char *flags);

