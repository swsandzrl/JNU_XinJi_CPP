#pragma once

#include "Date.h"
#include <string>

class Account {
private:
    static double total;
protected:
    Account(const Date& date, const std::string& id);
    void record(const Date& date, double amount, const std::string& desc);
    void error(const std::string& msg) const;
public:
    std::string id;
    double balance;
    const std::string& getId() const;
    double getBalance() const;
    static double getTotal();
    virtual void show() const = 0;
    virtual void deposit(const Date& date, double amount, const std::string& desc) = 0;
    virtual void withdraw(const Date& date, double amount, const std::string& desc) = 0;
    virtual void settle(const Date& date) = 0;
};