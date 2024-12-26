#ifndef WITHDRAWTRANSACTION__HPP
#define WITHDRAWTRANSACTION__HPP

#include "BankAccount.hpp"
#include "Transaction.hpp"

class WithdrawTransaction : public Transaction {
 private:
  BankAccount* account;
  double amount;

 public:
  WithdrawTransaction(BankAccount* account, double amount);
  void execute() override;
  string getDetails() override;
};

#endif