


int private_cli_compare_elements_size(const void *element1,const  void *element2){
    CTextStack  *s1 = *(CTextStack**)element1;
    CTextStack  *s2 = *(CTextStack**)element2;

    return (int)(s2->size - s1->size);


}


void private_cli_sort_text_arrays_by_size(CTextArray *elements){
    qsort(elements->stacks, (size_t)elements->size,sizeof(CTextStack **),private_cli_compare_elements_size);
}


CTextArray * private_cli_parse_flags(const char *flags,bool case_sensitive){
    CTextArray *elements = CTextArray_split(flags,"|");
    private_cli_sort_text_arrays_by_size(elements);

    CTextArray_foreach(elements,CTextStack_self_trim);

    if(!case_sensitive){
        CTextArray_foreach(elements,CTextStack_self_lower);
    }
    return elements;
}

CTextStack *private_cli_get_flag_if_its_an_flag(CTextArray *identifiers,CTextStack *possible_flag,bool case_sensitve){

    CTextStack *formated_possible_flag = CTextStack_clone(possible_flag);
    if(!case_sensitve){
        CTextStack_self_lower(formated_possible_flag);
    }


    for(int i =0; i < identifiers->size; i++){

        CTextStack  *current_identifier = identifiers->stacks[i];

        if(CTextStack_starts_with(formated_possible_flag,current_identifier->rendered_text)){
            CTextStack_self_substr(formated_possible_flag, (long)current_identifier->size,-1);
            
            return formated_possible_flag;
        }

    }
    CTextStack_free(formated_possible_flag);

    return NULL;
}

char * private_cli_get_str_from_array(privateCliGarbage *garbage, CTextArray *elements, int position,bool case_sensitive){
    if(position >=elements->size){
        return NULL;
    }
    CTextStack *current = elements->stacks[position];
    char *result;
    if(case_sensitive){
        CTextStack *formated = CTextStack_lower(current);
        result = CTextStack_self_transform_in_string_and_self_clear(formated);
    } else{
        result =strdup(current->rendered_text);
    }

    private_CliGarbage_append(garbage, PRIVATE_CLI_CHAR_TRASH, result);
    return result;
}

long private_cli_get_long_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return -1;
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_parse_to_integer(current);
}

double private_cli_get_double_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return -1;
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_parse_to_double(current);
}

bool private_cli_get_bool_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return false;
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_parse_to_bool(current);
}