#ifndef RESULTS_H
#define RESULTS_H

#include <string>
#include "../unit.h"
#include "date.h"

using namespace std;

        /**
         * @class Results
         * @brief Stores results for a unit, also manages Unit and Date classes
         *
         * Stores objects of both Date and Unit. Has a full set of get and set
         * methods. Contains the results and semester of a student.
         *
         * @author Jake Kroon
         * @version 01
         * @date 01/04/2015
         *
         * @bug No bugs to my knowledge
         */

class Results
{

    public:

                /**
                 * @brief Default constructor for class results
                 *
                 * This constructor initialises a Results class object with the default values
                 *
                 * @return void
                 */
        Results();

                //-------------- Setters -----------//

                /**
                 * @brief Sets the Result
                 *
                 * Sets the result of this object.
                 * The variable type is a unsigned.
                 *
                 * @param res - The result for the results object as a unsigned

                 * @return void
                 */
        void SetResult(unsigned res);

                /**
                 * @brief Sets the semester
                 *
                 * Sets the semester of this object.
                 * The variable type is an unsigned integer
                 *
                 * @param sem - The semester the unit was taken as an unsigned int
                 * @return void
                 */
        void SetSemester(unsigned sem);

                /**
                 * @brief Sets the Units Name
                 *
                 * Sets the unit name of the object aUnit.
                 * The variable type is a string.
                 *
                 * @param name - The name of the unit as a string
                 * @return void
                 */
        void SetUnitName(string name);

                /**
                 * @brief Sets the Units Id
                 *
                 * Sets the unit id of the object aUnit.
                 * The variable type is a string.
                 *
                 * @param id - The id of the unit as a string
                 * @return void
                 */
        void SetUnitId(string id);

                /**
                 * @brief Sets the Units credits
                 *
                 * Sets the credits of the object aUnit.
                 * The variable type is an unsigned integer.
                 *
                 * @param cred - The credit points of the unit
                 * @return void
                 */
        void SetUnitCredits(unsigned cred);

                /**
                 * @brief Sets the day of the Date object
                 *
                 * Sets the day of the object aDate.
                 * The variable type is an unsigned integer.
                 *
                 * @param day - The day to be set in the Date object as an unsigned int
                 * @return void
                 */
        void SetDay(unsigned day);

                /**
                 * @brief Sets the month of the Date object
                 *
                 * Sets the month of object aDate.
                 * The variable type is a string.
                 *
                 * @param month - The month to be set in the Date object as a string
                 * @return void
                 */
        void SetMonth(string month);

                /**
                 * @brief Sets te year of the Date object
                 *
                 * Sets the year of the object aDate.
                 * The variable type is an unsigned int.
                 *
                 * @param year - The ear to be set in the Date object as an unsigned int
                 * @return void
                 */
        void SetYear(unsigned year);

                //-------------- Getters ----------//

                /**
                 * @brief Gets the Result
                 *
                 * Returns the result stored in this class.
                 * This will return a default value unless the result is set.
                 *
                 * @return result - A constant unsigned integer represting the result
                 */
        const unsigned GetResult() const;

                /**
                 * @brief Gets the Semester
                 *
                 * Returns the semeser stored in this class.
                 * This will return a default value unless the semester is set.
                 *
                 * @return semester - A constant unsigned representing the semester
                 */
        const unsigned GetSemester() const;

                /**
                 * @brief Gets the Unit id
                 *
                 * Returns the unit id of the unit that the result was achieved in.
                 * This will return a default value unless the id is set.
                 *
                 * @return unitId - A constant string representing the Unit Id
                 */
        const string GetUnitId() const;

                /**
                 * @brief Gets the Day
                 *
                 * Returns the day of a Date object created by this class.
                 * This will return a default value, unless the Day is set.
                 *
                 * @return day - A constant unsigned integer representing the day in a Date object
                 */
        const unsigned GetDay() const;

                /**
                 * @brief Gets the Month
                 *
                 * Returns the month of a Date object created by this class.
                 * This will return a default value, unless the Month is set.
                 *
                 * @return month - A constant string representing the month in a Date object
                 */
        const string GetMonth() const;

                /**
                 * @brief Gets the Year
                 *
                 * Returns the year of a Date object created by this class.
                 * This will return a defaul value, unless the Year is set.
                 *
                 * Returns the year of a Date object
                 */
        const unsigned GetYear() const;

    private:
        unsigned   result;   /** Result for a unit                    */
        Date     aDate;      /** an object of Date class              */
        unsigned semester;   /** The semester the result was achieved */
        string unitId;       /** The unit that the result was achieved in */

};
#endif // RESULTS_H
