import java.util.*;

public class Problem1133 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		int n = 0;
		if (a > b) {
			n += b;
			++n;
			while (n > b && n < a) {
				if (n % 5 == 2 || n % 5 == 3) {
					System.out.println(n);
				}
				++n;
			}
		} else if (b > a) {
			n += a;
			++n;
			while (n > a && n < b) {
				if (n % 5 == 2 || n % 5 == 3) {
					System.out.println(n);
				}
				++n;
			}
		}
	}
}
