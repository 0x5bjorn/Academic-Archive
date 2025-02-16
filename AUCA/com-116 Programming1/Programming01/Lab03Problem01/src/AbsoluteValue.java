import java.util.*;

public class AbsoluteValue {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		
		Scanner input = new Scanner(System.in);
		System.out.print("some real number? ");
		double number = input.nextDouble();
		double n = number;
		
		if (number < 0) {
			n *= -1;
		}
		System.out.printf("|%.3f| = %.3f",number ,n);
	}
}
