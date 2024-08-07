package link_of_the_list;
import java.util.Scanner;
import java.util.Iterator;
import java.util.LinkedList;

public class Main {
	public static void main(String[] args) {
		LinkedList <Integer> array = new LinkedList <Integer> ();
		Scanner scanner = new Scanner(System.in);
		
		while(array.size() < 5) {
			int number = scanner.nextInt();
			array.add(number);
		}
		scanner.close();
		
		int sum = 0;
		Iterator <Integer> iterator = array.iterator();

		while(iterator.hasNext()) {
			sum += iterator.next();
		}
		
		System.out.println("SUM: " + sum);
	}
}
