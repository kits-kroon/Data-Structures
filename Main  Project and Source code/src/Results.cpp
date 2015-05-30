#include "../include/results.h"

Results::Results()
{
    SetResult(0);
    SetSemester(0);
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

void Results::SetUnitName(string name)
{
    aUnit.SetName(name);
}

void Results::SetUnitId(string id)
{
    aUnit.SetId(id);
}

void Results::SetUnitCredits(unsigned cred)
{
    aUnit.SetCredits(cred);
}

void Results::SetDay(unsigned day)
{
    aDate.SetDay(day);
}

void Results::SetMonth(string month)
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

const string Results::GetUnitName() const
{
    return aUnit.GetName();
}

const string Results::GetUnitId() const
{
    return aUnit.GetId();
}

const unsigned Results::GetUnitCredits() const
{
    return aUnit.GetCredits();
}

const unsigned Results::GetDay() const
{
    return aDate.GetDay();
}

const string Results::GetMonth() const
{
    return aDate.GetMonth();
}

const unsigned Results::GetYear() const
{
    return aDate.GetYear();
}
