#include "Date.h"
#include <sstream>

Date::Date()
{
    SetDay(0);
    SetMonth(0);
    SetYear(0);
}

void Date::SetDay(unsigned d)
{
    day = d;
}

void Date::SetMonth(unsigned mon)
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

const unsigned Date::GetMonth() const
{
    return month;
}

const unsigned Date::GetYear() const
{
    return year;
}

const string Date::GetDate() const
{
    string date;
    stringstream ss; // used for clean conversion of unsigned to string

    if(day < 10)
    {
        ss <<  "0" << day << "/";
    }
    else
    {
        ss << day << "/";
    }

    if(month < 10)
    {
        ss << "0" << month << "/";
    }
    else
    {
        ss << month << "/";
    }

    if(year < 10)
    {
        ss << "000" << year;
    }
    else if(year < 100)
    {
        ss << "00" << year;
    }
    else if (year < 1000)
    {
        ss << "0" << year;
    }
    else
    {
        ss << year;
    }

    date = ss.str(); // convert stringstream to string

    return date;
}
