import java.util.*;

public class WERTYU {
	static Scanner input = new Scanner(System.in);
	static String kb = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
	static char[] kbl = kb.toCharArray();

	public static void main(String[] args) {

		while (input.hasNext()) {
			String m = input.nextLine();
			decode(m);
		}
	}

	private static void decode(String m) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < m.length(); ++i) {
			char c = m.charAt(i);
			if (c != '`' && c != 'Q' && c != 'A' && c != 'Z') {
				if (c == ' ') sb.append(' ');
				else {
					for (int j = 0; j < kbl.length; ++j) {
						if (c == kbl[j]) {
							sb.append(kbl[j - 1]);
						}
					}
				}
			} else break;
		}
		System.out.println(sb);
	}
}
