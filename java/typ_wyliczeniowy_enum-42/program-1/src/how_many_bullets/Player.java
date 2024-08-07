package how_many_bullets;

public class Player {
	Player(Difficulty diff) {
		switch(diff) {
		case EASY:
			System.out.println("YOU HAVE 3000 BULLETS");
			break;
		case MEDIUM:
			System.out.println("YOU HAVE 2000 BULLETS");
			break;
		case HARD:
			System.out.println("YOU HAVE 1000 BULLETS");
			break;
		}
	}
}
