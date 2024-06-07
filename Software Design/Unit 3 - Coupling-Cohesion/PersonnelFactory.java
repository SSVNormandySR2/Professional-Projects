/*
 * Vincent Latona
 */


/*
 * This class creates personnel objects
 */
public class PersonnelFactory 
{
	/*
	 * This method returns custom personnel objects
	 */
	public Person createPersonnel(int type, String last, String first, String middle, int id, double sal)
	{
		Person p = null; //Initialize to null
		switch(type) //Switch on type
		{
			case 1: //Person case
				p = new Person(last, first, middle); //Create person object
				break; //Do not fall through
			case 2: //Employee case
				p = new Employee(last, first, middle, id, sal); //Create employee object
				break; //Do not fall through
			//Future cases
		}
		return p; //Return object pointer
	}
}
