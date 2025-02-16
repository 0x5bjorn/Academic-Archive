import java.util.*;

public class DancingSent {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextLine()) {
			String m = input.nextLine();
			dance(m);
		}
	}

	static void dance(String m) {
		StringBuilder m1 = new StringBuilder();
		int count = 0;
		for (int i = 0; i < m.length(); i++) {
			char c = m.charAt(i);
			if (Character.isLetter(c)) {
				if (count % 2 == 0) {
					m1.append(Character.toUpperCase(c));
				} else {
					m1.append(Character.toLowerCase(c));
				}
				count++;
			} else {
				m1.append(c);
			}
		}
		System.out.println(m1);
	}
}
