import java.util.*;

public class Zero {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			String m = input.next();
			String m1 = input.next();
			if (m.equals("0") && m1.equals("0")) {
				break;
			}
			remove(m, m1);
		}
	}

	static void remove(String m, String m1) {
		int a = Integer.parseInt(m);
		int a1 = Integer.parseInt(m1);
		int sum = a + a1;
		String[] sum1 = String.valueOf(sum).split("0", 0);
		for (int i = 0; i < sum1.length-1; i++) {
			System.out.print(sum1[i]);
		}
		System.out.println(sum1[sum1.length-1]);
	}
}
