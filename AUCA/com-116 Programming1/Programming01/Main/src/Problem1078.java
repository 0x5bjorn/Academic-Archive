import java.util.*;

public class Problem1078 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int a = 0;
		while (a<10) {
			++a;
			int n1 = n*a;
			System.out.printf("%d x %d = %d\n", a, n, n1);
		}
		
	}
}
