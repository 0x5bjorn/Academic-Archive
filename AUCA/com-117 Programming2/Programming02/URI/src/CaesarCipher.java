import java.util.*;

public class CaesarCipher {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.nextLine();
			String n = input.nextLine();
			int sN = Integer.parseInt(n);
			shift(m, sN);
		}
	}

	static void shift(String m, int sN) {
		StringBuilder m1 = new StringBuilder(50);
		m1.append(m);
		for (int i = 0; i < m.length(); ++i) {
			char c = m1.charAt(i);
			if (Character.isLetter(c)) {
				c -= sN;
				if (c<'A') {
					int d = 'A'-c;
					c = 'Z';
					c-=d-1;
				}
				m1.setCharAt(i, c);
			}
		}
		System.out.println(m1);
	}
}
