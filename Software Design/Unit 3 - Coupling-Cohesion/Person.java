/*
 * Vincent Latona
 */

/*
 * This class represents a person
 */
public class Person 
{
	protected String last; //String for last name
	protected String first; //String for first name
	protected String middle; //String for middle name

	/*
	 * This constructor creates a person object
	 */
	public Person(String last, String first, String middle) 
	{
		//Initialize names
		this.last = last;
		this.first = first;
		this.middle = middle;
	}
	
	/*
	 * This method returns the first name
	 */
	public String getFirst()
	{
		return first; //Return first name
	}
	
	/*
	 * This method returns the last name
	 */
	public String getLast()
	{
		return last; //Return last name
	}

	/*
	 * This method prints names in first, middle, last order
	 */
	public void printNameFML()
	{
		System.out.println(first + "  " + middle + "  " + last); //Print names in order
	}
	
	/*
	 * This method prints names in last, middle, first order
	 */
	public void printNameLMF()
	{
		System.out.println(last + " ," + middle + " " + first); //Print names in order
	}
	
	/*
	 * This method prints names in last, first, middle order
	 */
	public void printNameLFM()
	{
		System.out.println(last + " ," + first + " " + middle); //Print names in order
	}
}