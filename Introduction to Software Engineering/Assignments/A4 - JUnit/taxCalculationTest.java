/*
 * Assignment 4
 * Vincent Latona
 */

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

//JUnit testing class
class taxCalculationTest 
{

	//Create taxCalculation object
	private taxCalculation calc;
	
	//Before Each set up
	@BeforeEach
	public void setUp() throws Exception
	{
		
		//Instantiate taxCalculation object
		calc = new taxCalculation();
		
	}//End of Before Each set up
	
	//Test case 1
	@Test
	public void testTax1()
	{
		
		//Test
		assertEquals(-1, calc.calculateTax(-1));
		
	}//End of test case 1
	
	//Test case 2
	@Test
	public void testTax2()
	{
		
		//Test
		assertEquals(-1, calc.calculateTax(-0.0001));
		
	}//End of test case 2
	
	//Test case 3
		@Test
		public void testTax3()
		{
			
			//Test
			assertEquals(0, calc.calculateTax(0));
			
		}//End of test case 3
		
		//Test case 4
		@Test
		public void testTax4()
		{
			
			//Test
			assertEquals(0, calc.calculateTax(0.0001));
			
		}//End of test case 4
		
		//Test case 5
		@Test
		public void testTax5()
		{
			
			//Test
			assertEquals(0, calc.calculateTax(12500));
			
		}//End of test case 5
		
		//Test case 6
		@Test
		public void testTax6()
		{
			
			//Test
			assertEquals(0, calc.calculateTax(24999.999));
			
		}//End of test case 6
		
		//Test case 7
		@Test
		public void testTax7()
		{
			
			//Test
			assertEquals(0, calc.calculateTax(25000));
			
		}//End of test case 7
		
		//Test case 8
		@Test
		public void testTax8()
		{
			
			//Test
			assertEquals(5000.00002, calc.calculateTax(25000.0001));
			
		}//End of test case 7
		
		//Test case 9
		@Test
		public void testTax9()
		{
			
			//Test
			assertEquals(7500, calc.calculateTax(37500));
			
		}//End of test case 9
		
		//Test case 10
		@Test
		public void testTax10()
		{
			
			//Test
			assertEquals(9999.99998, calc.calculateTax(49999.9999));
			
		}//End of test case 10
		
		//Test case 11
		@Test
		public void testTax11()
		{
			
			//Test
			assertEquals(10000, calc.calculateTax(50000));
			
		}//End of test case 11
		
		//Test case 12
		@Test
		public void testTax12()
		{
			
			//Test
			assertEquals(12500.000025, calc.calculateTax(50000.0001));
			
		}//End of test case 12
		
		//Test case 13
		@Test
		public void testTax13()
		{
			
			//Test
			assertEquals(18750, calc.calculateTax(75000));
			
		}//End of test case 13
		
		//Test case 14
		@Test
		public void testTax14()
		{
			
			//Test
			assertEquals(24999.999975, calc.calculateTax(99999.9999));
			
		}//End of test case 14
		
		//Test case 15
		@Test
		public void testTax15()
		{
			
			//Test
			assertEquals(25000, calc.calculateTax(100000));
			
		}//End of test case 15
		
		//Test case 16
		@Test
		public void testTax16()
		{
			
			//Test
			assertEquals(33000.000033000004, calc.calculateTax(100000.0001));
			
		}//End of test case 16
		
		//Test case 17
		@Test
		public void testTax17()
		{
			
			//Test
			assertEquals(165000, calc.calculateTax(500000));
			
		}//End of test case 17
		
		//Test case 18
		@Test
		public void testTax18()
		{
					
			//Test
			assertEquals(329999.99996700004, calc.calculateTax(999999.9999));
					
		}//End of test case 18
		
		//Test case 19
		@Test
		public void testTax19()
		{
					
			//Test
			assertEquals(330000, calc.calculateTax(1000000));
					
		}//End of test case 19
		
		//Test case 20
		@Test
		public void testTax20()
		{
					
			//Test
			assertEquals(-1, calc.calculateTax(1000000.0001));
					
		}//End of test case 20
		
		//Test case 21
		@Test
		public void testTax21()
		{
					
			//Test
			assertEquals(-1, calc.calculateTax(1000001));
					
		}//End of test case 21

}//End of JUnit testing class
