#include "TransferTransaction.hpp"

TransferTransaction::TransferTransaction(BankAccount* source,
                                         BankAccount* destination,
                                         double amount) {
  this->source = source;
  this->destination = destination;
  this->amount = amount;
}

void TransferTransaction::execute() {
  source->withdraw(amount);
  source->addTransaction(this);

  destination->deposit(amount);
  destination->addTransaction(this);
}

string TransferTransaction::getDetails() {
  return "Transferred of $" + to_string(amount) + " from account " +
         source->getAccountNumber() + " to account" +
         destination->getAccountNumber();
}
