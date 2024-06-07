/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Builder.java
// SPECIFICATION: Class to aid Lab7 class
// TIME SPENT: 3 hours total
//-----------------------------------------------------------*/

//Class name must match filename
public class Builder 
{
	//Instance variable declaration
	
	//String to store builder name
	private String name = ""; 
	
	//Builder constructor
	Builder(String name)
	{
		
		//Binding of instance variable to object state
		this.name = name; 
		
	}//End of constructor
	
	/**
	 * Method to return the name input by the user
	 */
	public String getName()
	{
		
		//Return of name of builder
		return name; 
		
	}//End of getName method
	
	/**
	 * Method to create row of characters of a specific length specified by the user
	 */
	public String makeRow(int n, String s)
	{
		
		String a = ""; //String to be returned
		
		//Loop to create a row of characters
		for (int i = 0; i < n; i++)
		{
			
			//Creation of row of characters
			a = a + s; 
				
		}//End of row loop
		
		//Return of string of row of characters
		return a; 
		
	}//End of makeRow method
	
	/**
	 * Method to create a pyramid from a base length and character specified by the user
	 */
	public void makePyramid(int n, String s)
	{
		
		//String to contain a row created by the makeRow method
		String a = "";
		
		//Loop to create a pyramid of characters
		for (int j = 1; j <= n; j = j + 2)
		{
			
			//String to create row enclosers
			String b = "";
			
			//Loop to create row enclosers
			for (int i = 0; i < ((n - j) / 2); i++)
			{
				
				//Creation of row enclosers
				b = b + "_";
				
			}//End of row encloser loop
			
			//Method call to create the row of characters
			a = makeRow(j, s);
			
			//Concatenation of enclosers and the row of characters
			System.out.println(b + a + b);
			
		}//End of pyramid loop
		
		//Creation of space after the pyramid for further functionality in the future
		System.out.println();
		
	}//End of makePyramid method
	
}//End of Builder class
