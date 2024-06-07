// Assignment #: 11
// Name: Vincent Latona
// Description: Patient class represent a patient
// that visits a hospital to see a doctor.

public class Patient
 {
   private String conditionLevel;
   private int patientID;

   //Constructor to initialize member variables
   public Patient(int patientID, String level)
    {
     this.patientID = patientID;
     this.conditionLevel = level;
    } 

   //Accessor method to access its patientID
   public int getPatientID()
    {
     return patientID;
    }
  
   //Accessor method to access its conditionLevel
   public String getConditionLevel()
    {
     return conditionLevel;
    }
     
   //toString method returns a string containing
   //the information of a patient
   public String toString( )
    {
     String result = "Patient ID: " + patientID
                   + "/Condition Level: (" + conditionLevel +")";
     return result;
    }

 }