#ifndef ENV_H
#define ENV_H

#include<stddef.h>
#include "e_object.h"

typedef struct Env Env;
    
struct Env {
    Env* top; // the top environment, the same for the whole env hierarchy
    Env* parent; // the parent environment
    EObject** objects; // the eobjects in the current env
};


Env* new_env();

Env* child_of_env(Env* parent);

Env* new_env_with_max_variables(Env* parent, size_t max_variables_count);

void free_env(Env* env);

#endif