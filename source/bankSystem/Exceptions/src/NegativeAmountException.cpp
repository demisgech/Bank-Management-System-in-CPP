#include "NegativeAmountException.hpp"

NegativeAmountException::NegativeAmountException(const char* message) {
  this->message = message;
}

const char* NegativeAmountException::what() const noexcept { return message; }
