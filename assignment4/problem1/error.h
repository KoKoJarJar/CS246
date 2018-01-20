#include <string>

// class Error provides arguments for exception handling
class Error {
private:
  std::string message;

public:
  Error(std::string string);
};
