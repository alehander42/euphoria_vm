#ifndef EUPHORIA_H
#define EUPHORIA_H

#include<stddef.h>
#include "opcode.h"
#include "opcode_body.h"
#include "e_object.h"
#include "env.h"
#include "data.h"

EObject* run(OpcodeBody opcode_body, EObject** stack, Env* env, Data* data);

inline size_t run_opcode(Opcode opcode, int value, EObject** stack, size_t sp, Env* env, Data* data);

#endif
