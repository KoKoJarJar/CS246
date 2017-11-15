//#include "  include.cpp"
#ifndef _STRING_
#define _STRING_
#include <string>
#endif /* end of include guard */
#ifndef _FSTREAM_
#define _FSTREAM_
#include <fstream>
#endif /* end of include guard */
#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#endif /* end of include guard */

// stack ADT
struct Stack;

// allocate_stack() allocates and reutrns a stack ADT pointer
// effects: allocates memory, caller has to free
// complexity: O(1)
// exception_handling: in case of bad_alloc terminates
Stack *allocate_stack();

// destroy_stack(stack) frees the memory from stack
// effects: frees memory
// complexity: O(n) where n is the length of stack
// requires: stack not null
// exception_handling: in case of bad_alloc or stack null terminates
void destroy_stack(Stack *stack);

// add_stack(filename, stack) adds filename to stack
// effects: allocates more memory
// complexity: O(m) where m is the length of filename
// requires: stack is allocated
// exception_handling: in case of bad_alloc or stack null terminates
void add_stack(std::string filename, Stack *stack);

// search_stack(filename, stack) searches for filename in stack
// complexity: O(nm) where n is the length of stack and m length of filename
// requires: stack is allocated
// exception_handling: in case of error terminates
bool search_stack(std::string filename, Stack *stack);

// pop_stack(stack) pops the first entry in the stack and returns the value
// effects: modifies the stack
// complexity: O(1)
// requires: stack is allocated and len > 1
// exception_handling: in case of error terminates
std::string pop_stack(Stack *stack);

// show_stack(stack) returns the first value in the stack
// complexity: O(1)
// requires: stack is allocated and len > 1
// exception_handling: in case of error terminates
std::string show_stack(Stack *stack);

// process_one_file(in, out, stack, prefix) recursively opens include files
// from in and copies them in out (acting like a pre-processor)
// effects: modifies stack and prefix
// complexity: O(n) where n is the number of include files + I/O
// exception_handling: in case of error terminates
void process_one_file(std::istream &in, std::ostream &out, Stack *stack, std::string prefix);
