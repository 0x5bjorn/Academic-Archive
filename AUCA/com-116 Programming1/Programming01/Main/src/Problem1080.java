import java.util.*;

public class Problem1080 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int count = 0;
		int max = 0;
		for (int i=1; i<=100; ++i) {
			int a = input.nextInt();
			if (a>max) {
				max=a;
				count=i;
			}
		}
		System.out.println(max);
		System.out.println(count);
	}
}