import java.util.*;

public class Problem1160 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for (int i = 0; i < t; ++i) {
			long pa = input.nextLong();
			long pb = input.nextLong();
			double g1 = input.nextDouble();
			double g2 = input.nextDouble();
			long y = 0;
			if (pa < pb) {
				while (pa <= pb) {
					pa += (long) (pa * (g1 / 100));
					pb += (long) (pb * (g2 / 100));
					++y;
				}
				if (y > 100) {
					System.out.println("Mais de 1 seculo.");
				} else {
					System.out.printf("%d anos.\n", y);
				}
			}
		}
	}
}
