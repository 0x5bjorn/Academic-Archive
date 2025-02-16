import java.util.*;
	
public class Problem1042 {
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		int c = input.nextInt();
		
		int[] list = {a, b, c};
		int[] list1 = {a, b, c};
		
		Arrays.sort(list);
		for (int n : list) {
			System.out.println(n);
		}
		System.out.println("");
		for (int n: list1) {
			System.out.println(n);
		}
		
	}
}