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
Date nextDateSimple(int month, int day, int year);
#endif // NEXT_DATA_HPP_