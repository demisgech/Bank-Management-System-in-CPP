#ifndef CUSTOMER__HPP
#define CUSTOMER__HPP

#include <string>

#include "User.hpp"

using std::string;

class Customer : public User {
 private:
  int customerId;

 public:
  Customer(const string& username, const string& password, int cutomerId);
  int getCustomerId() const;
};

#endif