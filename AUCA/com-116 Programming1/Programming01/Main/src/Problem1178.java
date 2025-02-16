import java.util.*;

public class Problem1178 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double x = input.nextDouble();
		double[] list = new double[100];
		for (int i = 0; i < list.length; ++i, x/=2) {
			list[i] = x;
			System.out.printf("N[%d] = %.4f\n", i, list[i]);
		}
	}
}
