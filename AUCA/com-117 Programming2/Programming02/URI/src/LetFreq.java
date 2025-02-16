import java.util.*;

public class LetFreq {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.nextLine();
			freq(m);
		}
	}

	static void freq(String m) {
		String alph = "abcdefghijklmnopqrstuvwxyz";
		char[] alp = alph.toCharArray();
		String m1 = m.toLowerCase();
		int[] count = new int[26];
		for (int i = 0; i < alph.length(); i++) {
			for (int j = 0; j < m1.length(); j++) {
				if (alph.charAt(i) == m1.charAt(j)) {
					++count[i];
				}
			}
		}
		for (int i = 0; i < alph.length(); i++) {
			if (count[i] == Max(count)) {
				System.out.print(alp[i]);
			}
		}
		System.out.println();
	}

	static int Max(int[] count) {
		int max = 0;
		for (int i = 0; i < 26; ++i) {
			int a = count[i];
			if (max < a) {
				max = a;
			}
		}
		return max;
	}
}