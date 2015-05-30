#ifndef STUDENT_H
#define STUDENT_H

#include "unit.h"
#include "include\results.h"
#include "MyVector.h"
#include <string>
#include <algorithm>

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
                 * @brief Gets the Unit Name at a vector index
                 *
                 * Returns the unit name of the Results object at index i in results.
                 * This will return a default value unless the unit name is set.
                 *
                 * @param i - The index of the results vector to return the unit name from
                 * @return unitName - A constant string representing the unit name of a unit
                 */
        const string GetUnitName(unsigned i) const;

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
                 * @brief Gets the Unit Credits at a vector index
                 *
                 * Returns the credit points of the Results object at index i in results.
                 * This will return a default value, unless the credits are set.
                 *
                 * @param i - The index of the results vector to return the unit credits from
                 * @return unitCredits - A constant unsigned integer representing the credit points of a unit
                 */
        const unsigned GetUnitCredits(unsigned i) const;

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
        const string GetMonth(unsigned i) const;

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
                 * @brief
                 *
                 *
                 * @param
                 * @return
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
                 * @brief Sets the Units Name at index i
                 *
                 * Sets the unit name through Results object at index i in results
                 * The variable type is a string.
                 *
                 * @param i - The index of results to set the unitName
                 * @param name - The name of the unit as a string
                 * @return void
                 */
        void SetUnitName(unsigned i, string name);

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
                 * @brief Sets the Units credits
                 *
                 * Sets the credits through the Results object at index i in results
                 * The variable type is an unsigned integer.
                 *
                 * @param i - The index of results to set the unit credits
                 * @param cred - The credit points of the unit
                 * @return void
                 */
        void SetUnitCredits(unsigned i, unsigned cred);

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
        void SetMonth(unsigned i, string month);

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
                 * @return GPA - The GPA of the student as a double
                 */
        const double CalculateGPA() const;

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

        long     studentId;         /** Student Id for a student                  */
        string   fName;             /** The first name of the student             */
        string   lName;             /** The last name of the student              */
        MyVector<Results> *results; /** A vector of results objects               */
};
#endif //STUDENT_H
