import java.util.*;

public class Problem1176 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		long[] list = new long[61];
		list[0] = 0;
		list[1] = 1;
		for (int i=2; i<61; ++i) {
			list[i] = list[i-1] + list[i-2];
		}
		for (int i=0; i<a; ++i) {
			int b = input.nextInt();
			System.out.printf("Fib(%d) = %d\n", b, list[b]);
		}
	}
}
