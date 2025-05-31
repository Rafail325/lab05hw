#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"
#include "Transaction.h"

using ::testing::Return;
using ::testing::_;

class MockTransaction : public Transaction {
public:
    MOCK_METHOD(int, GetAmount, (), (const, override));
    MOCK_METHOD(std::string, GetDescription, (), (const, override));
};

class AccountTest : public ::testing::Test {
protected:
    void SetUp() override {
        account = std::make_unique<Account>(1, 1000);
    }

    std::unique_ptr<Account> account;
};

TEST_F(AccountTest, InitialBalance) {
    EXPECT_EQ(account->GetBalance(), 1000);
}

TEST_F(AccountTest, AddTransaction) {
    MockTransaction mockTransaction;
    EXPECT_CALL(mockTransaction, GetAmount()).WillOnce(Return(500));

    account->Lock();
    account->AddTransaction(std::shared_ptr<Transaction>(&mockTransaction, [](Transaction*){}));
    EXPECT_EQ(account->GetBalance(), 1500);
}

TEST_F(AccountTest, AddNegativeTransaction) {
    MockTransaction mockTransaction;
    EXPECT_CALL(mockTransaction, GetAmount()).WillOnce(Return(-300));

    account->Lock();
    account->AddTransaction(std::shared_ptr<Transaction>(&mockTransaction, [](Transaction*){}));
    EXPECT_EQ(account->GetBalance(), 700);
}

TEST_F(AccountTest, ChangeBalanceLockedAccount) {
    account->Lock();
    account->ChangeBalance(500);
    EXPECT_EQ(account->GetBalance(), 1500);
}

TEST_F(AccountTest, ChangeBalanceUnlockedAccount) {
    account->ChangeBalance(100);
    EXPECT_EQ(account->GetBalance(), 1100);
}

TEST_F(AccountTest, LockAccount) {
    account->Lock();
    EXPECT_THROW(account->Lock(), std::runtime_error);
}

TEST_F(AccountTest, UnlockAccount) {
    account->Lock();
    account->Unlock();
    EXPECT_THROW(account->Unlock(), std::runtime_error);
}

TEST_F(AccountTest, Destructor) {
}

TEST_F(AccountTest, DestructorCoverage) {
    Account* acc = new Account(1, 100);
    delete acc;
}

TEST_F(AccountTest, GetId) {
    Account account(123, 1000);
    EXPECT_EQ(account.id(), 123);
}

TEST_F(AccountTest, GetTransactionHistory) {
    Account account(1, 1000);
    auto transaction1 = std::make_shared<Transaction>(100, "First transaction");
    auto transaction2 = std::make_shared<Transaction>(200, "Second transaction");
    
    account.Lock();
    account.AddTransaction(transaction1);
    account.AddTransaction(transaction2);
    
    const auto& history = account.GetTransactionHistory();
    EXPECT_EQ(history.size(), 2);
    EXPECT_EQ(history[0], transaction1);
    EXPECT_EQ(history[1], transaction2);
} 
