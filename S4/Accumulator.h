#pragma once

#include "Date.h"

class Accumulator { // ����������Ϣ���ۼ���
private:
	Date lastDate;
	double value; // �൱��balance
	double sum; // �൱��accumulation

public:
	Accumulator(const Date& date, double value);

	double getSum(const Date& date) const;
	void change(const Date& date, double value);
	void reset(const Date& date, double value);
};