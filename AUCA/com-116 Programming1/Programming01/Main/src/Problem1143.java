import java.util.*;

public class Problem1143 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int i=1; i<=n; ++i) {
			System.out.print(i + " ");
			int sq = i*i;
			System.out.print(sq + " ");
			int cub = i*i*i;
			System.out.println(cub);
		}
	}
}
