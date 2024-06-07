import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import org.junit.jupiter.api.Test;
import java.util.*;
import java.util.stream.Stream;

class ssnTest 
{
	hw2Question2 program = new hw2Question2(); //Testing object
	
	/*
	 * Generate test cases to be used
	 */
	private static Stream<Arguments> inputs()
	{
		return Stream.of(
				Arguments.of("333-50-5000", "valid ssn"), //All S1-1 partition cases
				Arguments.of("333-50-555", "invalid ssn"),
				Arguments.of("333-50-0000", "invalid ssn"),
				Arguments.of("333-5-5000", "invalid ssn"),
				Arguments.of("333-5-555", "invalid ssn"),
				Arguments.of("333-5-0000", "invalid ssn"),
				Arguments.of("333-00-5000", "invalid ssn"),
				Arguments.of("333-00-555", "invalid ssn"),
				Arguments.of("333-00-0000", "invalid ssn"),
				Arguments.of("777-50-5000", "valid ssn"), //All S1-2 partition cases
				Arguments.of("777-50-555", "invalid ssn"),
				Arguments.of("777-50-0000", "invalid ssn"),
				Arguments.of("777-5-5000", "invalid ssn"),
				Arguments.of("777-5-555", "invalid ssn"),
				Arguments.of("777-5-0000", "invalid ssn"),
				Arguments.of("777-00-5000", "invalid ssn"),
				Arguments.of("777-00-555", "invalid ssn"),
				Arguments.of("777-00-0000", "invalid ssn"),
				Arguments.of("55-50-5000", "invalid ssn"), //All E1-1 partition cases
				Arguments.of("55-50-555", "invalid ssn"),
				Arguments.of("55-50-0000", "invalid ssn"),
				Arguments.of("55-5-5000", "invalid ssn"),
				Arguments.of("55-5-555", "invalid ssn"),
				Arguments.of("55-5-0000", "invalid ssn"),
				Arguments.of("55-00-5000", "invalid ssn"),
				Arguments.of("55-00-555", "invalid ssn"),
				Arguments.of("55-00-0000", "invalid ssn"),
				Arguments.of("000-50-5000", "invalid ssn"), //All E1-2 partition cases
				Arguments.of("000-50-555", "invalid ssn"),
				Arguments.of("000-50-0000", "invalid ssn"),
				Arguments.of("000-5-5000", "invalid ssn"),
				Arguments.of("000-5-555", "invalid ssn"),
				Arguments.of("000-5-0000", "invalid ssn"),
				Arguments.of("000-00-5000", "invalid ssn"),
				Arguments.of("000-00-555", "invalid ssn"),
				Arguments.of("000-00-0000", "invalid ssn"),
				Arguments.of("666-50-5000", "invalid ssn"), //All E1-3 partition cases
				Arguments.of("666-50-555", "invalid ssn"),
				Arguments.of("666-50-0000", "invalid ssn"),
				Arguments.of("666-5-5000", "invalid ssn"),
				Arguments.of("666-5-555", "invalid ssn"),
				Arguments.of("666-5-0000", "invalid ssn"),
				Arguments.of("666-00-5000", "invalid ssn"),
				Arguments.of("666-00-555", "invalid ssn"),
				Arguments.of("666-00-0000", "invalid ssn"),
				Arguments.of("955-50-5000", "invalid ssn"), //All E1-4 partition cases
				Arguments.of("955-50-555", "invalid ssn"),
				Arguments.of("955-50-0000", "invalid ssn"),
				Arguments.of("955-5-5000", "invalid ssn"),
				Arguments.of("955-5-555", "invalid ssn"),
				Arguments.of("955-5-0000", "invalid ssn"),
				Arguments.of("955-00-5000", "invalid ssn"),
				Arguments.of("955-00-555", "invalid ssn"),
				Arguments.of("955-00-0000", "invalid ssn")
				);
	}
	
	@ParameterizedTest
	@MethodSource("inputs")
	void strongRobust(String input, String expected) 
	{
		assertEquals(program.validateSSN(input), expected); //Test each input against the expected output
	}

}
