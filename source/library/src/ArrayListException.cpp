#include "ArrayListException.hpp"

ArrayListException::ArrayListException(const char* message) {
  this->message = message;
}

const char* ArrayListException::what() const noexcept { return message; }
