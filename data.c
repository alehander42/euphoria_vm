/*
 * `integer_cache` contains Euphoria integers for the first 257 numbers
 * `strings` contains Euphoria strings for the string constants
 */
typedef struct {
	EObject** integer_cache[257];
	EObject** strings[200];
} Data;

