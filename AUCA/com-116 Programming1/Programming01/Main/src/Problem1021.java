import java.util.*;

public class Problem1021 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		double N = input.nextDouble();
		
		int N1 = (int) N;
		double N2 = (N-N1)*100;
		int N3 = (int) N2;
		
		int hundred = N1 /100;
		N1 %= 100;
		int fifty = N1 / 50;
		N1 %= 50; 	
		int twenty = N1 / 20;
		N1 %= 20; 	
		int ten = N1 / 10;
		N1 %= 10; 	
		int five = N1 / 5;
		N1 %= 5;
		int two = N1 / 2;
		N1 %= 2; 	
		System.out.println("NOTAS:");
		System.out.printf("%d nota(s) de R$ 100.00\n", hundred);
		System.out.printf("%d nota(s) de R$ 50.00\n", fifty);
		System.out.printf("%d nota(s) de R$ 20.00\n", twenty);
		System.out.printf("%d nota(s) de R$ 10.00\n", ten);
		System.out.printf("%d nota(s) de R$ 5.00\n", five);
		System.out.printf("%d nota(s) de R$ 2.00\n", two);
		int one = N1 / 1;
		int half = N3 / 50;
		N3 %= 50;
		int quater = N3 / 25;
		N3 %= 25;
		int ten2 = N3 / 10;
		N3 %= 10;
		int five2 = N3 / 5;
		N3 %= 5;
		int one2 = N3 / 1;
		N3 %= 1;
		System.out.println("MOEDAS:");
		System.out.printf("%d moeda(s) de R$ 1.00\n", one);
		System.out.printf("%d moeda(s) de R$ 0.50\n", half);
		System.out.printf("%d moeda(s) de R$ 0.25\n", quater);
		System.out.printf("%d moeda(s) de R$ 0.10\n", ten2);
		System.out.printf("%d moeda(s) de R$ 0.05\n", five2);
		System.out.printf("%d moeda(s) de R$ 0.01\n", one2);
	}
}