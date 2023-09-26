#pragma once

#include "Date.h"

class Accumulator { // 辅助计算利息的累加器
private:
	Date lastDate;
	double value; // 相当于balance
	double sum; // 相当于accumulation

public:
	Accumulator(const Date& date, double value);

	double getSum(const Date& date) const;
	void change(const Date& date, double value);
	void reset(const Date& date, double value);
};