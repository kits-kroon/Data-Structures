#ifndef STUDENT_H
#define STUDENT_H

#include "include\results.h"
#include "MyVector.h"
#include "BinaryTree.h"
#include <string>

        /**
         * @class Student
         * @brief Manages the results object and input / output
         *
         * The Student class manages a results object and has various
         * methods relating to it. This includes the calculation of the
         * GPA as well as finding the highest and lowest grades.
         *
         * @author Jake Kroon
         * @version 01
         * @date 01/04/2015
         *
         * @bug No bugs to my knowledge
         */

using namespace std;

class Student
{

    public:

                /**
                 * @brief Default constructor for class Student
                 *
                 * This constructor initialises a Regist class object with the default values
                 *
                 * @return void
                 */
        Student();

                /**
                 * @brief Copy constructor for class Student
                 *
                 * This takes an object that is of class Student
                 * and makes this object equal to it by deep copying
                 * he data in the vector.
                 *
                 * @param obj - The student object to be replicated
                 * @return void
                 */
        Student(const Student &obj);

                /**
                 * @brief Default Destructor
                 *
                 * Cleans up the memory by deleting the results
                 * vector
                 *
                 * @return void
                 */
        ~Student();


                //-------------- GETTERS ----------------//

                /**
                 * @brief Returns the id of a student
                 *
                 * Allows the getting of a student id of a student class object
                 *
                 * @return studentId - A constant long representing a studentId
                 */
        const long GetStudentId() const;

                /**
                 * @brief Returns the first name of a student
                 *
                 * Allows the getting of a students first name from a student class object
                 *
                 * @return firstName - A constant string representing a students first name
                 */
        const string GetFirstName() const;

                /**
                 * @brief Returns the last name of a student
                 *
                 * Allows the getting of a students last name from a student class object
                 *
                 * @return lastName - A constant string representing a students last name
                 */
        const string GetLastName() const;

                /**
                 * @brief Returns the amount of initialised object in the vector
                 *
                 * Allows the getting of the total number of objects in the vector
                 *
                 * @return size - An unsigned integer representing a total number of units
                 */
        const unsigned GetSize() const;

                /**
                 * @brief Gets the Unit id at a vector index
                 *
                 * Returns the unit id of the Results object at index i in results.
                 * This will return a default value unless the id is set.
                 *
                 * @param i - The index of the results vector to return the unit id
                 * @return unitId - A constant string representing the Unit Id of a unit
                 */
        const string GetUnitId(unsigned i) const;

                /**
                 * @brief Gets the Day
                 *
                 * Returns the day of the Results object at index i in results.
                 * This will return a default value, unless the Day is set.
                 *
                 * @param i - The index of the results vector to return the day from
                 * @return day - A constant unsigned integer representing a day
                 */
        const unsigned GetDay(unsigned i) const;

                /**
                 * @brief Gets the Month
                 *
                 * Returns the month of the Results object at index i in results.
                 * This will return a default value, unless the Month is set.
                 *
                 * @param i - The index of the results vector to return the month from
                 * @return month - A constant string representing a month
                 */
        const unsigned GetMonth(unsigned i) const;

                /**
                 * @brief Gets the Year
                 *
                 * Returns the year of the Results object at index i in results
                 * This will return a default value, unless the Year is set.
                 *
                 * @param i - The index of the results vector to return the year from
                 * @return year - A constant unsigned integer representing a year
                 */
        const unsigned GetYear(unsigned i) const;

                /**
                 * @brief Gets the Result
                 *
                 * Returns the result of the Results object at index i in results
                 * This will return a default value, unless the result is set.
                 *
                 * @param i - The index of the results vector to return the result from
                 * @return result - A constant double representing the result
                 */
        const double GetResult(unsigned i) const;

                /**
                 * @brief Gets the semester a result was achieved in
                 *
                 * Returns the semester that a result was achieved in at index i in results
                 * This will return a default value, unless the result is set.
                 *
                 * @param i - The index of the results vector to return the semester from
                 * @return semester - A constant unsigned integer representing the semester a result was achieved in
                 */
        const unsigned GetResultSemester(unsigned i) const;

                /**
                 * @brief Gets the size of the results vector
                 *
                 * Returns an unsigned integer that is the size of the
                 * results vector.
                 *
                 * @return size - The size of the results vector as an unsigned integer
                 */
        const unsigned GetResultsSize() const;

                //----------------- SETTERS ------------------//

                /**
                 * @brief Sets the student Id
                 *
                 * Allows the setting of a students Id
                 *
                 * @param sId - A long representing the student Id of a student
                 * @return void
                 */
        void SetStudentId(long sId);

                /**
                 * @brief Sets the first name
                 *
                 * Allows the setting of the first name of a student
                 *
                 * @param first - The first name of a student as a string
                 * @return void
                 */
        void SetFirstName(string first);

                /**
                 * @brief Sets the last name
                 *
                 * Allows the setting of the last name of a student
                 *
                 * @param last - The last name of a student as a string
                 * @return void
                 */
        void SetLastName(string last);

                /**
                 * @brief Sets the Result at index i
                 *
                 * Sets the result of a Results object at index i in results
                 * The variable type is a double
                 *
                 * @param i - The index of the results object to set the result
                 * @param res - The result for the Results object as a double
                 * @return void
                 */
        void SetResult(unsigned i, double res);

                /**
                 * @brief Sets the semester for a result
                 *
                 * Sets the semester that a result was achieved in, in the
                 * Results object. The variable type is an unsigned integer.
                 *
                 * @param i - The index of the results object to set the semester
                 * @param sem - The semester to set as 1 or 2
                 * @return void
                 */
        void SetResultSemester(unsigned i, unsigned sem);

