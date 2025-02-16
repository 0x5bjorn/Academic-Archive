import java.util.*;

public class Problem1094 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		int c = 0;
		int r = 0;
		int s = 0;
		for (int i=0; i<t; ++i) {
			int n = input.nextInt();
			String a = input.next();
			if (a.equals("C")) {
				c+=n;
			}
			else if (a.equals("R")) {
				r+=n;
			}
			else if (a.equals("S")) {
				s+=n;
			}
		}
		int total = c+r+s;
		double percC = (c*100.0)/total;
		double percR = (r*100.0)/total;
		double percS = (s*100.0)/total;
		System.out.printf("Total: %d cobaias\n", total);
		System.out.printf("Total de coelhos: %d\n", c);
		System.out.printf("Total de ratos: %d\n", r);
		System.out.printf("Total de sapos: %d\n", s);
		System.out.printf("Percentual de coelhos: %.2f ", percC);
		System.out.println("%");
		System.out.printf("Percentual de ratos: %.2f ", percR);
		System.out.println("%");
		System.out.printf("Percentual de sapos: %.2f ", percS);
		System.out.println("%");
	}
}
