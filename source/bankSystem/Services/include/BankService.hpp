#ifndef BANKSERVICE__HPP
#define BANKSERVICE__HPP

#include "BankAccount.hpp"

class BankService {
 private:
  BankAccount* account;

 public:
  void deposit(BankAccount* account, double amount);
  void withdraw(BankAccount* account, double amount);
  void transfer(BankAccount* source, BankAccount* destination, double amount);
  void printStatement(BankAccount* account);
};

#endif