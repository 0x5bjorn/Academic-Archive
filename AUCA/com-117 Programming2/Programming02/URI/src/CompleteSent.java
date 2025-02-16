import java.util.Scanner;

public class CompleteSent {
	static String alphabet = "abcdefghijklmnopqrstuvwxyz";
	static char[] alph = alphabet.toCharArray();

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String m = input.nextLine();
			if (count(m)>=26) {
				System.out.println("frase completa");
			} else if (count(m)>=26/2 && count(m)<26) {
				System.out.println("frase quase completa");
			} else if (count(m)<=26/2) {
				System.out.println("frase mal elaborada");
			}
		}
	}

	static int count(String m) {
		int total = 0;
		int count[] = new int[26];
		for (int i = 0; i < alph.length; ++i) {
			for (int j = 0; j < m.length(); ++j) {
				char c = m.charAt(j);
				if (c == alph[i]) {
					++count[i];
				}
			}
		}
		for (int i = 0; i < alphabet.length(); ++i) {
			if (count[i] >= 1) {
				++total;
			}
		}
		return total;
	}
}
