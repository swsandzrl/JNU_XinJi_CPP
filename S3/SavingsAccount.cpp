#include "SavingsAccount.h"
#include <iostream>
#include <cmath>

double SavingsAccount::total = 0;

SavingsAccount::SavingsAccount(const Date& date, const std::string& id, double rate) : id(id), rate(rate), lastDate(date), balance(0), accumulation(0) {
    date.show();
    std::cout << "\t#" << id << " created" << std::endl;
}

void SavingsAccount::record(const Date& date, double amount, const std::string& desc) {
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    date.show();
    std::cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << std::endl;
}

std::string SavingsAccount::getId() const {
    return id; 
}

double SavingsAccount::getBalance() const {
    return balance; 
}

double SavingsAccount::getRate() const { 
    return rate; 
}

void SavingsAccount::deposit(const Date& date, double amount, const std::string& desc) {
    record(date, amount, desc);
}

void SavingsAccount::withdraw(const Date& date, double amount, const std::string& desc) {
    if (amount > getBalance())
        std::cout << "Error: not enough money" << std::endl;
    else
        record(date, -amount, desc);
}

void SavingsAccount::settle(const Date& date) {
    double interest = accumulate(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
    if (interest != 0)
        record(date, interest, "interest");
    accumulation = 0;
}

double SavingsAccount::accumulate(const Date& date) const {
    return accumulation + balance * date.distance(lastDate);
}

void SavingsAccount::show() const { 
    std::cout  << id << "\tbalance: " << balance << std::endl; 
}

double SavingsAccount::getTotal() {
    return total;
}

void SavingsAccount::error(const std::string& msg) const {
    std::cout << "Error(#" << id << "): " << msg << std::endl;
}
