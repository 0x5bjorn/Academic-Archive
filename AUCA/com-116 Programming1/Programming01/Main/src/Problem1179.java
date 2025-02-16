import java.util.*;

public class Problem1179 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] par = new int[5];
		int[] impar = new int[5];
		int cp = 0;
		int cmp = 0;
		for (int i = 0; i < 15; ++i) {
			int a = input.nextInt();
			if (a % 2 == 0) {
				par[cp] = a;
				++cp;
			} else if (a % 2 != 0) {
				impar[cmp] = a;
				++cmp;
			}
			if (cp == 5) {
				for (int k = 0; k < cp; ++k) {
					System.out.printf("par[%d] = %d\n", k, par[k]);
				}
				cp = 0;
			}
			if (cmp == 5) {
				for (int j = 0; j < cmp; ++j) {
					System.out.printf("impar[%d] = %d\n", j, impar[j]);
				}
				cmp = 0;
			}
			if (i == 14) {
				for (int j = 0; j < cmp; ++j) {
					System.out.printf("impar[%d] = %d\n", j, impar[j]);
				}
				for (int k = 0; k < cp; ++k) {
					System.out.printf("par[%d] = %d\n", k, par[k]);
				}

			}

		}
	}
}
