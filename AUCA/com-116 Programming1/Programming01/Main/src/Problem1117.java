import java.util.*;

public class Problem1117 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input  = new Scanner(System.in);
		int i = 0;
		double aver = 0;
		while (i<2) {
			double a = input.nextDouble();
			if (a>=0 && a<=10.0) {
				++i;
				aver += a;
			}
			else {
				System.out.println("nota invalida");
			}
		}
		aver/=2;
		System.out.printf("media = %.2f\n", aver);
	}
}
