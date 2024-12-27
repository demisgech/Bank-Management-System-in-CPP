#ifndef BANKSYSTEM__HPP
#define BANKSYSTEM__HPP

#include <string>
using std::string;

#include "BankAccount.hpp"
#include "BankService.hpp"
#include "Map.hpp"
#include "User.hpp"

class BankSystem {
 private:
  BankService* bankService;
  Map<string, User*>* users;
  User* currentUser;

  // Handlers
  BankAccount* selectAccount();
  void displayBalance(BankAccount* account);
  void handleDeposit(BankAccount* account);
  void handleWithdraw(BankAccount* account);
  void handleTransfer(BankAccount* account);
  double getAmountFromUser(const string& prompt);
  string getStringFromUser(const string& prompt);

 public:
  BankSystem();
  ~BankSystem();
  void registerUser(const string& username, const string& password,
                    const string& accountNumber, double initialBalance);
  bool login(const string& username, const string& password);
  void logout();
  User* getCurrentUser() const;
  BankAccount* getAccountByNumber(const string& accountNumber) const;
  void performTask(int choice);
};

#endif