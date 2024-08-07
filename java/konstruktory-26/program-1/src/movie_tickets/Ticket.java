package movie_tickets;

public class Ticket {
	protected String movie;
	protected int row;
	protected int seat;
	
	Ticket(String movie, int row, int seat) {
		this.setMovie(movie);
		this.setRow(row);
		this.setSeat(seat);
	}
	
	public String getMovie() {
		return this.movie;
	}
	
	public int getRow() {
		return this.row;
	}
	
	public int getSeat() {
		return this.seat;
	}
	
	public void setMovie(String movie) {
		this.movie = movie;
	}
	
	public void setRow(int row) {
		this.row = row;
	}
	
	public void setSeat(int seat) {
		this.seat = seat;
	}
}
