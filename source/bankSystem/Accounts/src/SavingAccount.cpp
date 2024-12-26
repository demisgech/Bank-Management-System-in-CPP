#include "SavingAccount.hpp"

#include <iostream>
using namespace std;

#include "DepositTransaction.hpp"
#include "InsufficientBalanceException.hpp"
#include "NegativeAmountException.hpp"
#include "WithdrawTransaction.hpp"

SavingAccount::SavingAccount(const string& accountNumber, double initialBalance,
                             double interestRate)
    : BankAccount{accountNumber, initialBalance} {
  this->interestRate = interestRate;
}

void SavingAccount::deposit(double amount) {
  if (amount <= 0) {
    throw NegativeAmountException{"Amount cannot be negative or zero!"};
  }
  this->balance += amount;
  this->addTransaction(new DepositTransaction(this, amount));
}

void SavingAccount::withdraw(double amount) {
  if (amount >= balance) {
    throw InsufficientBalanceException{"Sorry! You don't have enough balance."};
  }
  this->balance -= amount;
  this->addTransaction(new WithdrawTransaction(this, amount));
}

void SavingAccount::addInterest() {
  this->balance = this->balance * interestRate;
  cout << "Interest added: New Balance: $" << balance << endl;
}

string SavingAccount::accountType() { return "Checking"; }