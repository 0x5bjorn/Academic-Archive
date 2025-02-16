import java.util.*;

public class Problem1061 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.next();
		int d1 = input.nextInt();
		int h1 = input.nextInt();
		String a1 = input.next();
		int m1 = input.nextInt();
		String a2 = input.next();
		int s1 = input.nextInt();
		
		String a3 = input.next();
		int d2 = input.nextInt();
		int h2 = input.nextInt();
		String a4 = input.next();
		int m2 = input.nextInt();
		String a5 = input.next();
		int s2 = input.nextInt();
		
		int d = d2-d1;
		int h = h2-h1;
		int m = m2-m1;
		int s = s2-s1;
		
		if (h<0) {
			h = 24+h;
			d-=1;
		}
		if (m<0) {
			m = 60+m;
			h-=1;
		}
		if (s<0) {
			s = 60+s;
			m-=1;
		}
		System.out.printf("%d dia(s)\n", d);
		System.out.printf("%d hora(s)\n", h);
		System.out.printf("%d minuto(s)\n", m);
		System.out.printf("%d segundo(s)\n", s);
	}
}
