#include "error.h"

Error::Error(std::string string) : message(string){};

Error::Error(char *string) : message(string){};
