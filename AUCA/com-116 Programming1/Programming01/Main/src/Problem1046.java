import java.util.*;
	
public class Problem1046 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		if (a>=b && a<24 && b<24) {
			int res = 24-a+b;
			System.out.printf("O JOGO DUROU %d HORA(S)\n", res);
		}
		else if (b>=a && a<24 && b<24) {
			int res1 = b-a;
			System.out.printf("O JOGO DUROU %d HORA(S)\n", res1);
		}
	}
}
