import java.util.*;

public class RockPaper {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m1 = input.next();
			String m2 = input.next();
			play(m1, m2);
	}
}

	static void play(String m1, String m2) {
		if (m1.equals("pedra") && (m2.equals("lagarto") || m2.equals("tesoura")) ||
			m1.equals("tesoura") && (m2.equals("papel") || m2.equals("lagarto")) ||
			m1.equals("papel") && (m2.equals("pedra") || m2.equals("spock")) ||
			m1.equals("lagarto") && (m2.equals("spock") || m2.equals("papel")) ||
			m1.equals("spock") && (m2.equals("tesoura") || m2.equals("pedra"))) {
			System.out.println("rajesh");
		} else if (m1.equals(m2)) {
			System.out.println("empate");
		} else {
			System.out.println("sheldon");
		}
	}
} 