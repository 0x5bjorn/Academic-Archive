import java.util.*;

public class Problem1116 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int i=0; i<n; ++i) {
			int a = input.nextInt();
			int b = input.nextInt();
			if (b==0) {
				System.out.println("divisao impossivel");
			}
			else {
				double res = (double) a/b;
				System.out.println(res);
			}
		}
	}
}
