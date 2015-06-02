#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstddef>
#include <iostream>

using namespace std;

        /**
         * @class BinaryTree
         * @brief A binary search tree data structure
         *
         * Allows the use of a binary tree, contains appropriate methods
         * for binary tree traversal as well as other functions.
         *
         * @author Jake Kroon
         * @version 01
         * @date 18/05/2015
         *
         * @bug No bugs to my knowledge
         */

template <class T>
class BinaryTree
{
    public:

            /**
             * @brief Default Constructor
             *
             * Initialises the object and sets the pointer of the root object
             * node to NULL
             *
             * @return void
             */
        BinaryTree();

            /**
             * @brief Copy Constructor
             *
             * Deep copies the object passed in, into a new BinaryTree object
             *
             * @param rhs - a constant reference to a BinaryTree object
             * @return void
             */
        BinaryTree(const BinaryTree & rhs);

            /**
             * @brief Destructor
             *
             * Clears memory by destroying all objects on the heap
             *
             * @return void
             */
        ~BinaryTree();

            /**
             * @brief Insert data into the tree
             *
             * Insert new data into the tree and will automatically
             * sort the data. This requires the opertor < to be
             * overloaded for the chosen data type.
             *
             * @param newData - new data to be entered of the templated data type
             * @return void
             */
        void Insert(T newData);

            /**
             * @brief Processes the data in an in order way
             *
             * Traverses the binary tree in order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void InOrder(void(*travFunc)(const T & data));

            /**
             * @brief Processes the data in a pre order way
             *
             * Traverses the binary tree pre order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void PreOrder(void(*travFunc)(const T & data));

            /**
             * @brief Processes the data in a post order way
             *
             * Traverses the binary tree post order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void PostOrder(void(*travFunc)(const T & data));

            /**
             * @brief Searches for an object matching type T
             *
             * This is intended to be used with operator overloading
             * for non primitive types. Searches for an object and returns
             * it where a match is found. Returns NULL if object isn't found.
             *
             * @param searchFunc - A pointer to a function that will act on the data at the node.
             * @param key - An object of type T to search for
             * @return Object - An object of of type T that matches the key
             */
        bool Search(T key, void(*searchFunc)(const T & data));

            /**
             * @brief Makes a deep copied version of the BinaryTree being assigned
             *
             * Makes a new BinaryTree object that is a deep copy of the object
             * on the right hand side of the  = operator. This new BinaryTree
             * object is then returned.
             *
             * @param rhs - A constant reference to a BinaryTree object
             * @return BinaryTree - A deep copy of the binary tree assigned
             */
        BinaryTree operator = (const BinaryTree & rhs);

    private:

            /**
             * @struct node
             * @brief A node struct containing a left and right pointer as well as data
             *
             * This is the node that is used by the program, there is a left and right
             * pointer as well as data of the templated data type defined by the user.
             *
             */
        struct node
        {
            node* left;
            node* right;
            T data;
        };

        node *root; /** The root node of the tree */

            /**
             * @brief Inserts new data into
             *
             * Allows the insertion of new data into the tree, automatically
             * orders the data. If inserting with a class object, overload the
             * comparison operator '<' so that comparisons between objects
             * can be made.
             *
             * @param data - data of the templated data type
             * @param parent - a pointer reference to the node passed in
             * @return void
             */
        void Insert(T data, node *& parent);

            /**
             * @brief A recursive function for In Order traversal
             *
             * Traverses in order, performs a function on the data at each node.
             *
             * @param parent - a pointer reference to a node to traverse
             * @return void
             */
        void InOrderHelper(node *& parent, void(*travFunc)(const T & data));

            /**
             * @brief A recursive function for Pre Order traversal
             *
             * Traverse pre order, performs a function on the data at each node.
             *
             * @param parent - a pointer reference to a node to traverse
             * @return void
             */
        void PreOrderHelper(node *& parent, void(*travFunc)(const T & data));

            /**
             * @brief A recursive function for Post Order traversal
             *
             * Traverse post order, performs a fucntion on the data at each node.
             *
             * @param parent - a pointer reference to a node to traverse
             * @return void
             */
        void PostOrderHelper(node *& parent, void(*travFunc)(const T & data));

            /**
             * @brief A helper method for the destructor
             *
             * Recursively deletes the objects at each node and sets the pointer
             * to NULL
             *
             * @param parent - a pointer to a node, this is for recursion
             * @return void
             */
        void Clear(node * parent);

            /**
             * @brief A method for deep copying
             *
             * Creates a deep copy of the tree passed in from the node
             * entered as a parameter
             *
             * @param parent - a pointer to a node, this is for recursion
             * @return node - A pointer to a node
             */
        node * Copy(const node * parent);

