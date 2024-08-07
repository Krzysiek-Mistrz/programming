package board_game_attributes;

public class Main {
	public static void main(String[] args) {
		Chess chess = new Chess();
		Battleships battleships = new Battleships();
		Monopoly monopoly = new Monopoly();
		
		chess.play();
		battleships.play();
		monopoly.play();
	}
}