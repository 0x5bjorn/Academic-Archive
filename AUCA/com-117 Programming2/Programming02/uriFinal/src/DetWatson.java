import java.util.*;

public class DetWatson {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		while (true) {
			int n = input.nextInt();
			if (n == 0)
				break;

			check(n);
		}
	}

	private static void check(int n) {
		int[] lst = new int[n];
		for (int i = 0; i < n; ++i) {
			lst[i] = input.nextInt();
		}
		int c = Max(n, lst);
		lst[c-1] = 0;
		int c2 = Max(n, lst);
		System.out.println(c2);
	}

	private static int Max(int n, int[] lst) {
		int count = 0;
		int max = 0;
		for (int i = 0; i < lst.length; ++i) {
			int a = lst[i];
			if (a > max) {
				max = a;
				count = i + 1;
			}
		}
		return count;
	}
}
