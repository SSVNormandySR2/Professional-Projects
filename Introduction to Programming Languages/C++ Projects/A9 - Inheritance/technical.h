#ifndef _TECHNICAL_H_
#define _TECHNICAL_H_

// Q1b: Create Technical class (5 points)
class Technical : public Employee
{

	//Public members
	public:

		//Constructor
		Technical(string empName, double salary, empType employeeType) : Employee(empName, salary, employeeType) {};

		//Technical Employee display function
		void displayEmployee();

};//End of class Technical

#endif // _TECHNICAL_H_