import java.util.*;

public class MultRead {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextLine()) {
			String m = input.nextLine();
			String n = input.nextLine();
			int n1 = Integer.parseInt(n);
			read(m, n1);
		}
	}

	static void read(String m, int n1) {
		int sum = 0;
		int count = 0;
		for (int i = 0; i < m.length(); ++i) {
			char c1 = m.charAt(i);
			if (c1 == 'W') {
				++sum;
				if (count > 0) {
					++sum;
					count = 0;
				}
			}
			if (c1 == 'R') {
				++count;
				if (count == n1) {
					++sum;
					count = 0;
				}
			}
		}
		if (count > 0) {
			++sum;
		}
		System.out.println(sum);
	}
}
