package welcome;
import java.util.Scanner;

public class MyClass {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int age = scanner.nextInt();
		Pupils pupil = new Pupils();
		pupil.setAge(age);
	}
}
