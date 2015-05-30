#include<e_object.h>

DEFAULT_MAX_IVARS_COUNT = 8;

DEFAULT_MAX_METHODS_COUNT = 4;

EObject* new_object(EObject* class) {
    return new_object_with_max_ivars(class, DEFAULT_MAX_IVARS_COUNT);
}

EObject* new_object_with_max_ivars(EObject* class, size_t max_ivars_count) {
    EObject* object = (EObject*)malloc(sizeof(EObject));
    object->vm_type = VM_OBJECT;
    object->class   = class;
    object->ivars   = (EObject**)malloc(max_ivars_count * sizeof(EObject*));
    return object;
}

EObject* new_class(EObject* parent) {
    return new_class_with_max_methods(parent, DEFAULT_MAX_METHODS_COUNT);
}

EObject* new_class_with_max_methods(EObject* parent, size_t max_methods_count) {
    EObject* class = (EObject*)malloc(sizeof(EObject));
    object->vm_type = VM_CLASS;
    object->parent  = parent;
    object->methods = (EObject**)malloc(max_methods_count * sizeof(EObject*));
    return object;
}
