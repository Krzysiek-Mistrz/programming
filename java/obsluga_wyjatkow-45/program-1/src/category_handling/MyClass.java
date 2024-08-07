package category_handling;
import java.util.Scanner;

public class MyClass {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int choice = scanner.nextInt();
		String [] category = {"PCs", "Notebooks", "Tablets", "Phones", "Accesories"};
		
		try {
			System.out.println(choice);
		}
		catch (Exception e) {
			System.out.println("WRONG OPTION");
		}
	}
}
