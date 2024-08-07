package checking_or_saving;

public class CheckingAcc extends Account {
	CheckingAcc(double amount) {
		super(amount);
	}
	
	public double getIncome() {
		return (getAmount() + (0.05 * getAmount()));
	}
}