import java.util.*;

public class ExchCards {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		while (true) {
			int n = input.nextInt();
			int m = input.nextInt();
			if (n == 0 && m==0) break;
			exch(n, m);
		}
	}

	private static void exch(int n, int m) {
		HashSet<Integer> one = new HashSet<Integer>();
		HashSet<Integer> two = new HashSet<Integer>();
		for (int i = 0; i < n; ++i) {
			one.add(input.nextInt());
		}
		for (int i = 0; i < m; ++i) {
			two.add(input.nextInt());
		}
		int c1 = 0;
		int c2 = 0;

		for (Integer i : one) {
			if (!two.contains(i))
				++c1;
		}
		for (Integer i : two) {
			if (!one.contains(i))
				++c2;
		}
		System.out.println(Math.min(c1, c2));
	}
}
