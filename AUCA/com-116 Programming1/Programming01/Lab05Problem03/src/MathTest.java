import java.util.*;

public class MathTest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Random rnd = new Random();
		System.out.print("Number of tests? ");
		int n = input.nextInt();
		int cor = 0;
		int incor = 0;

		for (int i = 0; i < n; ++i) {
			int a = rnd.nextInt(100) - 50;
			int b = rnd.nextInt(100);
			System.out.printf("%d + %d = ", a, b);
			int ans = input.nextInt();
			if (ans == a+b) {
				++cor;
			} else {
				++incor;
			}
		}
		System.out.printf("Number of correct answers: %d\n", cor);
		System.out.printf("Number of incorrect answers: %d\n", incor);
	}
}
