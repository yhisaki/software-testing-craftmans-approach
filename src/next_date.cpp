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

Date nextDate1(Date today)
{
    Date tomorrow = {today.day, today.month, today.year};

    switch (today.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (today.day < 31)
        {
            tomorrow.day = today.day + 1;
        }
        else if (today.day == 31)
        {
            tomorrow.day = 1;
            tomorrow.month = today.month + 1;
        }
        else
        {
            throw std::out_of_range("Cannot have 31 days in a month");
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (today.day < 30)
        {
            tomorrow.day = today.day + 1;
        }
        else if (today.day == 30)
        {
            tomorrow.day = 1;
            tomorrow.month = today.month + 1;
        }
        else if (today.day == 31)
        {
            throw std::out_of_range("Cannot have 30 days in a month");
        }
        else
        {
            throw std::out_of_range("Cannot have 31 days in a month");
        }
        break;
    case 12:
        if (today.day < 31)
        {
            tomorrow.day = today.day + 1;
        }
        else if (today.day == 31)
        {
            tomorrow.day = 1;
            tomorrow.month = 1;

            tomorrow.year = today.year + 1;
        }
        else
        {
            throw std::out_of_range("Cannot have 31 days in a month");
        }
        break;
    case 2:
        if (today.day < 28)
        {
            tomorrow.day = today.day + 1;
        }
        else if (today.day == 28)
        {
            if (isLeapYear(today.year))
            {
                tomorrow.day = 29;
            }
            else
            {
                tomorrow.day = 1;
                tomorrow.month = 3;
            }
        }
        else if (today.day == 29)
        {
            if (isLeapYear(today.year))
            {
                tomorrow.day = 1;
                tomorrow.month = 3;
            }
            else
            {
                throw std::out_of_range("Cannot have Feb 29 in a non-leap year");
            }
        }
        else
        {
            throw std::out_of_range("Cannot have 30 days in Feb");
        }
        break;
    }

    return tomorrow;
}