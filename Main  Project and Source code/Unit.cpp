// COURSE.CPP - Course class implementation

#include "unit.h"
#include <iostream>

Unit::Unit()
{
  SetName("NO_INPUT");
  SetId("NO_INPUT");
  SetCredits(0);
}

//---------------------- GET METHODS ---------------------------

const unsigned Unit::GetCredits() const
{
    return credits;
}

const string Unit::GetName() const
{
    return name;
}

const string Unit::GetId() const
{
    return id;
}

//---------------------- SET METHODS ---------------------------

void Unit::SetCredits( unsigned cred )
{
  credits = cred;
}

void Unit::SetName(string nam)
{
  name = nam;
}

void Unit::SetId(string nId)
{
  id = nId;
}

bool operator < (const Unit & lhs, const Unit & rhs)
{
    int compareInt; // Integer produced by compare
    compareInt = (lhs.GetId()).compare(rhs.GetId());

    if(compareInt <= 0)
    {
        return false; // lhs is greater than or equal to rhs
    }

    return true; // ID is less than rhs
}

bool operator == (const Unit & lhs, const Unit & rhs)
{
    if(lhs.GetId().compare(rhs.GetId()) == 0)
    {
        return true;
    }

    return false;
}
