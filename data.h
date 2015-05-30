#ifndef DATA_H
#define DATA_H

#include<stddef.h>
#include "e_object.h"
#include "opcode_body.h"

/*
 * `integer_cache` contains Euphoria integers for the first 257 numbers
 * `strings` contains Euphoria strings for the string constants
 */
typedef struct Data {
	EObject* integer_cache[257];
	EObject* strings[200];
	EObject* labels[200];
	EObject* classes[80];
	OpcodeBody methods[200];
} Data;

Data* new_data(char** strings, size_t strings_count, char** labels, size_t labels_count);

#endif

