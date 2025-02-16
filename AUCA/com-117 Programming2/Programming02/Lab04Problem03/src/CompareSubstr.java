import java.util.*;

public class CompareSubstr {

}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextLine()) {
			String m1 = input.nextLine();
			String m2 = input.nextLine();
			compare(m1, m2);
		}
	}

	static void compare(String m1, String m2) {
		for (int i = 0; i < Max(m1, m2); ++i) {
			for (int j = 0; j < Min(m1, m2); ++j) {
				char c = 
			}
		}
	}

	static int Min(String m1, String m2) {
		int min = m1.length();
		if (min > m2.length()) {
			min = m2.length();
		}
		return min;
	}

	static int Max(String m1, String m2) {
		int max = m1.length();
		if (max < m2.length()) {
			max = m2.length();
		}
		return max;
	}
}
