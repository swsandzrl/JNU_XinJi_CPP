#pragma once

class Date {
private:
    int year;
    int month;
    int day;
    int totalDays;

public:
    Date(int year, int month, int day);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getMaxDay() const;
    bool isLeapYear() const;
    void show() const;
    int distance(const Date& date) const;
};