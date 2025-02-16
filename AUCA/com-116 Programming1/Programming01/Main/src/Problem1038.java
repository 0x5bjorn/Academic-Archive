import java.util.*;
	
public class Problem1038 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double[] list = new double[6];
		list[1] = 4.00;
		list[2] = 4.50;
		list[3] = 5.00;
		list[4] = 2.00;
		list[5] = 1.50;
		int x = input.nextInt();
		int y = input.nextInt();
		double result = list[x] * y;
		System.out.printf("Total: R$ %.2f\n", result);
		
		
	}
}