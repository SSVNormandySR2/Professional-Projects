// Assignment #: 8
//         Name: Vincent Latona
//		Time took you to complete the assignment: 5 minutes
//		Description: The President class describes a President.
//               It also provides their accessor, mutator methods,
//               and toString method.

//Package import for Serializable
import java.io.*;

public class President implements Serializable
{
 private String firstName;
 private String lastName;
 private String academicLevel;

 //Constructor method to initialize intance variables.
 public President()
  {
      firstName = new String("?");
      lastName= new String("?");
      academicLevel = new String("?");
  }

 //Accessor method for first name
 public String getFirstName()
  {
   return firstName;
  }

 //Accessor method for last name
 public String getLastName()
  {
   return lastName;
  }

  //Accessor method for academic level
  public String getAcademicLevel()
   {
    return academicLevel;
   }

 //modifier method for first name
 public void setFirstName(String someFirstName)
  {
   firstName = someFirstName;
  }

 //modifier method for last name
 public void setLastName(String someLastName)
  {
   lastName = someLastName;
  }

 //modifier method for academic level
 public void setAcademicLevel(String someAcademicLevel)
  {
   academicLevel = someAcademicLevel;
  }
 
 	/**
	 * This method copies attributes from the President parameter to the calling
	 * President
	 */
 public void copy(President other)
 {
	 
	 //Attribute copying
	 this.firstName = other.getFirstName();
	 this.lastName = other.getLastName();
	 this.academicLevel = other.getAcademicLevel();
	 
 }//End of the copy method

 //This method return a string containing the attribute information of a President
 public String toString()
  {
   String result;

      result = lastName + "," + firstName + "(" + academicLevel + ")";

   return result;
  }

}