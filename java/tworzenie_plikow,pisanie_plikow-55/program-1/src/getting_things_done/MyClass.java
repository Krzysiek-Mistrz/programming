package getting_things_done;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.io.FileNotFoundException;
import java.io.File;

public class MyClass {
	public static void main(String[] args) {
		try {
			Formatter file = new Formatter("task.txt");
			Scanner scanner = new Scanner(System.in);
			
			for(int i = 0; i < 3; i++) {
				String word = scanner.nextLine();
				file.format("%s", word + "\n");
			}

			scanner.close();
			file.close();
		}
		catch(FileNotFoundException e1) {
			System.out.println("Error: File Not Found");
		}
		catch(Exception e2) {
			System.out.println("Undefined Error");
		}
	}

	public static void readFile() {
		try {
			File file = new File("task.txt");
			Scanner scanner = new Scanner(file);
			
			while(scanner.hasNext()) {
				System.out.println(scanner.next());
			}
			scanner.close();
		}
		catch(FileNotFoundException e1) {
			System.out.println("Error: File Not Found (To Read From File)");
		}
		catch(Exception e2) {
			System.out.println("Error: Undefined Error (To Read From File)");
		}
	}
}