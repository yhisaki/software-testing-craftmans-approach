#include "next_date.hpp"
#include <stdexcept>

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

Date nextDateSimple(int month, int day, int year)
{
    Date tomorrow = {day, month, year};

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (day < 31)
        {
            tomorrow.day = day + 1;
        }
        else
        {
            tomorrow.day = 1;
            tomorrow.month = month + 1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day < 30)
        {
            tomorrow.day = day + 1;
        }
        else
        {
            tomorrow.day = 1;
            tomorrow.month = month + 1;
        }
        break;
    case 12:
        if (day < 31)
        {
            tomorrow.day = day + 1;
        }
        else
        {
            tomorrow.day = 1;
            tomorrow.month = 1;
            if (year == 2012)
            {
                throw std::out_of_range("2012 is over");
            }
            else
            {
                tomorrow.year = year + 1;
            }
        }
        break;
    case 2:
        if (day < 28)
        {
            tomorrow.day = day + 1;
        }
        else if (day == 28)
        {
            if (isLeapYear(year))
            {
                tomorrow.day = 29;
            }
            else
            {
                tomorrow.day = 1;
                tomorrow.month = 3;
            }
        }
        else if (day == 29)
        {
            if (isLeapYear(year))
            {
                tomorrow.day = 1;
                tomorrow.month = 3;
            }
            else
            {
                std::out_of_range("Day out of range");
            }
        }
        break;
    }
    return tomorrow;
}
