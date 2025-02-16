import java.util.*;

public class Problem1101 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		while (a > 0 && b > 0) {
			int total = 0;
			int n = 0;
			if (a > b) {
				n += b;
				while (n >= b && n <= a) {
					total += n;
					System.out.print(n + " ");
					++n;
				}
				System.out.printf("Sum=%d\n", total);
			} else if (b > a) {
				n += a;
				while (n >= a && n <= b) {
					total += n;
					System.out.print(n + " ");
					++n;
				}
				System.out.printf("Sum=%d\n", total);
			}
			a = input.nextInt();
			b = input.nextInt();
		}
	}
}
