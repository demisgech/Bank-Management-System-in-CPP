#ifndef TRANSACTION__HPP
#define TRANSACTION__HPP

#include <string>

using std::string;

// An interface for all transactions
class Transaction {
 public:
  virtual ~Transaction() = default;
  virtual void execute() = 0;
  virtual string getDetails() = 0;
};

#endif