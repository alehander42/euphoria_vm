#ifndef METHOD_H
#define METHOD_H

#include<stddef.h>
#include "e_object.h"
#include "opcode_body.h"
#include "env.h"
#include "data.h"


EObject* invoke_method(OpcodeBody method, EObject* this, EObject** args, size_t args_count, Env* env, Data* data);

#endif