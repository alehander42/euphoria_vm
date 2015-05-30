#include<method.h>

const size_t DEFAULT_METHOD_STACK_LIMIT = 512;
EObject* invoke_method(OpcodeBody method, EObject* this, EObject** args, size_t args_count, Env* env, Data* data) {
    Env* method_env = child_of_env(env);
    method_env->objects[0] = this; // self
    int a;
    for(a = 0;a < args_count;a ++) {
        method_env->objects[a + 1] = args[a];
    }
    EObject** method_stack[DEFAULT_METHOD_STACK_LIMIT];
    EObject* result = run(method, method_stack, method_env, data);
    free_env(method_env);
    return result;
}

    
