


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
