import java.util.*;

public class Problem1150 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int x = input.nextInt();
		int z = input.nextInt();
		int j = 0;
		int i = 0;
		int sum = 0;
		boolean run = true;
		while (run) {
			if (z > x) {
				i = x;
				while (sum<z) {
					sum += i;
					++i;
					++j;
				}
				System.out.println(j);
				run=false;
			} 
			else {
				z = input.nextInt();
			}
		}
	}
}
