#ifndef BANKSYSTEM__HPP
#define BANKSYSTEM__HPP

#include <memory>
#include <string>
using namespace std;

#include "BankAccount.hpp"
#include "BankService.hpp"
#include "Map.hpp"
#include "User.hpp"

class BankSystem {
 private:
  BankService* bankService;
  shared_ptr<Map<string, User*>> users;
  shared_ptr<User> currentUser;

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
  shared_ptr<User> getCurrentUser() const;
  BankAccount* getAccountByNumber(const string& accountNumber) const;
  void performTask(int choice);
};

#endif