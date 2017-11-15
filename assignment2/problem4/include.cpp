#include "include.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

using std::string;

struct Node {
  string filename;
  Node *link;
};

struct Stack {
  Node *first;
  unsigned int len;
};
#ifndef TEST
int main(int argc, char const *argv[]) {
  try {
    char c_string[FILENAME_MAX];
    string prefix;
    std::istream *infile = &std::cin;
    std::ostream *outfile = &std::cout;
    Stack *stack = allocate_stack();
    switch (argc) {
    case 3:
      if (realpath(argv[2], c_string) == nullptr) {
        throw "output file does not exist";
      }
      outfile = new std::ofstream(c_string);
    case 2: {
      if (realpath(argv[1], c_string) == nullptr) {
        throw "input file does not exist";
      }
      prefix = c_string;
      add_stack(prefix, stack);
      infile = new std::ifstream(c_string);
      string::size_type last_slash = prefix.find_last_of('/');
      prefix = prefix.substr(0, last_slash);
    }
    case 1:
      break;
    default:
      throw "wrong command arguments";
    }
    if (infile == &std::cin) {
      realpath(".", c_string);
      prefix = c_string;
    }
    std::istream &in = *infile;
    std::ostream &out = *outfile;
    chdir(prefix.c_str());
    process_one_file(in, out, stack, prefix);
    destroy_stack(stack);
    if (outfile != &std::cout) {
      delete outfile;
    }
    if (infile != &std::cin) {
      delete infile;
    }
    return 0;
  } catch (const char *err) {
    std::cerr << err << std::endl;
    exit(EXIT_FAILURE);
  } catch (std::bad_alloc &err) {
    std::cerr << "not enough memory" << std::endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    exit(EXIT_FAILURE);
  }
}
#endif
// Look at header for description
Stack *allocate_stack() {
  try {
    auto stack = new Stack;
    stack->len = 0;
    stack->first = nullptr;
    return stack;
  } catch (...) {
    std::cout << "insufficient memory, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header for description
void destroy_stack(Stack *stack) {
  try {
    if (stack == nullptr) {
      throw "stack not allocated";
    }
    Node *temp_node = stack->first;
    for (unsigned int i = 0; i < stack->len; ++i) {
      Node *temp_node2 = temp_node->link;
      delete temp_node;
      temp_node = temp_node2;
    }
    temp_node = nullptr;
    delete stack;
  } catch (const char *err) {
    std::cout << err << std::endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    std::cout << "deallocation error, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header for description
void add_stack(string filename, Stack *stack) {
  try {
    if (stack == nullptr) {
      throw "stack not allocated";
    }
    auto new_node = new Node;
    new_node->filename = filename;
    new_node->link = stack->first;
    stack->first = new_node;
    ++stack->len;
  } catch (const char *err) {
    std::cout << err << std::endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    std::cout << "insufficient memory, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header for description
bool search_stack(string filename, Stack *stack) {
  try {
    if (stack == nullptr) {
      throw "stack not allocated";
    }
    Node *first = stack->first;
    for (unsigned int i = 0; i < stack->len; ++i) {
      if (first->filename == filename) {
        return true;
      }
        first = first->link;
    }
    return false;
  } catch (const char *err) {
    std::cout << err << std::endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    std::cout << "unknown error, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header for description
string pop_stack(Stack *stack) {
  try {
    if (stack == nullptr) {
      throw "stack not allocated, exiting";
    }
    if (stack->len < 1) {
      throw "stack empty, exiting";
    }
    --stack->len;
    string return_string = stack->first->filename;
    Node *temp_node = stack->first;
    stack->first = stack->first->link;
    delete temp_node;
    return return_string;
  } catch (const char *err) {
    std::cerr << err << std::endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    std::cerr << "unknown error, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header for description
string show_stack(Stack *stack) {
  try {
    if (stack == nullptr) {
      throw "stack not allocated, exiting";
    }
    if (stack->len < 1) {
      return "empty";
    }
    return stack->first->filename;
  } catch (const char *err) {
    exit(EXIT_FAILURE);
    std::cerr << err << std::endl;
  } catch (...) {
    std::cerr << "unknown error, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// is_user_include(line, include) checks to see if line is of type
// user_include, also returns the string for the include file if it exists
// effects: changes include
// complexity: O(m) where m is the length of line
// restrictions: line is a valid string
static bool is_user_include(string line, string &include) {
  static char buffer[FILENAME_MAX];
  static unsigned short include_length = 7;
  try {
    std::stringstream ss(line);
    ss.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    ss >> std::ws;
    ss.read(buffer, sizeof(char));
    string check(buffer);
    check.resize(1);
    if (check != "#") {
      return false;
    }
    ss >> std::ws;
    ss.read(buffer, include_length * sizeof(char));
    check = buffer;
    check.resize(include_length);
    if (check != "include") {
      return false;
    }
    ss >> std::ws;
    ss.read(buffer, sizeof(char));
    check = buffer;
    check.resize(1);
    if (check != "\"") {
      return false;
    }
    ss >> std::ws;
    std::getline(ss, check, '"');
    string::size_type first_ws = check.find_first_of(" \n\t\r\v\f");
    if (first_ws != string::npos) {
      check = check.substr(0, first_ws);
    }
    ss >> std::ws;
    if (!ss.eof()) {
      return false;
    }
    include = check;
    return true;
  } catch (std::ios_base::failure &err) {
    return false;
  } catch (...) {
    std::cerr << "unknown error" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header for description
void process_one_file(std::istream &in, std::ostream &out, Stack *stack,
                      std::string prefix) {
  static char buffer2[FILENAME_MAX];
  try {
    string line;
    string check;
    string &include = check;
    while (std::getline(in, line) && !in.fail()) {
      if (!is_user_include(line, include)) {
        break;
      }
      if (realpath(include.c_str(), buffer2) == nullptr) {
        throw "invalid file name";
      }
      include = buffer2;
      if (search_stack(include, stack)) {
        throw "recursive inclusion";
      }
      add_stack(include, stack);
      string::size_type last_slash = include.find_last_of("/");
      if (last_slash == string::npos) {
        throw "wrong file name";
      }
      std::ifstream file(include.c_str());
      std::istream &next_in = file;
      string next_dir = include.substr(0, last_slash);
      chdir(next_dir.c_str());
      process_one_file(next_in, out, stack, next_dir);
      chdir(prefix.c_str());
      out << std::endl;
      pop_stack(stack);
      file.close();
    }
    while (!in.fail()) {
      out << line << std::endl;
      std::getline(in, line);
    }
    return;
  } catch (const char *err) {
    std::cerr << err << std::endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    std::cerr << "unknown I/O error" << std::endl;
    exit(EXIT_FAILURE);
  }
}
