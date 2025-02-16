import java.util.*;

public class SumOfTwoSq {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		while (input.hasNextLine()) {
			int n = input.nextInt();
			check(n);
		}
	}

	static void check(int n) {
		boolean res = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i * i + j * j) == n) res = true;
			}
		}
		if (res) System.out.println("YES");
		else	 System.out.println("NO");
	}
}
