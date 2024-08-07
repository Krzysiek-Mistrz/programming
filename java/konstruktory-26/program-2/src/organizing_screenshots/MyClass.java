package organizing_screenshots;
import java.util.Scanner;

public class MyClass {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String name = scanner.nextLine();
		
		Screenshots screenshot1 = new Screenshots(name);
		Screenshots screenshot2 = new Screenshots();
		
		System.out.println(screenshot1.getName());
		System.out.println(screenshot2.getName());
	}
}
