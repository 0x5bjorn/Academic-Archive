import java.util.*;

public class HeadOrTail {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int n = input.nextInt();
			
			if (n==0) {
				break;
			}
			
			int m = 0;
			int j=0;
			for (int i=0; i<n; ++i) {
				int a = input.nextInt();
				if (a==0) {
					++m;
				} else {
					++j;
				}
			}
			System.out.printf("Mary won %d times and John won %d times\n", m, j);
		}
	}
}
