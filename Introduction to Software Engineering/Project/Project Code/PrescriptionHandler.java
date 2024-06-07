import java.util.*;

public class PrescriptionHandler //Class for PrescriptionHandler 
{
	
	
	private boolean sent;	//private data
	
	
	public PrescriptionHandler() //constructor
	{

		sent = false; //assigns our private data
		
	}//ends our constructor
	
	
	public boolean sendToPharmacy(String patientPharm, ArrayList<String> meds) //sends meds to pharmacy and returns true if there is a pharmacy
	{
		
		
		if(patientPharm.equals("")) //if there is no pharmacy case
		{
			
			//Return false for no pharmacy
			return false;
			
		}//end of no pharmacy case
		
		sent = true;
		return sent;
		
	}//ends our sendToPharmacy method

}//End of class PrescriptionHandler