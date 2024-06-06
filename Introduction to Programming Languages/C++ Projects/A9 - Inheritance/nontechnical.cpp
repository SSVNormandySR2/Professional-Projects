#include "employee.h"
#include "nontechnical.h"
#include <iostream>
#include <string>

using namespace std;

//Nontechnical implementation of Employee display function
void Nontechnical::displayEmployee()
{

	//Data member display
	cout << "\nEmployee: " << getName() << endl;
	cout << "Salary: " << getSalary() << endl;
	cout << "Employee Type: Nontechnical\n" << endl;

}//End of function displayEmployee