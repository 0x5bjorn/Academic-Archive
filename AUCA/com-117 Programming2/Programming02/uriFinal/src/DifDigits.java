import java.util.*;

public class DifDigits {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		
		while (input.hasNext()) {
			String n = input.next();
			String m = input.next();
			check(n, m);
		}
	}

	private static void check(String n, String m) {
		int a = Integer.parseInt(n);
		int b = Integer.parseInt(m);
		int res = 0;
		for (int i = a; i<=b; ++i) {
			HashSet<Integer> lst = new HashSet<>();
			for (int j = 0; j<String.valueOf(i).length(); ++j) {
				lst.add(String.valueOf(i).charAt(j) - '0');
			}
			if (lst.size() == String.valueOf(i).length()) ++res;
		}
		System.out.println(res);
	}
}
