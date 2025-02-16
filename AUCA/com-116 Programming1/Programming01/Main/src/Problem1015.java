import java.util.*;

public class Problem1015 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double x1 = input.nextDouble();
		double y1 = input.nextDouble();
		double x2 = input.nextDouble();
		double y2 = input.nextDouble();
		double D = Math.sqrt(Math.pow((x2 - x1),2) + Math.pow((y2 - y1),2));
		System.out.printf("%.4f\n", D);
	}
}
