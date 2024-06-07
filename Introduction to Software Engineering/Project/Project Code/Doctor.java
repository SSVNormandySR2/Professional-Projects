import java.util.*;

//Child Doctor class for doctors
public class Doctor extends User {

	// Private variables of Doctor
	private ArrayList<Nurse> nurses;
	// private ArrayList<Patient> patients;

	// Constructor
	Doctor(String fname, String lname, String dob, String username, String password, String phone, String mail) {

		// Build Doctor user
		super(true, false, false, fname, lname, dob, username, password, phone, mail);

	}// End of Constructor

	// Mutators
	// changeName method
	public boolean changeName(String newFirst, String newLast) {

		// Use user
		return super.changeName(newFirst, newLast);

	}// End of method changeName

	// changeDOB method
	public boolean changeDOB(String birth) {

		// Use user
		return super.changeDOB(birth);

	}// End of method changeDOB

	// changePhone method
	public boolean changePhone(String newPhone) {

		// Use user
		return super.changePhone(newPhone);

	}// End of method changePhone

	// changeEmail method
	public boolean changeEmail(String mail) {

		// Use user
		return super.changeEmail(mail);

	}// End of changeEmail method

	// addPatient method
	/*
	 * public boolean addPatient(Patient p) {
	 * 
	 * // Add patient and return true boolean bool = patients.add(p); return bool;
	 * 
	 * }// End of addPatient method
	 * 
	 * // removePatient method public boolean removePatient(Patient p) {
	 * 
	 * // Remove patient and return true boolean bool = patients.remove(p); return
	 * bool;
	 * 
	 * }// End of removePatient method
	 */

	// removeNurse method
	public boolean removeNurse(Nurse n) {

		// Add patient and return true
		boolean bool = nurses.remove(n);
		return bool;

	}// End of removeNurse method

	// toString method
	public String toString() {

		// Use user
		return "\n" + fName + "\n" + lName + "\n" + dob + "\n" + phone
				+ "\n" + email + "\n";

	}// End of toString method

}// End of Doctor class