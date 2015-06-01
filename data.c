#include<stdlib.h>
#include "top_env.h"
#include "data.h"

Data* new_data(char** strings, size_t strings_count, char** labels, size_t labels_count) {
	Data* data = (Data*)malloc(sizeof(Data));
	size_t z;
	for(z = 0;z < 257;z++) {
		data->integer_cache[z] = new_integer(z);
	}
	
	for(z = 0;z < strings_count;z++) {
		data->strings[z] = new_string(strings[z]);
	}
	
	for(z = 0;z < labels_count;z++) {
		data->labels[z] = new_string(labels[z]);
	}
	return data;
}

