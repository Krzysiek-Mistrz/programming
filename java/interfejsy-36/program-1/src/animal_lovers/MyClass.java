package animal_lovers;

public class MyClass {
	public static void main(String[] args) {
		//poniewaz cat i Dog dziedziczy z klasy Animal:
		Animal cat = new Cat();
		Animal dog = new Dog();
	
		cat.play();
		cat.swim();
		dog.play();
		dog.swim();
	}
}
