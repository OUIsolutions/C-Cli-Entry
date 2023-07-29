

typedef struct CliStringArray{
    int size;
    char **strings;
}CliStringArray;

CliStringArray * newCliStringArray();

void CliStringArray_append(CliStringArray *self);
