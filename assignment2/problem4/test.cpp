#ifndef _INCLUDE_
#define _INCLUDE_
#include "include.h"
#endif /* end of include guard */
#ifndef _ASSERT_
#define _ASSERT_
#include <cassert>
#endif /* end of include guard */
#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#endif /* end of include guard */
#ifndef _STRING_
#define _STRING_
#include <string>
#endif /* end of include guard */

int main() {
  Stack *stack = allocate_stack();
  add_stack("boz", stack);
  add_stack("lame", stack);
  add_stack("meh", stack);
  assert(show_stack(stack) == "meh");
  assert(show_stack(stack) == "meh");
  assert(search_stack("meh", stack));
  assert(search_stack("lame", stack));
  assert(search_stack("boz", stack));
  assert(!search_stack("lul", stack));
  assert(!search_stack("lel", stack));
  pop_stack(stack);
  assert(show_stack(stack) == "lame");
  pop_stack(stack);
  assert(show_stack(stack) == "boz");
  pop_stack(stack);
  assert(show_stack(stack) == "empty");
  destroy_stack(stack);
}
