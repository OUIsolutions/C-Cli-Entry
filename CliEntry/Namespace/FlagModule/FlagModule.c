
CliFlagModule newCliFlagModule(){
    CliFlagModule self = {0};
    self.typeof_arg = CliFlag_typeof_arg;
    self.is_numeric =CliFlag_is_numeric;
    self.type_of_arg_in_str = CliFlag_typeof_arg_in_str;
    self.get_str = CliFlag_get_str;
    self.get_long = CliFlag_get_long;
    self.get_double = CliFlag_get_double;
    self.get_bool = CliFlag_get_bool;
    self.represent =CliFlag_represent;
    return self;
}