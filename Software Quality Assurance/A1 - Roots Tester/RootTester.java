/*
 * Vincent Latona
 */

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class RootTester {

	@Test
	public void SR1()
	{
		Roots.calculate_roots(2, 0, -2); //Calculate roots
		assertEquals(2.0, Roots.num_roots()); //Get number of roots
		assertEquals(1.0, Roots.first_root()); //Get root one
		assertEquals(-1.0, Roots.second_root()); //Get root two
	}
	
	@Test
	public void SR2()
	{
		Roots.calculate_roots(1, -4, 4); //Calculate roots
		assertEquals(1.0, Roots.num_roots()); //Get number of roots
		assertEquals(2.0, Roots.first_root()); //Get root one
		assertEquals(2.0, Roots.second_root()); //Get root two
	}
	
	@Test
	public void SR3()
	{
		Roots.calculate_roots(1, -4, 8); //Calculate roots
		assertEquals(0.0, Roots.num_roots()); //Get number of roots
		assertEquals(-1.0, Roots.first_root()); //Get root one
		assertEquals(-1.0, Roots.second_root()); //Get root two
	}
	
	@Test
	public void SR4()
	{
		boolean failed = false; //Boolean to test failure
		try //Test program
		{
			Roots.calculate_roots(0, 0, 5); //Calculate roots
		}
		catch(ArithmeticException e) //Catch Arithmetic exception
		{
			failed = true;
			assertTrue(failed); //Pass test case
		}
	}

}
