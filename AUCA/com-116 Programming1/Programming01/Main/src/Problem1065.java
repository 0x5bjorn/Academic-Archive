import java.util.*;

public class Problem1065 {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int total = 0;
		int a = 0;
		while (a<5) {
			int n = input.nextInt();
			if (n%2==0) {
				++total;
			}
			++a;
		}
		System.out.printf("%d valores pares\n", total);
	}
}
