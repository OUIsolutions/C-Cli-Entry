
#define PRIVATE_CLI_CHAR_TRASH 1
#define PRIVATE_CLI_FLAG_TRASH 2

typedef struct privateCliGarbageElement{
    int type;
    void *value;
}privateCliGarbageElement;


typedef struct privateCliGarbage{
    int size;
    privateCliGarbageElement **values;

}privateCliGarbage;


privateCliGarbage *private_cli_newGarbageArray();
void private_CliGarbage_append(privateCliGarbage*self, int type, void *value);
void private_cli_free_garbage(privateCliGarbage*self);



