/*
 * Vincent Latona
 */

import java.util.*; //Import ArrayList

/*
 * This class represents a collection of person objects
 */
public class Personnel 
{
	private ArrayList<Person> personList; //List of person objects
	private PersonnelFactory factory; //Factory for object creation

	/*
	 * This constructor initializes the list
	 */
	public Personnel() 
	{
	   personList = new ArrayList<Person>(); //Initialize list
	   factory = new PersonnelFactory(); //Initialize factory
	}

	/*
	 * This method adds a new employee to the list
	 */
	public void addPersonnel(String last, String first, String middle, int id, double sal)
	{
		personList.add(factory.createPersonnel(2, last, first, middle, id, sal)); //Create and add employee to list
	}
	
	/*
	 * This method searches the list for a person by name
	 */
	public void search(String first, String last)
	{
		for(Person p : personList) //Iterate over list
		{
			if(p.getFirst().equals(first) & p.getLast().equals(last)) //Found case
			{
				System.out.println("Found\n"); //Print found message
				p.printNameFML(); //Print found person
				System.out.println(); //Print newline
				return; //End method
			}
		}
		System.out.println("Not found\n"); //Print unfound message
		personList.add(factory.createPersonnel(1, last, first, " ", 0, 0)); //Add the person to the list
		return; //End method
	}

	/*
	 * This method returns the total number of objects created
	 */
	public int getTotalObjects()
	{
		return personList.size(); //Return length of list
	}
	
	/*
	 * This method prints all names in the list in first, middle, last order
	 */
	public void printNamesFML()
	{
		for(Person p : personList) //Iterate over list
		{
			p.printNameFML(); //Print person
		}
		if(personList.size() == 0) //Empty list case
		{
			System.out.println("Please add personnel to display."); //Print instruction message
		}
		System.out.println(); //Print newline
	}
	
	/*
	 * This method prints all names in the list in last, middle, first order
	 */
	public void printNamesLMF()
	{
		for(Person p : personList) //Iterate over list
		{
			p.printNameLMF(); //Print person
		}
		if(personList.size() == 0) //Empty list case
		{
			System.out.println("Please add personnel to display."); //Print instruction message
		}
		System.out.println(); //Print newline
	}
	
	/*
	 * This method prints all names in the list in first, middle, last order
	 */
	public void printNamesLFM()
	{
		for(Person p : personList) //Iterate over list
		{
			p.printNameLFM(); //Print person
		}
		if(personList.size() == 0) //Empty list case
		{
			System.out.println("Please add personnel to display."); //Print instruction message
		}
		System.out.println(); //Print newline
	}
}