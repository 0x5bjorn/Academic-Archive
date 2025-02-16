import java.util.*;

public class Problem1146 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int x = input.nextInt();
		boolean run = true;
		int i = 0;
		while (run) {
			if (x > 0) {
				while (i < x - 1) {
					++i;
					System.out.print(i + " ");
				}
				System.out.println(x);
				i=0;
				x = input.nextInt();
			}
			else {
				run = false;
			}
		}
	}
}
