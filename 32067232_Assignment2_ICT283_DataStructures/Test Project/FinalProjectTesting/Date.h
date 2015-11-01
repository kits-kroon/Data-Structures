#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

        /**
         * @class Date
         * @brief Stores day, month and year for a date class
         *
         * A date class, stores day, month and year. Has appropriate
         * set and get methods to aid with use.
         *
         * @author Jake Kroon
         * @version 01
         * @date 01/04/2015
         *
         * @bug No bugs to my knowledge
         */

class Date
{

    public:

                /**
                 * @brief Default constructor for class date
                 *
                 * This constructor initialises a Date class object with the default values
                 *
                 * @return void
                 */
        Date();

                // -------------------- Setters --------------------- //

                /**
                 * @brief Sets the day
                 *
                 * Allows the setting of a day for an object of class Date
                 *
                 * @param d - The day that will be set for the Date object as an unsigned integer
                 *
                 * @return void
                 */
        void SetDay(unsigned d);

                /**
                 * @brief Sets the month
                 *
                 * Allows the setting of a month for an object of class Date
                 *
                 *
                 * @param mon - The month that will be set for the Date object as a string
                 *
                 * @return void
                 */
        void SetMonth(unsigned mon);

                /**
                 * @brief Sets the year
                 *
                 * Allows the setting of a year for an object of class Date
                 *
                 * @param yr - The year that will be set for the Date object as an integer
                 *
                 * @return void
                 */
        void SetYear(unsigned yr);

                // --------------- Getters ------------------//

                /**
                 * @brief Gets the day
                 *
                 * Allows the getting of a day that has been set for an object of class Date
                 *
                 * @return day - A constant unsigned integer representing a day of a month
                 */
        const unsigned GetDay() const;

                /**
                 * @brief Gets the month
                 *
                 * Allows the getting of a month that has been set for an object of class Date
                 *
                 * @return month - A constant string representing a month
                 */
        const unsigned GetMonth() const;

                /**
                 * @brief Gets the year
                 *
                 * Allows the getting of a year that has been set for an object of class Date
                 *
                 * @return year - A constant unsigned integer representing a year
                 */
        const unsigned GetYear() const;

        const string GetDate() const;

        private:

            unsigned day;      /** Day for a date   */
            unsigned month;    /** Month for a date */
            unsigned year;     /** Year for a date  */
};
#endif // DATE_H
