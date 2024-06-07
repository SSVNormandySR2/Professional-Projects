
import java.util.*; //Use of ArrayLists

//Class Appointment for Doctors and Nurses
public class Appointment {

	// Private variables
	private String height;
	private String weight;
	private String bloodPressure;
	private ArrayList<String> allergies;
	private ArrayList<String> concerns;
	private ArrayList<String> newMeds;
	private String summary;
	private Patient patient;

	// Constructor
	public Appointment(String h, String w, String bp, Patient p) {

		// Set private variables
		height = h;
		weight = w;
		bloodPressure = bp;
		summary = "";
		patient = p;

	}// End of constructor

	public Appointment() {

	}

	// Public methods
	// Mutators
	// Set Height
	public boolean setHeight(String h) {

		// Set height and return true
		height = h;
		return true;

	}// End of method setHeight

	// Set Weight
	public boolean setWeight(String w) {

		// Set weight and return true
		weight = w;
		return true;

	}// End of method setWeight

	// Set BP
	public boolean setBP(String bp) {

		// Set BP and return true
		bloodPressure = bp;
		return true;

	}// End of method setBP

	// Set Patient
	public boolean setPatient(Patient p) {

		// Set patient and return true
		patient = p;
		return true;

	}// End of method setPatient

	// Set Summary
	public boolean setSummary(String s) {

		// Set summary and return true
		summary = s;
		return true;

	}// End of method setSummary

	// Add Allergy
	public boolean addAllergy(String allergy) {

		// Add allergy and return true/false
		boolean bool = allergies.add(allergy);
		return bool;

	}// End of method addAllergy

	// Remove Allergy
	public boolean removeAllergy(String allergy) {

		// Remove allergy and return true/false
		boolean bool = allergies.remove(allergy);
		return bool;

	}// End of method removeAllergy

	// Add Concern
	public boolean addConcern(String concern) {

		// Add concern and return true/false
		boolean bool = concerns.add(concern);
		return bool;

	}// End of method addConcern

	// Remove Concern
	public boolean removeConcern(String concern) {

		// Remove concern and return true/false
		boolean bool = concerns.remove(concern);
		return bool;

	}// End of method removeConcern

	// Add Med
	public boolean addMed(String med) {

		// Add new med and return true/false
		boolean bool = newMeds.add(med);
		return bool;

	}// End of method addMed

	// Remove Med
	public boolean removeMed(String med) {

		// Remove new med and return true/false
		boolean bool = newMeds.remove(med);
		return bool;

	}// End of method removeMed

	// createSummary method for the appointment
	public String createSummary() {

		// Generate summary of appointment
		summary = "Allergies:\n" + allergies.toString() + "Concerns:\n" + concerns.toString() + "New Medications:\n"
				+ newMeds.toString();

		return summary;
	}// End of method createSummary

	// Update History
	/*
	 * public boolean updateHistory() {
	 * 
	 * //Update visit history with summary patient.updateVisit(summary); return
	 * true;
	 * 
	 * }//End of method updateHistory
	 * 
	 * //Send Prescriptions public boolean sendPrescriptions(PrescriptionHandler ph)
	 * {
	 * 
	 * //Send prescriptions to pharmacy and return true/false boolean bool =
	 * ph.sendToPharmacy(patient.getPharmacy(), newMeds); return bool;
	 * 
	 * }//End of method sendPrescriptions
	 */

}// End of class Appointment
