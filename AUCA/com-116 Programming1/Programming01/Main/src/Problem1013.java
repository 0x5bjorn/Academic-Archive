import java.util.*;

public class Problem1013 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		int c = input.nextInt();
		int abs1 = (a + b + Math.abs(a-b))/2;
		int abs2 = (a + c + Math.abs(a-c))/2;
		int abs = (abs1 + abs2 + Math.abs(abs1-abs2))/2;
		
		System.out.printf("%d eh o maior", abs);
	}

}
