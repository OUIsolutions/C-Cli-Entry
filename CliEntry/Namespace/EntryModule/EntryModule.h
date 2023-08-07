
typedef struct CliEntryModule{

    CliFlag *(*get_flag)(struct CliEntry *self,const char *flags,bool case_sensitive);
    char*   (*get_str)(struct CliEntry *self, int position, bool case_sensitive);

    long    (*get_long)(struct CliEntry *self, int position);
    double  (*get_double)(struct CliEntry *self, int position);
    double  (*get_bool)(struct CliEntry *self, int position);
    void (*free)(struct CliEntry *self);

}CliEntryModule;

CliEntryModule newCliEntryModule();
