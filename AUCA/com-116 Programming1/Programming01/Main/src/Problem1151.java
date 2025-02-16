import java.util.*;

public class Problem1151 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int[] list = new int[47];
		list[0] = 0;
		list[1] = 1;
		if (a > 2) {
			for (int i = 2; i < 47; ++i) {
				list[i] = list[i - 1] + list[i - 2];
			}
			for (int i = 0; i < a-1; ++i) {
				System.out.print(list[i] + " ");
			}
			System.out.println(list[a-1]);
		} else {
			System.out.print(list[0] + " " + list[1]);
		}
	}
}
