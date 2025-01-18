#include "BankSystem.hpp"

#include <exception>
#include <iostream>

using namespace std;

#include "HashMap.hpp"

BankSystem::BankSystem() {
  this->bankService = new BankService();
  this->users = make_shared<HashMap<string, User*>>();
  currentUser = nullptr;
}

BankSystem::~BankSystem() { delete bankService; }

void BankSystem::registerUser(const string& username, const string& password,
                              const string& accountNumber,
                              double initialBalance) {
  if (!users->contains(username)) {
    try {
      User* newUser = new User(username, password);
      users->put(username, newUser);
      newUser->createAccount(accountNumber, initialBalance);
      cout << "User successfully registered!" << endl;
    } catch (const exception& e) {
      std::cerr << "Failed to create account: " << e.what() << '\n';
    }
  } else {
    cout << "User already registered!" << endl;
  }
}

bool BankSystem::login(const string& username, const string& password) {
  User* user = users->get(username);
  if (user != nullptr && user->checkPassword(password)) {
    this->currentUser = shared_ptr<User>(user);
    cout << "User successfully logged in!" << endl;
    return true;
  }
  cout << "Invalid username or password!" << endl;
  return false;
}

void BankSystem::logout() {
  this->currentUser = nullptr;
  cout << "Logged out successfully!" << endl;
}

shared_ptr<User> BankSystem::getCurrentUser() const {
  return currentUser;
  // return shared_ptr<User>(currentUser);
}

BankAccount* BankSystem::getAccountByNumber(const string& accountNumber) const {
  if (currentUser != nullptr) return currentUser->getAccount(accountNumber);
  return nullptr;
}

void BankSystem::performTask(int choice) {
  BankAccount* account = selectAccount();
  if (!account) {
    cout << "No account selected!" << endl;
    return;
  }

  switch (choice) {
    case 1:
      displayBalance(account);
      break;

    case 2:
      handleDeposit(account);
      break;

    case 3:
      handleWithdraw(account);
      break;

    case 4:
      handleTransfer(account);
      break;

    case 5:
      bankService->printStatement(account);
      break;

    case 6:
      logout();
      break;

    default:
      cout << "Invalid choice! Please, try again!" << endl;
      break;
  }
}

BankAccount* BankSystem::selectAccount() {
  try {
    auto accounts = currentUser->getAccounts();
    auto keySet = accounts->keySet();
    if (keySet.getSize() == 0) {
      cout << "No account found!" << endl;
      return nullptr;
    }

    BankAccount* account = nullptr;
    auto it = keySet.begin();
    for (long i = 0; i < keySet.getSize(); i++) {
      auto accountNumber = keySet[i];
      account = getAccountByNumber(accountNumber);
      if (account) {
        return account;
      }
    }

    cout << "No valid account found!" << endl;
    return nullptr;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return nullptr;
  }
}

void BankSystem::displayBalance(BankAccount* account) {
  if (account != nullptr) {
    double balance = account->getBalance();
    cout << "Balance: $" << balance << endl;
  }
}

void BankSystem::handleDeposit(BankAccount* account) {
  if (account) {
    auto amount = getAmountFromUser("Amount: ");
    bankService->deposit(account, amount);
  }
}

void BankSystem::handleWithdraw(BankAccount* account) {
  if (account) {
    auto amount = getAmountFromUser("Amount: ");
    bankService->withdraw(account, amount);
  }
}

void BankSystem::handleTransfer(BankAccount* account) {
  if (account) {
    string destinationUsername = getStringFromUser("Destination username: ");
    string destinationAccountNumber =
        getStringFromUser("Destination Account Number: ");
    double amount = getAmountFromUser("Balance to transfer: ");

    User* destinationUser = users->get(destinationUsername);
    if (destinationUser != nullptr) {
      BankAccount* destinationAccount =
          destinationUser->getAccount(destinationAccountNumber);
      if (destinationAccount != nullptr) {
        bankService->transfer(account, destinationAccount, amount);
        cout << "Successfully transferred!" << endl;
      } else {
        cout << "Destination account is not found!" << endl;
      }
    } else {
      cout << "Destination user is not found!" << endl;
    }
  }
}

double BankSystem::getAmountFromUser(const string& prompt) {
  cout << prompt;
  double amount;
  cin >> amount;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return amount;
}

string BankSystem::getStringFromUser(const string& prompt) {
  cout << prompt;
  string input;
  cin >> input;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return input;
}
