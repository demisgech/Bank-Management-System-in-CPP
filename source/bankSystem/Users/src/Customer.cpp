#include "Customer.hpp"

Customer::Customer(const string& username, const string& password,
                   int cutomerIdd)
    : User{username, password} {
  this->customerId = customerId;
}

int Customer::getCustomerId() const { return customerId; }
