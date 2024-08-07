package binary_converter;

public class Converter 
{
	public static String toBinary(int decNumber)
	{
		String binNumber = "";
		
		while(decNumber > 0)
		{
			binNumber = (decNumber % 2) + binNumber;
			
			decNumber /= 2;
		}
		
		return binNumber;
	}
}
