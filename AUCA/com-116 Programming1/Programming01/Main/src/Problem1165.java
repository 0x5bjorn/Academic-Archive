import java.util.*;

public class Problem1165 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int a = 0;
		int b = 0;
		int sum = 0;
		for (int i=0; i<n; ++i, sum=0, a=0, b=0) {
			int x = input.nextInt();
			while (a<x) {
				++a;
				if (x%a==0) {
					sum+=a;
				}
			}
			if (sum==a+1) {
				System.out.printf("%d eh primo\n", x);
			} else {
				System.out.printf("%d nao eh primo\n", x);
			}
		}
	}
}
