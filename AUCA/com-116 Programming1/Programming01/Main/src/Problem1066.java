import java.util.*;

public class Problem1066 {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int a = 0;
		int even = 0;
		int odd = 0;
		int pos = 0;
		int neg = 0;
		while (a<5) {
			int n = input.nextInt();
			if (n%2==0) {
				++even;
			}
			if (n%2!=0) {
				++odd;
			}
			if (n>0) {
				++pos;
			}
			if (n<0) {
				++neg;
			}
			++a;
		}
		System.out.printf("%d valor(es) par(es)\n", even);
		System.out.printf("%d valor(es) impar(es)\n", odd);
		System.out.printf("%d valor(es) positivo(s)\n", pos);
		System.out.printf("%d valor(es) negativo(s)\n", neg);
	}
}
