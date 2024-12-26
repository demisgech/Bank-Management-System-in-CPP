#include "DepositTransaction.hpp"

DepositTransaction::DepositTransaction(BankAccount* account, double amount) {
  this->account = account;
  this->amount = amount;
}

void DepositTransaction::execute() {
  account->deposit(amount);
  account->addTransaction(this);
}

string DepositTransaction::getDetails() {
  return "Deposit of $" + to_string(amount) + " to account " +
         account->getAccountNumber();
}
