#include "utf8char.h"
#include "utf8string.h"
#include <cmath>
#include <cstring>
#include <sstream>

utf8::string::string() : chars(nullptr), length(0), capacity(0){};

utf8::string::string(const string &string)
    : chars(nullptr), length(string.length), capacity(string.capacity) {
  chars = new Character[capacity];
  std::memcpy(string.chars, chars, sizeof(Character) * string.length);
}

utf8::string::string(const char *string) : utf8::string() {
  static const int min_allocation = 5;
  if (string == nullptr) {
    return;
  }
  std::stringstream input(string);
  if (!input.good()) {
    throw std::ios_base::failure("invalid string");
  }
  chars = new Character[min_allocation];
  capacity = 5;
  for (unsigned int i = 0;; ++i) {
    if (input.eof()) {
      break;
    }
    if (capacity == length) {
      this->reserve(2 * capacity);
    }
    read(input, chars[i]);
    ++length;
  }
}

utf8::string::~string() {
  if (capacity == 0) {
    return;
  }
  delete[] chars;
}

utf8::string &utf8::string::operator=(const string &string) {
  utf8::string temp(string);
  std::swap(length, temp.length);
  std::swap(capacity, temp.capacity);
  std::swap(chars, temp.chars);
  return *this;
}

void utf8::string::push_back(Character ch) {
  if (length == capacity) {
    this->reserve(2 * capacity);
  }
  chars[length] = ch;
  ++length;
}

void utf8::string::reserve(unsigned int n) {
  if (n <= length) {
    return;
  }
  capacity = static_cast<unsigned int>(std::log2(static_cast<double>(n))) + 1;
  if (length == 0) {
    chars = new Character[capacity];
    return;
  }
  if (n > length) {
    auto *temp = new Character[capacity];
    std::memcpy(chars, temp, sizeof(Character) * length);
    std::swap(temp, chars);
    delete[] temp;
  }
}