            /**
             * @brief A recursive function for searching for searching
             *
             * Searches for an item that matches the key recursively,
             * returns the matching key or NULL.
             *
             * @param key - The object to be found
             * @param parent - The node of the parent of the leaves being looked at.
             * @return object - An object of type T or a primitive, if not found returns NULL
             */
        bool SearchHelper(T key, node *& parent, void(*searchFunc)(const T & data));
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

//****************************************************************************
//                   DESTRUCTOR AND HELPER                                   *
//****************************************************************************

template <class T>
BinaryTree<T>::~BinaryTree()
{
    Clear(root);
}

template <class T>
void BinaryTree<T>::Clear(node * parent)
{
    if(parent != NULL)
    {
        Clear(parent -> left); // Clears all leaves left of a root
        Clear(parent -> right); // Clears all leaves right of a root
        delete parent; // delete parent node
        parent = NULL; // no dangling pointer
    }
}

//****************************************************************************
//                   COPY CONSTRUCTORS                                       *
//****************************************************************************

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree & rhs)
{
    root = Copy(rhs.root);
}

template <class T>
typename BinaryTree<T>::node * BinaryTree<T>::Copy(const node * parent)
{
    if(parent == NULL)
    {
        return NULL;
    }

    node *newNode = new node();
    newNode -> right = NULL;
    newNode -> left  = NULL;

    newNode -> data  = parent -> data;
    newNode -> right = Copy(parent -> left);
    newNode -> left  = Copy(parent -> right);

    return newNode;
}

template <class T>
BinaryTree<T> BinaryTree<T>::operator = (const BinaryTree & rhs)
{
    BinaryTree newBT(rhs);
    return newBT;
}

//****************************************************************************
//                  INSERTING INTO THE TREE                                  *
//****************************************************************************

template <class T>
void BinaryTree<T>::Insert(T newData)
{

    if(root == NULL)
    {
        node *newnode = new node();
        newnode -> data = newData;

        newnode -> left = NULL;
        newnode -> right = NULL;

        root = newnode;
    }
    else
    {
        Insert(newData, root);

    }
}

template <class T>
void BinaryTree<T>::Insert(T newData, node *& parent)
{
    if(newData < parent -> data)
    {
        if(parent -> left == NULL)
        {
            node *newnode = new node();
            newnode -> data = newData;

            newnode -> left = NULL;
            newnode -> right = NULL;

            parent -> left = newnode;
        }
        else
        {
            Insert(newData, parent -> left);
        }
    }
    else if(parent -> data < newData )
    {
        if(parent -> right == NULL)
        {
            node *newnode = new node();
            newnode -> data = newData;

            newnode -> left = NULL;
            newnode -> right = NULL;

            parent -> right = newnode;
        }
        else
        {
            Insert(newData, parent -> right);
        }
    }
}

//****************************************************************************
//                  IN ORDER PROCESSING                                      *
//****************************************************************************

template <class T>
void BinaryTree<T>::InOrder(void(*travFunc)(const T & data))
{
    InOrderHelper(root, travFunc);
}

template <class T>
void BinaryTree<T>::InOrderHelper(node *& parent, void(*travFunc)(const T & data))
{
    if(parent != NULL)
    {
        InOrderHelper(parent -> left, travFunc);
        travFunc(parent -> data);
        InOrderHelper(parent -> right, travFunc);
    }
}

//****************************************************************************
//                  PRE ORDER PROCESSING                                     *
//****************************************************************************

template <class T>
void BinaryTree<T>::PreOrder(void(*travFunc)(const T & data))
{
    PreOrderHelper(root, travFunc);
}

template <class T>
void BinaryTree<T>::PreOrderHelper(node *& parent, void(*travFunc)(const T & data))
{
    if(parent != NULL)
    {
        travFunc(parent -> data);
        PreOrderHelper(parent -> left, travFunc);
        PreOrderHelper(parent -> right, travFunc);
    }
}

//****************************************************************************
//                  POST ORDER PROCESSING                                    *
//****************************************************************************

template <class T>
void BinaryTree<T>::PostOrder(void(*travFunc)(const T & data))
{
    PostOrderHelper(root, travFunc);
}

template <class T>
void BinaryTree<T>::PostOrderHelper(node *& parent, void(*travFunc)(const T & data))
{
    if(parent != NULL)
    {
        PostOrderHelper(parent -> left, travFunc);
        PostOrderHelper(parent -> right, travFunc);
        travFunc(parent -> data);
    }
}

//****************************************************************************
//                          SEARCH FUNCTION                                  *
//****************************************************************************

template <class T>
bool BinaryTree<T>::Search(T key ,void(*searchFunc)(const T & data))
{
    bool found;
    found = SearchHelper(key, root, searchFunc);

    return found;
}

template<class T>
bool BinaryTree<T>::SearchHelper(T key, node *& parent, void(*searchFunc)(const T & data))
{
    if(parent != NULL)
    {
        if(key == parent -> data)
        {
            searchFunc(parent -> data);
            return true;
        }

        if(key < parent -> data)
        {
            return SearchHelper(key, parent -> left, searchFunc);
        }
        else
        {
            return SearchHelper(key, parent -> right, searchFunc);
        }
    }

    return false;
}

#endif // BINARYTREE_H
