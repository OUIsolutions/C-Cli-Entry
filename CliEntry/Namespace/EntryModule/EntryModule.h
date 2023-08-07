
typedef struct CliEntryModule{

    CliEntry *(*newEntry)(int argc, char **argv);
    int (*typeof_arg)(CliEntry *self, int position);
    const char *(*typeof_arg_in_str)(CliEntry *self, int position);
    CliFlag *(*get_flag)(CliEntry *self,const char *flags,bool case_sensitive);
    char*   (*get_str)(CliEntry *self, int position, bool case_sensitive);

    long    (*get_long)(CliEntry *self, int position);
    double  (*get_double)(CliEntry *self, int position);
    bool  (*get_bool)(CliEntry *self, int position);
    void (*free)(CliEntry *self);

}CliEntryModule;

CliEntryModule newCliEntryModule();
