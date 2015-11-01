#include "results.h"
#include <iostream>

Results::Results()
{
    SetResult(0);
    SetSemester(0);
    SetUnitId("NULL");
}

        //------------------- SET METHODS ------------------------

void Results::SetSemester(unsigned sem)
{
    semester = sem;
}

void Results::SetResult(unsigned res)
{
    result = res;
}

void Results::SetUnitId(string id)
{
    unitId = id;
}


void Results::SetDay(unsigned day)
{
    aDate.SetDay(day);
}

void Results::SetMonth(unsigned month)
{
    aDate.SetMonth(month);
}

void Results::SetYear(unsigned year)
{
    aDate.SetYear(year);
}

        //------------------- GET METHODS ------------------------

const unsigned Results::GetResult() const
{
    return result;
}

const unsigned Results::GetSemester() const
{
    return semester;
}

const string Results::GetUnitId() const
{
    return unitId;
}

const unsigned Results::GetDay() const
{
    return aDate.GetDay();
}

const unsigned Results::GetMonth() const
{
    return aDate.GetMonth();
}

const unsigned Results::GetYear() const
{
    return aDate.GetYear();
}

const string Results::GetDate() const
{
    return aDate.GetDate();
}
