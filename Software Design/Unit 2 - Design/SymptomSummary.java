/*
 * Vincent Latona
 */

/*
 * This class models a game symptom summary
 */
public class SymptomSummary 
{
	//Summary attributes
	private int symptomTotal; //Total number of unique symptoms
	private int symptomSeverity; //Total severity of all symptoms
	private String overallRating; //Difference with previous game
	
	/*
	 * Constructor for summary
	 */
	public SymptomSummary(int symptomTotal, int symptomSeverity, String overallRating)
	{
		//Set summary attributes
		this.symptomTotal = symptomTotal;
		this.symptomSeverity = symptomSeverity;
		this.overallRating = overallRating;
	}
	
	/*
	 * This method returns symptom total
	 */
	public int getSymptomTotal()
	{
		return symptomTotal; //Return attribute copy
	}
	
	/*
	 * This method returns symptom severity
	 */
	public int getSymptomSeverity()
	{
		return symptomSeverity; //Return attribute copy
	}
	
	/*
	 * This method returns overall rating
	 */
	public String getOverallRating()
	{
		return overallRating; //Return attribute copy
	}
	
	/*
	 * This method sets symptom total
	 */
	public void setSymptomTotal(int total)
	{
		symptomTotal = total; //Set new symptom total
	}
	
	/*
	 * This method sets symptom severity
	 */
	public void setSymptomSeverity(int severity)
	{
		symptomSeverity = severity; //Set new symptom severity
	}
	
	/*
	 * This method sets overall rating
	 */
	public void setOverallRating(String overall)
	{
		overallRating = overall; //Set new overallRating
	}
	
	/*
	 * This method prints the contents of the summary
	 */
	public void printSummary()
	{
		//Print summary contents
		System.out.println("Total # of Symptoms: " + symptomTotal);
		System.out.println("Total Severity of Symptoms: " + symptomSeverity);
		System.out.println("Overall Rating: " + overallRating);
	}
}
