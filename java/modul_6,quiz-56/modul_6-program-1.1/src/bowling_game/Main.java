package bowling_game;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Bowling game = new Bowling();
		Scanner scanner = new Scanner(System.in);
		
		for(int i = 0; i < 3; i++) {
			String input = scanner.nextLine();
			String [] values = input.split(" ");
			
			String name = values[0];
			int points = Integer.parseInt(values[1]);
			game.addPlayer(name, points);
		}
		scanner.close();
		
		game.getWinner();
	}
}
