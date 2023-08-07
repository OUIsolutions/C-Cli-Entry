
CliNamespace newCliNamespace(){
    CliNamespace self = {0};
    self.flag = newCliFlagModule();
    self.entry = newCliEntryModule();
    return self;
}
