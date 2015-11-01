#include <iostream>
#include <fstream>
#include <cstdlib>
#include "unit.h"
#include "date.h"
#include "results.h"
#include "student.h"
#include "myvector.h"
#include "binarytree.h"
#include "studentio.h"

using namespace std;

void TestUnit();
void TestDate();
void TestResult();
void TestMyVector();
void TestTree();
void TestStudent();
void PrintUnit(const Unit & unit);
void PrintData(const int & i);
void IntTreeTest();
void TestStudentIO();

int main()
{
    //TestUnit();
    //TestDate();
    //TestResult();
    //TestMyVector();
    //TestTree();
    //IntTreeTest();
    //TestStudent();
    TestStudentIO();

    return 0;
}

void TestUnit()
{
    cout << "Test Unit" << endl << endl;

         //------------- TEST UNIT CLASS -------------//

    Unit u; // Initialise with default constructor

    cout << u.GetName() << endl;
    cout << u.GetId() << endl;
    cout << u.GetCredits() << endl;
    cout << endl;

        //------------- NORMAL INPUT ----------------//

    u.SetCredits(3);
    u.SetName("Data Structures and Abstractions");
    u.SetId("ICT283");

        //------------- NORMAL OUTPUT --------------//

    cout << "Normal Output" << endl;

    if(u.GetCredits() == 3)
        cout << "PASSED: " << u.GetCredits() << endl;

    if(u.GetName() == "Data Structures and Abstractions")
        cout << "PASSED: " << u.GetName() << endl;

    if(u.GetId() == "ICT283")
        cout << "PASSED: " << u.GetId() << endl;

    cout << endl;

        //------------ BOUNDARIES -------------//
    cout << "Boundaries" << endl;
    cout << "SetCredits(-1)" << endl;
    u.SetCredits(-1);
    cout << "Output = " << u.GetCredits() << endl;

    cout << "SetCredits(65536)" << endl;
    u.SetCredits(65536);
    cout << "Output = " << u.GetCredits() << endl;

    Unit u2 = u;

    cout << u2.GetId()      << endl;
    cout << u2.GetCredits() << endl;
    cout << u2.GetName()    << endl;

    cout << endl;
}

void TestDate()
{
    cout << "Test Date" << endl << endl;

    Date d;

    cout << d.GetDay() << endl;
    cout << d.GetMonth() << endl;
    cout << d.GetYear() << endl;
    cout << endl;

         //------------- NORMAL INPUT ----------------//
    d.SetDay(1);
    d.SetMonth(1);
    d.SetYear(2015);

        //-------------- NORMAL OUTPUT ---------------//
    cout << "Normal Output" << endl;
    if(d.GetDay() == 1)
        cout << "PASSED: " << d.GetDay() << endl;

    if(d.GetMonth() == 1)
        cout << "PASSED: " << d.GetMonth() << endl;

    if(d.GetYear() == 2015)
        cout << "PASSED: " << d.GetYear() << endl;

    cout << endl;

        //------------ BOUNDARIES -------------//
    cout << "Boundaries" << endl;
    cout << "SetDay(-1)" << endl;
    d.SetDay(-1);
    cout << "output = " << d.GetDay() << endl;

    cout << "GetYear(-1)" << endl;
    d.SetYear(-1);
    cout << "output = " << d.GetYear() << endl;

    cout << endl;

    cout << "SetDay(65536)" << endl;
    d.SetDay(65536);
    cout << "ouput = " << d.GetDay() << endl;

    cout << "SetYear(65536)" << endl;
    d.SetYear(65536);
    cout << "output = " << d.GetYear() << endl;

    cout << endl;
}

