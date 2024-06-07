/*------------------------------------------------------------------------- 
// AUTHOR: Vincent Latona
// FILENAME: Collection.java
// SPECIFICATION: User defined class to provide methods for the driver class
// TIME SPENT: 4 hours
//----------------------------------------------------------------------*/

public class Collection 
{
	
	//Instance variables
	private int[] numArray;
	private int count;
	
	/**
	 This constructor creates an empty array of a user-specified size
	 */
	public Collection(int arraySize)
	{
		
		count = 0;
		numArray = new int[arraySize];
		
	}//End of constructor
	
	/**
	 This method is a service method that searches for a number specified by a user
	 */
	private int search(int searchingNum)
	{
		
		//Values to evaluate the loop
		int i = 0;
		boolean done = false;
		
		//Searching loop
		while (i < numArray.length && !done)
		{
			
			//Number found condition
			if (numArray[i] == searchingNum)
			{
				
				//Number found, end loop
				done = true;
				
			}
			
			//Number not found condition
			else
			{
				
				//Number not found, increment and look again
				i++;
				
			}//End of not found condition
			
		}//End of searching loop
		
		//Number found return condition
		if (done)
		{
			
			return i;
			
		}//End of found return
		
		//Not found return condition
		else
		{
			
			return -1;
			
		}//End of not found return
		
	}//End of search method
	
	/**
	 This method adds a user-specified number to the array
	 */
	public boolean add(int numberToAdd)
	{
		
		//Boolean to return
		boolean answer;
		
		//Condition to double array size if the array is filled and the desired number is not in the array
		if (count >= numArray.length && search(numberToAdd) < 0)
		{
			
			//Service method to double the array size
			doubleArray();
			
		}//End of double array condition
		
		//Condition to add number to the array if not already present
		if (count < numArray.length && search(numberToAdd) < 0)
		{
			
			//Adding of number to the array at the lowest index
			numArray[count] = numberToAdd;
			
			//Boolean becomes true
			answer = true;
			
			//Increment of count to specify the number of actual elements in the array
			count++;
			
		}
		
		//Condition when the number desired already exists in the array
		else
		{
			
			//Boolean becomes false
			answer = false;
			
		}
		
		//Return of boolean to driver program
		return answer;
		
	}//End of add method
	
	/**
	 This method removes a user-specified number to the array
	 */
	public boolean remove(int numberToRemove)
	{
		
		//Boolean to be returned
		boolean answer;
		
		//Assignment of element index to a variable
		int a = search(numberToRemove);
		
		//Condition to remove the element
		if (a > -1)
		{
			
			//Loop to shift all values to the left
			for (int i = a + 1; i < count; i++)
			{
				
				//Shifting of variables to the left
				numArray[i - 1] = numArray[i];
				
			}//End of shifting loop
			
			//Boolean becomes true
			answer = true;
			
			//Decrement the size of the array
			count--;
			
		}//End of removing condition
		
		//Condition if the element is not in the array
		else
		{
			
			//Boolean becomes false
			answer = false;
			
		}//End of not present condition
		
		return answer;
		
	}//End of remove method
	
	/**
	 This service method doubles the size of the array
	 */
	private void doubleArray()
	{
		
		int[] temp = new int[numArray.length];
		
		//Loop to store values from the array before it is altered
		for(int i = 0; i < numArray.length; i++)
		{
			
			//Saving of array values to be populated in the new array
			temp[i] = numArray[i];
			
		}//End of saving loop
		
		//Variable to store the previous size of the array
		int a = numArray.length;
		
		//Double array size
		int b = numArray.length * 2;
		numArray = new int[b];
		
		//Loop to populate the new array
		for (int j = 0; j < a; j++)
		{
			
			//Filling of new/larger array with previous values
			numArray[j] = temp[j];
			
		}//End of new array population
		
	}//End of doubleArray method
	
	/**
	 This method searches for the largest element
	 */
	public int findLargest()
	{
		
		//Variable to store the largest element
		int largest = numArray[0];
		
		//Loop to evaluate largest element
		for (int i = 1; i < numArray.length; i++)
		{
			
			//Condition for larger element
			if (numArray[i] > largest)
			{
				
				//Assignment of new largest value
				largest = numArray[i];
				
			}//End of larger condition
					
		}//End of largest loop
		
		//Display of largest value of the array
		return largest;
		
	}//End of findLargest method
	
	/**
	 This method computes the average of the integers stored in the array
	 */
	public double computeAvg()
	{
		
		//Variable to store the sum
		double sum = 0;
		
		//Loop to find sum of all values
		for (int i = 0; i < numArray.length; i++)
		{
			
			sum = sum + numArray[i];
			
		}//End of summation loop
		
		double avg = sum / count;
		
		return avg;
		
	}//End of computeAvg method
	
	/**
	 This method counts the number of positive values in the array
	 */
	public int countPositive()
	{
		
		//Variable to store positive values
		int pos = 0;
		
		//Loop to evaluate positive values
		for (int i = 0; i < numArray.length; i++)
		{
			
			//Positive condition
			if (numArray[i] > 0)
			{
				
				//Incrementation of positive counter
				pos++;
				
			}//End of positive condition
			
		}//End of element evaluation loop
		
		//Display of number of positive values
		return pos;
		
	}//End countPositive method
	
	/**
	 This method returns a string of the array of the object
	 */
	public String toString()
	{
		
		//Beginning, middle, and ending parts of the array display
		String start = "{";
		String center = "";
		
		for (int i = 0; i < count - 1; i++)
		{
			
			center = center + numArray[i] + ", ";
			
		}
		
		String end = "" + numArray[count - 1] + "}";
		
		return start + center + end;
		
	}//End of toString method
	
}//End of Collection class