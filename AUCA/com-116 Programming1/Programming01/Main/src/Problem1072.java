import java.util.*;

public class Problem1072 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int x = 0;
		int a = 0;
		int a1 = 0;
		while (x<n) {
			int b = input.nextInt();
			if (b>9 && b<21) {
				++a;
			}	
			else {
				++a1;
			}
			++x;
		}
		System.out.printf("%d in\n", a);
		System.out.printf("%d out\n", a1);
	}
}
