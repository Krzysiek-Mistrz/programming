package arraylist;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		ArrayList <Integer> array = new ArrayList <Integer> ();
		Scanner scanner = new Scanner(System.in);
		int sum = 0;
		
		while(array.size() != 3) {
			int number = scanner.nextInt();
			array.add(number);
			sum += number;
		}
		scanner.close();
		
		System.out.println("AVERAGE OF NUMBERS IN ARRAY: " + sum / 3);
	}
}
