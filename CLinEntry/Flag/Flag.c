
CliFlag *private_cli_newCliFlag(){
    CliFlag *self = (CliFlag*) malloc(sizeof(CliFlag));
    *self = (CliFlag){0};
    self->elements = newCTextArray();
    self->private_garbage = private_cli_newGarbageArray();
}

void private_cli_CliFlag_free(CliFlag *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->private_garbage);
    free(self);
}


int CliFlag_typeof_arg(CliFlag *self, int position){
    return private_cli_get_type_from_array(self->elements,position);
}

const char *CliFlag_typeof_arg_in_str(CliFlag *self, int position){
    return private_cli_get_type_in_str_from_array(self->elements,position);
}

char* CliFlag_get_str(CliFlag *self, int position, bool case_sensitive){
    return private_cli_get_str_from_array(self->private_garbage,self->elements, position,case_sensitive);
}

long  CliFlag_get_long(CliFlag *self, int position){
    return private_cli_get_long_from_array(self->elements,position);
}
double CliFlag_get_double(CliFlag *self, int position){
    return private_cli_get_double_from_array(self->elements,position);
}
bool CliFlag_get_bool(CliFlag *self, int position){
    return private_cli_get_bool_from_array(self->elements,position);
}
