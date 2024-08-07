package student_information_system;

public class Student {
	public String name;
	public int age;
	
	public void setAge(int a) {
		this.age = a;
		if(a < 0)
			this.age = 0;
	}
		
	public int getAge() {
		return age;
	}
}