void TestResult()
{
    cout << "Test Result" << endl;

    Results r;

    cout << r.GetResult() << endl;
    cout << r.GetSemester() << endl;

           //------------- NORMAL INPUT ----------------//

    r.SetResult(90);
    r.SetSemester(2);
    r.SetUnitId("ICT283");
    r.SetDay(1);
    r.SetMonth(1);
    r.SetYear(2015);

        //-------------- NORMAL OUTPUT ---------------//
    cout << "Normal Output" << endl;
    if(r.GetResult() == 90)
        cout << "PASSED: " << r.GetResult() << endl;

    if(r.GetSemester() == 2)
        cout << "PASSED: " << r.GetSemester() << endl;

    if(r.GetUnitId() == "ICT283")
        cout << "PASSED: " << r.GetUnitId() << endl;

    if(r.GetDay() == 1)
        cout << "PASSED: " << r.GetDay() << endl;

    if(r.GetMonth() == 1)
        cout << "PASSED: " << r.GetMonth() << endl;

    if(r.GetYear() == 2015)
        cout << "PASSED: " << r.GetYear() << endl;

    cout << endl;

         //------------ BOUNDARIES -------------//

    cout << "Boundaries" << endl;

    cout << "SetResult(0.0000000000000000013)" << endl;
    r.SetResult(0.0000000000000000013);
    cout << "output = " << r.GetResult() << endl;

    cout << "SetSemester()" << endl;
    r.SetSemester(-1);
    cout << "output = " << r.GetSemester() << endl;

    cout << "SetYear(-1)" << endl;
    r.SetYear(-1);
    cout << "output = " << r.GetYear() << endl;

    cout << "SetResult(111111111111111111)" << endl;
    r.SetResult(11111111111);
    cout << "output = " << r.GetResult() << endl;

    cout << "SetSemester(65536)" << endl;
    r.SetSemester(65536);
    cout << "output = " << r.GetSemester() << endl;

    cout << "SetYear(65536)" << endl;
    r.SetYear(65536);
    cout << "output = " << r.GetYear() << endl;

    cout << endl;
}

void TestMyVector()
{
    cout << "Vector Test" << endl << endl;

    MyVector<unsigned> *vec;
    vec = new MyVector<unsigned>();

    cout << "Test Vector with Integers and default constructor" << endl;

    cout << "Range is 0 - 3000" << endl;

    for(unsigned i = 0; i <= 3000; i++)
    {
        (*vec)[i] = i;
    }

    cout << "Get size:  " << vec -> GetSize() << endl;
    cout << "First index:" << (*vec)[0] << endl;
    cout << "Last index:" << (*vec)[vec -> GetSize() - 1] << endl;

    cout << endl;

    cout << "Copy constructor" << endl;

    MyVector<unsigned> *vec2;
    vec2 = new MyVector<unsigned>(*vec);

    cout << "Get size:  " << vec2 -> GetSize() << endl;
    cout << "First index:" << (*vec2)[0] << endl;
    cout << "Last index:" << (*vec2)[vec2 -> GetSize() - 1] << endl;
    cout << endl;

    if(vec2 != vec)
        cout << "OBJECT ADDRESS NOT SAME PASSED" << endl;

    cout << endl;

    delete vec;
    vec = NULL;

    delete vec2;
    vec2 = NULL;

    cout << "Constructor that takes unsigned integer as vector size" << endl;
    vec = new MyVector<unsigned>(5);

    for(unsigned i = 0; i < 10; i++)
    {
        (*vec)[i] = i;
    }

    cout << "Get size:  " << vec -> GetSize() << endl;
    cout << "First index:" << (*vec)[0] << endl;
    cout << "Last index:" << (*vec)[vec -> GetSize() - 1] << endl;
    cout << endl;

    delete vec;
    vec = NULL;

    MyVector<Date> *dates;
    dates = new MyVector<Date>();

    for(unsigned i = 0; i <= 30; i++)
    {
        (*dates)[i].SetDay(i + 1);
        (*dates)[i].SetMonth(1);
        (*dates)[i].SetYear(2015);
    }

    cout << "First Index of dates" << endl;
    cout << (*dates)[0].GetDay() << endl;
    cout << (*dates)[0].GetMonth() << endl;
    cout << (*dates)[0].GetYear() << endl;
    cout << endl;

    cout << "Last Index of dates" << endl;
    cout << (*dates)[dates -> GetSize() -1].GetDay()   << endl;
    cout << (*dates)[dates -> GetSize() -1].GetMonth() << endl;
    cout << (*dates)[dates -> GetSize() -1].GetYear()  << endl;
    cout << endl;


    cout << "Test memory" << endl;
    for(unsigned i = 0; i < 3000000; i++)
    {
        (*dates)[i].SetDay(i + 1);
        (*dates)[i].SetMonth(1);
        (*dates)[i].SetYear(2015);
    }

    cout << "Didn't crash over 3000000 creations of the date object" << endl;
    cout << dates -> GetSize();
    cout << endl;

    cout << "Test for index of -1" << endl;

    try
    {
        (*dates)[-1].SetDay(1);
    }
    catch(...)
    {
        cout << "Exception thrown" << endl;
    }
    cout << "PASSED as exception thrown" << endl;
    cout << "This is a desired result"   << endl;
    cout << endl;

}

