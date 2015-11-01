#ifndef MYVECTOR_H
#define MYVECTOR_H

#include<iostream>

template <class T>

            /**
             * @class MyVector
             * @brief Creates an vector that dynamically expands and contracts
             *
             * A minimal vector class for the implementation of Assignment 1.
             * Expands dynamically as required by the user. Large indexes can be
             * entered and the vector will change itself to accomodate. That
             * is of course, any index of zero and above.
             *
             * @author Jake Kroon
             * @version 01
             * @date 15/04/2015
             *
             * @bug No bugs to my knowledge
             */

class MyVector
{

    public:

            /**
             * @brief Default constructor for MyVector
             *
             * This constructor initialises a MyVector object to
             * have a counter set to zero, an vector size of 10 also
             * initialises the vector itself.
             *
             * @return void
             */
        MyVector();

            /**
             * @brief Constructor that sets user defined vector size
             *
             * This constructer initialises a MyVector object to have
             * a counter set to zero, an vector of size, size and also
             * initialises the vector itself.
             *
             * @param size - An unsigned integer that is the size of the vector
             * @return void
             */
        MyVector(unsigned size);

            /**
             * @brief Copy Constructor
             *
             * This takes an object that is of class MyVector
             * and makes this object equal to it by deep copying
             * the data in the vector.
             *
             * @param newVec - The MyVector object that will be copied into this one
             * @return void
             */
        MyVector(const MyVector &newVec);

            /**
             * @brief Default Destructor
             *
             * Cleans up the memory by deleting the vector, also
             * sets the vec pointer to NULL
             *
             * @return void
             */
        ~MyVector();

            /**
             * @brief Gets actual vector size
             *
             * Returns the amount of values that have been set
             * in the vector.
             *
             * @return counter - The amount of set values in the vector
             */
        const unsigned GetSize() const;

            /**
             * @brief Overloaded operator [] returns value at index
             *
             * Using the [] operator with a value between the square brackets
             * will return the value at that index in the vector. An example is
             * shown below. This value can be modified. Also if an index outside
             * of the current vector size is entered, it will dynamically expand
             * to ensure the user can enter data at any index they want.
             *
             * WARNING: If an index larger than the current amount of set values
             *          is entered, all values from the previous last index and
             *          the new out of bounds index will be constructed via the
             *          default constructor.
             *
             * IF A NEGATIVE NUMBER IS ENTERED AN EXCEPTION WILL BE THROWN
             *
             * @param i - an integer representing the index of the vector
             * @return value - A direct reference to the value at index i
             */
        T & operator[](const int i);

        void Clear();

    private:
        unsigned counter; /** Actual Size of array  */
        unsigned arrSize; /** Allocated memory Size */
        T *vec;           /** An array of type T    */

            /**
             * @brief Increases arrSize
             *
             * This method increases the arrSize value by doubling it.
             * It then copies the current array into a temporary array.
             * The old array is deleted and the pointer address is
             * changed to that of the new array. This is designed to
             * occur when the index entered is out of bounds or about
             * to hit the capacity of the vector.
             *
             * @param i - The out of bounds index, a constant unsigned integer
             * @return void
             */
        void GrowVector(const unsigned i);

            /**
             * @brief Copies a MyVector object into this one
             *
             * This method makes this MyVector object equal to another of the
             * same datatype (according to the template). This is done through
             * deep copying.
             *
             * @param newVec - The object of MyVector that this will replicate
             * @return void
             */
        void Copy(const MyVector &newVec);

            /**
             * @brief Clears all items in the vector
             *
             * Empties the vector of all elements and cleans
             * the memory.
             *
             * @return void
             */
        void EmptyVector();

};

template <class T>
MyVector<T>::MyVector()
{
    counter = 0;
    arrSize = 10;
    vec = new T[arrSize];
}

template <class T>
MyVector<T>::MyVector(unsigned size)
{
    counter = 0;
    arrSize = size;
    vec = new T[arrSize];
}

template <class T>
MyVector<T>::MyVector(const MyVector &newVec)
{
    Copy(newVec);
}

template <class T>
MyVector<T>::~MyVector()
{
    EmptyVector();
}

template <class T>
const unsigned MyVector<T>::GetSize() const
{
    return counter;
}

template <class T>
T & MyVector<T>::operator[](const int j)
{
    if(j < 0)
    {
        throw -1;
    }

    unsigned i = static_cast<unsigned>(j); // casting necessary

    if((i + 1) >= arrSize)
    {
        GrowVector(i);
        /* Sets the arrSize value to *
         *  i * 2                    */
    }

    if(i >= counter)
    {
        counter = i + 1;
        /* +1 because the counter represents number of values  *
         * whereas an index starts from zero, with zero being  *
         * an acceptable value.                                */
    }

    return vec[i];
}

template <class T>
void MyVector<T>::GrowVector(const unsigned i)
{
    arrSize = i * 2;
    T *tmp = new T[arrSize];

    for(unsigned j = 0; j < counter; j++)
    {
        tmp[j] = vec[j];
    }

    delete [] vec;

    vec = tmp;
}

template<class T>
void MyVector<T>::Copy(const MyVector &newVec)
{
    if(this != &newVec) // Ensures objects aren't the same
    {
        counter = newVec.counter;
        arrSize = newVec.arrSize;

        delete [] vec;
        vec = new T[arrSize];

        for(unsigned i = 0; i < newVec.GetSize(); i++)
        {
            vec[i] = newVec.vec[i];
        }
    }

}

template<class T>
void MyVector<T>::EmptyVector()
{
    if(vec != NULL)
    {
        delete [] vec;
    }

    vec = NULL;
}

template<class T>
void MyVector<T>::Clear()
{
    EmptyVector();
    counter = 0;
    arrSize = 10;
    vec = new T[arrSize];
}
#endif // MYVECTOR_H
