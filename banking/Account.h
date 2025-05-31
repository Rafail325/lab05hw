#pragma once

#include <vector>
#include <memory>
#include "Transaction.h"

class Account {
 public:
  Account(int id, int balance);
  virtual ~Account();

  // Virtual to test.
  virtual int GetBalance() const;

  // Virtual to test.
  virtual void ChangeBalance(int diff);

  // Virtual to test.
  virtual void Lock();

  // Virtual to test.
  virtual void Unlock();

  int id() const { return id_; }

  void AddTransaction(std::shared_ptr<Transaction> transaction);
  const std::vector<std::shared_ptr<Transaction>>& GetTransactionHistory() const;

 private:
  int id_;
  int balance_;
  bool is_locked_;
  std::vector<std::shared_ptr<Transaction>> transactions_;
};
