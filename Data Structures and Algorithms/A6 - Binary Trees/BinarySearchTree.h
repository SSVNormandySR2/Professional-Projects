// Assignment #6
// Name: Vincent Latona
// Description: This header file provides the framework
//              for the construction of a binary search tree
//              and provides the functions of the structure.

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi

using namespace std;

//Club represents some club information
class Club
{
private:
    string clubName;
    string universityName;
    Club* left, * right, * parent;


public:
    //The following two functions are constructors
    Club()
    {
        clubName = "?";
        universityName = "?";
        parent = NULL;
        left = NULL;
        right = NULL;
    }


    Club(string clubName1, string universityName1)
    {
        clubName = clubName1;
        universityName = universityName1;

        parent = NULL;
        left = NULL;
        right = NULL;
    }

    //The following functions are accessor functions
    Club* getLeft()
    {
        return left;
    }

    Club* getRight()
    {
        return right;
    }

    Club* getParent()
    {
        return parent;
    }

    string getClubName()
    {
        return clubName;
    }
    string getUniversityName()
    {
        return universityName;
    }


    //The following functions are mutator functions
    void setLeft(Club* other)
    {
        left = other;
    }

    void setRight(Club* other)
    {
        right = other;
    }

    void setParent(Club* other)
    {
        parent = other;
    }

    //The print method prints the clubName and universityName
    void print()
    {
        cout << "Club Name: " << clubName << endl;
        cout << "University Name: " << universityName << endl << endl;
    }

    //you can add more functions

};

//class BinarySearchTree will contains clubs
class BinarySearchTree
{
private:
    Club* root;
    int size;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    int postOrderTreeDelete(Club*);
    bool isEmpty();
    void inOrderTreePrint();
    void preOrderTreePrint();
    void postOrderTreePrint();
    void inOrderTreeWalk(Club*);
    void preOrderTreeWalk(Club*);
    void postOrderTreeWalk(Club*);
    Club* treeSearchNode(Club*, string, string);
    Club* treeSearch(string, string);
    Club* treeMinimum();
    Club* treeMaximum();
    Club* treeMinimumNode(Club*);
    Club* treeMaximumNode(Club*);
    Club* treeSuccessor(string, string);
    Club* treePredecessor(string, string);
    bool treeInsert(string, string);
    bool rightRotate(string, string);
    bool leftRotate(string, string);
};

//The constructor initialize the root to be NULL
BinarySearchTree::BinarySearchTree()
{
    root = NULL;
    size = 0;
}

//The descurtor should delete all nodes in the tree 
//and perform garbage collections starting from leaves (bottom-up order). 
//The destructor should also print “The number of nodes deleted: X” 
//where X is the number of nodes deleted
BinarySearchTree::~BinarySearchTree()
{
    
    //Use helper function to delete the tree and count nodes
    int deleted = postOrderTreeDelete(root);

    //Display message for how many clubs were deleted
    cout << "The number of of nodes deleted: " << deleted << endl;

}//End of destructor

/*
* This function deletes the tree and counts the number of nodes deleted
*/
int BinarySearchTree::postOrderTreeDelete(Club* x)
{

    //Base case
    if (x == NULL)
    {

        //Return size of table deleted
        return 0;

    }//End of base case

    //Recursive cases
    else
    {

        //Perform post order deletion
        int a = postOrderTreeDelete(x->getLeft());
        int b = postOrderTreeDelete(x->getRight());
        delete x;

        //Return recursive solution
        return a+b+1;

    }//End of recursive cases

}//End of function postOrderTreeDelete

//Checks if the tree is empty
bool BinarySearchTree::isEmpty()
{
    if (root == NULL)
        return true;
    else
        return false;
}

//prints all nodes using in-order
void BinarySearchTree::inOrderTreePrint()
{
    if (isEmpty())
        cout << "tree is empty" << endl;
    else
    {
        cout << "\n";
        inOrderTreeWalk(root);
        cout << "\n";
    }
}

//prints all nodes using pre-order
void BinarySearchTree::preOrderTreePrint()
{
    if (isEmpty())
        cout << "tree is empty" << endl;
    else
    {
        cout << "\n";
        preOrderTreeWalk(root);
        cout << "\n";
    }
}

