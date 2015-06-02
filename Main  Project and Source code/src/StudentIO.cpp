#include "StudentIO.h"
#include <algorithm>
#include <fstream>
#include <cctype>
#include <stdlib.h>
#include "../Unit.h"
#include "../MyVector.h"

/* Default Constructor is not intended to do anything, but stop the compiler
 * from making a default constructor
 */
StudentIO::StudentIO() {}

StudentIO::StudentIO(string iFileName, string oFileName)
{
    SetIFileName(iFileName);
    SetOFileName(oFileName);
}

void StudentIO::GetHighestMarkOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const
{
    ofstream oFile(oFileName.c_str());

    for(unsigned i = 0; i < students[sId].GetSize(); i++)
    {
        if(students[sId].GetResult(i) == students[sId].GetHighestMark())
        {

            if(Student::SetUnit(students[sId].GetUnitId(i), units))
            {
                oFile << "Student ID: " << students[sId].GetStudentId()  << endl;
                oFile << "Surname   : " << students[sId].GetLastName()   << endl;
                oFile << "Unit code : " << students[sId].GetUnitId(i)    << endl;
                oFile << "Unit name : " << Student::GetUnitName()        << endl;
                oFile << "Unit mark : " << students[sId].GetResult(i)    << endl;
                oFile << "Date      : " << students[sId].GetDate(i)      << endl;
                oFile << endl;

                cout << "Student ID: " << students[sId].GetStudentId()  << endl;
                cout << "Surname   : " << students[sId].GetLastName()   << endl;
                cout << "Unit code : " << students[sId].GetUnitId(i)    << endl;
                cout << "Unit name : " << Student::GetUnitName()        << endl;
                cout << "Unit mark : " << students[sId].GetResult(i)    << endl;
                cout << "Date      : " << students[sId].GetDate(i)      << endl;
                cout << endl;
            }
            else
            {
                oFile << "Output Failed" << endl;
                oFile << endl;

                cout << "Output Failed" << endl;
                cout << endl;
            }
        }
    }

    oFile.close();
}

void StudentIO::GetLowestMarkOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const
{
    ofstream oFile(oFileName.c_str());

    for(unsigned i = 0; i < students[sId].GetSize(); i++)
    {
        if(students[sId].GetResult(i) == students[sId].GetLowestMark())
        {

            if(Student::SetUnit(students[sId].GetUnitId(i), units))
            {
                oFile << "Student ID: " << students[sId].GetStudentId()  << endl;
                oFile << "Surname   : " << students[sId].GetLastName()   << endl;
                oFile << "Unit code : " << students[sId].GetUnitId(i)    << endl;
                oFile << "Unit name : " << Student::GetUnitName()        << endl;
                oFile << "Unit mark : " << students[sId].GetResult(i)    << endl;
                oFile << "Date      : " << students[sId].GetDate(i)      << endl;
                oFile << endl;

                cout << "Student ID: " << students[sId].GetStudentId()  << endl;
                cout << "Surname   : " << students[sId].GetLastName()   << endl;
                cout << "Unit code : " << students[sId].GetUnitId(i)    << endl;
                cout << "Unit name : " << Student::GetUnitName()        << endl;
                cout << "Unit mark : " << students[sId].GetResult(i)    << endl;
                cout << "Date      : " << students[sId].GetDate(i)      << endl;
                cout << endl;
            }
            else
            {
                oFile << "Output Failed" << endl;
                oFile << endl;

                cout << "Output Failed" << endl;
                cout << endl;
            }
        }
    }

    oFile.close();
}

void StudentIO::GetGPACalcOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const
{
    ofstream oFile(oFileName.c_str());

    oFile << "Student ID: " << students[sId].GetStudentId()         << endl;
    oFile << "Surname   : " << students[sId].GetLastName()          << endl;
    oFile << "GPA       : " << students[sId].CalculateGPA(units)    << endl;
    oFile << endl;

    cout << "Student ID: " << students[sId].GetStudentId()         << endl;
    cout << "Surname   : " << students[sId].GetLastName()          << endl;
    cout << "GPA       : " << students[sId].CalculateGPA(units)    << endl;
    cout << endl;

    oFile.close();
}

void StudentIO::GetHighestLowest(map<long, Student> & students, BinaryTree<Unit> & units)
{
    double highest = -1;
    double lowest  = 4.00;


        /* Vectors are declared so if there exists more than one
            student with the highest or lowest GPA they can be recorded
            in a large class body this is a possibility, without this function
            the output of this program would not be accurate */

    MyVector<string> hnames;
    MyVector<long>   hsids;
    MyVector<string> lnames;
    MyVector<long>   lsids;

    map<long, Student>::iterator it; // iterator for map

    for(it = students.begin(); it != students.end(); ++it)
    {
        double gpa = it -> second.CalculateGPA(units);

        HighestGPA(hnames, hsids, highest, it -> second, gpa);
        LowestGPA(lnames, lsids, lowest, it -> second, gpa);
    }

    HighestLowestOutput(lnames, hnames, lsids, hsids, lowest, highest);
}

void StudentIO::HighestGPA(MyVector<string> & hnames, MyVector<long> & hsids, double & highest, const Student & check, double gpa)
{
    if(gpa > highest)
    {
        hnames.Clear();
        hsids.Clear();

        highest = gpa;

        hsids[hsids.GetSize()] = check.GetStudentId();
        hnames[hnames.GetSize()] = check.GetLastName();
    }
    else if(gpa == highest) // Checks for if more than one student has the highest GPA
    {
        hsids[hsids.GetSize()] = check.GetStudentId();
        hnames[hnames.GetSize()] = check.GetLastName();
    }

}

