#define SET_UNIFORM_I(name, value) shader_set_uniform_i(shader_get_uniform(standard, name), value);
#define SET_UNIFORM_F(name, ...) shader_set_uniform_f(shader_get_uniform(standard, name), __VA_ARGS__);

#define CHANGE_SET 0
#define CHANGE_ADD 1
