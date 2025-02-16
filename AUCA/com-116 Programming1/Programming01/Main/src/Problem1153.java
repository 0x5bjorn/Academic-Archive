import java.util.*;

public class Problem1153 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = 0;
		int c = a;
		int fac = 1;
		while (b<a) {
			++b;
			fac *= c;
			c=a-b;
		}
		System.out.println(fac);
	}
}
