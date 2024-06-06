// Vincent Latona
// Programming environment used: VS


#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "employee.h"
#include "technical.h"
#include "nontechnical.h"

using namespace std;

// functions already implemented:
void executeAction(char c);
Employee* searchEmployee(string name_input);


// functions that need implementation:
void addEmployee(string name_input, double salary_input, empType type);			// 7 points
void displayList();							// 4 points
void save(string fileName);					// 7 points
void load(string fileName);					// 7 points

Container* list = NULL;				// global list

int main()
{
	char c = 'i';				// initialized to a dummy value

  // During first execution, there will be no list.txt in source directory. list.txt is generated by save() while exiting the program.
	load("list.txt");
	do {
		cout << "\nCSE240 HW9\n";
		cout << "Please enter your selection:\n";
		cout << "\t a: add a new employee\n";
		cout << "\t d: display employee list\n";
		cout << "\t c: change salary of an employee\n";
		cout << "\t q: quit\n";
		cin >> c;
		cin.ignore();
		executeAction(c);
	} while (c != 'q');

	save("list.txt");

	list = NULL;

	return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	double salary_input;
	int type_input = 2;
	empType type;
	Employee* empResult = NULL;

	switch (c)
	{
	case 'a':	// add employee
				// input employee details from user
		cout << endl << "Enter employee name: ";
		getline(cin, name_input);
		cout << "Enter new salary: ";
		cin >> salary_input;
		cin.ignore();

		while (!(type_input == 0 || type_input == 1))
		{
			cout << "Enter employee type: " << endl;
			cout << "0. Nontechnical" << endl;
			cout << "1. Technical" << endl;
			cin >> type_input;
			cin.ignore();
		}
		type = (empType)type_input;

		// searchEmployee() will return the employee object if found, else returns NULL
		empResult = searchEmployee(name_input);
		if (empResult == NULL)
		{
			addEmployee(name_input, salary_input, type);
			cout << endl << "Employee added to list!" << endl << endl;
		}
		else
			cout << endl << "Employee already present in the list!" << endl << endl;

		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'c':		// change salary
		cout << endl << "Enter employee name: ";
		getline(cin, name_input);
		// searchEmployee() will return the employee node if found, else returns NULL
		empResult = searchEmployee(name_input);
		if (empResult == NULL)
		{
			cout << endl << "Employee not in list!" << endl << endl;
		}
		else
		{
			// if employee exists in the list, then ask user for new salary
			cout << endl << "Enter new salary: ";
			cin >> salary_input;
			cin.ignore();

			// Q3c Call changeSalary() here   (1 point)
			// 'empResult' contains the employee whose 'salary' is to be changed.
			// 'salary_input' contains the new salary of the employee.
			// Call the function with appropriate arguments.
			empResult->changeSalary(empResult, salary_input);

			cout << endl << "Salary changed!" << endl << endl;
		}
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// No implementation needed here, however it may be helpful to review this function
Employee* searchEmployee(string name_input)
{

	Container* tempList = list;			// work on a copy of 'list'

	while (tempList != NULL)			// parse till end of list
	{
		if (tempList->emp->getName() == name_input)
		{
			return tempList->emp;	// return the employee if found
		}

		tempList = tempList->next;		// parse the list
	}

	return NULL;						// return NULL if employee not found in list
}

// Q3b: Define Friend Function changeSalary()  (3 points)
// Define the function changeSalary()that is declared in employee.h file.
// This function sets the new 'salary' of the employee. The employee object and new salary is to be passed as function arguments.
// Use 'd' display option after using 'c' option to verify.
// You will need to implement add() and displayList() before you test this function.
void Employee::changeSalary(Employee* emp, double newSalary)
{

	//New salary assignment
	emp->salary = newSalary;

}//End of function changeSalary

// Q4: addEmployee  (7 points)
// This function is used to add a new employee to the global linked list 'list'. You may add the new employee to head or tail of the list. (Sample solution adds to tail)
// empType 'type' can be Nontechnical or technical. You will need to use the function argument �type� to determine which constructor to use to create new employee node.
// For example, if the user enters type as 'technical', then you need to use Technical class and constructor to create new employee node and add it to the list.
// NOTE: In executeAction(), searchEmployee() is called before this function. Therefore no need to check here if the employee exists in the list.
// See how this fucntion is called in case 'a' of executeAction()

void addEmployee(string name_input, double salary_input, empType type)
{
	Container* tempList = list;				// work on a copy of 'list'

	//Follower iterator for tail addition
	Container* follower = NULL;

	//Container node declaration
	Container* node = new Container();

	//Nontechnical case
	if (type == 0)
	{

		//Nontechnical employee declaration and node employee assignment
		Nontechnical* nonTechEmployee = new Nontechnical(name_input, salary_input, type);
		node->emp = nonTechEmployee;

	}//End of Nontechnical case

	//Technical case
	else
	{

		//Technical employee declaration and node employee assignment
		Technical* techEmployee = new Technical(name_input, salary_input, type);
		node->emp = techEmployee;

	}//End of Technical case

	//Placement iterator
	while (tempList != NULL)
	{

		//Iterate through list and set follower
		follower = tempList;
		tempList = tempList->next;

	}//End of placement iterator

	//Head addition
	if (follower == NULL)
	{

		//Add to head and reassign head
		node->next = list;
		list = node;

	}//End of head addition

	//Tail addition
	else
	{

		//Add to tail and reassign previous node's next
		follower->next = node;
		node->next = tempList;

	}//End of tail addition

}//End of function addEmployee

// Q5: displayList	(4 points)
// This function displays the list of employee and their details (name, salary, employee type)
// Parse the list and use the class member function to display the employee info.
// See expected output in the question file.
void displayList()
{
	Container* tempList = list;			// work on a copy of 'list'

	//Display iterator
	while (tempList != NULL)
	{

		//Display employee members and iterate
		tempList->emp->displayEmployee();
		tempList = tempList->next;

	}//End of display iterator

}//End of function displayList

// Q6: save  (7 points)
// Save the linked list of employees to a file list.txt using ofstream.
// You will need to save the number of employees in linked list. That will help in load() when reading the file.
// One format to store is:
// <no. of employees>
// <Employee1 name>
// <Employee1 salary>
// <Employee1 type>
// <Employee2 name>
// <Employee2 salary>
// <Employee2 type>
// and so on..
// You may store the list in another format if you wish. You need to read the file in load () the same way that it is saved in save().
// This function is called when exiting the program (end of main() ).
// Hint: You may want to cast the enum �empType� to an int before writing it to the file.


void save(string fileName)
{

	//Counting variable
	int elements = 0;

	//Container list iterator
	Container* tempList = list;

	//Counting iterator
	while (tempList != NULL)
	{

		//Iterate and increment count
		tempList = tempList->next;
		elements++;

	}//End of counting iterator

	//Save
	if (elements > 0)
	{

		//Writing variable and file open
		ofstream write;
		write.open(fileName);

		//Write contents
		if (write.is_open())
		{

			//Save node count
			write << elements << endl;

			//Reset tempList
			tempList = list;

			//Writing iterator
			for (int a = 0; a < elements; a++)
			{

				//Save node members
				write << tempList->emp->getName() << endl;
				write << tempList->emp->getSalary() << endl;
				
				//Cast of enum type
				int type = static_cast<int>(tempList->emp->getEmpType());

				//Save employee type
				write << type << endl;

				//Iterate
				tempList = tempList->next;

			}//End of writing iterator

			//Close file
			write.close();

		}//End of write contents

	}//End of save

}//End of function save

// Q7: load (7 points)
// Load the linked list of employees from the file using ifstream.
// You will need to create the linked list in the same order that is was saved to the file in save().
// First, read the number of employees saved in the file.
// Then, for every employee you will need to create a new Employee node depending on employee type. You may add the employee to head or tail of the list. 
// Hint: If you casted the enum 'empType' to an int, you will need to cast it back to 'empType' when making the employee node.
// This function is called at the beginning of main().

void load(string fileName)
{

	//Reading variable and file open
	ifstream read;
	read.open(fileName);

	//Read contents
	if (read.is_open())
	{

		//Node count variable
		int elements = 0;

		//Read node count
		read >> elements;

		//Temporary member holders
		string name;
		double salary;
		empType type;
		int tempType;

		//Reading iterator
		for (int a = 0; a < elements; a++)
		{

			//Load members
			read >> name;
			read >> salary;
			read >> tempType;

			//Cast to enum type
			type = static_cast<empType>(tempType);

			//Add node to list
			addEmployee(name, salary, type);

		}//End of reading iterator

		//Close file
		read.close();

	}//End of read contents

}//End of function load