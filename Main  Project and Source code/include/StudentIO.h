#ifndef STUDENTIO_H
#define STUDENTIO_H

#include "../student.h"
#include "BinaryTree.h"
#include <string>
#include <map>

        /**
         * @class StudentIO
         * @brief An input output class that deals a student object
         *
         * Deals with all the input and output between main and the
         * student class. This class deals solely with input and
         * ouput of a students details. The filenames are entererd
         * into the constructor as strings.
         *
         * @author Jake Kroon
         * @version 01
         * @date 22/04/2015
         *
         * @bug No bugs to my knowledge
         */

class StudentIO
{

    public:

                /**
                 * @brief Constructor that sets the input and output file names
                 *
                 * This constructor initialises the StudentIO object to have
                 * the names of the input and output files, iFileName and
                 * oFileName respectively set as strings.
                 *
                 * @param iFileName - The name of the input file as a string
                 * @param oFileName - The name of the output file as a string
                 * @return void
                 */
        StudentIO(string iFileName, string oFileName);

                /**
                 * @brief Outputs unit details with the highest mark
                 *
                 * Prints the unit(s) with the highest mark to the console and
                 * writes then to the file with the name oFileName is set as.
                 *
                 * @param students - A map of Student objects
                 * @param units - A binary tree of Unit objects
                 * @return void
                 */
        void GetHighestMarkOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const;

                /**
                 * @brief Outputs unit details with the lowest mark
                 *
                 * Prints the unit(s) with the lowest mark to the console and
                 * writes them to the file with the name oFilename is set as.
                 *
                 * @param students - A map of Student objects
                 * @param units - A binary tree of Unit objects
                 * @return void
                 */
        void GetLowestMarkOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const;

                /**
                 * @brief Outputs a details of a student and their GPA to console
                 *
                 * Prints the students studentId, Surname and GPA to the console.
                 *
                 * @param students - A map of Student objects
                 * @param units - A binary tree of Unit objects
                 * @return void
                 */
        void GetGPACalcOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const;

                /**
                 * @brief Outputs the highest, lowest and average GPA and details
                 *
                 * Outputs the details of the highest, lowest and average GPA as well
                 * as the id's and surnames of the highest and lowest achieving students.
                 *
                 * @param students - A map of Student objects
                 * @param units - A binary tree of Unit objects
                 * @return void
                 */
        void GetHighestLowest(map<long, Student> & students, BinaryTree<Unit> & units);

                /**
                 * @brief Sets all information about a student
                 *
                 * Accesses the input file and inputs all the data
                 * that is relevant to a student.
                 *
                 * @return void
                 */
        void InitialiseIO(map<long, Student> & students, BinaryTree<Unit> & units);

    private:

        string iFileName; /** The name of the input file    */
        string oFileName; /** The name of the output file   */

                /**
                 * @brief Default constructor
                 *
                 * Made private to deny user access.
                 * Does nothing but stop the compiler
                 * from creating its own
                 *
                 * @return void
                 */
        StudentIO();

            //------------- SETTERS --------------//

                /**
                 * @brief Set the string object iFileName
                 *
                 * Takes a string input and sets iFileName to it.
                 *
                 * @param inf - The name to set iFileName as, as a string
                 * @return void
                 */
        void SetIFileName(string inf);

                /**
                 * @brief Set the string object oFileName
                 *
                 * Takes a string input and sets oFileName to it.
                 *
                 * @param of - The name to set oFileName as, as string
                 * @return void
                 */
        void SetOFileName(string of);

                /**
                 * @brief Removes newline characters from a string
                 *
                 * Removes the new line characters '\n' and '\r' the input string
                 * and returns it.
                 *
                 * @param input - the string being entered for newLine removal
                 * @return output - the string without newline characters
                 */
        string EraseNewLine(string input);

                /**
                 * @brief Sets all variables relating to the highest GPA
                 *
                 * Modifies the vectors hnames and hsids, adding the highest achieving students names and student ids
                 * respectively. Finds the highest GPA and modifies the double value highest.
                 *
                 * @param hnames - A reference to a vector of strings containing the names with the highest gpa
                 * @param hsids - A reference to a vector of long integers containing the student ids with the highest gpa
                 * @param highest - A reference to the highest GPA so far
                 * @param check - A reference to a student object to check
                 * @param gpa - The GPA of the student entered
                 *
                 * @return void
                 */
        const void HighestGPA(MyVector<string> & hnames, MyVector<long> & hsids,
                            double & highest, const Student & check, double gpa);

                /**
                 * @brief Sets all variables relating to the lowest GPA
                 *
                 * Modifies the vectors lnames and lsids, adding the lowest achieving students names and student ids
                 * respectively. Finds the lowest GPA and modifies the double value lowest.
                 *
                 * @param lnames - A reference to a vector of strings containing the names with the lowest gpa
                 * @param lsids - A reference to a vector of long integers containg the student ids with the lowest gpa
                 * @param lowest - A reference to the highest GPA so far
                 * @param check - A reference to a student object to check
                 * @param gpa - The GPA of the student entered
                 *
                 * @return void
                 */
        const void LowestGPA(MyVector<string> & lnames, MyVector<long> & lsids,
                                   double & lowest, const Student & check, double gpa);

                /**
                 * @brief Outputs the highest and lowest gpa as well as average to stream
                 *
                 * This function outputs the highest and lowest GPA along with the name and student id
                 * of all students whom achieved those GPAs respectively. The average GPA is also output.
                 * This function writes to the stream chosen as a parameter.
                 *
                 * @param os - The stream to be written to
                 * @param lnames - An address to a vector of strings containing the lowest names
                 * @param hnames - An address to a vector of strings containing the highest names
                 * @param lSid - An address to a vector of long integers containing the lowest student ids
                 * @param hSid - An address to a vector of long integer containing the highest student ids
                 * @param lowest - The lowest GPA achieved
                 * @param highest - The highest GPA achieved
                 * @param avg - The average GPA achieved
                 *
                 * @return void
                 */
        const void HighestLowestOutput(ostream & os, MyVector<string> & lnames, MyVector<string> & hnames,
                         MyVector<long> & lSid, MyVector<long> & hSid,
                         const double lowest, const double highest, const double avg);

};
#endif // STUDENTIO_H