void TestTree()
{
    BinaryTree<Unit> tree;

    ifstream inFile("unitInput.csv");

    string unitId;
    string unitName;
    string credits;

    while(getline(inFile, unitId, ','))
    {
        Unit newUnit;

        getline(inFile, unitName, ',');
        getline(inFile, credits);

        newUnit.SetId(unitId);
        newUnit.SetName(unitName);
        newUnit.SetCredits(atol(credits.c_str()));

        tree.Insert(newUnit);
    }

    void (*print)(const Unit & unit);
    print = *PrintUnit;

    cout << "Post Order" << endl << endl;
    tree.PostOrder(print);
    cout << endl <<"In Order" << endl << endl;
    tree.InOrder(print);

    inFile.close();

    cout << endl;
    ifstream newFile("unitInput.csv");
    while(getline(newFile, unitId, ','))
    {
        Unit searchUnit;

        getline(newFile, unitName, ',');
        getline(newFile, credits);

        searchUnit.SetId(unitId);
        searchUnit.SetName(unitName);
        searchUnit.SetCredits(atol(credits.c_str()));

        if(tree.Search(searchUnit, print))
        {

        }
        else
        {
            cout << "Test Failed" << endl;
        }
    }
}

void IntTreeTest()
{
    BinaryTree<int> tree;

    for(int i = 10; i > 0; i--)
    {
        tree.Insert(i);
    }

    for(int i = 5; i <= 20; i++)
    {
        tree.Insert(i);
    }

    void (*print)(const int & i);
    print = &PrintData;

    cout << endl << "Pre Order" << endl;
    tree.PreOrder(print);
    cout << endl << "In Order" << endl;
    tree.InOrder(print);

    BinaryTree<int> newTree(tree);

    cout << "Copy Tree PreOrder" << endl;
    newTree.PreOrder(print);
    cout << "Copy Tree InOrder"  << endl;
    newTree.InOrder(print);

    if(&newTree == &tree)
        cout << "Failed" << endl;
    else
        cout << "Passed" << endl;

    BinaryTree<int> newTree2 = tree;

    if(&newTree2 == &tree)
        cout << "Failed" << endl;
    else
        cout << "Passed" << endl;

    if(newTree2.Search(1, print));

}

