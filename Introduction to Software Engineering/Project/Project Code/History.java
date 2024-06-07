import java.util.*;

//History class for medical history
public class History {

	// Private lists
	private ArrayList<String> immunizations;
	private ArrayList<String> visits;

	// appendVisit method to append new visit summaries
	public void appendVisit(String newVisit) {

		// Add visit summary to history
		visits.add(newVisit);

	}// End of method appendVisit

	// appendImmunizations method to add new immunizations
	public void appendImmunization(String newImm) {

		// Add immunizations to history
		immunizations.add(newImm);

	}// End of method appendImmunization

	// toString method to write contents
	public String toString() {

		return "Immunizations:\n" + immunizations.toString() + "\nVisit History:\n" + visits.toString();

	}// End of method toString

}// End of History class