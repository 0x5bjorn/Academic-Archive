import java.util.*;

public class Problem1018 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		if (N > 0 && N < 1000000) {
			int hundred = N / 100;
			int fifty = N % 100 / 10 / 5;
			int twenty = N % 100 / 10 % 5 / 2;
			int ten = N % 100 / 10 % 5 % 2;
			int five = N % 10 / 5;
			int two = N % 10 % 5 / 2;
			int one = N % 10 % 5 % 2;
			System.out.println(N);
			System.out.printf("%d nota(s) de R$ 100,00\n", hundred);
			System.out.printf("%d nota(s) de R$ 50,00\n", fifty);
			System.out.printf("%d nota(s) de R$ 20,00\n", twenty);
			System.out.printf("%d nota(s) de R$ 10,00\n", ten);
			System.out.printf("%d nota(s) de R$ 5,00\n", five);
			System.out.printf("%d nota(s) de R$ 2,00\n", two);
			System.out.printf("%d nota(s) de R$ 1,00\n", one);
		
		/*System.out.printf("%d nota(s) de R$ 100,00\n" +
						  "%d nota(s) de R$ 50,00\n" +
						  "%d nota(s) de R$ 20,00\n" +
						  "%d nota(s) de R$ 10,00\n" +
						  "%d nota(s) de R$ 5,00\n" +
						  "%d nota(s) de R$ 2,00\n" +
						  "%d nota(s) de R$ 1,00\n", hundred, fifty, twenty, ten, five, two, one);*/
		
		}
	}
}