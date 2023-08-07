



privateCliGarbageArray *private_cli_newGarbageArray(){
    privateCliGarbageArray *self = (privateCliGarbageArray*) malloc(sizeof (privateCliGarbageArray));
    self->values = malloc(0);
    self->size = 0;
    return self;
}

privateCliGarbageArray *private_cli_append_gargabe(privateCliGarbageArray*self,int type, void *value){
    self->values = (privateCliGarbage**) realloc(self->values,(self->size+1) * sizeof (privateCliGarbage**));
    privateCliGarbage *new_garbage = (privateCliGarbage*) malloc(sizeof (privateCliGarbage));
    new_garbage->type = type;
    new_garbage->value = value;
    self->values[self->size] = new_garbage;
    self->size+=1;;
}

privateCliGarbageArray *private_cli_free_garbage(privateCliGarbageArray*self){
    for(int i = 0 ; i < self->size; i++){
        privateCliGarbage *current = self->values[i];
        if(current->type == PRIVATE_CLI_CHAR_TRASH){
            free(current->value);
        }
        if(current->type == PRIVATE_CLI_FLAG_TRASH){
            CliFlag *current_flag = (CliFlag*)current->value;
            private_cli_freeCliFlag(current_flag);
        }
        free(current);
    }
    free(self->values);
    free(self);
}


