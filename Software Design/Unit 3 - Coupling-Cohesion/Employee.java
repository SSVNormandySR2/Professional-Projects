/*
 * Vincent Latona
 */


/*
 * This class represents employees, who are personnel
 */
public class Employee extends Person
{
	private int empID; //Employee ID field
	private double baseSalary; //Salary field

	/*
	 * This constructor creates an employee
	 */
	public Employee(String last, String first, String middle, int id, double sal) 
	{
		super(last, first, middle); //Use parent constructor
		empID = id; //Set ID
		baseSalary = sal; //Set salary
	}

	/*
	 * This method returns the Employee ID
	 */
	public int getID()
	{
		return empID; //Return ID
	}
}