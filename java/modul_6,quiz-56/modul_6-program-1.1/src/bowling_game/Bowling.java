package bowling_game;
import java.util.*;

public class Bowling {
	HashMap <String, Integer> players;
	
	Bowling() {
		players = new HashMap <String, Integer> ();
	}
	
	public void addPlayer(String name, int p) {
		players.put(name, p);
	}
	
	public void getWinner() {
		int mark = 0;
		String name = "";
		
		for(String helpName: players.keySet()) {
			if(players.get(helpName) > mark) {
				mark = players.get(helpName);
				name = helpName;
			}
		}
		
		System.out.println("WINNER: " + name + " " + mark);
	}
}
