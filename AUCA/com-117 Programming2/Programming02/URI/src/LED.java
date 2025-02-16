import java.util.*;

public class LED {
	static int[] LED = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i=0; i<a1; ++i) {
			String n = input.nextLine();
			countLeds(n);
		}
	}
	

	static void countLeds(String n) {
		int sum = 0;
		for (int i=0; i<n.length(); ++i) {
			char a = n.charAt(i);
			int b = Integer.parseInt(String.valueOf(a));
			sum += LED[b];
		}
		System.out.println(sum + " leds");
	}
}
