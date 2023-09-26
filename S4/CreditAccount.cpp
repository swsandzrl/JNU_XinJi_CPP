#include "CreditAccount.h"
#include <iostream>

CreditAccount::CreditAccount(const Date& date, const std::string& id, double credit, double rate, double fee) : Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) {}

double CreditAccount::getDebt() const {
    double balance = getBalance();
    return (balance < 0 ? balance : 0);
}

double CreditAccount::getCredit() const {
    return credit;
}

double CreditAccount::getRate() const {
    return rate;
}

double CreditAccount::getFee() const {
    return fee;
}

double CreditAccount::getAvailableCredit() const {
    if (getBalance() < 0)
        return credit + getBalance();
    else
        return credit;
}

void CreditAccount::deposit(const Date& date, double amount, const std::string& desc) {
    record(date, amount, desc);
    acc.change(date, getDebt());
}

void CreditAccount::withdraw(const Date& date, double amount, const std::string& desc) {
    if (amount - getBalance() > credit)
        error("not enough credit");
    else {
        record(date, -amount, desc);
        acc.change(date, getDebt());
    }
}

void CreditAccount::settle(const Date& date) {
    double interest = acc.getSum(date) * rate;
    if (interest != 0)
        record(date, interest, "interest");
    if (date.getMonth() == 1)
        record(date, -fee, "annual fee");
    acc.reset(date, getDebt());
}

void CreditAccount::show() const {
    Account::show();
    std::cout << "\tAvailable credit:" << getAvailableCredit();
}
