import java.util.*;

public class MaximumValue {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("1st number? ");
		int first = input.nextInt();
		System.out.print("2nd number? ");
		int second = input.nextInt();
		if (first > second) {
			System.out.printf("The first number (%d) is the greater than second (%d).", first, second);
		}
		else {
			System.out.printf("The second number (%d) is the greater or equal to first (%d).", second, first);
		}
		
	}

}
