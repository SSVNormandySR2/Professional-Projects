import java.util.*;

public class Nurse extends User {
	
	private Doctor doc;

	Nurse(String fname, String lname, String birthDate, String uname, String pass, String phoneNumber, String mail) {

		super(false, true, false, fname, lname, birthDate, uname, pass, phoneNumber, mail);
	}

	public boolean changeName(String newFirst, String newLast) {

		return super.changeName(newFirst, newLast);
	}

	public boolean changeDOB(String birth) {

		return super.changeDOB(birth);
	}

	public boolean changePhone(String newPhone) {

		return super.changePhone(newPhone);
	}

	public boolean changeEmail(String mail) {

		return super.changeEmail(mail);
	}
	
	/*public boolean addPatient(Patient p) {

		boolean bool = patients.add(p);
		return bool;
	}


	public boolean removePatient(Patient p) {

		boolean bool = patients.remove(p);
		return bool;
	}*/

	public String toString() {

		return "First Name: " + fName + "\nLast Name: " + lName + "\nDate of Birth: " + dob + "\nPhone Number: " + phone
				+ "\nEmail: " + email + "\n";
	}
}
