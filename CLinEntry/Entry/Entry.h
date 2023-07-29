

typedef struct CliEntry{
    CliStringArray * elements;
    char *flag_identifiers;
    bool case_sensitive;

    CliStringArray * (*get_args)(CliStringArray *self, char *flags);


}CliEntry;

CliEntry * newCliEntry(int argc, char **argv);


CliStringArray * CliStringArray_get_args(char *flags);

