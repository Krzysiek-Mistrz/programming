package special_customer_discount;

public class Purchase {
	public int totalAmount(int price) {
		return ((int)(price - (price * 0.1)));
	}
}
