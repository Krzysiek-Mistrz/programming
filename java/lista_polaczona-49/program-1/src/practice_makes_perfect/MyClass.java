package practice_makes_perfect;
import java.util.Scanner;
import java.util.LinkedList;

public class MyClass {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		LinkedList <String> words = new LinkedList <String> ();
		
		while(words.size() < 5) {
			String word = scanner.nextLine();
			words.add(word);
		}
		scanner.close();
		
		for(String word: words) {
			if(word.length() == 4)
				System.out.println(word);
		}
	}
}
