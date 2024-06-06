#include "employee.h"
#include "technical.h"
#include <iostream>
#include <string>

using namespace std;

//Technical implementation of Employee display function
void Technical::displayEmployee()
{

	//Data member display
	cout << "\nEmployee: " << getName() << endl;
	cout << "Salary: " << getSalary() << endl;
	cout << "Employee Type: Technical\n" << endl;

}//End of function displayEmployee