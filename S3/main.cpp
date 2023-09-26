#include "SavingsAccount.h"
#include "Date.h"
#include <iostream>

int main()
{
    const int numAccounts = 2;
    SavingsAccount sa[numAccounts] = {
        SavingsAccount(Date(2008, 11, 1), "User_1", 0.015),
        SavingsAccount(Date(2008, 11, 1), "User_2", 0.015)
    };

    sa[0].deposit(Date(2008, 11, 5), 5000, "salary");
    sa[1].deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
    sa[0].deposit(Date(2008, 12, 5), 5500, "salary");
    sa[1].withdraw(Date(2008, 12, 20), 4000, "nuy a laplop");

    std::cout << std::endl;
    for (int i = 0; i < numAccounts; i++) {
    sa[i].settle(Date(2009, 1, 1));
    sa[i].show();
    };
   
    std::cout << "Total:" << SavingsAccount::getTotal() << std::endl;

    return 0;
}