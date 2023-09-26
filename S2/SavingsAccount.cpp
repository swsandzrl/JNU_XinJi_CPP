#include "SavingsAccount.h"

#include <iostream>
#include <cmath>

double SavingsAccount::total = 0; // ��̬���ݳ�Ա��ʼ��

SavingsAccount::SavingsAccount(int date, const std::string& id, double rate)
	: lastDate(date), balance(0), id(id), rate(rate), accumulation(0) {
	std::cout << date << "\t#" << id << " is created" << std::endl;
}

void SavingsAccount::record(int date, double amount) {
	accumulation = accumulate(date); // �����ۻ���Ϣ
	lastDate = date; // �����ϴβ�������
	amount = floor(amount * 100 + 0.5) / 100; // �Դ�ȡ������о�ȷ��С�������λ�Ĵ���
	balance += amount; // �����˻����
	std::cout << date << "\t" << id << "\t" << amount << "\t" << balance << std::endl;
}

double SavingsAccount::accumulate(int date) const {
	return accumulation + balance * (date - lastDate); // �����ۻ���Ϣ
}

std::string SavingsAccount::getId() const {
	return id; // ��ȡ�˻�ID
}

double SavingsAccount::getBalance() const {
	return balance; // ��ȡ�˻����
}

double SavingsAccount::getRate() const {
	return rate; // ��ȡ����
}

void SavingsAccount::deposit(int date, double amount) {
	record(date, amount); // ������
	total += amount; // �����ܽ��
}

void SavingsAccount::withdraw(int date, double amount) {
	if (amount > balance)
		std::cout << "Error: not enough money" << std::endl; // ���㣬�޷�ȡ��
	else {
		record(date, -amount); // ȡ�����
		total -= amount; // �����ܽ��
	}
}

void SavingsAccount::settle(int date) {
	double interest = accumulate(date) * rate / 365; // ����Ӧ�������Ϣ
	if (interest != 0)
		record(date, interest); // ������Ϣ
	accumulation = 0; // �����ۻ���Ϣ
}

void SavingsAccount::show() const {
	std::cout << "#" << id << "\tBalance:" << balance; // ��ʾ�˻���Ϣ
}

double SavingsAccount::getTotal() {
	return total; // ��ȡ�ܽ��
}