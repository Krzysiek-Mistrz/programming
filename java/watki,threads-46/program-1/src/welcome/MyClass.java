package welcome;

public class MyClass {
	public static void main(String[] args) {
		Name name = new Name();
		Welcome welcome = new Welcome();
		
		name.setPriority(10);
		welcome.setPriority(1);
		
		name.start();
		welcome.start();
	}
}
