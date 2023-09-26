#pragma once

#include <string>

class SavingsAccount {
private:
	static double total; // ��̬���ݳ�Ա����¼�ܽ��
	std::string id; // �˻�ID
	double balance; // �˻����
	double rate; // ����
	int lastDate; // �ϴβ�������
	double accumulation; // �ۻ���Ϣ

	void record(int date, double amount); // ��¼����
	double accumulate(int date) const; // �����ۻ���Ϣ

public:
	SavingsAccount(int date, const std::string& id, double rate); // ���캯��
	std::string getId() const; // ��ȡ�˻�ID
	double getBalance() const; // ��ȡ�˻����
	double getRate() const; // ��ȡ����
	void deposit(int date, double amount); // ���
	void withdraw(int date, double amount); // ȡ��
	void settle(int date); // ������Ϣ
	void show() const; // ��ʾ�˻���Ϣ

	static double getTotal(); // ��ȡ�ܽ��ľ�̬��Ա����
};