import java.util.*;

public class Help {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int a1 = input.nextInt();
			if (a1 == 0) {
				break;
			}

			int c = 0;
			int n = 0;
			String[] pi = new String[a1];
			int[] t = new int[a1];
			String[] jud = new String[a1];
			for (int i = 0; i < a1; ++i) {
				pi[i] = input.next();
				t[i] = input.nextInt();
				jud[i] = input.next();
			}
			help(a1, c, n, pi, t, jud);
		}
	}

	private static void help(int a1, int c, int n, String[] pi, int[] t, String[] jud) {
		for (int i = 0; i < a1; ++i) {
			if (jud[i].equals("correct")) {
				c += t[i];
				++n;
				if (i > 0 && pi[i].equals(pi[i - 1])) {
					c += 20;
				}
			}
		}
		System.out.print(n + " ");
		System.out.println(c);
	}
}
