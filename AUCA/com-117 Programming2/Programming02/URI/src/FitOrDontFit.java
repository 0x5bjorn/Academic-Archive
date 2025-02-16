import java.util.*;

public class FitOrDontFit {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.next();
			String m1 = input.next();
			verify(m, m1);
		}
	}

	static void verify(String m, String m1) {
		if (m.length() >= m1.length()) {
			int a = m.length() - m1.length();
			String s = m.substring(a);
			if (s.equals(m1)) {
				System.out.println("encaixa");
			} else {
				System.out.println("nao encaixa");
			}
		} else {
			System.out.println("nao encaixa");
		}
	}
}
