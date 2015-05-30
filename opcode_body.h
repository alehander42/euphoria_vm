#ifndef OPCODE_BODY_H
#define OPCODE_BODY_H

#include<stddef.h>
#include "opcode.h"

typedef struct OpcodeBody {
    Opcode* opcodes;
    int*    values;
    size_t  count;
} OpcodeBody;

#endif