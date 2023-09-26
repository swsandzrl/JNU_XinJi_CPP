#include "Date.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <iostream>

int main() {
	Account* Accounts[3];
	int numAccounts = 0;

	Date date_created(2008, 11, 1);
	Account* a0 = new SavingsAccount(date_created, "User_1", 0.015);
	Accounts[numAccounts++] = a0;
	Account* a1 = new SavingsAccount(date_created, "User_2", 0.015);
	Accounts[numAccounts++] = a1;
	Account* a2 = new CreditAccount(date_created, "User_3", 10000, 0.0005, 50);
	Accounts[numAccounts++] = a2;

	a0->deposit(Date(2008, 11, 5), 5000, "Salary");
	a2->withdraw(Date(2008, 11, 15), 2000, "buy a cell");
	a1->deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
	a2->settle(Date(2008, 12, 1));
	a2->deposit(Date(2008, 12, 1), 2016, "repay the credit");
	a0->deposit(Date(2008, 12, 5), 5500, "Salary");
	a0->settle(Date(2009, 1, 1));
	a1->settle(Date(2009, 1, 1));
	a2->withdraw(Date(2009, 1, 1), 50, "annual Fee");

	std::cout << std::endl;

	for (int i = 0; i < numAccounts; i++) {
		Accounts[i]->show();
		std::cout << std::endl;
		delete Accounts[i]; // 释放动态分配的内存
	}

	std::cout << "Total:" << Account::getTotal() << std::endl;

	std::cout << std::endl;
	Date d1(2022, 6, 3);
	Date d2(2022, 7, 5);
	d1.show();
	std::cout << " and ";
	d2.show();
	if ((d2 - d1) == 0)                         // 如果是同一天。
		std::cout << " are the same day.";
	else if ((d2 - d1) == 1 || (d2 - d1) == -1) // 如果仅相差一天，用单数。
		std::cout << " are one day apart.";
	else                                        // 如果相差大于两天，用复数。
		std::cout << " are " << abs(d2 - d1) << " days apart.";
	std::cout << std::endl;

	return 0;
}