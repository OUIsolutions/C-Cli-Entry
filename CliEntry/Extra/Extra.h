int private_cli_compare_elements_size(const void *element1,const  void *element2);

void private_cli_sort_text_arrays_by_size(CTextArray *element);

CTextArray * private_cli_parse_flags(const char *flags,bool case_sensitive);

CTextStack *private_cli_get_flag_if_its_an_flag(CTextArray *identifiers,CTextStack *possible_flag,bool case_sensitve);

//getterso of arrays
int private_cli_get_type_from_array(CTextArray *elements,int position);

const char * private_cli_get_type_in_str_from_array(CTextArray *elements,int position);

char * private_cli_get_str_from_array(privateCliGarbage *garbage, CTextArray *elements, int position,bool case_sensitive);

long private_cli_get_long_from_array(CTextArray *elements,int position);

double private_cli_get_double_from_array(CTextArray *elements,int position);

bool private_cli_get_bool_from_array(CTextArray *elements,int position);