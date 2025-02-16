import java.util.*;

public class Problem1036 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double A = input.nextDouble();
		double B = input.nextDouble();
		double C = input.nextDouble();
		double sqrt = Math.sqrt(Math.pow(B, 2) - 4*A*C);
		double R1 = (-B + sqrt) / (2*A);
		double R2 = (-B - sqrt) / (2*A);
		if ( A == 0 || (Math.pow(B, 2) - 4*A*C) < 0) {
			System.out.println("Impossivel calcular");
		}
		else {
			System.out.printf("R1 = %.5f\n", R1);
			System.out.printf("R2 = %.5f\n", R2);
		}
	}

}
