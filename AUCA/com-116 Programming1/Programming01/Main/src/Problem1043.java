import java.util.*;

public class Problem1043 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double a = input.nextDouble();
		double b = input.nextDouble();
		double c = input.nextDouble();
		if (a<b+c && b<a+c && c<a+b){
			double perimeter = a+b+c;
			System.out.printf("Perimetro = %.1f\n", perimeter);
		}
		else {
			double area = (a+b)/2 * c;
			System.out.printf("Area = %.1f\n", area);
		}
		
		
	}
}