package minimum_and_maximum;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	public static void main(String[] args) {
		ArrayList <Integer> array = new ArrayList <Integer> ();
		Scanner scanner = new Scanner(System.in);
		
		while(array.size() != 5) {
			int number = scanner.nextInt();
			array.add(number);
		}
		
		int max = Collections.max(array);
		int min = Collections.min(array);
		
		System.out.println(max);
		System.out.println(min);
		
		scanner.close();
	}
}
