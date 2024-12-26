#include "HashMapException.hpp"

HashMapException::HashMapException(const char* message) {
  this->message = message;
}

const char* HashMapException::what() const noexcept { return message; }
