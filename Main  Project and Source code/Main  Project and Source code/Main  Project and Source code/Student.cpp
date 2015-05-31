// REGIST.CPP - Student class implementation.

#include "student.h"

Student::Student()
{
  SetStudentId(0);
  SetFirstName("NOT INIT");
  SetLastName("NOT INIT");
  results = new MyVector<Results>();
}

Student::Student(const Student &obj)
{
    results = new MyVector<Results>();
    Copy(obj);
}

Student::~Student()
{
    Clear();
}

        //-------------------- GETTERS --------------------//

const string Student::GetFirstName() const
{
    return fName;
}

const string Student::GetLastName() const
{
    return lName;
}

const unsigned Student::GetSize() const
{
  return results -> GetSize();
}

const long Student::GetStudentId() const
{
    return studentId;
}

const string Student::GetUnitId(unsigned i) const
{
    return (*results)[i].GetUnitId();
}

const unsigned Student::GetDay(unsigned i) const
{
    return (*results)[i].GetDay();
}

const string Student::GetMonth(unsigned i) const
{
    return (*results)[i].GetMonth();
}

const unsigned Student::GetYear(unsigned i) const
{
    return (*results)[i].GetYear();
}

const double Student::GetResult(unsigned i) const
{
    return (*results)[i].GetResult();
}

const unsigned Student::GetResultSemester(unsigned i) const
{
    return (*results)[i].GetSemester();
}

const unsigned Student::GetResultsSize() const
{
    return results -> GetSize();
}

    //------------------------- SETTERS ---------------------//

void Student::SetStudentId(long sId)
{
    studentId = sId;
}

void Student::SetFirstName(string first)
{
    fName = first;
}

void Student::SetLastName(string last)
{
    lName = last;
}

void Student::SetUnitId(unsigned i, string id)
{
    (*results)[i].SetUnitId(id);
}

void Student::SetResult(unsigned i, double res)
{
    (*results)[i].SetResult(res);
}

void Student::SetResultSemester(unsigned i, unsigned sem)
{
    (*results)[i].SetSemester(sem);
}

void Student::SetDay(unsigned i, unsigned day)
{
    (*results)[i].SetDay(day);
}

void Student::SetMonth(unsigned i, string month)
{
    (*results)[i].SetMonth(month);
}

void Student::SetYear(unsigned i, unsigned year)
{
    (*results)[i].SetYear(year);
}

    //--------------------- CALCULATIONS ---------------//

const double Student::CalculateGPA(BinaryTree<Unit> & units) const
{
    /*
     * Information on calculating a GPA according to this format can
     * be found at https://www.murdoch.edu.au/students/myinfo/GPA.html
     * this information was created by Murdoch University and is not
     * my own work.
     *
     */
    double totalCreditPoints; // Total Credit points
    double preDivisionTotal;  // Achievable Credit Points * GPA Value
    double GPA;               // The final GPA value

    preDivisionTotal = 0;   // Initialized to zero
    totalCreditPoints = 0;  // Initialized to zero

    for(unsigned i = 0; i < GetSize(); i++)
    {
        Unit searchUnit;
        searchUnit.SetId(GetUnitId(i));

        Unit helperUnit;
        helperUnit = units.Search(searchUnit);

        if(GetResult(i) >= 80) // HD
        {
            preDivisionTotal += helperUnit.GetCredits() * 4;
        }
        else if(GetResult(i) >= 70) // D
        {
            preDivisionTotal += helperUnit.GetCredits() * 3;
        }
        else if(GetResult(i) >= 60) // C
        {
            preDivisionTotal += helperUnit.GetCredits() * 2;
        }
        else if(GetResult(i) >= 50) // P
        {
            preDivisionTotal += helperUnit.GetCredits() * 1;
        }

        totalCreditPoints += helperUnit.GetCredits(); // Counts the total credits including fails
    }

    GPA = preDivisionTotal / totalCreditPoints;

    return GPA;
}

const unsigned Student::GetHighestMark() const
{
    unsigned highest = 0; // Initializes to lowest possible mark

    for(unsigned i = 0; i < GetSize(); i++)
    {
        if(highest < GetResult(i))
        {
            highest = GetResult(i);
        }
    }

    return highest;
}

const unsigned Student::GetLowestMark() const
{
    unsigned lowest = 101; // Above highest as it will never be reached

    for(unsigned i = 0; i < GetSize(); i++)
    {
        if(lowest > GetResult(i))
        {
            lowest = GetResult(i);
        }
    }

    return lowest;
}

    //--------------------- OTHERS ---------------------//

void Student::Clear()
{
  if(results != NULL)
  {
      delete results;
  }

  results = NULL;
}

void Student::Copy(const Student &obj)
{
    if(this != &obj)
    {
        delete results;
        results = new MyVector<Results>();

        SetStudentId(obj.GetStudentId());
        SetFirstName(obj.GetFirstName());
        SetLastName(obj.GetLastName());

        for(unsigned i = 0; i < obj.GetSize(); i++)
        {
            SetUnitId(i, obj.GetUnitId(i));
            SetResult(i, obj.GetResult(i));
            SetResultSemester(i, obj.GetResultSemester(i));
            SetDay(i, obj.GetDay(i));
            SetMonth(i, obj.GetMonth(i));
            SetYear(i, obj.GetYear(i));
        }

    }
}
