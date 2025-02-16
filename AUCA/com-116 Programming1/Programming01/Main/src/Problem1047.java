import java.util.*;
	
public class Problem1047 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int hour = input.nextInt();
		int min = input.nextInt();
		int hour1 = input.nextInt();
		int min1 = input.nextInt();
		int a = hour1-hour;
		int b = min1-min;
		
		if (a<=0) {
			a = 24+a;
		}
		if (b<0) {
			b = 60+b;
			a-=1;
		}
		System.out.printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", a, b);
	}
}
