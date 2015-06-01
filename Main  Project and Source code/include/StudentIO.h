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
             * @return void
             */
        void GetHighestMarkOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const;

            /**
             * @brief Outputs unit details with the lowest mark
             *
             * Prints the unit(s) with the lowest mark to the console and
             * writes them to the file with the name oFilename is set as.
             *
             * @return void
             */
        void GetLowestMarkOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const;

            /**
             * @brief Outputs a details of a student and their GPA to console
             *
             * Prints the students studentId, Surname and GPA to the console.
             *
             * @return void
             */
        void GetGPACalcOutput(const long sId, map<long, Student> & students, BinaryTree<Unit> & units) const;

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
};
#endif // STUDENTIO_H
