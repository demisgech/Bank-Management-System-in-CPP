#ifndef CHECKINKACCOUNT__HPP
#define CHECKINKACCOUNT__HPP

#include "BankAccount.hpp"

class CheckingAccount : public BankAccount {
 private:
  double overdriftLimit;

 public:
  CheckingAccount(const string& accountNumber, double initialBalance,
                  double overdriftLimit);
  void deposit(double amount) override;
  void withdraw(double amount) override;
  string accountType() override;
};

#endif