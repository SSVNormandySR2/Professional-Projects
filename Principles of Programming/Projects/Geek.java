/*------------------------------------------------------------------------- 
// AUTHOR: Vincent Latona
// FILENAME: Geek.java
// SPECIFICATION: User-defined class to be utilized by the Assignment5 class.
// TIME SPENT: 4 hours 15 minutes
//----------------------------------------------------------------------*/

//Class name must be the same as filename
public class Geek 
{
	
	//Instance variable declaration
	private String geekName;
	private int questionsAsked;
	
	//Constructor for Geek objects
	public Geek(String name)
	{
		
		//Data member assignment
		this.geekName = name;
		questionsAsked = 0;
		
	}//End of Geek constructor
	
	/**
	 This method returns the name of the geek object
	 */
	public String getName()
	{
		
		//Returns the name of the geek's name
		return geekName;
		
	}//End of getName method
	
	/**
	 This method returns the number of questions asked
	 */
	public int getNumberOfQuestions()
	{
		
		//Returns the number of questions asked
		return questionsAsked;
		
	}//End of getNumberOfQuestions method
	
	/**
	 This method evaluates if a number is even
	 */
	public boolean isEven(int num)
	{
		
		//Boolean to be returned
		boolean numEven;
		
		//Check if number is even
		if (num % 2 == 0)
		{
			
			//Number is true when even
			numEven = true;
			
		}//End of true condition
		
		else
		{
			
			//Number is false when odd
			numEven = false;
			
		}//End of false condition
		
		//Increment the questions asked
		questionsAsked++;
		
		//Return boolean for if the number is even or not
		return numEven;
		
	}//End of isEven method
	
	/**
	 This method concatenates a user specified string a specified number of times
	 */
	public String multiConcat(String str, int count)
	{
		
		//String to be returned
		String concated = "";
		
		//Loop to concatenate a string to itself a specified number of times
		for (int i = 1; i <= count; i++)
		{
			
			//Concatenation of string to itself
			concated = concated + str;
			
		}//End of concatenation loop
		
		//Increment the questions asked
		questionsAsked++;
		
		//Returns the concatenated string
		return concated;
		
	}//End of multiConcat method
	
	/**
	 This method calculates the sum of 2 numbers if they're in sequence
	 */
	public int sumRange(int num1, int num2)
	{
		
		//Variable to hold the sum
		int sum = 0;
		
		//Condition if numbers are the same
		if (num1 == num2)
		{
			
			//Prints 0 if numbers are the same
			sum = 0;
			
		}//End of equal numbers condition
		
		//True condition to accept if the numbers are proper values
		else if (num1 < num2)
		{
			
			//Loop to calculate the sum of the range exclusively
			for (int i = num1 + 1; i < num2; i++)
			{
				
				//Summation calculation
				sum = sum + i;
				
			}//End of summation loop
			
			System.out.println(sum);
			
		}//End of different numbers condition
		
		//False condition to display an error message
		else
		{
			
			//Prints 0 if num1 is larger than num2
			sum = 0;
			
			
		}//End of default condition
		
		//Increment questions asked
		questionsAsked++;
		
		//Returns the sum
		return sum;
		
	}//End of sumRange method
	
	/**
	 This method evaluates if a number set is sorted
	 */
	public boolean sorted(int num1, int num2, int num3)
	{
		
		//variable to be returned
		boolean correct;
		
		//Evaluate if the number set is sorted
		if ((num1 < num2 && num1 < num3) && (num2 > num1 && num2 < num3))
		{
			
			//Make boolean true
			correct = true;
			
		}//End of sorted number set
		
		//Number set is unsorted
		else
		{
			
			//Make boolean false
			correct = false;
			
		}//End of unsorted set
		
		//Increment questions asked
		questionsAsked++;
		
		//Return of boolean value
		return correct;
		
	}//End of sorted method
	
	/**
	 This method counts the number of a's in a user string input
	 */
	public int countA(String str)
	{
		
		//Convert string to lower-case to evaluate the number of a's
		str = str.toLowerCase();
		
		//Variable for number of a's in a string
		int numA = 0;
		
		
		//Loop to count the number of a's in a string
		for (int i = 0; i < str.length(); i++)
		{
			
			//Character to store the character of the string at an index
			char ch = str.charAt(i);
			
			if (ch == 'a')
			{
				
				//Increment numA
				numA++;
				
			}//End of a's condition
			
		}//End of a counting loop
		
		//Increment questions asked
		questionsAsked++;
		
		//Return number of a's in the string
		return numA;
		
	}//End of countA method
	
	public int countDigits(int num)
	{
		
		//Variable to count number of digits
		int digits = 0;
		
		//Conversion of input to a string
		String numDigits = "" + num;
		
		//Calculate the length of the string
		int length = numDigits.length();
		
		//Assign length to digits
		digits = length;
		
		//Increment questions asked
		questionsAsked++;
		
		//Return digits in the number
		return digits;
		
	}//End of countDigits method
	
	public boolean isPrime(int num)
	{
		
		//Variable to store true/false for prime
		boolean prime;
		
		//Evaluation of core prime numbers that are factors of all other numbers
		if (num == 2 || num == 3 || num == 5 || num == 7)
		{
			
			//Number is prime, make true
			prime = true;
			
		}//End of core primes
		
		//Evaluation if the number is divisible by values other than itself and 1
		else if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0)
		{
			
			//Number is prime, make true
			prime = true;
			
		}//End of primes by calculation
		
		//Non-prime number condition
		else
		{
			//Number is not prime, make false
			prime = false;
			
		}//End of non-primes
		
		//Increment questions asked
		questionsAsked++;
		
		//Return boolean prime
		return prime;
		
	}//End of isPrime method

}//End of Geek class
