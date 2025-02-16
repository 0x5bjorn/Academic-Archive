import java.util.*;

public class Problem1118 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		boolean n = true;
		int i = 0;
		double aver = 0;
		while (n) {
			while (i < 2) {
				double a = input.nextDouble();
				if (a >= 0 && a <= 10.0) {
					++i;
					aver += a;
				} else {
					System.out.println("nota invalida");
				}
			}
			aver /= 2;
			System.out.printf("media = %.2f\n", aver);
			System.out.println("novo calculo (1-sim 2-nao)");
			int c = input.nextInt();
			while (c<1 || c>2) {
				System.out.println("novo calculo (1-sim 2-nao)");
				c = input.nextInt();
			}
			if (c==1) {
				aver=0;
				i-=2;
				n=true;
			}
			else {
				n=false;
			}
		}
	}
}
