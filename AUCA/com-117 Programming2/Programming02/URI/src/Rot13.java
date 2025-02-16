import java.util.*;

public class Rot13 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextLine()) {
			String m = input.nextLine();
			encrypt(m);
		}
	}

	static void encrypt(String m) {
		StringBuilder m1 = new StringBuilder();
		m1.append(m);
		for (int i = 0; i < m.length(); ++i) {
			char c = m1.charAt(i);
			if (Character.isLetter(c) && Character.isUpperCase(c)) {
				c -= 13;
				if (c<'A') {
					int d = 'A'-c;
					c = 'Z';
					c-=d-1;
				}
				m1.setCharAt(i, c);
			} else if (Character.isLetter(c) && Character.isLowerCase(c)) {
				c -= 13;
				if (c<'a') {
					int d = 'a'-c;
					c = 'z';
					c-=d-1;
				}
				m1.setCharAt(i, c);
			}
		}
		System.out.println(m1);
	}
}
