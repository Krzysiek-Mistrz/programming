package double_trouble;

public class Main {
	public static void main(String[] args) {
		int a = 10;
		double b = 10.5;
		
		System.out.println(doubleTheValue(a));
		System.out.println(doubleTheValue(b));
	}
	
	public static int doubleTheValue(int arg) {
		return arg * 2;
	}
		
	//nadpisanie pierwszej metody 
	public static double doubleTheValue(double arg) {
		return arg * 2;
	}
}