

CliEntry * newCliEntry(int argc, char **argv){
    CliEntry *self = (CliEntry*) malloc(sizeof (CliEntry));

    self->elements = newCTextArray();
    self->garbage_array = private_cli_newGarbageArray();

    self->flag_identifiers = " - | -- | ---";
    for(int i = 0; i < argc; i++){
        CTextArray_append_string(self->elements,argv[i]);
    }
    return self;

}

CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive){

}
char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive){
        
}

long    CliEntry_get_long(CliEntry *self, int position);
double  CliEntry_get_double(CliEntry *self, int position);
double  CliEntry_get_bool(CliEntry *self, int position);


void CliEntry_free(struct CliEntry *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->garbage_array);
    free(self);
}

