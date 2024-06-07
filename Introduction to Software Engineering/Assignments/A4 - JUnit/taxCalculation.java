
public class taxCalculation 
{
	
	public static double calculateTax(double income)
	{
		
		double tax = 0, taxRate = 0;
		if(income < 0 || income > 1000001)
		{
			
			return -1.0;
			
		}
		
		else
		{
			
			if(income >= 0 && income <= 25000)
			{
				
				taxRate = 0;
				
			}
			
			else if(income <= 50000)
			{
				
				taxRate = 0.20;
				
			}
			
			else if(income <= 100000)
			{
				
				taxRate = 0.25;
				
			}
			
			else if(income <= 1000000)
			{
				
				taxRate = 0.33;
				
			}
			
			tax = income*taxRate;
			return tax;
			
		}
		
	}

}
