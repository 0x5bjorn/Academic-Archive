import java.util.*;
	
public class Problem1045 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double a = input.nextDouble();
		double b = input.nextDouble();
		double c = input.nextDouble();
		if (a>=b+c || b>=a+c || c>=a+b) {
			System.out.println("NAO FORMA TRIANGULO");
		}
		else if (Math.pow(a, 2) == Math.pow(b, 2) + Math.pow(c, 2) ||
				 Math.pow(b, 2) == Math.pow(a, 2) + Math.pow(c, 2) ||
				 Math.pow(c, 2) == Math.pow(b, 2) + Math.pow(a, 2)	 ) {
			System.out.println("TRIANGULO RETANGULO");
		}
		else if (Math.pow(a, 2) > Math.pow(b, 2) + Math.pow(c, 2) ||
				 Math.pow(b, 2) > Math.pow(a, 2) + Math.pow(c, 2) ||
				 Math.pow(c, 2) > Math.pow(b, 2) + Math.pow(a, 2)	) {
			System.out.println("TRIANGULO OBTUSANGULO");
		}
		else if (Math.pow(a, 2) < Math.pow(b, 2) + Math.pow(c, 2) ||
				 Math.pow(b, 2) < Math.pow(a, 2) + Math.pow(c, 2) ||
				 Math.pow(c, 2) < Math.pow(b, 2) + Math.pow(a, 2)	) {
			System.out.println("TRIANGULO ACUTANGULO");
		}
		if (a==b && a==c && b==c) {
			System.out.println("TRIANGULO EQUILATERO");
		}
		else if (a==b || a==c || b==c) {
			System.out.println("TRIANGULO ISOSCELES");
		}	
		
	}
}