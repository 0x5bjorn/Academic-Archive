import java.util.*;

public class ArrayHash {
	static String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char[] alph = alphabet.toCharArray();
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);

		for (int i = 0; i < a1; ++i) {
			String b = input.nextLine();
			int b1 = Integer.parseInt(b);
			String[] arr = new String[b1];
			for (int j = 0; j < b1; j++) {
				arr[j] = input.nextLine();
			}
			count(b1, arr);
		}
	}

	static void count(int b1, String[] arr) {
		int result = 0;
		for (int i = 0; i < b1; ++i) {
			char[] chr = arr[i].toCharArray();
			for (int j = 0; j < chr.length; ++j) {
				for (int k = 0; k < alph.length; ++k) {
					if (chr[j] == alph[k]) {
						result += (k + j + i);
					}
				}
			}
		}
		System.out.println(result);
	}
}
