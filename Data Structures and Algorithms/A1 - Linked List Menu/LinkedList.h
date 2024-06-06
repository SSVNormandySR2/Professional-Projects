#pragma once
// Assignment #1
// Name: Vincent Latona
// Description: This program executes the functionality of 
//              the linked list defined by the user-driven
//              program of Assignment1.cpp.

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Club represents some club information
struct Club
{
    string clubName;
    string univName;
    struct Club* next;
};

//class LinkedList will contains a linked list of clubs
class LinkedList
{
private:
    struct Club* head;
    int elementCount; //Element counter

public:
    LinkedList();
    ~LinkedList();
    bool addElement(string clubName, string univName, int index);
    bool removeElement(string clubName, string univName);
    void printList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
    elementCount = 0; //Instantiate to 0
}

//Destructor
//Description: This function acts as garbage collection to prevent memory leaks
LinkedList::~LinkedList()
{
    int deleted = 0; //Deletion counter

    struct Club* temp = head; //Deletion iterators
    struct Club* follower = NULL;

    while (temp != NULL) //Deletion iterator
    {
        follower = temp; //Iterate both pointers
        temp = temp->next;

        delete follower; //Garbage collection

        deleted++; //Increment deletion counter

        elementCount--; //Decrement element counter
    }

    cout << "The number of deleted clubs is: " << deleted << endl; //Display message
}

//Description: This function validates and facilitates the addition of a node to the existing linked list
bool LinkedList::addElement(string newClubName, string newUnivName, int index)
{
    if (index < 0 || index > elementCount) //Index bounds check
    { 
        return false; //Cannot add element out of bounds
    }
    else if (index == 0) //First element case
    {
        struct Club* newClub = new Club;

        if (newClub == NULL) //Out of Memory Handler
        {
            cout << "The program has run of out memory!";
            return false;
        }
        else
        {
            newClub->clubName = newClubName; //Assign data to new club
            newClub->univName = newUnivName;

            newClub->next = head; //Place node into linked list
            head = newClub;

            elementCount++; //Increment count

            return true; //Successful add
        }
    }
    else
    {
        struct Club* iterator = head;

        for (int a = 0; a < index-1; a++) //Index iterator
        {
            iterator = iterator->next;
        }

        struct Club* newClub = new Club;
        
        if (newClub == NULL) //Out of Memory Handler
        {
            cout << "The program has run of out memory!";
            return false;
        }
        else
        {
            newClub->clubName = newClubName; //Assign data to new club
            newClub->univName = newUnivName;

            newClub->next = iterator->next; //Place node into linked list
            iterator->next = newClub;

            elementCount++; //Increment count

            return true; //Successful add
        }
    }
}

//Description: This function validates and facilitates the deletion of a node from the existing linked list
bool LinkedList::removeElement(string someClubName, string someUnivName)
{
    struct Club* temp = head; //Iterator pointers
    struct Club* follower = NULL;

    bool found = false; //Deletion condition

    while (temp != NULL) //Club search iterator
    {
        if (temp->clubName == someClubName && temp->univName == someUnivName) //Club found
        {
            found = true;
            break;
        }

        follower = temp; //Iterate
        temp = temp->next;
    }

    if (found) //Delete condition
    {
        if (follower == NULL) //First element deletion
        {
            head = temp->next;
            delete temp;

            elementCount--; //Decrement count
        }
        else //Arbitrary element deletion
        {
            follower->next = temp->next;
            delete temp;

            elementCount--; //Decrement count
        }

        return true; //Club found and deleted
    }
    else //Club not in list
    {
        return false; //Club not found
    }
}

//Description: This function prints the current contents of the linked list
void LinkedList::printList()
{
    if (elementCount == 0) //Empty list
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        struct Club* temp = head; //Iterative pointer

        while (temp != NULL) //Printing iterator
        {
            cout << "Club Name: " << temp->clubName << ", University Name: " << temp->univName << endl; //Node data display

            temp = temp->next; //Iterate
        }
    }
}
