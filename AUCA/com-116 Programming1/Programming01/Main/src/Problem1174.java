import java.util.*;

public class Problem1174 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int[] list = new int[100];
	 	for (int i=0; i<list.length; ++i) {
	 		double n = input.nextDouble();
	 		if (n<=10.0) {
	 			System.out.printf("A[%d] = %.1f\n", i, n);
	 		}
		 }
	}
}
