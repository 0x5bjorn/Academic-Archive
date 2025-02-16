import java.util.*;

public class Problem1010 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int code = input.nextInt();
		int number = input.nextInt();
		double price = input.nextDouble();
		int code1 = input.nextInt();
		int number2 = input.nextInt();
		double price2 = input.nextDouble();
		double total = (price * number) + (price2 * number2);
		System.out.printf("VALOR A PAGAR: R$ %.2f\n", total);
			

	}

}
