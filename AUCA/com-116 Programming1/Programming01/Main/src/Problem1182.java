import java.util.*;

public class Problem1182 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		double m[][] = new double[12][12];
		int l = input.nextInt();
		String t = input.next();

		double sum = 0;

		for (int r = 0; r < m.length; ++r) {
			for (int c = 0; c < m.length; ++c) {
				m[r][c] = input.nextDouble();
				if (c == l) {
					sum += m[r][c];
				}
			}
		}
		if (t.equals("S")) {
			System.out.printf("%.1f\n", sum);
		} else if (t.equals("M")) {
			sum /= m.length;
			System.out.printf("%.1f\n", sum);
		}
	}
}
