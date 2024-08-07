package binary_converter;
import java.util.Scanner;

public class Program 
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		
		int x = scanner.nextInt();
		
		System.out.println(Converter.toBinary(x));
	}
}
