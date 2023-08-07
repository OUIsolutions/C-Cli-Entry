
void private_cli_parse_flags_sort_text_array(CTextArray *element);

CTextArray * private_cli_parse_flags(const char *flags,bool case_sensitive);

CTextStack *private_cli_get_flag_if_its_an_flag(CTextArray *identifiers,CTextStack *possible_flag,bool case_sensitve);
