

CTextArray * private_cli_parse_flags(const char *flags,bool case_sensitive){
    CTextArray *elements = CTextArray_split(flags,"|");
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
