

CliEntry * newCliEntry(int argc, char **argv){
    CliEntry *self = (CliEntry*) malloc(sizeof (CliEntry));
    self->size = argc;
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
        long converted_position = private_CText_transform_index(self->elements->size,position);
        printf("%ld\n",converted_position);
        
        CTextStack *current = self->elements->stacks[converted_position];
        char *result = strdup(current->rendered_text);
        private_cli_append_gargabe(self->garbage_array,PRIVATE_CLI_CHAR_TRASH,result);
        return result;
}

long CliEntry_get_long(CliEntry *self, int position){
    long converted_position = private_CText_transform_index(self->elements->size,position);
    CTextStack *current = self->elements->stacks[converted_position];
    return CTextStack_parse_to_integer(current);
}
double CliEntry_get_double(CliEntry *self, int position){
    long converted_position = private_CText_transform_index(self->elements->size,position);
    CTextStack *current = self->elements->stacks[converted_position];
    return CTextStack_parse_to_double(current);
}

double CliEntry_get_bool(CliEntry *self, int position){
    long converted_position = private_CText_transform_index(self->elements->size,position);
    CTextStack *current = self->elements->stacks[converted_position];
    return CTextStack_parse_to_bool(current);
}

void CliEntry_free(struct CliEntry *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->garbage_array);
    free(self);
}

