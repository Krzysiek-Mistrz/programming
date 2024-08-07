package age_dependent;
import java.util.Scanner;
import java.util.HashMap;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		HashMap<String, Integer> ages = new HashMap<String, Integer> ();
		
	    ages.put("David", 22);
	    ages.put("Tom", 23);
	    ages.put("Robert", 32);
	    ages.put("Alice", 21);
	    ages.put("Sophie", 19);
	    ages.put("Maria", 24);
	    ages.put("John", 28);
	    
	    String [] nameArr = new String [ages.size()];
	    nameArr = ages.keySet().toArray(nameArr);
	    
	    int ageLimit = scanner.nextInt();
	    scanner.close();
	    for(String name : nameArr) {
	    	if(ages.get(name) < ageLimit) {
	    		ages.remove(name);
	    	}
	    }
	    System.out.println(ages);
	}
}
