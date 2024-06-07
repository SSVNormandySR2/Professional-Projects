import java.util.*;

//Parent User class for all users
public class User {

	// Protected variables
	protected String fName;
	protected String lName;
	protected String dob;
	protected String username;
	protected String password;
	protected String phone;
	protected String email;
	protected boolean dr;
	protected boolean nurse;
	protected boolean patient;

	// Constructor
	User(boolean doc, boolean nur, boolean pat, String fname, String lname, String birthDate, String uname, String pass,
			String phoneNumber, String mail) {

		// Assign data members
		fName = fname;
		lName = lname;
		dob = birthDate;
		username = uname;
		password = pass;
		phone = phoneNumber;
		email = mail;
		dr = doc;
		nurse = nur;
		patient = pat;

	}// End of Constructor

	User() {

	}

	public String getFName() {
		return fName;
	}

	public String getLName() {
		return lName;
	}

	public String getBirthDate() {
		return dob;
	}

	public String getUserName() {
		return username;
	}

	public String getPassword() {
		return password;
	}

	public String getPhoneNum() {
		return phone;
	}

	public String getEmail() {
		return email;
	}

	// Mutators
	// changeName method
	public boolean changeName(String newFirst, String newLast) {

		// Set data members and return true
		fName = newFirst;
		lName = newLast;
		return true;

	}// End of method changeName

	// changeDOB method
	public boolean changeDOB(String birth) {

		// Set data member and return true
		dob = birth;
		return true;

	}// End of method changeDOB

	// changePhone method
	public boolean changePhone(String newPhone) {

		// Set data member and return true
		phone = newPhone;
		return true;

	}// End of method changePhone

	// changeEmail method
	public boolean changeEmail(String mail) {

		// Set data member and return true
		email = mail;
		return true;

	}// End of changeEmail method

	// isDoctor method
	public boolean isDoctor() {

		// Return boolean data
		return dr;

	}// End of isDoctor method

	// isNurse method
	public boolean isNurse() {

		// Return boolean data
		return nurse;

	}// End of isNurse method

	// isPatient method
	public boolean isPatient() {

		// Return boolean data
		return patient;

	}// End of isPatient method

	// toString method
	public String toString() {

		return "First Name: " + fName + "\nLast Name: " + lName + "\nDate of Birth: " + dob + "\nPhone Number: " + phone
				+ "\nEmail: " + email + "\n";

	}// End of toString method

}// End of class User