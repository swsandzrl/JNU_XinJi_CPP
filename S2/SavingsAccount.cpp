#include "SavingsAccount.h"

#include <iostream>
#include <cmath>

double SavingsAccount::total = 0; // 静态数据成员初始化

SavingsAccount::SavingsAccount(int date, const std::string& id, double rate)
	: lastDate(date), balance(0), id(id), rate(rate), accumulation(0) {
	std::cout << date << "\t#" << id << " is created" << std::endl;
}

void SavingsAccount::record(int date, double amount) {
	accumulation = accumulate(date); // 更新累积利息
	lastDate = date; // 更新上次操作日期
	amount = floor(amount * 100 + 0.5) / 100; // 对存取款金额进行精确到小数点后两位的处理
	balance += amount; // 更新账户余额
	std::cout << date << "\t" << id << "\t" << amount << "\t" << balance << std::endl;
}

double SavingsAccount::accumulate(int date) const {
	return accumulation + balance * (date - lastDate); // 计算累积利息
}

std::string SavingsAccount::getId() const {
	return id; // 获取账户ID
}

double SavingsAccount::getBalance() const {
	return balance; // 获取账户余额
}

double SavingsAccount::getRate() const {
	return rate; // 获取利率
}

void SavingsAccount::deposit(int date, double amount) {
	record(date, amount); // 存款操作
	total += amount; // 更新总金额
}

void SavingsAccount::withdraw(int date, double amount) {
	if (amount > balance)
		std::cout << "Error: not enough money" << std::endl; // 余额不足，无法取款
	else {
		record(date, -amount); // 取款操作
		total -= amount; // 更新总金额
	}
}

void SavingsAccount::settle(int date) {
	double interest = accumulate(date) * rate / 365; // 计算应结算的利息
	if (interest != 0)
		record(date, interest); // 结算利息
	accumulation = 0; // 重置累积利息
}

void SavingsAccount::show() const {
	std::cout << "#" << id << "\tBalance:" << balance; // 显示账户信息
}

double SavingsAccount::getTotal() {
	return total; // 获取总金额
}