

typedef struct CliFlagModule{

    int      (*typeof_arg)(struct CliFlag *self, int position);
    const char *(*type_of_arg_in_str)(struct CliFlag *self, int position);
    char*   (*get_str)(struct CliFlag *self, int position, bool case_sensitive);
    long    (*get_long)(struct CliFlag *self, int position);
    double  (*get_double)(struct CliFlag *self, int position);
    bool  (*get_bool)(struct CliFlag *self, int position);


}CliFlagModule;

CliFlagModule newCliFlagModule();