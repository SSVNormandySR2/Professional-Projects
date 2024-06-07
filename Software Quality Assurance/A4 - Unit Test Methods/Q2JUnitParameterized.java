/*
 * Vincent Latona
 */

import static org.junit.jupiter.api.Assertions.*;
import java.util.stream.Stream;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.MethodSource;
import org.junit.jupiter.params.provider.ValueSource;

class Q2JUnitParameterized 
{
	public static String sortStr(String str)
	{
		char char_array[] = str.toCharArray();
		char temp; 
		
		int i = 0;
		while(i < char_array.length)
		{
			int j = i + 1;
			while(j < char_array.length)
			{
				if(char_array[j] < char_array[i])
				{
					temp = char_array[i];
					char_array[i] = char_array[j];
					char_array[j] = temp;
				}
				j += 1;
			}
			i += 1;
		}
		String returnStr = String.valueOf(char_array);
		return returnStr;
	}
	
	@ParameterizedTest
	@CsvSource({ //Define parameters
			"'',''", //Path 1
			"i,i", //Path 2
			"ij,ij", //Path 3
			"ij,ji" //Path 4
	})
	/*
	 * This parameterized test covers all paths of the sortStr method
	 */
	void ParameterizedSortStr(String expected, String input)
	{
		assertEquals(expected, sortStr(input));
	}

}
