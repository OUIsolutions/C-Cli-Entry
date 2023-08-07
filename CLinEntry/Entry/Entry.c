

CliEntry * newCliEntry(int argc, char **argv){
    CliEntry *self = (CliEntry*) malloc(sizeof (CliEntry));
    self->size = argc;
    self->elements = newCTextArray();
    self->garbage_array = private_cli_newGarbageArray();

    self->flag_identifiers = " - | -- | --- ";
    for(int i = 0; i < argc; i++){
        CTextArray_append_string(self->elements,argv[i]);
    }
    return self;

}



CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive){
    CTextArray *identifiers = private_cli_parse_flags(self->flag_identifiers,case_sensitive);
    CTextArray *formated_flags = private_cli_parse_flags(flags,case_sensitive);

    bool found_flag = false;
    CliFlag *flag = private_cli_newCliFlag();

    for(int i = 0; i < self->size;i++){


        CTextStack *possible_flag = private_cli_get_flag_if_its_an_flag(identifiers,self->elements->stacks[i],case_sensitive);
        //means its an flag
        if(possible_flag){
            //means its the  end of current flag and start of other
            if(found_flag){
                CTextStack_free(possible_flag);
                break;
            }
            else{
                if(CTextArray_includes(formated_flags,possible_flag->rendered_text)){
                    found_flag = true;
                }
            }
            CTextStack_free(possible_flag);
        }

        else{
            //means its an normal atribute
            if(found_flag){
                CTextArray_append_string(flag->elements,self->elements->stacks[i]->rendered_text);
            }
        }
    }


    CTextArray_free(identifiers);
    CTextArray_free(formated_flags);
    if(found_flag){
        return flag;
    }
    private_cli_CliFlag_free(flag);
    return NULL;

}

char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive){
    if(position >=self->size){
        return NULL;
    }

    CTextStack *current = self->elements->stacks[position];
    char *result = strdup(current->rendered_text);
    private_cli_append_gargabe(self->garbage_array,PRIVATE_CLI_CHAR_TRASH,result);
    return result;
}

long CliEntry_get_long(CliEntry *self, int position){
    if(position >=self->size){
        return -1;
    }
    CTextStack *current = self->elements->stacks[position];
    return CTextStack_parse_to_integer(current);
}

double CliEntry_get_double(CliEntry *self, int position){
    if(position >=self->size){
        return -1;
    }
    CTextStack *current = self->elements->stacks[position];
    return CTextStack_parse_to_double(current);
}

bool CliEntry_get_bool(CliEntry *self, int position){
    if(position >=self->size){
        return false;
    }
    CTextStack *current = self->elements->stacks[position];
    return CTextStack_parse_to_bool(current);
}

void CliEntry_free(struct CliEntry *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->garbage_array);
    free(self);
}

