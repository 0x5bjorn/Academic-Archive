import java.util.*;

public class Problem1051 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double s = input.nextDouble();
		
		if (s<2000) {
			System.out.println("Isento");
		}
		else if (s>=2000.01 && s<=3000.00) {
			double tax = (s-2000)*8/100;
			System.out.printf("R$ %.2f\n", tax);
		}
		else if (s>=3000.01 && s<=4500.00) {
			double tax = ((s-2000)-(s-3000))*8/100 + (s-3000)*18/100;
			System.out.printf("R$ %.2f\n", tax);
		}
		else if (s>=4500.01) {
			double tax = ((s-2000)-(s-3000))*8/100 + ((s-3000)-(s-4500))*18/100 + (s-4500)*28/100;
			System.out.printf("R$ %.2f\n", tax);
		}
	}
}
