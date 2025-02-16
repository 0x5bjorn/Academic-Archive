import java.util.*;

public class Problem1157 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int a = 0;
		while (a<n) {
			++a;
			if (n%a==0) {
				System.out.println(a);
			}
		}
	}
}
