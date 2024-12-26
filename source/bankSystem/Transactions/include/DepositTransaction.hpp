#ifndef DEPOSITTRANSACTION__HPP
#define DEPOSITTRANSACTION__HPP

#include "BankAccount.hpp"
#include "Transaction.hpp"

class DepositTransaction : public Transaction {
 private:
  BankAccount* account;
  double amount;

 public:
  DepositTransaction(BankAccount* account, double amount);
  void execute() override;
  string getDetails() override;
};

#endif