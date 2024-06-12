#ifndef NEXT_DATA_HPP_
#define NEXT_DATA_HPP_
#include <iostream>

struct Date
{
    int day;
    int month;
    int year;
};

bool isLeapYear(int year);
Date nextDate1(Date today);
#endif // NEXT_DATA_HPP_