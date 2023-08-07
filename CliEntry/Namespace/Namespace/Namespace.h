
typedef struct CliNamespace{
    CliEntryModule entry;
    CliFlagModule  flag;
}CliNamespace;

CliNamespace newCliNamespace();