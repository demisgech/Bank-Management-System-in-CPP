#ifndef TRANSFERTRANSACTION__HPP
#define TRANSFERTRANSACTION__HPP

#include "BankAccount.hpp"
#include "Transaction.hpp"

class TransferTransaction : public Transaction {
 private:
  BankAccount* source;
  BankAccount* destination;
  double amount;

 public:
  TransferTransaction(BankAccount* source, BankAccount* destination,
                      double amount);
  void execute() override;
  string getDetails() override;
};

#endif