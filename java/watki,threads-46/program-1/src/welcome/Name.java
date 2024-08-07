package welcome;
import java.util.Scanner;

public class Name extends Thread{
	public void run() {
		System.out.println("YOUR NAME: ");
		Scanner scanner = new Scanner(System.in);
		String name = scanner.next();
		System.out.println("YOUR NAME IS" + name);
		scanner.close();
	}
}
