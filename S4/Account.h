#pragma once

#include "Date.h"
#include <string>

class Account {
private:
    std::string id;
    double balance;
    static double total;

protected:
    Account(const Date& date, const std::string& id);
    void record(const Date& date, double amount, const std::string& desc);
    void error(const std::string& msg) const;

public:
    const std::string& getId() const;
    double getBalance() const;
    static double getTotal();
    void show() const;
};