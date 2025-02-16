import java.util.*;

public class SumOfDigits {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Integer? ");
		int n = input.nextInt();
		int total = 0;
		while (n!=0) {
			total += n%10;
			n/=10;
		}
		System.out.printf("The sum of all digits is %d\n", total);
	}
}
