#pragma once

#include "Account.h"
#include "Accumulator.h"

class CreditAccount : public Account {
private:
    double credit;
    double rate;
    double fee;
    Accumulator acc;

    double getDebt() const;

public:
    CreditAccount(const Date& date, const std::string& id, double credit, double rate, double fee);
    double getCredit() const;
    double getRate() const;
    double getFee() const;
    double getAvailableCredit() const;
    void deposit(const Date& date, double amount, const std::string& desc);
    void withdraw(const Date& date, double amount, const std::string& desc);
    void settle(const Date& date);
    void show() const;
};
