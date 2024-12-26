#ifndef INSUFFICIENTBALANCEEXCEPTION__HPP
#define INSUFFICIENTBALANCEEXCEPTION__HPP

#include <exception>

class InsufficientBalanceException : public std::exception {
 private:
  const char* message;

 public:
  InsufficientBalanceException(const char* message);

  const char* what() const noexcept override;
};

#endif