#ifndef ACCOUNTNOTFOUNDEXCEPTION__HPP
#define ACCOUNTNOTFOUNDEXCEPTION__HPP

#include <exception>

class AccountNotFoundException : public std::exception {
 private:
  const char* message;

 public:
  AccountNotFoundException(const char* message);
  const char* what() const noexcept override;
};

#endif