import java.util.*;

public class Problem1014 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int km = input.nextInt();
		double fuel = input.nextDouble();
		double consumption = km / fuel;
		System.out.printf("%.3f km/l\n", consumption);

	}

}
