#ifndef OPCODE_H
#define OPCODE_H

typedef enum Opcode {
    // name         arg         effect on stack documentation
    A0,
    A1,
    LOAD_INTEGER,   // value    +1          loads an euphoria integer object
    LOAD_LOCAL,     // index    +1          loads a local variable 
    LOAD_STRING,    // index    +1          loads a string constant
    LOAD_UPPER,     // index    +1          loads a variable from the upper env
    SAVE_LOCAL,     // index    -1          saves the last stack object to a local variable
    SAVE_UPPER,     // index    -1          saves the last stack object to a variable in the upper env
    LOAD_METHOD,    // index    0           loads a method of the last stack class, pops the class
    CONVERT_B_S,    // index    0           converts the last stack object from a boolean to a string
    CONVERT_I_S,    // <none>   0           converts the last stack object from an integer to a string
    INVOKE_METHOD,  // index,args_count  - args_count invokes a method
    ECHO,           // args_count - args_count  prints and pops the last args_count objects
    EXIT            // status   /           exits from the program with code status
} Opcode;

#endif


