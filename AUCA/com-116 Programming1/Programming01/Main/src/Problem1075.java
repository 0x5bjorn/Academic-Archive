import java.util.*;

public class Problem1075 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int a = 0;
		while (a<10000) {
			++a;
			if (a%n==2) {
				System.out.println(a);
			}
		}
	}
}
