import java.util.*;

public class Problem1142 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int a = 1; a <= n*4; ++a) {
			if (a % 4 == 0) {
				System.out.println("PUM");
			} 
			else {
				System.out.print(a + " ");
			}
		}
	}
}
