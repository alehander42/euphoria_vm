#include<stdlib.h>
#include "top_env.h"
#include "env.h"

EObject* new_integer(int value) {
    EObject* integer = new_object(CORE_INTEGER);
    integer->value.i = value;
    return integer;
}

EObject* new_string(char* value) {
    EObject* string = new_object(CORE_STRING);
    string->value.s = value;
    return string;
}

size_t DEFAULT_MAX_VARIABLE_COUNT = 16;

Env* new_env() {
    return new_env_with_max_variables(NULL, DEFAULT_MAX_VARIABLE_COUNT);
}

Env* child_of_env(Env* parent) {
    return new_env_with_max_variables(parent, DEFAULT_MAX_VARIABLE_COUNT);
}

Env* new_env_with_max_variables(Env* parent, size_t max_variables_count) {
    Env* env = (Env*)malloc(sizeof(Env));
    if(parent == NULL) {
        env->top = env;
    }
    else if(parent->top) {
        env->top = parent->top;
    }
    else {
        env->top = parent;
    }
    env->parent = parent;
    env->objects = (EObject**)malloc(max_variables_count * sizeof(EObject*));
    return env;
}

void free_env(Env* env) {
    free(env->objects);
    free(env);
}

