import java.util.*;

public class Calculator {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("1st number? ");
		int first = input.nextInt();
		
		System.out.print("2nd number? ");
		int second = input.nextInt();
		
		System.out.printf("%d + %d = %d", first, second, first + second);
	}
}
