#pragma once

#include "Date.h"
#include <string>

class SavingsAccount {
private:
    std::string id;
    double balance;
    double rate;
    Date lastDate;
    double accumulation;
    void record(const Date& date, double amount, const std::string& desc);
    double accumulate(const Date& date) const;

public:
    SavingsAccount(const Date& date, const std::string& id, double rate);
    std::string getId() const;
    double getBalance() const;
    double getRate() const;
    void deposit(const Date& date, double amount, const std::string& desc);
    void withdraw(const Date& date, double amount, const std::string& desc);
    void settle(const Date& date);
    void show() const;
    static double total;
    static double getTotal();
    void error(const std::string& msg) const;
};