CliEntryModule newCliEntryModule(){
    CliEntryModule self = {0};
    self.newEntry = newCliEntry;
    self.typeof_arg = CliEntry_typeof_arg;
    self.typeof_arg_in_str = CliEntry_typeof_arg_in_str;
    self.get_flag =CliEntry_get_flag;
    self.get_long = CliEntry_get_long;
    self.get_str = CliEntry_get_str;
    self.get_double = CliEntry_get_double;
    self.get_bool = CliEntry_get_bool;
    self.free = CliEntry_free;
    return self;
}