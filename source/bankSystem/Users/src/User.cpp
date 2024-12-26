#include "User.hpp"

#include <iostream>

using namespace std;

#include "CheckingAccount.hpp"
#include "NegativeAmountException.hpp"
#include "SavingAccount.hpp"

User::User(const string& username, const string& paasword) {
  this->username = username;
  this->password = paasword;
  this->accounts = new HashMap<string, BankAccount*>();
}

string User::getUsername() { return username; }

bool User::checkPassword() const { return this->password == password; }

void User::addAccount(BankAccount* account) {
  this->accounts->put(account->getAccountNumber(), account);
}

Map<string, BankAccount*>* User::getAccounts() { return accounts; }

BankAccount* User::getAccount(const string& accountNumber) {
  return this->accounts->get(accountNumber);
}

void User::createAccount(const string& accountNumber, double initialBalance) {
  if (initialBalance <= 0) {
    throw NegativeAmountException{"initial blance cannot be negative"};
  }
  BankAccount* account;
  cout << "Account Type: " << endl
       << "1. Checking" << endl
       << "1. Saving" << endl
       << "2. Checking" << endl
       << "Choice: ";
  int choice;
  cin >> choice;
  switch (choice) {
    case 1:
      account = new CheckingAccount(accountNumber, initialBalance, 10);
      break;
    case 2:
      account = new SavingAccount(accountNumber, initialBalance, .03);
    default:
      return;
  }
}
