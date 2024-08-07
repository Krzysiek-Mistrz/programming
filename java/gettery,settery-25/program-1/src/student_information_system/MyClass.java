package student_information_system;
import java.util.Scanner;

public class MyClass {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int age = reader.nextInt();
		String name = reader.nextLine();
		Student student = new Student();
		
		student.name = name;
		student.setAge(age);
		
		if(age < 0)
			System.out.println("!!!INVALID AGE!!!");
		else
		{
			System.out.println("NAME: " + student.name);
			System.out.println("AGE: " + student.age);
		}
	}
}
