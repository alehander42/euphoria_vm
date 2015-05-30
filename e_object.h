#ifndef E_OBJECT_H
#define E_OBJECT_H

#include<stddef.h>
#include<stdbool.h>

typedef enum VmType { VM_OBJECT, VM_CLASS } VmType;

typedef struct EObject EObject;

/*
* The base euphoria object. 
* 
* `.vm_type` the vm type of the object
*  it can be `object`, `class`
*
* `.u` :
*   `.parent` the parent of a `class`
*   `.class`  the class of an `object`
*
* `.z` :
*   `.methods` the methods of a `class`
*   `.ivars`   the instance variables of an `object`
*   `.body`    the body of a `method`
*
* `.value` :
*   `.i`       an int value
*   `.b`       a bool value
*   `.s`       a char* value
*   `.length`  an int value, the length of data
*
*  `.data` :
*    `.i`      an int array
*    `.b`      a bool array
*    `.s`      a char* array
*/

struct EObject {
    
    VmType vm_type;
    
    union u {
        EObject* parent;
        EObject* class;
    } u;
    
    union z {
        EObject* methods;
        EObject** ivars;
        EObject** body;
    } z;
    
    union value {
        int i;
        bool b;
        char* s;
        int length;
    } value;
    
    union data {
        int* i;
        bool* b;
        char** s;
    } data;
};

EObject* new_object(EObject* class);

EObject* new_object_with_max_ivars(EObject* class, size_t max_ivars_count);

EObject* new_class(EObject* parent);

EObject* new_class_with_max_methods(EObject* parent, size_t max_methods_count);

#endif
