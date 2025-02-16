
import java.util.*;

public class LottoNumbers {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		boolean[] isCovered = new boolean[99];

		int n = input.nextInt();
		while (n != 0) {
			isCovered[n - 1] = true;
			n = input.nextInt();
		}
		boolean allCovered = true;
		for (int i = 0; i < 99; ++i) {
			if (!isCovered[i]) {
				allCovered = false;
				break;
			}
		}
		if (allCovered) {
			System.out.println("The tickets cover all numbers");
		} else {
			System.out.println("The tickets don't cover all numbers");
		}
	}
}
