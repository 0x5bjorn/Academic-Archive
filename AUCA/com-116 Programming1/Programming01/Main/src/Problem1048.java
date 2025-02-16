import java.util.*;

public class Problem1048 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double s = input.nextDouble();
		if (s>=0 && s<=400.00) {
			double perc = s/100*15;
			double s1 = s + perc;
			System.out.printf("Novo salario: %.2f\n", s1);
			System.out.printf("Reajuste ganho: %.2f\n", perc);
			System.out.println("Em percentual: 15 %");			
		}
		else if (s>=400.01 && s<=800.00) {
			double perc = s/100*12;
			double s1 = s + perc;
			System.out.printf("Novo salario: %.2f\n", s1);
			System.out.printf("Reajuste ganho: %.2f\n", perc);
			System.out.println("Em percentual: 12 %");			
		}
		else if (s>=800.01 && s<=1200.00) {
			double perc = s/100*10;
			double s1 = s + perc;
			System.out.printf("Novo salario: %.2f\n", s1);
			System.out.printf("Reajuste ganho: %.2f\n", perc);
			System.out.println("Em percentual: 10 %");			
		}
		else if (s>=1200.01 && s<=2000.00) {
			double perc = s/100*7;
			double s1 = s + perc;
			System.out.printf("Novo salario: %.2f\n", s1);
			System.out.printf("Reajuste ganho: %.2f\n", perc);
			System.out.println("Em percentual: 7 %");			
		}
		else if (s>2000.00) {
			double perc = s/100*4;
			double s1 = s + perc;
			System.out.printf("Novo salario: %.2f\n", s1);
			System.out.printf("Reajuste ganho: %.2f\n", perc);
			System.out.println("Em percentual: 4 %");			
		}		
	}
}
