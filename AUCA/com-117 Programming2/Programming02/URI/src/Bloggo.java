import java.util.*;

public class Bloggo {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextLine()) {
			String m = input.nextLine();
			translate(m);
		}
	}

	static void translate(String m) {
		StringBuilder sb = new StringBuilder(m);
		int a = 0;
		int b = 0;
		for (int i = 0; i < sb.length(); i++) {
			char c = sb.charAt(i);
			if (c == '_') {
				if (a % 2 == 0) {
					sb.replace(i, i + 1, "<i>");
					a++;
				} else {
					sb.replace(i, i + 1, "</i>");
					a++;
				}
			}
			if (c == '*') {
				if (b % 2 == 0) {
					sb.replace(i, i + 1, "<b>");
					b++;
				} else {
					sb.replace(i, i + 1, "</b>");
					b++;
				}
			}
		}
		System.out.println(sb);
	}
}