void StudentIO::LowestGPA(MyVector<string> & lnames, MyVector<long> & lsids, double & lowest, const Student & check, double gpa)
{
        if(gpa < lowest)
        {
            lsids.Clear();
            lnames.Clear();

            lowest = gpa;

            lsids[lsids.GetSize()] = check.GetStudentId();
            lnames[lnames.GetSize()] = check.GetLastName();
        }
        else if(gpa == lowest) // CHecks for if more than one student has the lowest GPA
        {
            lsids[lsids.GetSize()] = check.GetStudentId();
            lnames[lnames.GetSize()] = check.GetLastName();
        }
}

void StudentIO::HighestLowestOutput(MyVector<string> & lnames, MyVector<string> & hnames,
                         MyVector<long> & lSid, MyVector<long> & hSid,
                         double lowest, double highest)
{
    ofstream oFile(oFileName.c_str());

    cout  << "Highest GPA: **" << highest << "**" << endl;
    oFile << "Highest GPA: **" << highest << "**" << endl;


        /* Students with the highest GPA */
    for(unsigned i = 0; i < hnames.GetSize(); i++)
    {
        cout << "Student ID: " << hSid[i] << endl;
        cout << "Surname: "    << hnames[i] << endl;
        cout << endl;

        oFile << "Student ID: " << hSid[i] << endl;
        oFile << "Surname: "    << hnames[i] << endl;
        oFile << endl;
    }

    cout  << "Lowest GPA: **" << lowest << "**" << endl;
    oFile << "Lowest GPA: **" << lowest << "**" << endl;

        /*Students with the highest GPA */
    for(unsigned i = 0; i <lnames.GetSize(); i++)
    {
        cout << "Student ID: " << lSid[i] << endl;
        cout << "Surname: "    << lnames[i] << endl;
        cout << endl;

        oFile << "Student ID: " << lSid[i] << endl;
        oFile << "Surname: "    << lnames[i] << endl;
        oFile << endl;
    }
}

void StudentIO::SetIFileName(string inf)
{
    iFileName = inf;
}

void StudentIO::SetOFileName(string of)
{
    oFileName = of;
}

void StudentIO::InitialiseIO(map<long, Student> & students, BinaryTree<Unit> & units)
{
    ifstream inFile(iFileName.c_str());
    if(!inFile)
    {
        throw -1;
    }

    string sId;      // Student Id
    string firstN;   // First name
    string lastN;    // Last name
    string sem;      // Semester
    string name;     // unit name
    string id;       // id for units
    string credits;  // number of credits
    string result;   // results for a unit but goes to Result class
    string day;      // day from date
    string month;    // month from date
    string year;     // year from date
    long sIdL;       // long sId as key
    unsigned i = 0;  // iterator

    while(getline(inFile, sId, ','))
    {
        /*
         * For type casting all strings have been converted
         * to a c string and then to their appropriate data
         * type.
         */
        getline(inFile, firstN, ',');
        getline(inFile, lastN, ',');
        getline(inFile, sem, ',');
        getline(inFile, id, ',');
        getline(inFile, name, ',');
        getline(inFile, credits, ',');
        getline(inFile, result, ',');
        getline(inFile, day, '/');
        getline(inFile, month, '/');
        getline(inFile, year);

        sId     = EraseNewLine(sId);
        sIdL    = atol(sId.c_str());
        firstN  = EraseNewLine(firstN);
        lastN   = EraseNewLine(lastN);
        sem     = EraseNewLine(sem);
        id      = EraseNewLine(id);
        name    = EraseNewLine(name);
        credits = EraseNewLine(credits);
        result  = EraseNewLine(result);
        day     = EraseNewLine(day);
        month   = EraseNewLine(month);
        year    = EraseNewLine(year);

        if(!sId.empty())
        {
            i = students[sIdL].GetSize();

            if(!(students.find(sIdL) == students.end())) // Only needs to be taken in once, therefore only set once
            {
                students[sIdL].SetStudentId(sIdL);
                students[sIdL].SetFirstName(firstN);
                students[sIdL].SetLastName(lastN);
            }

            Unit newUnit;
            newUnit.SetId(id);
            newUnit.SetName(name);
            newUnit.SetCredits(atol(credits.c_str()));

            units.Insert(newUnit);

            students[sIdL].SetUnitId(i, id);
            students[sIdL].SetResult(i, atol(result.c_str()));
            students[sIdL].SetResultSemester(i, atol(sem.c_str()));
            students[sIdL].SetDay(i, atol(day.c_str()));
            students[sIdL].SetMonth(i, atol(month.c_str()));
            students[sIdL].SetYear(i, atol(year.c_str()));

        }
    }

    inFile.close();
}

string StudentIO::EraseNewLine(string input)
{
    // remove new line character
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());
    // remove carriage return character
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());

    // Removes whitespace at the beginning in the string
    input.erase(input.begin(), find_if(input.begin(), input.end(), bind1st(not_equal_to<char>(), ' ')));
    //  Removes whitespace at the end of a string
    input.erase(find_if(input.rbegin(), input.rend(), bind1st(not_equal_to<char>(), ' ')).base(), input.end());

    return input;
}
