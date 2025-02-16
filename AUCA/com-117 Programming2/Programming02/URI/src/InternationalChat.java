import java.util.*;

public class InternationalChat {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			String b = input.nextLine();
			int b1 = Integer.parseInt(b);
			String[] arr = new String[b1];
			for (int j = 0; j < b1; ++j) {
				arr[j] = input.nextLine();
			}
			chat(arr, b1);
		}
	}

	private static void chat(String[] arr, int b1) {
		String l = arr[0];
		int n = 1;
		for (int i = 1; i < b1; ++i) {
			if (arr[i].equals(l)) {
				n++;
			}
		}
		if (n==b1) {
			System.out.println(arr[0]);
		} else {
			System.out.println("ingles");
		}
	}
}