//prints all nodes using post-order
void BinarySearchTree::postOrderTreePrint()
{
    if (isEmpty())
        cout << "tree is empty" << endl;
    else
    {
        cout << "\n";
        postOrderTreeWalk(root);
        cout << "\n";
    }
}

/*
* This function performs an in-order traversal of the BST
*/
void BinarySearchTree::inOrderTreeWalk(Club* x)
{

    //Printable element case
    if (x != NULL)
    {

        //Print left, node, right
        inOrderTreeWalk(x->getLeft());
        x->print();
        inOrderTreeWalk(x->getRight());

    }//End of printable element case

}//End of function inOrderTreeWalk

/*
* This function performs a pre-order traversal of the BST
*/
void BinarySearchTree::preOrderTreeWalk(Club* x)
{

    //Printable element case
    if (x != NULL)
    {

        //Print node, left, right
        x->print();
        preOrderTreeWalk(x->getLeft());
        preOrderTreeWalk(x->getRight());

    }//End of printable element case

}//End of function preOrderTreeWalk

/*
* This function performs a post-order traversal of the BST
*/
void BinarySearchTree::postOrderTreeWalk(Club* x)
{

    //Printable element case
    if (x != NULL)
    {

        //Print left, right, node
        postOrderTreeWalk(x->getLeft());
        postOrderTreeWalk(x->getRight());
        x->print();

    }//End of printable element case

}//End of function postOrderTreeWalk

/*
* This function returns the minimum club of the tree
*/
Club* BinarySearchTree::treeMinimum()
{

    //Empty tree case
    if (isEmpty())
    {

        //Return NULL for empty tree case
        return NULL;

    }//End of empty tree case

    //Return call to treeMinimumNode at root
    Club* search = root;
    return treeMinimumNode(search);

}//End of function treeMinimum

/*
* This function returns the minimum club of a tree rooted at an arbitrary club
*/
Club* BinarySearchTree::treeMinimumNode(Club* x)
{

    //Minimum iterator
    while (x->getLeft() != NULL)
    {

        //Go left to find minimum
        x = x->getLeft();

    }//End of minimum iterator

    //Return pointer to min
    return x;

}//End of function treeMinimumNode

/*
* This function returns the maximum club of the tree
*/
Club* BinarySearchTree::treeMaximum()
{

    //Empty tree case
    if (isEmpty())
    {

        //Return NULL for empty tree case
        return NULL;

    }//End of empty tree case

    //Return call to treeMaximumNode at root
    Club* search = root;
    return treeMaximumNode(search);

}//End of function treeMaximum

/*
* This function returns the maximum club of a tree rooted at an arbitrary club
*/
Club* BinarySearchTree::treeMaximumNode(Club* x)
{

    //Minimum iterator
    while (x->getRight() != NULL)
    {

        //Go left to find maximum
        x = x->getRight();

    }//End of maximum iterator

    //Return pointer to max
    return x;

}//End of function treeMaximumNode

/*
* This function finds the predecessor of the given club
*/
Club* BinarySearchTree::treePredecessor(string cName, string uName)
{

    //Search tree for given club
    Club* search = treeSearch(cName, uName);

    //Nonexistent club case
    if (search == NULL)
    {

        //Return NULL for nonexistent club
        return search;

    }//End of nonexistent club case

    //Predecessor find case
    else
    {

        //Left tree max case
        if (search->getLeft() != NULL)
        {

            //Return recursive call of minimum of search club
            return treeMaximumNode(search->getLeft());

        }//End of left tree max case

        //Search parents case
        else
        {

            //Predecessor iterator
            Club* predecessor = search->getParent();

            //Upward tree iterator
            while (predecessor != NULL && search == predecessor->getLeft())
            {

                //Iterate up the tree
                search = predecessor;
                predecessor = predecessor->getParent();

            }//End of upward tree iteration

            //Return predecessor iterator
            return predecessor;

        }//End of search parents case

    }//End of predecessor find case

}//End of function treePredecessor

