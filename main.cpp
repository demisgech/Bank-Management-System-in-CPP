#include <iostream>

#include "BankSystem.hpp"

using namespace std;

class Main {
 private:
  static BankSystem bankSystem;

 public:
  static void main() {
    while (true) {
      cout << "*************************" << endl
           << "*   Welcome to          *" << endl
           << "*   Bank Management     *" << endl
           << "*      System           *" << endl;
      cout << "1. Register" << endl
           << "2. Login" << endl
           << "3. Exit" << endl
           << "Choice: ";
      int choice;
      cin >> choice;
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (performTask(choice)) return;
    }
  }

 private:
  static bool performTask(int choice) {
    switch (choice) {
      case 1:
        registerUser();
        break;
      case 2:
        login();
        break;
      case 3:
        cout << "Exiting the system....." << endl;
        return true;
      default:
        cout << "Invalid choice! Please try again!" << endl;
    }
    return false;
  }

  static void login() {
    string username = getStringFromUser("Username: ");
    string password = getStringFromUser("Password: ");
    bool isLoggedIn = bankSystem.login(username, password);
    if (isLoggedIn) {
      while (true) {
        cout << "1. Check Balance" << endl
             << "2. Deposite" << endl
             << "3. Withdraw" << endl
             << "4. Transfer" << endl
             << "5. Print statement" << endl
             << "6. Logout" << endl
             << "Choice: ";
        int choice;
        cin >> choice;
        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 6) {
          logout();
          break;
        }
        bankSystem.performTask(choice);
      }
    }
  }

  static void logout() { bankSystem.logout(); }
  static void registerUser() {
    string username = getStringFromUser("Username: ");
    string password = getStringFromUser("Password:");
    string accountNumber = getStringFromUser("Account Number: ");
    cout << "Initial Balace: ";
    double initialBalance;
    cin >> initialBalance;
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bankSystem.registerUser(username, password, accountNumber, initialBalance);
  }

  static string getStringFromUser(const string& prompt) {
    cout << prompt;
    string input;
    cin >> input;
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
  }
};

BankSystem Main::bankSystem;

int main() {
  try {
    Main::main();

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}