

CliStringArray * newCliStringArray(){
    CliStringArray  *self = (CliStringArray*) malloc(sizeof (CliStringArray));
    *self = (CliStringArray){0};
    self->strings= malloc(0);
}

void CliStringArray_append(CliStringArray *self){
    
}
