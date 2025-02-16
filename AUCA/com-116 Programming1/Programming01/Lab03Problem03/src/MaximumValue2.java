import java.util.*;

public class MaximumValue2 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("1st number? ");
		int first = input.nextInt();
		System.out.print("2nd number? ");
		int second = input.nextInt();
		System.out.print("3rd number? ");
		int third = input.nextInt();
		if (first > second && first > third) {
			System.out.printf("The value %d is the greatest one.", first);
		}
		else if (second > first && second > third) {
			System.out.printf("The value %d is the greatest one.", second);
		}
		else {
			System.out.printf("The value %d is the greatest one.", third);
		}
	}

}
