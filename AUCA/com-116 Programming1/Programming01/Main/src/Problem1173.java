import java.util.*;

public class Problem1173 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int[] list = new int[10];
	 	for (int i=0; i<list.length; ++i, n*=2) {
			System.out.printf("N[%d] = %d\n", i, n);
		}
	}
}
