import java.util.*;

public class ArithmeticMean {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int g = input.nextInt();
		double sum = 0;
		int total = 0;
		while (g!=0) {
			g = input.nextInt();
			sum += g;
			total++;
		}
		if (total!=0) {
			sum/=total;
			System.out.printf("The arithmetic mean is %.1f", sum);
		}
		else {
			System.out.println("Nothing to calculate");
		}
	}
}
