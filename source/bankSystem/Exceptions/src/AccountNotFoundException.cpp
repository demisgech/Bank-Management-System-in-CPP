#include "AccountNotFoundException.hpp"

AccountNotFoundException::AccountNotFoundException(const char* message) {}

const char* AccountNotFoundException::what() const noexcept { return message; }
