import java.util.*;

public class InsideOut {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.nextLine();
			gibberish(m);
		}
	}

	static void gibberish(String m) {
		StringBuilder sb = new StringBuilder(m);
		sb.reverse();
		int a = sb.length() / 2;
		String h1 = sb.substring(0, a);
		String h2 = sb.substring(a);
		sb.delete(0, sb.length());
		sb.append(h2);
		sb.append(h1);
		System.out.println(sb);
	}
}