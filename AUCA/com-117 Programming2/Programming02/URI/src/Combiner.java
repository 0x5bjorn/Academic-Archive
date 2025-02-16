import java.util.*;

public class Combiner {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.next();
			String m1 = input.next();
			combine(m, m1);
		}
	}

	static void combine(String m, String m1) {
		StringBuilder sb = new StringBuilder();
		int max = Math.max(m.length(), m1.length());
		for (int i = 0; i < max; i++) {
			if (i < m.length()) {
				char c = m.charAt(i);
				sb.append(c);
			}
			if (i < m1.length()) {
				char c1 = m1.charAt(i);
				sb.append(c1);
			}
		}
		System.out.println(sb);
	}
}
