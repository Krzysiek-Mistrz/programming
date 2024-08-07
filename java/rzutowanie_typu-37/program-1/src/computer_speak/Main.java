package computer_speak;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		char a = scanner.next().charAt(0);
		int b = (int) a;
		System.out.println("NUMERIC VALUE: " + b);
	}
}
