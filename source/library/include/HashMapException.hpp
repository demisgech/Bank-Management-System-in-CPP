#ifndef HASHMAPEXCEPTION__HPP
#define HASHMAPEXCEPTION__HPP

#include <exception>

class HashMapException : public std::exception {
 private:
  const char* message;

 public:
  HashMapException(const char* message);
  const char* what() const noexcept override;
};

#endif
