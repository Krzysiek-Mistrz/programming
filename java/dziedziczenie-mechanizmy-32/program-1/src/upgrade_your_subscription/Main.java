package upgrade_your_subscription;

public class Main {
	public static void main(String[] args) {
		Standard standard = new Standard();
		Pro pro = new Pro();
		
		standard.write();
		standard.draw();
			
		//poniewaz Pro dziedziczy z Standard moge wywolac te same metody na rzeczy obiektu klasy Pro.
		pro.write();
		pro.draw();
		pro.useEffects();
		pro.changeResolution();
	}
}
