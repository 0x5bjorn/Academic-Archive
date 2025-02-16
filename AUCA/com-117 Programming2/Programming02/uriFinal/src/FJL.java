import java.util.*;

public class FJL {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		int t = input.nextInt();
		for (int i = 1; i <= t; ++i) {
			int n = input.nextInt();
			int k = input.nextInt();
			circle(n, k);
			System.out.printf("Case %d: %d\n", i, circle(n, k));
		}
	}

	static int circle(int n, int k) {
		ArrayList<Integer> lst = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			lst.add(i + 1);
		}
		int i = 0;
		while (lst.size()>1) {
			i = (i+k-1)%lst.size();
			lst.remove(i);
		}
		return lst.get(0);
	}
}
