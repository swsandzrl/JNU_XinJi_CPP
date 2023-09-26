#include "Date.h"
#include <iostream>

const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    int years = year - 1;
    totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
    if (isLeapYear() && month > 2)
        totalDays++;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::distance(const Date& date) const {
    return totalDays - date.totalDays;
}

bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::getMaxDay() const {
    if (isLeapYear() && month == 2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

void Date::show() const {
    std::cout << year << "-" << month << "-" << day;
}
