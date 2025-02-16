import java.util.*	;

public class Problem1017 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int hours = input.nextInt();
		int km = input.nextInt();
		double fuel = km*hours/12.0;
		System.out.printf("%.3f\n", fuel);
	}

}
