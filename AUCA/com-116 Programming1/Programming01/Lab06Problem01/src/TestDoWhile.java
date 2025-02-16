import java.util.*;

public class TestDoWhile {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int d;
		int sum = 0;
		do {
			System.out.print("Enter an int value (the program exits if the input is 0): ");
			d = input.nextInt();
			sum += d;
		} while (d != 0);
		System.out.println("The sum is " + sum);
	}
}