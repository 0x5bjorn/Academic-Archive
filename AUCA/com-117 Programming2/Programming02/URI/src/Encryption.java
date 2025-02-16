import java.util.*;

public class Encryption {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.nextLine();
			encrypt(m);
		}
	}

	static void encrypt(String m) {	
		StringBuilder m1 = new StringBuilder();
		m1.append(m);
		for (int i = 0; i < m.length(); ++i) {
			char c = m1.charAt(i);
			if (Character.isLetter(c)) {
				c += 3;
				m1.setCharAt(i, c);
			}
		}
		m1.reverse();
		for (int i = m1.length() / 2; i < m.length(); ++i) {
			char c = m1.charAt(i);
			c -= 1;
			m1.setCharAt(i, c);
		}
		System.out.println(m1);
	}
}
