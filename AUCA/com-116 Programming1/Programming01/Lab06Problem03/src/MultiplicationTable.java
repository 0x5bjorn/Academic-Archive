import java.util.*;

public class MultiplicationTable {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				System.out.printf("%5d", i*j);
			}
			System.out.println();
		}
	}
}
