package special_customer_discount;
import java.util.Scanner;

public class MyClass {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int price = scanner.nextInt();
		
		Purchase firstClient = new Purchase();
		firstClient.totalAmount(price);
		
		Purchase secondClient = new Purchase() {
			public int totalPrice(int price) {	//@Override
				return ((int)(price - (price * 0.1)));
			}
		};
		secondClient.totalAmount(price);
	}
}
