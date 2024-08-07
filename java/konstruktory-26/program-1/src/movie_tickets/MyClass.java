package movie_tickets;
import java.util.Scanner;

public class MyClass {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String movie = scanner.nextLine();
		int row = scanner.nextInt();
		int seat = scanner.nextInt();
		Ticket ticket = new Ticket(movie, row, seat);
		
		System.out.println("MOVIE " + ticket.getMovie());
		System.out.println("SEAT: " + ticket.getSeat());
		System.out.println("ROW " + ticket.getRow());
	}
}