                /**
                 * @brief Sets the Units Id
                 *
                 * Sets the unit through Results object at index i in results
                 * The variable type is a string.
                 *
                 * @param i - The index of results to set the unitId
                 * @param id - The id of the unit as a string
                 * @return void
                 */
        void SetUnitId(unsigned i, string id);

                /**
                 * @brief Sets the day
                 *
                 * Sets the day through the Results object at index i in results
                 * The variable type is an unsigned integer.
                 *
                 * @param i - The index of results to set the day of a date
                 * @param day - The day to be set in the Date object as an unsigned int
                 * @return void
                 */
        void SetDay(unsigned i, unsigned day);

                /**
                 * @brief Sets the month
                 *
                 * Sets the month through the Results object at index i in results
                 * The variable type is a string.
                 *
                 * @param i - The index of results to set the day of a date
                 * @param month - The month to be set in the Date object as a string
                 * @return void
                 */
        void SetMonth(unsigned i, unsigned month);

                /**
                 * @brief Sets te year
                 *
                 * Sets the year through the Results object at index in results
                 * The variable type is an unsigned int.
                 *
                 * @param i - The index of results to set the day of a date
                 * @param year - The ear to be set in the Date object as an unsigned int
                 * @return void
                 */
        void SetYear(unsigned i, unsigned year);

                //----------------- CALCULATIONS ------------//

                /**
                 * @brief Calculate the students GPA
                 *
                 * Calculates a students GPA based on Murdoch Universities
                 * formula. GPA is returned as a double. More information
                 * on Murdoch Universities formula can be found below.
                 *
                 * https://www.murdoch.edu.au/students/myinfo/GPA.html
                 *
                 * @param units - A tree of units
                 * @return GPA - The GPA of the student as a double
                 */
        const double CalculateGPA(BinaryTree<Unit> & units);

                /**
                 * @brief Calculates the GPA for a year
                 *
                 * Calculates a students GPA based on Murdoch Universities
                 * formula for a given year. GPA is returned as a double.
                 * More information can be found on Murdoch Universities
                 * formula below.
                 *
                 * https://www.murdoch.edu.au/students/myinfo/GPA.html
                 *
                 * @param units - A tree of units
                 * @param year - The year to calculate the GPA for (first number of unit code)
                 * @return A GPA for a year
                 */
        const double CalculateGPA(BinaryTree<Unit> & units, unsigned year);

                /**
                 * @brief Finds the highest mark achieved
                 *
                 * Cycles through the results vector and finds the highest mark
                 * a student has achieved.
                 *
                 * @return mark - The highest mark the student achieved as an unsigned integer
                 */
        const unsigned GetHighestMark() const;

                /**
                 * @brief Finds the lowest mark achieved
                 *
                 * Cycles through the results vector and finds the lowest mark
                 * a student has achieved.
                 *
                 * @return mark - The lowest mark a student has achieved as an unsigned integer
                 */
        const unsigned GetLowestMark() const;

                /**
                 * @brief Gets the date of a date object
                 *
                 * Returns the date of a date object formatted as dd/mm/yyyy
                 * So if the date is the 1st of January 2015
                 * The date will return as 01/01/2015
                 *
                 * @return date - the date of a date object dd/mm/yyyy formatting
                 */
        const string GetDate(unsigned i) const;

                /**
                 * @brief Gets a unit object for a unit Id
                 *
                 * Finds a unit object in a particular unit and returns
                 * the unit Id.
                 *
                 * @param unitId - A string containing the Id of a unit
                 * @param units - A binary tree of units
                 * @return aUnit - A unit for a particular
                 */
        static const bool SetUnit(string unitId, BinaryTree<Unit> & units);

                /**
                 * @brief Get Unit Name
                 *
                 * If the unit has not been set using SetUnit, defaults will
                 * be returned.
                 *
                 * @return unitName - A string containing the name of a unit
                 */
        static const string GetUnitName();

    private:

                /**
                 * @brief Clears the object
                 *
                 * Deletes the MyVector object from the class
                 * also sets the pointer to NULL.
                 *
                 * @return void
                 */
        void Clear();

                /**
                 * @brief Copies a Student object into this one
                 *
                 * This method makes this object equal to another
                 * Student object. This is done through deep copying.
                 *
                 * @param obj - The object of Student tha this will replicate
                 * @return void
                 */
        void Copy(const Student &obj);

                /**
                 * @brief Finds the GPA value of particular unit and result
                 *
                 *
                 *
                 * @param tcp - A reference to the total credit points
                 * @param pdt - A reference to the pre division total of point values (Letter grade value)
                 * @return void
                 */
        const void UnitGPACalc(BinaryTree<Unit> & units, double & tcp, double & pdt, unsigned i);

                /**
                 * @brief Sets the static unit object
                 *
                 * Deep copies a unit object that is passed in via a constant reference
                 * This information is copied into the static variable aUnit.
                 *
                 * @param newUnit - A constant reference to a Unit object
                 * @return void
                 */
        static void SetUnit(const Unit &newUnit);

        long     studentId;         /** Student Id for a student                  */
        string   fName;             /** The first name of the student             */
        string   lName;             /** The last name of the student              */
        MyVector<Results> *results; /** A vector of results objects               */
        static Unit statUnit;       /** A static unit for retrieving a unit from the binary tree */

};

#endif //STUDENT_H
