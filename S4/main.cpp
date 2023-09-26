#include "Date.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <iostream>

int main() {
	// 双指针数组方案
	const int MAX_ACCOUNTS = 1000; // 最大账户数量
	SavingsAccount* savingsAccounts[MAX_ACCOUNTS]; // 储蓄账户数组
	CreditAccount* creditAccounts[MAX_ACCOUNTS]; // 信用账户数组
	int numSavingsAccounts = 0; // 当前储蓄账户数量
	int numCreditAccounts = 0; // 当前信用账户数量

	Date date_created(2008, 11, 1);
	SavingsAccount* sa1 = new SavingsAccount(date_created, "User_1", 0.015);
	savingsAccounts[numSavingsAccounts++] = sa1;
	SavingsAccount* sa2 = new SavingsAccount(date_created, "User_2", 0.015);
	savingsAccounts[numSavingsAccounts++] = sa2;
	CreditAccount* ca1 = new CreditAccount(date_created, "User_3", 10000, 0.0005, 50);
	creditAccounts[numCreditAccounts++] = ca1;

	sa1->deposit(Date(2008, 11, 5), 5000, "Salary");
	ca1->withdraw(Date(2008, 11, 15), 2000, "buy a cell");
	sa2->deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
	ca1->settle(Date(2008, 12, 1));
	ca1->deposit(Date(2008, 12, 1), 2016, "repay the credit");
	sa1->deposit(Date(2008, 12, 5), 5500, "Salary");
	sa1->settle(Date(2009, 1, 1));
	sa2->settle(Date(2009, 1, 1));
	ca1->withdraw(Date(2009, 1, 1), 50, "annual Fee");

	std::cout << std::endl;

	for (int i = 0; i < numSavingsAccounts; i++) {
		savingsAccounts[i]->show();
		std::cout << std::endl;
	}
	for (int i = 0; i < numCreditAccounts; i++) {
		creditAccounts[i]->show();
		std::cout << std::endl;
	}

	std::cout << "Total:" << Account::getTotal() << std::endl;

	// 释放动态分配的内存
	for (int i = 0; i < numSavingsAccounts; i++) {
		delete savingsAccounts[i];
	}
	for (int i = 0; i < numCreditAccounts; i++) {
		delete creditAccounts[i];
	}

	return 0;
}