void TestStudent()
{
    Student *s;
    s = new Student();

           //------------- DEFAULT CONSTRUCTOR ---------//

    cout << "TESTING DEFAULT CONSTRUCTOR" << endl;

    if(s -> GetStudentId() == 0)
    {
        cout << "PASSED: " << s -> GetStudentId() << endl;
    }

    if(s -> GetFirstName() == "NOT INIT")
    {
        cout << "PASSED: " << s -> GetFirstName() << endl;
    }

    if(s -> GetLastName() == "NOT INIT")
    {
        cout << "PASSED: " << s -> GetLastName() << endl;
    }

    cout << endl;
    cout << "to test the MyVector object, results I need to use the GET and SET methods" << endl;
    cout << "thus they will be tested concurrently" << endl;
    cout << endl;

    s -> SetStudentId(32067232);
    s -> SetFirstName("Jake");
    s -> SetLastName("Kroon");
    s -> SetResult(0, 80);
    s -> SetResultSemester(0, 1);
    s -> SetUnitId(0, "ICT283");
    s -> SetDay(0, 26);
    s -> SetMonth(0, 5);
    s -> SetYear(0, 2015);

        //------------- OUTPUT ----------------------//

    if(s -> GetStudentId() == 32067232)
        cout << "PASSED: " << s -> GetStudentId() << endl;

    if(s -> GetFirstName() == "Jake")
        cout << "PASSED: " << s -> GetFirstName() << endl;

    if(s -> GetLastName() == "Kroon")
        cout << "PASSED: " << s -> GetLastName() << endl;

    if(s -> GetResult(0) == 80)
        cout << "PASSED: " << s -> GetResult(0) << endl;

    if(s -> GetResultSemester(0) == 1)
        cout << "PASSED: " << s -> GetResultSemester(0) << endl;

    if(s -> GetUnitId(0) == "ICT283")
        cout << "PASSED: " << s -> GetUnitId(0) << endl;

    if(s -> GetDay(0) == 26)
        cout << "PASSED: " << s -> GetDay(0) << endl;

    if(s -> GetMonth(0) == 5)
        cout << "PASSED: " << s -> GetMonth(0) << endl;

    if(s -> GetYear(0) == 2015)
        cout << "PASSED: " << s -> GetYear(0) << endl;

        //-------- OUTPUT FOR INDEX NOT SET ------//

    cout << endl;
    cout << s -> GetStudentId() << endl;
    cout << s -> GetFirstName() << endl;
    cout << s -> GetLastName() << endl;
    cout << s -> GetResult(1)  << endl;
    cout << s -> GetResultSemester(1) << endl;
    cout << s -> GetUnitId(1) << endl;
    cout << s -> GetDay(1) << endl;
    cout << s -> GetMonth(1) << endl;
    cout << s -> GetYear(1) << endl;

    cout << endl;

        //------- GET CALCULATIONS -------//

    int i = 1;

    s -> SetResult(i, 68);
    s -> SetResultSemester(i, 1);
    s -> SetUnitId(i, "uni1");
    s -> SetDay(i, 1);
    s -> SetMonth(i, 5);
    s -> SetYear(i, 2015);

    i = 2;

    s -> SetResult(i, 62);
    s -> SetResultSemester(i, 1);
    s -> SetUnitId(i, "uni2");
    s -> SetDay(i, 1);
    s -> SetMonth(i, 5);
    s -> SetYear(i, 2015);

    i = 3;

    s -> SetResult(i, 50);
    s -> SetResultSemester(i, 1);
    s -> SetUnitId(i, "uni3");
    s -> SetDay(i, 1);
    s -> SetMonth(i, 5);
    s -> SetYear(i, 2015);

    i = 4;

    s -> SetResult(i, 81);
    s -> SetResultSemester(i, 1);
    s -> SetUnitId(i, "uni4");
    s -> SetDay(i, 1);
    s -> SetMonth(i, 5);
    s -> SetYear(i, 2015);

    cout << endl;
    cout << "Testing on calculations" << endl;
    if(s -> GetHighestMark() == 81)
        cout << "PASSED: " << s -> GetHighestMark() << endl;

    if(s -> GetLowestMark() == 50)
        cout << "PASSED: " << s -> GetLowestMark()  << endl;

    BinaryTree<Unit> unitTree;

    Unit newUnit;

    newUnit.SetName("Data Structures and Abstractions");
    newUnit.SetId("ICT283");
    newUnit.SetCredits(3);

    unitTree.Insert(newUnit);

    newUnit.SetId("uni1");

    unitTree.Insert(newUnit);

    newUnit.SetId("uni2");

    unitTree.Insert(newUnit);

    newUnit.SetId("uni3");

    unitTree.Insert(newUnit);

    newUnit.SetId("uni4");

    unitTree.Insert(newUnit);

    if(s -> CalculateGPA(unitTree) == 2.6)
        cout << s -> CalculateGPA(unitTree) << endl;

        //--- SET UNIT TEST ---//

    Student::SetUnit("ICT283", unitTree);
    cout << Student::GetUnitName() << endl;

    cout << "GPA for year" << endl;
    cout << s -> CalculateGPA(unitTree, 1) << endl;
    cout << s -> CalculateGPA(unitTree, 2) << endl;
    cout << s -> CalculateGPA(unitTree, 3) << endl;
    cout << s -> CalculateGPA(unitTree, 4) << endl;
    cout << s -> CalculateGPA(unitTree, 5) << endl << endl;

    cout << "Copy Constructor Test" << endl << endl;

    Student *copyTest;

    copyTest = new Student(*s);

    cout << "DATA CONTAINED IN STUDENT CLASS" << endl;
    cout << s -> GetStudentId() << endl;
    cout << s -> GetFirstName() << endl;
    cout << s -> GetLastName() << endl;
    cout << endl << endl;

    cout << "Data from child classes" << endl;
    cout << endl;
    cout << "First index" << endl;
    cout << copyTest -> GetResult(0)  << endl;
    cout << copyTest -> GetResultSemester(0) << endl;
    cout << copyTest -> GetUnitId(0) << endl;
    cout << copyTest -> GetDay(0) << endl;
    cout << copyTest -> GetMonth(0) << endl;
    cout << copyTest -> GetYear(0) << endl;
    cout << endl;

    cout << copyTest -> GetResult(copyTest -> GetSize() - 1)  << endl;
    cout << copyTest -> GetResultSemester(copyTest -> GetSize() - 1) << endl;
    cout << copyTest -> GetUnitId(copyTest -> GetSize() - 1) << endl;
    cout << copyTest -> GetDay(copyTest -> GetSize() - 1) << endl;
    cout << copyTest -> GetMonth(copyTest -> GetSize() - 1) << endl;
    cout << copyTest -> GetYear(copyTest -> GetSize() - 1) << endl;

    cout << endl;
    if(copyTest != s)
        cout << "PASSED: ADDRESSES DO NOT MATCH THEREFORE NOT THE SAME" << endl;

    cout << endl;
}

void TestStudentIO()
{
    BinaryTree<Unit> units;
    map<long, Student> students;

    StudentIO io("students.csv", "outdata.txt");

    cout << students.size() << endl;

    io.InitialiseIO(students, units);

    cout << students.size() << endl;

    io.GetHighestMarkOutput(32067232, students, units);
    io.GetLowestMarkOutput(32067232, students, units);
    io.GetGPACalcOutput(32067232, students, units);
    io.GetHighestLowest(students, units);
    io.GetYearGPA(32067232, 2, students, units);
}
        /* Overloaded less than operator for Unit objects */
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

        /* Overloaded equivalency operator for Unit objects */
bool operator == (const Unit & lhs, const Unit & rhs)
{
    if(lhs.GetId().compare(rhs.GetId()) == 0)
    {
        return true;
    }

    return false;
}

void PrintUnit(const Unit & unit)
{
    cout << unit << endl;
}

void PrintData(const int & i)
{
    cout << i << endl;
}

ostream & operator << (ostream & os, const Unit & aUnit)
{
    os << aUnit.GetId();

    return os;
}
