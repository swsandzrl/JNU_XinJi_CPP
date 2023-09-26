#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const Date& date, const std::string& id, double rate) : Account(date, id), rate(rate), acc(date, 0) {}

double SavingsAccount::getRate() const {
    return rate;
}

void SavingsAccount::deposit(const Date& date, double amount, const std::string& desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date& date, double amount, const std::string& desc) {
    if (amount > getBalance())
        error("not enough money");
    else {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

void SavingsAccount::settle(const Date& date) {
    double interest = acc.getSum(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
    if (interest != 0)
        record(date, interest, "interest");
    acc.reset(date, getBalance());
}
