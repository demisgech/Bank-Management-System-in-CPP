#include "CheckingAccount.hpp"

#include "DepositTransaction.hpp"
#include "InsufficientBalanceException.hpp"
#include "NegativeAmountException.hpp"
#include "WithdrawTransaction.hpp"

CheckingAccount::CheckingAccount(const string& accountNumber,
                                 double initialBalance, double overdriftLimit)
    : BankAccount{accountNumber, initialBalance} {
  this->overdriftLimit = overdriftLimit;
}

void CheckingAccount::deposit(double amount) {
  if (amount <= 0) {
    throw NegativeAmountException{"Amount cannot be negative! or zero!"};
  }
  this->balance += amount;
  this->addTransaction(new DepositTransaction(this, amount));
}

void CheckingAccount::withdraw(double amount) {
  if (amount >= balance + overdriftLimit) {
    throw InsufficientBalanceException{"Sorry! Overdrift limit exceed!"};
  }
  this->balance -= amount;
  this->addTransaction(new WithdrawTransaction(this, amount));
}

string CheckingAccount::accountType() { return "Checking"; }
