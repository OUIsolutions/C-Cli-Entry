

typedef struct privateCliGarbage{
    int type;
    void *value;
}privateCliGarbage;


typedef struct privateCliGarbageArray{
    int size;
    privateCliGarbage *values;

}privateCliGarbageArray;


privateCliGarbageArray *private_cli_newGarbageArray();
privateCliGarbageArray *private_cli_append_gargabe(int type, void *value);
privateCliGarbageArray *private_cli_free_garbage(int type, void *value);



