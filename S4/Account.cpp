#include "Account.h"
#include <iostream>

double Account::total = 0;

Account::Account(const Date& date, const std::string& id) : id(id), balance(0) {
    date.show();
    std::cout << "\t#" << id << " created" << std::endl;
}

void Account::record(const Date& date, double amount, const std::string& desc) {
    balance += amount;
    amount = floor(amount * 100 + 0.5) / 100;
    total += amount;
    date.show();
    std::cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << std::endl;
}

void Account::error(const std::string& msg) const {
    std::cout << "Error(#" << id << "): " << msg << std::endl;
}

const std::string& Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

double Account::getTotal() {
    return total;
}

void Account::show() const {
    std::cout << id << "\tBalance:" << balance;
}
