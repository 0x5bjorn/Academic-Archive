import java.util.*;

public class CountSheep {
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		int t = input.nextInt();
		for (int i = 0; i < t; ++i) {
			int n = input.nextInt();
			count(n);
		}
	}

	private static void count(int n) {
		HashSet<Integer> count = new HashSet<>();
		for (int i = 0; i<n; ++i) {
			int sh = input.nextInt();
			count.add(sh);
		}
		System.out.println(count.size());
	}
}
