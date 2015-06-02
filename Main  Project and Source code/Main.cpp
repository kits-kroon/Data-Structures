#include <cstdlib>
#include <iostream>
#include <string>
#include "include\StudentIO.h"
#include <map>
#include <sstream>
#include "include\BinaryTree.h"
#include "unit.h"

using namespace std;

void PrintMenu(); // prototype the method it can be used in main
long GetInput();

int main()
{
    string uInput; // User input
    bool flag = true;    // Loops through options
    long sId = 0; // input of student id

    map<long, Student> students;
    BinaryTree<Unit> unitTree;

    try
    {
        StudentIO io("students.csv", "outdata.txt");
        io.InitialiseIO(students, unitTree);

        PrintMenu(); // Prints the menu for the user

        while(flag)
        {
            cout << "Please enter your choice of input: " << endl;
            cin >> uInput;
            cout << endl;

            switch(atoi(uInput.c_str())) //converts string to c string then to integer
            {
                case 1: // Print highest mark to the screen and output to file
                    sId = GetInput();
                    if(!(students.find(sId) == students.end()))
                    {
                        io.GetHighestMarkOutput(sId, students, unitTree);
                    }
                    else
                    {
                        cout << "Student not found" << endl << endl;
                    }
                    break;
                case 2: // Print lowest mark to screen and output file
                    sId = GetInput();
                    if(!(students.find(sId) == students.end()))
                    {
                        io.GetLowestMarkOutput(sId, students, unitTree);
                    }
                    else
                    {
                        cout << "Student not found" << endl << endl;
                    }
                    break;
                case 3: // Print GPA to screen
                    sId = GetInput();
                    if(!(students.find(sId) == students.end()))
                    {
                        io.GetGPACalcOutput(sId, students, unitTree);
                    }
                    else
                    {
                        cout << "Student not found" << endl << endl;
                    }
                    break;
                case 4: // Exit the program
                    flag = false;
                    cout << "Thank you for using my program " << endl;
                    break;
                default: // Bad input,
                    cout << "You have not entered one of the correct options" << endl;
                    cout << "Please scroll up and review them               " << endl;
                    break;
            }
        }

    }
    catch(exception x)
    {
      cout << "Please check that the file 'rinput.csv' exists" << endl;
    }

    return 0;
}

void PrintMenu()
{
      cout << "**************************************************" << endl;
      cout << "*                                                *" << endl;
      cout << "*  Student Data Output Program                   *" << endl;
      cout << "*                                                *" << endl;
      cout << "*  - Enter 1 to get the unit(s) that the student *" << endl;
      cout << "*    has achieved the highest grade in and write *" << endl;
      cout << "*    data to 'outputdata.txt'                    *" << endl;
      cout << "*  - Enter 2 to get the unit(s) that the student *" << endl;
      cout << "*    has achieved the lowest grade in and write  *" << endl;
      cout << "*    data to 'outputdata.txt'                    *" << endl;
      cout << "*  - Enter 3 to get the GPA of the student       *" << endl;
      cout << "*  - Enter 4 to quit                             *" << endl;
      cout << "*                                                *" << endl;
      cout << "**************************************************" << endl;
      cout << endl;
}

long GetInput()
{
    long studentId = 0;
    bool flag = false;
    char junk;

    do
    {
        cout << "Please enter a studentId" << endl;
        cin.ignore();

        string line;
        getline(cin, line);
        stringstream linestream(line);

        if(!(linestream >> studentId))
            continue;

        if(linestream >> junk)
            continue;

        cout << endl;

        return studentId;

    } while(!flag);

    return studentId;
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
