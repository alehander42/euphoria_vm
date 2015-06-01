#include<stdio.h>
#include<stdlib.h>
#include "top_env.h"
#include "method.h"
#include "euphoria.h"

Opcode Opcodes[16536];
int Values[16536];
EObject* Stack[16536];

EObject* run(OpcodeBody opcode_body, EObject** stack, Env* env, Data* data) {
    
    size_t sp = 0;
    stack[0] = NULL;
    int opcodes_i = opcode_body.count;
    int a;
    for(a = 0; a < opcodes_i; a++) {
        sp = run_opcode(opcode_body.opcodes[a], opcode_body.values[a], stack, sp, env, data);
    }
    if(sp > 0) {
        return stack[sp];
    }
    else {
        return NULL;
    }
}

inline size_t run_opcode(Opcode opcode, int value, EObject** stack, size_t sp, Env* env, Data* data) {
    char* char_value;
    size_t old_sp;
    size_t z;
    size_t args_count;
    size_t index;
    
    
    switch(opcode) {
    
        case LOAD_INTEGER:

            if(value >= 0 && value <= 256) {
                stack[++ sp] = data->integer_cache[value];
            }
            else {
                stack[++ sp] = new_integer(value);
            }
            break;

        case LOAD_STRING:

            stack[++ sp] = data->strings[value];
            break;

        case LOAD_LOCAL:

            stack[++ sp] = env->objects[value];
            break;

        case LOAD_UPPER:
            
            stack[++ sp] = env->parent->objects[value];
            break;
            
        case SAVE_LOCAL:
               
            env->objects[value] = stack[sp --];
            break;
           
        case SAVE_UPPER:
            
            env->parent->objects[value] = stack[sp --];
            break;
            
        case LOAD_METHOD:
            
            break;
            
            //TODO add method dispatch based on inheritance
            //or do it somehow in the compiler??
            
        case CONVERT_I_S:
            
            char_value = (char*)malloc(32 * sizeof(char));
            sprintf(char_value, "%d", stack[sp]->value.i);
            stack[sp] = new_string(char_value);
            break;
            
        case CONVERT_B_S:
            
            if(stack[sp]->value.b) {
                stack[sp] = new_string("true");
            }
            else {
                stack[sp] = new_string("false");
            }
            break;
            
        case INVOKE_METHOD:
            
            old_sp = sp;
            index = 256 * ((value >> 24) & 0xff) + ((value >> 16) & 0xff);
            args_count = 256 * ((value >> 8) & 0xff) + (value & 0xff);
            sp -= args_count;
            // printf("%d %d %d\n", old_sp, sp, index);
            stack[sp] = invoke_method(data->methods[index], //method
                                                   stack[old_sp - args_count], //self
                                                   stack + old_sp - args_count + 1, //args
                                                   args_count,
                                                   env, data);
            break;
        
        case A0: break;
        
        case A1: break;
        
        case ECHO:
            
            sp -= value;
            
            for(z = 0;z < value;z ++) {
                printf("%s%s", stack[sp + z + 1]->value.s, z == value - 1 ? "" : " ");
            }
            printf("\n");
            break;
        
        case EXIT:
            
            exit(value);
    }
    return sp;
}

void main() {
    // 5 init 6 address 7 copy 8 to_string
    // ok
    // 94.echo
    // load_integer     94
    // invoke_method    8,0  # to_string
    // echo             1
    // exit             0
    Opcodes[0] = LOAD_INTEGER; Values[0] = 94;
    Opcodes[1] = INVOKE_METHOD;Values[1] = 0x00080000;
    Opcodes[2] = ECHO;         Values[2] = 1;
    Opcodes[3] = EXIT;         Values[3] = 0;
    
    OpcodeBody opcode_body = {.opcodes = Opcodes, .values = Values, .count = 4};
    init_top_env();
    char* data_strings[0];
    char* data_labels[0];
    
    Data* data = new_data(data_strings, 0, data_labels, 0);
    OpcodeBody e_integer_to_string;
    Opcode e[2]; int e2[2];
    e_integer_to_string.opcodes = e; e_integer_to_string.values = e2; e_integer_to_string.count = 2;
    // load_local       0 # self
    // convert_i_s      0 # internal integer to string converter

    e_integer_to_string.opcodes[0] = LOAD_LOCAL; e_integer_to_string.values[0] = 0;
    e_integer_to_string.opcodes[1] = CONVERT_I_S;e_integer_to_string.values[1] = 0;
    data->methods[8] = e_integer_to_string;

    run(opcode_body, Stack, TOP_ENV, data);
}





