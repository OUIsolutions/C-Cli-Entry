

CliEntry * newCliEntry(int argc, char **argv){
    CliEntry *self = (CliEntry*) malloc(sizeof (CliEntry));
    self->elements = newCTextArray();
    self->flag_identifiers = "-,--,---";
    self->get_flag = CliEntry_get_flag;
    self->get_str = CliEntry_get_str;
    self->get_long = CliEntry_get_long;
    self->get_double = CliEntry_get_double;
    self->get_bool = CliEntry_get_bool;

    for(int i = 0; i < argc; i++){
        CTextArray_append_string(self->elements,argv[i]);
    }

}

CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive){
    CTextArray *identifiers = CTextArray_split(self->flag_identifiers,",");
    CTextArray_foreach(identifiers,CTextStack_self_trim);
    

}
char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive);

long    CliEntry_get_long(CliEntry *self, int position);
double  CliEntry_get_double(CliEntry *self, int position);
double  CliEntry_get_bool(CliEntry *self, int position);
void CliEntry_free(struct CliEntry *self);

