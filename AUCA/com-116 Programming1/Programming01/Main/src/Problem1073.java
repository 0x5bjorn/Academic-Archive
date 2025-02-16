import java.util.*;

public class Problem1073 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int n = 1;
		if (a > 5 && a < 2000) {
			while (n <= a) {
				if (n % 2 == 0) {
					int sq = n * n;
					System.out.printf("%d^2 = %d\n", n, sq);
				}
				++n;
			}
		}
	}
}
