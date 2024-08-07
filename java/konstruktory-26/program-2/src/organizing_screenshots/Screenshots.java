package organizing_screenshots;

public class Screenshots {
	protected String name;
	
	Screenshots(String name) {
		setName(name);
	}
	
	Screenshots() {
		setName("Screenshot");
	}
	
	String getName() {
		return this.name;
	}
	
	void setName(String name) {
		this.name = name;
	}
}
