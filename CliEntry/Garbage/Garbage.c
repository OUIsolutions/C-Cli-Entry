



privateCliGarbage *private_cli_newGarbageArray(){
    privateCliGarbage *self = (privateCliGarbage*) malloc(sizeof (privateCliGarbage));
    self->values = (privateCliGarbageElement**)(0);
    self->size = 0;
    return self;
}

void private_CliGarbage_append(privateCliGarbage*self, int type, void *value){
    self->values = (privateCliGarbageElement**) realloc(self->values, (self->size + 1) * sizeof (privateCliGarbageElement**));
    privateCliGarbageElement *new_garbage = (privateCliGarbageElement*) malloc(sizeof (privateCliGarbageElement));
    new_garbage->type = type;
    new_garbage->value = value;
    self->values[self->size] = new_garbage;
    self->size+=1;;
    
}

void private_cli_free_garbage(privateCliGarbage*self){
    for(int i = 0 ; i < self->size; i++){
        privateCliGarbageElement *current = self->values[i];
        if(current->type == PRIVATE_CLI_CHAR_TRASH){
            free(current->value);
        }
        if(current->type == PRIVATE_CLI_FLAG_TRASH){
            CliFlag *current_flag = (CliFlag*)current->value;
            private_cli_CliFlag_free(current_flag);
        }
        free(current);
    }
    free(self->values);
    free(self);
}


