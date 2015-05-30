#ifndef TOP_ENV_H
#define TOP_ENV_H

#include "env.h"
#include "e_object.h"

Env* TOP_ENV;

EObject* BASE_OBJECT;

EObject* CORE_INTEGER;
EObject* CORE_BOOLEAN;
EObject* CORE_STRING;

EObject* new_string(char* value);

EObject* new_integer(int value);

Env* init_top_env();
#endif