/*
* This function finds the successor of the given element
*/
Club* BinarySearchTree::treeSuccessor(string cName, string uName)
{

    //Search tree for given club
    Club* search = treeSearch(cName, uName);

    //Nonexistent club case
    if (search == NULL)
    {

        //Return NULL for nonexistent club
        return search;

    }//End of nonexistent club case

    //Successor find case
    else
    {

        //Right tree min case
        if (search->getRight() != NULL)
        {

            //Return recursive call of minimum of search club
            return treeMinimumNode(search->getRight());

        }//End of right tree min case

        //Search parents case
        else
        {

            //Predecessor iterator
            Club* predecessor = search->getParent();

            //Upward tree iterator
            while (predecessor != NULL && search == predecessor->getRight())
            {

                //Iterate up the tree
                search = predecessor;
                predecessor = predecessor->getParent();

            }//End of upward tree iteration

            //Return predecessor iterator
            return predecessor;

        }//End of search parents case

    }//End of successor find case

}//End of function treeSuccessor

/*
* This function searches the tree for the specified club
*/
Club* BinarySearchTree::treeSearch(string cName, string uName)
{

    //Empty tree case
    if (isEmpty())
    {

        //Return NULL for empty tree
        return NULL;

    }//End of empty tree case

    //Search case
    else
    {

        //Initialize iterator to root
        Club* search = root;

        //Return the ouptut of the helper function
        return treeSearchNode(search, cName, uName);

    }//End of search case

}//End of function treeSearch

/*
* This function searches a tree rooted at an arbitrary club
*/
Club* BinarySearchTree::treeSearchNode(Club* search, string cName, string uName)
{

    //Not found case
    if (search == NULL)
    {

        //Return NULL for not found
        return NULL;

    }//End of not found case
    
    //Same university case
    else if (uName.compare(search->getUniversityName()) == 0)
    {

        //Found case
        if (cName.compare(search->getClubName()) == 0)
        {

            //Return found club
            return search;

        }//End of found case

        //Branch left case
        else if (cName.compare(search->getClubName()) < 0)
        {

            //Return recursive call on left child
            return treeSearchNode(search->getLeft(), cName, uName);

        }//End of branch left case

        //Branch right case
        else
        {

            //Return recursive call on right child
            return treeSearchNode(search->getRight(), cName, uName);

        }//End of branch right case

    }//End of same university case

    //Lexically smaller univeristy case
    else if (uName.compare(search->getUniversityName()) < 0)
    {

        //Return recursive call on left child
        return treeSearchNode(search->getLeft(), cName, uName);

    }//End of lexically smaller university case

    //Lexically larger university case
    else
    {

        //Return recursive call on right child
        return treeSearchNode(search->getRight(), cName, uName);

    }//End of lexically larger university case

}//End of function treeSearchNode

/*
* This function attempts to insert a specified club into the tree
*/
bool BinarySearchTree::treeInsert(string cName, string uName)
{

    //Arbitrary add case
    if (treeSearch(cName, uName) == NULL)
    {

        //Tree iterators
        Club* parent = NULL;
        Club* newNode = root;
        
        //Tree iterator
        while (newNode != NULL)
        {

            //Iterate parent
            parent = newNode;

            //Lexically smaller university case
            if (uName.compare(parent->getUniversityName()) < 0)
            {

                //Iterate left
                newNode = newNode->getLeft();

            }//End of lexically smaller university case

            //Same university case
            else if (uName.compare(parent->getUniversityName()) == 0)
            {

                //Smaller club case
                if (cName.compare(parent->getClubName()) < 0)
                {

                    //Iterate left
                    newNode = newNode->getLeft();

                }//End of smaller club case

                //Larger club case
                else
                {

                    //Iterate right
                    newNode = newNode->getRight();

                }//End of larger club case

            }//End of same university case

            //Lexically larger university case
            else
            {

                //Iterate right
                newNode = newNode->getRight();

            }//End of lexically larger university case

        }//End of tree iterator

        //Instantiate new club object
        newNode = new Club(cName, uName);

        //Insufficient memory case
        if (newNode == NULL)
        {

            //Return false for insufficient memeory
            return false;

        }//End of insufficient memory case

        //Set parent of new node
        newNode->setParent(parent);

        //Root case
        if (parent == NULL)
        {

            //Set new node to root and return true
            root = newNode;

        }//End of root case

        //Smaller university case
        else if (newNode->getUniversityName().compare(parent->getUniversityName()) < 0)
        {

            //Set left child
            parent->setLeft(newNode);

        }//End of smaller university case

        //Larger university case
        else if (newNode->getUniversityName().compare(parent->getUniversityName()) > 0)
        {

            //Set right child
            parent->setRight(newNode);

        }//End of larger university case

        //Same university case
        else
        {

            //Smaller club case
            if (newNode->getClubName().compare(parent->getClubName()) < 0)
            {

                //Set left child
                parent->setLeft(newNode);

            }//End of smaller club case

            //Larger club case
            else
            {

                //Set right child
                parent->setRight(newNode);

            }//End of larger club case

        }//End of same university case

        //Return true for successful add and increment size
        size++;
        return true;

    }//End of arbitrary add case

    //Duplicate case
    else
    {

        //Return false for duplicate
        return false;

    }//End of duplicate case

}//End of function treeInsert

