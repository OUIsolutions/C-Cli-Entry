
CliFlag *private_cli_newCliFlag(){
    CliFlag *self = (CliFlag*) malloc(sizeof(CliFlag));
    self->elements = newCTextArray();
    self->private_garbage = private_cli_newGarbageArray();
    self->size =0;
}

void private_cli_CliFlag_free(CliFlag *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->private_garbage);
    free(self);
}