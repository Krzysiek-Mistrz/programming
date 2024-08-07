package calculating_net_revenue_with_taxes;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		float taxPercent = scanner.nextFloat();
		float totalIncome = scanner.nextFloat();
		
		Income income = new Income();
		income.taxPercent = taxPercent;
		income.totalIncome = totalIncome;
		
		income.calculateNetRevenue();
		System.out.println("NET REVENUE: " + income.getNetRevenue());
	}
}
