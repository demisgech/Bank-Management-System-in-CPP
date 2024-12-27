#include "BankAccount.hpp"

#include <iostream>

using namespace std;

BankAccount::BankAccount(const string& accountNumber, double initialBalance) {
  this->accountNumber = accountNumber;
  this->balance = initialBalance;
}

double BankAccount::getBalance() const { return balance; }

string BankAccount::getAccountNumber() const { return accountNumber; }

void BankAccount::printStatement() {
  cout << "Account Number: " << accountNumber << endl
       << "Balance: $" << balance << endl
       << "******* Transactions ****" << endl;
  for (long i = 0; i < transactions.getSize(); i++) {
    cout << transactions[i]->getDetails() << endl;
  }
}

void BankAccount::addTransaction(Transaction* transaction) {
  this->transactions.addLast(transaction);
}
