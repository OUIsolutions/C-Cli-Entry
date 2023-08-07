

CliEntry * newCliEntry(int argc, char **argv){
    CliEntry *self = (CliEntry*) malloc(sizeof (CliEntry));
    self->size = argc;
    self->elements = newCTextArray();
    self->private_garbage = private_cli_newGarbageArray();

    self->flag_identifiers = " - | -- | --- ";
    for(int i = 0; i < argc; i++){
        CTextArray_append_string(self->elements,argv[i]);
    }
    return self;

}



CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive){
    CTextArray *identifiers = private_cli_parse_flags(self->flag_identifiers,case_sensitive);
    CTextArray *formated_flags = private_cli_parse_flags(flags,case_sensitive);

    CliFlag *flag = private_cli_newCliFlag();
    private_CliGarbage_append(self->private_garbage, PRIVATE_CLI_FLAG_TRASH, flag);
    for(int i = 0; i < self->size;i++){


        CTextStack *possible_flag = private_cli_get_flag_if_its_an_flag(identifiers,self->elements->stacks[i],case_sensitive);
        //means its an flag
        if(possible_flag){
            //means its the  end of current flag and start of other
            if(flag->exist){
                CTextStack_free(possible_flag);
                break;
            }
            else{
                if(CTextArray_includes(formated_flags,possible_flag->rendered_text)){
                    flag->exist = true;
                }
            }
            CTextStack_free(possible_flag);
        }

        else{
            //means its an normal atribute
            if(flag->exist){
                CTextArray_append_string(flag->elements,self->elements->stacks[i]->rendered_text);
            }
        }
    }


    CTextArray_free(identifiers);
    CTextArray_free(formated_flags);

    return flag;

}
int CliEntry_typeof_arg(CliEntry *self,int position){
    return private_cli_get_type_from_array(self->elements,position);
}

const char *CliEntry_typeof_arg_in_str(CliEntry *self,int position){
    return private_cli_get_type_in_str_from_array(self->elements,position);
}

char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive){
    return private_cli_get_str_from_array(self->private_garbage, self->elements, position, case_sensitive);
}

long CliEntry_get_long(CliEntry *self, int position){
    return private_cli_get_long_from_array(self->elements,position);
}

double CliEntry_get_double(CliEntry *self, int position){
    return private_cli_get_double_from_array(self->elements,position);
}

bool CliEntry_get_bool(CliEntry *self, int position){
    return private_cli_get_bool_from_array(self->elements,position);
}
bool  CliEntry_represent(CliEntry *self){
    CTextArray_represent(self);
}
void CliEntry_free(struct CliEntry *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->private_garbage);
    free(self);
}

