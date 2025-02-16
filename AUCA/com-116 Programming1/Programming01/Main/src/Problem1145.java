import java.util.*;

public class Problem1145 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		for (int i = 1; i <= b; ++i) {
			if (i % a == 0) {
				System.out.println(i);
			} 
			else {
				System.out.print(i + " ");
			}
		}
	}
}
