#ifndef NEGATIVEAMOUNTEXCEPTION__HPP
#define NEGATIVEAMOUNTEXCEPTION__HPP

#include <exception>

class NegativeAmountException : public std::exception {
 private:
  const char* message;

 public:
  NegativeAmountException(const char* message);
  const char* what() const noexcept override;
};

#endif