package exponents;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		double obj1 = scanner.nextDouble();
		double obj2 = scanner.nextDouble();
		
		double result = Math.pow(obj1, obj2);
		System.out.println(obj1 + " TO THE POWER " + obj2 + " IS: " + result);
	}
}
