#include "BankService.hpp"

#include <exception>

#include "TransferTransaction.hpp"

using std::exception;

void BankService::deposit(BankAccount* account, double amount) {
  try {
    account->deposit(amount);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void BankService::withdraw(BankAccount* account, double amount) {
  try {
    account->withdraw(amount);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void BankService::transfer(BankAccount* source, BankAccount* destination,
                           double amount) {
  try {
    TransferTransaction* transferTransaction =
        new TransferTransaction(source, destination, amount);
    transferTransaction->execute();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void BankService::printStatement(BankAccount* account) {
  account->printStatement();
}
