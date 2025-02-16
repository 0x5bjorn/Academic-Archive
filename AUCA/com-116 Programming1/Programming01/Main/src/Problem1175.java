import java.util.*;

public class Problem1175 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] list = new int[20];
		int fst = 0;
		int lst = list.length-1;
		for (int i = 0; i<list.length; ++i) {
			list[i] = input.nextInt();
		}
		while (fst<lst) {
			int t = list[fst];
			list[fst] = list[lst];
			list[lst] = t;
			++fst;
			--lst;
		}
		for (int i = 0; i < list.length; ++i) {
			System.out.printf("N[%d] = %d\n", i, list[i]);
		}
	}
}
