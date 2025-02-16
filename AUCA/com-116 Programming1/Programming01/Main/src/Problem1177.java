import java.util.*;

public class Problem1177 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int x = input.nextInt();
		int[] list = new int[1000];
		for (int i = 0, j = 0; j <= x && i < list.length; ++j, ++i) {
			if (j==x) {
				j-=x;
			}
			list[i] = j;
			System.out.printf("N[%d] = %d\n", i, list[i]);
		}
	}
}
