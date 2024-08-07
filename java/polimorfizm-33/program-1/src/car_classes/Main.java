package car_classes;

public class Main {
	public static void main(String[] args) {
		Vehicle vehicle = new Vehicle();
		Electric electric = new Electric();
		Hybrid hybrid = new Hybrid();
		
		vehicle.start();
		vehicle.resource();
		
		electric.start();
		electric.resource();
		
		hybrid.start();
		hybrid.resource();
	}
}
