import java.util.*;

public class HiddenMes {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.nextLine();
			returnHM(m);
		}
	}

	static void returnHM(String m) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < m.length(); i++) {
			char c = m.charAt(i);
			if (i==0 && Character.isLetter(c)) {
				sb.append(c);
			}
			if (i>0 && Character.isLetter(c) && m.charAt(i - 1) == ' ') {
				sb.append(c);
			}
		}
		System.out.println(sb);
	}
}