#ifndef USER__HPP
#define USER__HPP

#include "BankAccount.hpp"
#include "HashMap.hpp"
#include "Map.hpp"

class User {
 private:
  string username;
  string password;
  Map<string, BankAccount*>* accounts;

 public:
  User(const string& username, const string& paasword);

  string getUsername();
  bool checkPassword(const string& password) const;
  void addAccount(BankAccount* account);

  Map<string, BankAccount*>* getAccounts();
  BankAccount* getAccount(const string& accountNumber);

  void createAccount(const string& accountNumber, double initialBalance);
  virtual ~User() = default;
};

#endif