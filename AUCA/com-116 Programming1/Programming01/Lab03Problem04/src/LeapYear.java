import java.util.*;

public class LeapYear {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Year? ");
		int y = input.nextInt();
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
			System.out.println("This is a leap year.");
		}
		else {
			System.out.println("This is not a leap year.");
		}
	}

}
