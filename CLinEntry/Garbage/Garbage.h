
#define PRIVATE_CLI_CHAR_TRASH 1
#define PRIVATE_CLI_FLAG_TRASH 2

typedef struct privateCliGarbage{
    int type;
    void *value;
}privateCliGarbage;


typedef struct privateCliGarbageArray{
    int size;
    privateCliGarbage **values;

}privateCliGarbageArray;


privateCliGarbageArray *private_cli_newGarbageArray();
privateCliGarbageArray *private_cli_append_gargabe(privateCliGarbageArray*self,int type, void *value);
privateCliGarbageArray *private_cli_free_garbage(privateCliGarbageArray*self);



