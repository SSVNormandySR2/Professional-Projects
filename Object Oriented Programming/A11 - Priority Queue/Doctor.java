// Assignment #: 11
// Name: Vincent Latona
// Time took you to complete the assignment: 14 minutes
// Description: The doctor class represents a doctor and
// the patients that they care for.


public class Doctor
 {
  private int doctorID;
  private Patient currentPatient;

  //Constructor to initialize member variables
  //Initially no patient is assigned
  public Doctor(int id)
   {
    this.doctorID = id;
    currentPatient = null;
   }

  //toString method returns a string containing
  //the information of a doctor 
  public String toString()
   {
    String result = "Doctor id " + doctorID;

    if (currentPatient == null)
      result += " is not seeing any patient";
    else
      result += " is seeing a patient with id " + currentPatient.getPatientID();

    return result;
   }
     
  /**
   * This method returns true if the doctor has a patient assigned 
   * and false otherwise
   */
  public boolean hasPatient()
  {
	  
	  //No patient
	  if(currentPatient == null)
	  {
		  
		  //False for no patient
		  return false;
		  
	  }//End of no patient case
	  
	  //Patient present
	  else
	  {
		  
		  //True for patient present
		  return true;
		  
	  }//End of patient present case
	  
  }//End of hasPatient method
  
  /**
   * This method assigns a patient and returns true 
   * if the doctor does not have a patient, 
   * and returns false otherwise
   */
  public boolean assignPatient(Patient patient)
  {
	  
	  //Assignment
	  if(currentPatient == null)
	  {
		  
		  //Patient assignment and true return
		  currentPatient = patient;
		  return true;
		  
	  }//End of assignment case
	  
	  //Has patient
	  else
	  {
		  
		  //False when doctor has a patient
		  return false;
		  
	  }//End of has patient case
	  
  }//End of assignPatient method
  
  /**
   * This method returns the current patient 
   * and sets currentPatient to null
   */
  public Patient releasePatient()
  {
	  
	  //Release
	  if(currentPatient != null)
	  {
		  
		  //Patient reset and patient return
		  Patient patient = currentPatient;
		  currentPatient = null;
		  return patient;
		  
	  }//End of release case
	  
	  //No patient
	  else
	  {
		  
		  //null when there is no patient
		  return null;
		  
	  }//End of no patient case
	  
  }//End of releasePatient method
     
 }//End of Doctor class