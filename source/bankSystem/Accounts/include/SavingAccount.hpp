#ifndef SAVINGACCOUNT__HPP
#define SAVINGACCOUNT__HPP

#include "BankAccount.hpp"

class SavingAccount : public BankAccount {
 private:
  double interestRate;

 public:
  SavingAccount(const string& accountNumber, double initialBalance,
                double interestRate);

  void deposit(double amount) override;
  void withdraw(double amount) override;
  void addInterest();
  string accountType() override;
};

#endif