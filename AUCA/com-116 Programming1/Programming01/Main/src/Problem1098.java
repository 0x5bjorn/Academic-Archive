public class Problem1098 {

	public static void main(String[] args) {
		double a = 3;
		for (double i = 0; i <= 2; i += 0.2) {
			for (double j = 1 + i; j <= a + i; ++j) {
				if (i == 0 || Math.abs(i-1)<1E-10 || Math.abs(i-2)<1E-10) {
					System.out.printf("I=%.0f J=%.0f\n", i, j);
				}
				else {
					System.out.printf("I=%.1f J=%.1f\n", i, j);
				}
			}

		}
	}
}