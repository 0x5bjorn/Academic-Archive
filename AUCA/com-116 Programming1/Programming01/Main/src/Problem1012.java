import java.util.*;

public class Problem1012 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double A = input.nextDouble();
		double B = input.nextDouble();
		double C = input.nextDouble();
		double pi = 3.14159;
		double triangle = (0.5) * A * C;
		double circle =  pi * C * C;
		double trapezium = C * (A + B)/2;
		double square = B * B;
		double rectangle = A * B;
		System.out.printf("TRIANGULO: %.3f\nCIRCULO: %.3f\nTRAPEZIO: %.3f\nQUADRADO: %.3f\nRETANGULO: %.3f\n", 
				triangle, circle, trapezium, square, rectangle);
			
	}

}
