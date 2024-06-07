// Assignment #: 11
// Name: Vincent Latona
// Time took you to complete the assignment: 1 hour 39 minutes
// Description: This program manages patient queues, assigns patients to doctors,
//              release them to check out, etc.

import java.util.LinkedList;

public class PatientManagement
 {
    private LinkedList<Patient> highPriorityQueue; //Requires immediate life-saving intervention
    private LinkedList<Patient> intermediateQueue; //Requires significant intervention within two to four hours.
    private LinkedList<Patient> delayedCareQueue; //Needs medical treatment, but this can safely be delayed.

    private LinkedList<Patient> checkOutQueue; //queue for patients that need to check out

    private Doctor[] doctorList; //an array of doctors
     
  //Constructor to initialize member variables
  public PatientManagement(int numOfDoctors)
    {
        highPriorityQueue = new LinkedList<Patient>();
        intermediateQueue = new LinkedList<Patient>();
        delayedCareQueue = new LinkedList<Patient>();
        checkOutQueue = new LinkedList<Patient>();

        //creating doctor objects
        doctorList = new Doctor[numOfDoctors];
        for (int i=0; i<doctorList.length; i++)
        {
            doctorList[i] = new Doctor(i);
        }
    }
     
   //The printQueue prints out the content
   //of the queues and the array of doctors
   public void printPatientQueues()
     {
         System.out.print("\nHigh Priority Queue:\n" + highPriorityQueue.toString() + "\n");
         System.out.print("\nIntermediate Queue:\n" + intermediateQueue.toString() + "\n");
         System.out.print("\nDelayed Care Queue:\n" + delayedCareQueue.toString() + "\n\n");
         for (int i = 0; i < doctorList.length; i++)
         {
             System.out.println(doctorList[i].toString());
         }
         System.out.print("\nCheck Out Queue:\n" + checkOutQueue.toString() + "\n\n");
     }
     
   /**
    * This method assigns a patient to their corresponding queue 
    * based off of their condition and returns true, 
    * otherwise returns false if patient condition does not correspond to a queue
    */
   public boolean addPatient(int patientID, String conditionLevel)
   {
	   
	   //High Priority Queue
	   if(conditionLevel.equals("High Priority"))
	   {
		   
		   //Patient creation and queue addition, return true
		   Patient patient = new Patient(patientID, conditionLevel);
		   highPriorityQueue.add(patient);
		   return true;
		   
	   }//End of high priority queue case
	   
	   //Intermediate Queue
	   else if(conditionLevel.equals("Intermediate"))
	   {
		   
		   //Patient creation and queue addition, return true
		   Patient patient = new Patient(patientID, conditionLevel);
		   intermediateQueue.add(patient);
		   return true;
		   
	   }//End of intermediate queue case
	   
	   //Delayed Care Queue
	   else if(conditionLevel.equals("Delayed Care"))
	   {
		   
		   //Patient creation and queue addition, return true
		   Patient patient = new Patient(patientID, conditionLevel);
		   delayedCareQueue.add(patient);
		   return true;
		   
	   }//End of delayed care queue case
	   
	   //No condition
	   else
	   {
		   
		   //False if conditionLevel does not match existing queues
		   return false;
		   
	   }//End of no-condition case
	   
   }//End of addPatient method
   
   /**
    * This method attempts to assign a patient from a queue to an available doctor,
    * otherwise returns null if no patients exist or no doctors are available
    */
   public Patient assignPatientToDoctor()
   {
	   
	   //Int for doctorID and boolean for availability
	   int num = 0;
	   boolean available = false;
	   
	   //Doctor search loop
	   for(int i = 0; i < doctorList.length; i++)
	   {
		   
		   //Available doctor
		   if(!doctorList[i].hasPatient())
		   {
			   
			   //Variable manipulation and loop break
			   available = true;
			   num = i;
			   break;
			   
		   }//End of available doctor case
		   
	   }//End of doctor search loop
	   
	   //No doctors
	   if(!available)
	   {
		   
		   //Null if no doctors available
		   return null;
		   
	   }//End of no doctors case
	   
	   //Patient search
	   else
	   {
		   
		   //High Priority patient
		   if(!highPriorityQueue.isEmpty())
		   {
			   
			   //Doctor assignment and patient removal
			   doctorList[num].assignPatient(highPriorityQueue.peekFirst());
			   return highPriorityQueue.removeFirst();
			   
		   }//End of high priority patient case
		   
		   //Intermediate patient
		   else if(!intermediateQueue.isEmpty())
		   {
			   
			   //Doctor assignment and patient removal
			   doctorList[num].assignPatient(intermediateQueue.peekFirst());
			   return intermediateQueue.removeFirst();
			   
		   }//End of intermediate patient case
		   
		   //Delayed care patient
		   else if(!delayedCareQueue.isEmpty())
		   {
			   
			   //Doctor assignment and patient removal
			   doctorList[num].assignPatient(delayedCareQueue.peekFirst());
			   return delayedCareQueue.removeFirst();
			   
		   }//End of delayed care patient case
		   
		   //No patients
		   else
		   {
			   
			   //Null if no available patients
			   return null;
			   
		   }//End of no patients case
		   
	   }//End of patient search case
	   
   }//End of assignPatientToDoctor method
   
   /**
    * This method releases a patient from a doctor to the checkout queue
    * if the doctor exists and has a patient
    */
   public Patient releasePatientFromDoctorToCheckOutQueue(int doctorID)
   {
	   
	   //ArrayIndexOutOfBounds error
	   if(doctorID > doctorList.length-1 || doctorID < 0)
	   {
		   
		   //Null if index is out of bounds
		   return null;
		   
	   }//End of ArrayIndexOutOfBounds error case
	   
	   //Patient release
	   else if(doctorList[doctorID].hasPatient())
	   {
		   
		   //Patient release and addition to checkout queue
		   //return patient when released
		   Patient patient = doctorList[doctorID].releasePatient();
		   checkOutQueue.add(patient);
		   return patient;
		   
	   }//End of patient release case
	   
	   //No patient
	   else
	   {
		   
		   //Null if doctor has no patient
		   return null;
		   
	   }//End of no patient case
	   
   }//End of releasePatientFromDoctor method
   
   /**
    * This method checks if the checkout queue is empty and returns null,
    * otherwise it removes the first patient from the queue and returns it
    */
   public Patient checkOutPatient()
   {
	   
	   //Not empty
	   if(!checkOutQueue.isEmpty())
	   {
		   
		   //Remove first and return it
		   return checkOutQueue.removeFirst();
		   
	   }//End of not empty case
	   
	   //Empty
	   else
	   {
		   
		   //Null if empty
		   return null;
		   
	   }//End of empty case
	   
   }//End of checkOutPatient method
   
 }//End of PatientManagement class