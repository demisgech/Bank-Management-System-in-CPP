#include "WithdrawTransaction.hpp"

WithdrawTransaction::WithdrawTransaction(BankAccount* account, double amount) {
  this->account = account;
  this->amount = amount;
}

void WithdrawTransaction::execute() {
  account->withdraw(amount);
  account->addTransaction(this);
}

string WithdrawTransaction::getDetails() {
  return "Withdrew of $" + to_string(amount) + " from account " +
         account->getAccountNumber();
}
