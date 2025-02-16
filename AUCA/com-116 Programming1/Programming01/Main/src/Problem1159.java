import java.util.*;

public class Problem1159 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int b = 0;
		int sum = 0;
		for (boolean run = true; run; sum=0, b=0) {
			int x = input.nextInt();
			if (x == 0) {
				run = false;
			} else {
				while (b < 5) {
					if (x % 2 == 0) {
						sum += x;
						++b;
					}
					++x;
				}
				System.out.println(sum);
			}
		}
	}
}
