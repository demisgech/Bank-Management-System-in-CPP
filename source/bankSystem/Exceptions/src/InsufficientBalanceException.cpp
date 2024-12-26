#include "InsufficientBalanceException.hpp"

InsufficientBalanceException::InsufficientBalanceException(
    const char* message) {
  this->message = message;
}

const char* InsufficientBalanceException::what() const noexcept {
  return message;
}
