import java.util.*;

public class LostBoots {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {

		while (input.hasNextLine()) {
			int n = input.nextInt();
			ArrayList<Integer> s = new ArrayList<Integer>();
			ArrayList<String> p = new ArrayList<String>();
			for (int j = 0; j < n; ++j) {
				s.add(input.nextInt());
				p.add(input.next());
			}
			findPairs(n, s, p);
		}
	}

	static void findPairs(int n, ArrayList<Integer> s, ArrayList<String> p) {
		int count = 0;
		int[] r = new int[100];
		int[] l = new int[100];

		for (int i = 0; i < n; ++i) {
			if (p.get(i).equals("D")) {
				++r[s.get(i)];
			} else {
				++l[s.get(i)];
			}
		}

		for (int i = 0; i < 100; ++i) {
			count += Math.min(r[i], l[i]);
		}
		System.out.println(count);
	}
}
