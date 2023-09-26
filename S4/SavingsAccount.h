#pragma once

#include "Account.h"
#include "Accumulator.h"

class SavingsAccount : public Account {
private:
    double rate;
    Accumulator acc;

public:
    SavingsAccount(const Date& date, const std::string& id, double rate);
    double getRate() const;
    void deposit(const Date& date, double amount, const std::string& desc);
    void withdraw(const Date& date, double amount, const std::string& desc);
    void settle(const Date& date);
};