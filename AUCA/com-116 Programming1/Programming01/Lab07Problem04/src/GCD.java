import java.util.*;

public class GCD {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("A = ");
		int a = input.nextInt();

		System.out.print("B = ");
		int b = input.nextInt();
		
		int d = gcd(a, b);
		
		System.out.printf("GCD(%d, %d) = %d%n", a, b, d);
		
	}
	static int gcd(int a, int b) {
		if (a==0 && b==0) {
			throw new IllegalArgumentException("GCD(0, 0) is not defined");
		}
		if (a==0) {
			return b;
		}
		if (b==0) {
			return a;
		}
		int d = Math.min(a, b);
		while (a%d!=0 || b%d!=0) {
			--d;
		}
		return d;
	}
}
