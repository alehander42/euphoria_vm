#include "top_env.h"

Env* init_top_env() {
    TOP_ENV = new_env();
    BASE_OBJECT  = new_class(NULL);
    CORE_INTEGER = new_class(BASE_OBJECT);
    CORE_BOOLEAN = new_class(BASE_OBJECT);
    CORE_STRING  = new_class(BASE_OBJECT);
    
    TOP_ENV->objects[4] = BASE_OBJECT;
    TOP_ENV->objects[5] = CORE_BOOLEAN;
    TOP_ENV->objects[6] = CORE_INTEGER;
    TOP_ENV->objects[7] = CORE_STRING;
    
    return TOP_ENV;
}

