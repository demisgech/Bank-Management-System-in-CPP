#ifndef BANKACCOUNT__HPP
#define BANKACCOUNT__HPP

#include <iostream>

#include "ArrayList.hpp"
#include "Transaction.hpp"

using namespace std;

// Abstract base class for all bank accounts
class BankAccount {
 protected:
  string accountNumber;
  double balance;
  ArrayList<Transaction*> transactions;

 public:
  BankAccount(const string& accountNumber, double intialBalance);
  virtual ~BankAccount() = default;

  double getBalance() const;
  string getAccountNumber() const;

  virtual void deposit(double amount) = 0;
  virtual void withdraw(double amount) = 0;

  void printStatement();
  void addTransaction(Transaction* transaction);

  virtual string accountType() = 0;
};

#endif
