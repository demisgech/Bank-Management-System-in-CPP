#ifndef ARRAYLISTEXCEPTION__HPP
#define ARRAYLISTEXCEPTION__HPP

#include <stdexcept>

using std::exception;

class ArrayListException : public exception {
 private:
  const char* message;

 public:
  ArrayListException(const char* message);
  const char* what() const noexcept override;
};

#endif