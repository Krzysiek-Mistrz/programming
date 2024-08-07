package checking_or_saving;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		double saving = scanner.nextDouble();
		double checking = scanner.nextDouble();
		
		Account savingAcc = new SavingAcc(saving);
		Account checkingAcc = new CheckingAcc(checking);
		
		System.out.println(savingAcc.getIncome());
		System.out.println(checkingAcc.getIncome());
	}
}
