package shapes_module_5_program;
import java.util.Scanner;
import java.lang.Math.*;

abstract class Shape {
	int width;
	abstract void area();
}

public class Square extends Shape {
	private int width;
	
	public Square(int x) {
		width = x;
	}
	
	public void area() {
		System.out.println(width * width);
	}
}

public class Circle extends Shape { 
	private int radius;
	
	public Circle(int y) {
		radius = y;
	}
	
	public void area() {
		System.out.println(radius * radius * (double)Math.PI);
	}
}

public class MyClass {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		
		Square a = new Square(x);
		Circle b = new Circle(y);
		a.area();
		b.area();
	}
}
