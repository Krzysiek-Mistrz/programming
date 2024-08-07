package checking_or_saving;

public class SavingAcc extends Account {
	SavingAcc(double amount) {
		super(amount);
	}
	
	public double getIncome() {
		return (getAmount() + (0.2 * getAmount()));
	}
}
