#pragma once

#include <string>

class SavingsAccount {
private:
	static double total; // 静态数据成员，记录总金额
	std::string id; // 账户ID
	double balance; // 账户余额
	double rate; // 利率
	int lastDate; // 上次操作日期
	double accumulation; // 累积利息

	void record(int date, double amount); // 记录操作
	double accumulate(int date) const; // 计算累积利息

public:
	SavingsAccount(int date, const std::string& id, double rate); // 构造函数
	std::string getId() const; // 获取账户ID
	double getBalance() const; // 获取账户余额
	double getRate() const; // 获取利率
	void deposit(int date, double amount); // 存款
	void withdraw(int date, double amount); // 取款
	void settle(int date); // 结算利息
	void show() const; // 显示账户信息

	static double getTotal(); // 获取总金额的静态成员函数
};