/*
* This function attempts to do a right rotation about a given club
*/
bool BinarySearchTree::rightRotate(string cName, string uName)
{

    //Empty tree case
    if (isEmpty())
    {

        //Return false for empty tree
        return false;

    }//End of empty tree case

    //Attempt rotation case
    else
    {
        
        //Search tree for club
        Club* rotateAbout = treeSearch(cName, uName);

        //Cannot rotate case
        if (rotateAbout == NULL || rotateAbout->getLeft() == NULL)
        {

            //Return false for nonexistent or no left child
            return false;

        }//End of cannot rotate case

        //Rotation case
        else
        {

            //Initialize the left child of the rotating club
            Club* left = rotateAbout->getLeft();

            //Connect left's right child to the rotating club
            rotateAbout->setLeft(left->getRight());

            //Set parent case
            if (left->getRight() != NULL)
            {

                //Set rotating club to parent of its left child
                rotateAbout->getLeft()->setParent(rotateAbout);

            }//End of set parent case

            //Connect left to the parent of rotating club
            left->setParent(rotateAbout->getParent());

            //Left child case
            if (rotateAbout == rotateAbout->getParent()->getLeft())
            {

                //Set left to left child of parent of rotating club
                rotateAbout->getParent()->setLeft(left);

            }//End of left child case

            //Right child case
            else
            {

                //Set left to right child of parent of rotating club
                rotateAbout->getParent()->setRight(left);

            }//End of right child case

            //Connect rotating club and left anew
            left->setRight(rotateAbout);
            rotateAbout->setParent(left);

            //Return true for successful rotation
            return true;

        }//End of rotation case

    }//End of attempt rotation case

}//End of function rightRotate

/*
* This function attempts to do a left rotation about a given club
*/
bool BinarySearchTree::leftRotate(string cName, string uName)
{

    //Empty tree case
    if (isEmpty())
    {

        //Return false for empty tree
        return false;

    }//End of empty tree case

    //Attempt rotation case
    else
    {

        //Search tree for club
        Club* rotateAbout = treeSearch(cName, uName);

        //Cannot rotate case
        if (rotateAbout == NULL || rotateAbout->getRight() == NULL)
        {

            //Return false for nonexistent or no left child
            return false;

        }//End of cannot rotate case

        //Rotation case
        else
        {

            //Initialize the left child of the rotating club
            Club* right = rotateAbout->getRight();

            //Connect left's right child to the rotating club
            rotateAbout->setRight(right->getLeft());

            //Set parent case
            if (right->getLeft() != NULL)
            {

                //Set rotating club to parent of its right child
                rotateAbout->getRight()->setParent(rotateAbout);

            }//End of set parent case

            //Connect left to the parent of rotating club
            right->setParent(rotateAbout->getParent());

            //Left child case
            if (rotateAbout == rotateAbout->getParent()->getLeft())
            {

                //Set left to left child of parent of rotating club
                rotateAbout->getParent()->setLeft(right);

            }//End of left child case

            //Right child case
            else
            {

                //Set left to right child of parent of rotating club
                rotateAbout->getParent()->setRight(right);

            }//End of right child case

            //Connect rotating club and left anew
            right->setLeft(rotateAbout);
            rotateAbout->setParent(right);

            //Return true for successful rotation
            return true;

        }//End of rotation case

    }//End of attempt rotation case

}//End of function leftRotate