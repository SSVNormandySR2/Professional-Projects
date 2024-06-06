#ifndef _NONTECHNICAL_H
#define _NONTECHNICAL_H

// Q1a: Create Nontechnical class (5 points)
class Nontechnical : public Employee
{

	//Public members
	public:

		//Constructor
		Nontechnical(string empName, double salary, empType employeeType) : Employee(empName, salary, employeeType) {};

		//Nontechnical Employee display function
		void displayEmployee();

};//End of class Nontechnical

#endif // _NONTECHNICAL_H#pragma once