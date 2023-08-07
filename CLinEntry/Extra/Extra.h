int private_cli_compare_elements_size(const void *element1,const  void *element2);

void private_cli_sort_text_arrays_by_size(CTextArray *element);

CTextArray * private_cli_parse_flags(const char *flags,bool case_sensitive);

CTextStack *private_cli_get_flag_if_its_an_flag(CTextArray *identifiers,CTextStack *possible_flag,bool case_sensitve);
