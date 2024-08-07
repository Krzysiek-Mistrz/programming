package calculating_net_revenue_with_taxes;

public class Income {
	public float taxPercent;
	public float totalIncome;
	private float netRevenue;
	
	public void calculateNetRevenue() {
		this.netRevenue = this.totalIncome - (this.totalIncome * (this.taxPercent / 100));
	}
	
	public float getNetRevenue() {
		return netRevenue;
	}
}