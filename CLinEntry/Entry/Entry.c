

CliEntry * newCliEntry(int argc, char **argv){
    CliEntry *self = (CliEntry*) malloc(sizeof (CliEntry));
    self->size = argc;
    self->elements = newCTextArray();
    self->garbage_array = private_cli_newGarbageArray();

    for(int i = 0; i < argc; i++){
        CTextArray_append_string(self->elements,argv[i]);
    }
    return self;

}



CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive){
    CTextArray *formated_flags = private_cli_parse_flags(flags,case_sensitive);

    for(int i = 0; i < self->size;i++){
        CTextStack *possible_flag = private_cli_get_flag_if_its_an_flag(identifiers,self->elements->stacks[i],case_sensitive);
        if(possible_flag){
            printf("flag :%s\n",possible_flag->rendered_text);
            CTextStack_free(possible_flag);

        }

    }

    CTextArray_free(identifiers);
    CTextArray_free(formated_flags);

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

