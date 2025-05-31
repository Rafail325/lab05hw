#include "Account.h"

#include <stdexcept>

Account::Account(int id, int balance)
    : id_(id), balance_(balance), is_locked_(false) {}

Account::~Account() {}

int Account::GetBalance() const { return balance_; }

void Account::ChangeBalance(int diff) {
  balance_ += diff;
}

void Account::Lock() {
  if (is_locked_) throw std::runtime_error("already locked");
  is_locked_ = true;
}

void Account::Unlock() {
  if (!is_locked_) throw std::runtime_error("already unlocked");
  is_locked_ = false;
}

void Account::AddTransaction(std::shared_ptr<Transaction> transaction) {
    if (!is_locked_) throw std::runtime_error("at first lock the account");
    transactions_.push_back(transaction);
    balance_ += transaction->GetAmount();
}

const std::vector<std::shared_ptr<Transaction>>& Account::GetTransactionHistory() const {
    return transactions_;
}


/22
