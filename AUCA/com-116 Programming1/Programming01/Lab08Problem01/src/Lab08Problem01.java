import java.util.*;

public class Lab08Problem01 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Random rnd = new Random();
		
		System.out.print("N: ");
		int n = input.nextInt();
		
		int[] counters = new int[13];
		
		for (int i=0; i<n; ++i) {
			int d1 = 1 + rnd.nextInt(6);
			int d2 = 1 + rnd.nextInt(6);
			++counters[d1+d2];
		}
		for (int i=2; i<counters.length; ++i) {
			System.out.printf("%d: %d%n", i, counters[i]);
		}
	}
}
