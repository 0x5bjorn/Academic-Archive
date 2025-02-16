import java.util.*;

public class OpticalReader {
	static Scanner input = new Scanner(System.in);
	static String grades = "ABCDE";
	static char[] gr = grades.toCharArray();

	public static void main(String[] args) {
		while (true) {
			int n = input.nextInt();
			if (n == 0) break;
			for (int i = 0; i < n; ++i) {
				check();
			}
		}
	}

	static void check() {
		int[] lst = new int[5];
		int index = 0;
		int count = 0;
		for (int j = 0; j < 5; ++j) {
			lst[j] = input.nextInt();
			if (lst[j] < 128) {
				count++;
				index = j;
			}
		}
		if (count==1) System.out.println(gr[index]);
		else System.out.println("*");
	}
}
