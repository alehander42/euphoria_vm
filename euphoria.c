Opcode Opcodes[16536];
int Stack[16536];

void run(Opcode* opcodes, int* stack, int stack_size, Env* env, Data* data) {

	for(var i = 0; i < stack_size; i++) {
		run_opcode(opcodes[i], stack[i], int* stack, i, env, data);
	}
}

inline void run_opcode(Opcode opcode, int value, int* stack, int sp, Env* env, Data* data) {

    switch(opcode) {

    	case LOAD_INTEGER:

    		if(value >= 0 && value <= 256) {
    			stack[sp + 1] = data->integer_cache[value];
    		}
    		else {
    			stack[sp + 1] = env->root.e_integer(value);
    		}
    		break;

    	case LOAD_STRING:

    		stack[sp + 1] = data->strings[value];
    		break;

    	case LOAD_LOCAL:

    		stack[sp + 1] = env->variables[value];
    		break;

    	case LOAD_UPPER:
    		stack[sp + 1] = env->parent.variables[value];
    		break;
}

int main() {
    run(Opcodes, Stack, env);
}



