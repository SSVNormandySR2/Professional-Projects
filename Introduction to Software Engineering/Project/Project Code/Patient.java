import java.util.*;

//Child Patient class for patients
public class Patient extends User {

	// Private variables
	private String pharmacy;
	private String insurance;
	private History history;

	// Constructor
	Patient(boolean dr, boolean nurse, boolean pat, String fName, String lName, String dob, String uname, String pass,
			String phone, String mail) {

		// Use user
		super(dr, nurse, pat, fName, lName, dob, uname, pass, phone, mail);
		pharmacy = "None";
		insurance = "None";

	}// End of Constructor

	Patient() {

	}

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

	// setPharmacy method for new pharmacy
	public void setPharmacy(String newPharm) {

		// Set new pharmacy
		pharmacy = newPharm;

	}// End of method setPharmacy

	// setInsurance method for new insurance company
	public void setInsurance(String newInsurance) {

		// Set new insurance
		insurance = newInsurance;

	}// End of setInsurance method

	// getPharmacy method for access
	public String getPharmacy() {

		// Return current pharmacy
		return pharmacy;

	}// End of method getPharmacy

	// getInsurance method for access
	public String getInsurance() {

		// Return current insurance
		return insurance;

	}// End of method getInsurance

	// updateImmunization method to add new immunizations
	public void updateImmunization(String newImm) {

		// Append immunizations
		history.appendImmunization(newImm);

	}// End of updateImmunizations

	// updateVisit method to add new visits
	public void updateVisit(String newVisit) {

		// Append visits
		history.appendVisit(newVisit);

	}// End of method updateVisit

	// toString method
	public String toString() {

		return "\n" + fName + "\n" + lName + "\n" + dob + "\n" + phone
				+ "\n" + email + "\n" + pharmacy + "\n" + insurance + "\n";

	}

}// End of Patient class