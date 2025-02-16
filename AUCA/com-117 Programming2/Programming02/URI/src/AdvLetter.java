import java.util.*;

public class AdvLetter {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.next();
			String m1 = input.next();
			transform(m, m1);
		}
	}

	private static void transform(String m, String m1) {
		int a = 0;
		for (int i=0; i<m.length(); i++) {
			char c = m.charAt(i);
			char c1 = m1.charAt(i);
			while (c!=c1) {
				if (Character.isLetter(c)) {
					c++;
					if (c>'z') {
						int d = c-'z';
						c = 'a';
						c+=d-1;
					}
				}
				a++;
			}
		}
		System.out.println(a);
	}
}	