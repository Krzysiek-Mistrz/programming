package welcome;

public class Pupils {
	private int age;
	
	public void setAge(int age) {
		if(age > 6) {
			this.age = age;
			System.out.println("WELCOME!");
		}
		else
			System.out.println("SORRY");
	}
	public int getAge() {
		return age;
	}
}