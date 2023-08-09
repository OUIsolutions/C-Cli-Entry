

typedef struct CliFlagModule{

    int      (*typeof_arg)(CliFlag *self, int position);
    bool (*is_numeric)(CliFlag *self,int position);

    const char *(*type_of_arg_in_str)(CliFlag *self, int position);
    char*   (*get_str)(CliFlag *self, int position, bool case_sensitive);
    long    (*get_long)(CliFlag *self, int position);
    double  (*get_double)(CliFlag *self, int position);
    bool  (*get_bool)(CliFlag *self, int position);
    void  (*represent)(CliFlag *self);


}CliFlagModule;

CliFlagModule newCliFlagModule();