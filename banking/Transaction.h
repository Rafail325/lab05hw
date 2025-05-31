#pragma once

#include <string>
#include <vector>
#include <memory>

class Account;

class Transaction {
 public:
  Transaction(int amount, const std::string& description);
  Transaction();
  virtual ~Transaction();

  bool Make(Account& from, Account& to, int sum);
  int fee() const { return fee_; }
  void set_fee(int fee) { fee_ = fee; }

  virtual int GetAmount() const;
  virtual std::string GetDescription() const;

 private:
  void Credit(Account& accout, int sum);
  bool Debit(Account& accout, int sum);

  
  virtual void SaveToDataBase(Account& from, Account& to, int sum);

  int fee_;
  int amount_;
  std::string description_;
};
