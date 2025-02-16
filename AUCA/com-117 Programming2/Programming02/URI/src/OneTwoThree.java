import java.util.*;

public class OneTwoThree {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.nextLine();
			check(m);
		}

	}

	 static void check(String m) {
		if (m.length() == 3) {
			if (m.charAt(0) == 'o' && m.charAt(1) == 'n') {
				System.out.println(1);
			} else if (m.charAt(0) == 'o' && m.charAt(2) == 'e') {
				System.out.println(1);
			} else if (m.charAt(1) == 'n' && m.charAt(2) == 'e') {
				System.out.println(1);
			} else {
				System.out.println(2);
			}
		} else {
			System.out.println(3);
		}
	}
}
