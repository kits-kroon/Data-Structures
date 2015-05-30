#include "Date.h"

Date::Date()
{
    SetDay(0);
    SetMonth("NO_INPUT");
    SetYear(0);
}

void Date::SetDay(unsigned d)
{
    day = d;
}

void Date::SetMonth(string mon)
{
    month = mon;
}

void Date::SetYear(unsigned yr)
{
    year = yr;
}

const unsigned Date::GetDay() const
{
    return day;
}

const string Date::GetMonth() const
{
    return month;
}

const unsigned Date::GetYear() const
{
    return year;
}
