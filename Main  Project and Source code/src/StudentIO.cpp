#include "StudentIO.h"
#include <algorithm>
#include <fstream>
#include <cctype>
#include <stdlib.h>
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
            Unit searchUnit;
            searchUnit.SetId(students[sId].GetUnitId(i));

            Unit unitHelper = units.Search(searchUnit);

            oFile << "Student ID: " << students[sId].GetStudentId()  << endl;
            oFile << "Surname   : " << students[sId].GetLastName()   << endl;
            oFile << "Unit code : " << students[sId].GetUnitId(i)    << endl;
            oFile << "Unit name : " << unitHelper.GetName()          << endl;
            oFile << "Unit mark : " << students[sId].GetResult(i)    << endl;
            oFile << "Date      : " << students[sId].GetDay(i) << "/";
            oFile << students[sId].GetMonth(i) << "/" << students[sId].GetYear(i) << endl;
            oFile << endl;

            cout << "Student ID: " << students[sId].GetStudentId()  << endl;
            cout << "Surname   : " << students[sId].GetLastName()   << endl;
            cout << "Unit code : " << students[sId].GetUnitId(i)    << endl;
            cout << "Unit name : " << unitHelper.GetName()          << endl;
            cout << "Unit mark : " << students[sId].GetResult(i)    << endl;
            cout << "Date      : " << students[sId].GetDay(i) << "/";
            cout << students[sId].GetMonth(i) << "/" << students[sId].GetYear(i) << endl;
            cout << endl;
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

            Unit searchUnit;
            searchUnit.SetId(students[sId].GetUnitId(i));

            Unit unitHelper = units.Search(searchUnit);

            oFile << "Student ID: " << students[sId].GetStudentId()  << endl;
            oFile << "Surname   : " << students[sId].GetLastName()   << endl;
            oFile << "Unit code : " << students[sId].GetUnitId(i)    << endl;
            oFile << "Unit name : " << unitHelper.GetName()          << endl;
            oFile << "Unit mark : " << students[sId].GetResult(i)    << endl;
            oFile << "Date      : " << students[sId].GetDay(i) << "/";
            oFile << students[sId].GetMonth(i) << "/" << students[sId].GetYear(i) << endl;
            oFile << endl;

            cout << "Student ID: " << students[sId].GetStudentId()  << endl;
            cout << "Surname   : " << students[sId].GetLastName()   << endl;
            cout << "Unit code : " << students[sId].GetUnitId(i)    << endl;
            cout << "Unit name : " << unitHelper.GetName()          << endl;
            cout << "Unit mark : " << students[sId].GetResult(i)    << endl;
            cout << "Date      : " << students[sId].GetDay(i) << "/";
            cout << students[sId].GetMonth(i) << "/" << students[sId].GetYear(i) << endl;
            cout << endl;
        }
    }

    oFile.close();
}

void StudentIO::GetGPACalcOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const
{
    cout << "Student ID: " << students[sId].GetStudentId()         << endl;
    cout << "Surname   : " << students[sId].GetLastName()          << endl;
    cout << "GPA       : " << students[sId].CalculateGPA(units)    << endl;
    cout << endl;
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
            students[sIdL].SetMonth(i, month);
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
