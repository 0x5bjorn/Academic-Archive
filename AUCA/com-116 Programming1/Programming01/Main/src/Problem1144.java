import java.util.*;

public class Problem1144 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int i=1; i<=n; ++i) {
			System.out.print(i + " ");
			int sq1 = i*i;
			System.out.print(sq1 + " ");
			int cub1 = i*i*i;
			System.out.println(cub1);
			System.out.print(i + " ");
			int sq2 = i*i+1;
			System.out.print(sq2 + " ");
			int cub2 = i*i*i+1;
			System.out.println(cub2);
		}
	}
}
