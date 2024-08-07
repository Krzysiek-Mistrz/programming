package no_zeroes;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int number1 = scanner.nextInt();
		int number2 = scanner.nextInt();
		
		try {
			System.out.println(number1 / number2);
		}
		catch (ArithmeticException e1) {
			System.out.println("Error: division by zero");
		}
		catch (InputMismatchException e2) {
			System.out.println("Error: wrong value");
		}
		
		scanner.close();
	}
}

//mozna takze owo zadanie rozwiazac wykorzystujac instrukcje throw
/*
public class Main {
	public static void main(String[] args) throws ArithmeticException, InputMismatchException {
		Scanner scanner = new Scanner(System.in);
		int number1 = scanner.nextInt();
		int number2 = scanner.nextInt();
		
		if(number2 == 0){
			throw new ArithmeticException("Error: division by zero");
			throw new InputmismatchException("Error: wrong value");
		}
		else {
		System.out.println(number1 / number2);
	}
}
 */