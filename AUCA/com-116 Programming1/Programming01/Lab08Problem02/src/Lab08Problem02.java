import java.util.Scanner;

public class Lab08Problem02 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (true) {
			System.out.print("Year? ");
			if (!input.hasNextInt()) {
				break;
			}
			int y = input.nextInt();

			System.out.print("Month? ");
			if (!input.hasNextInt()) {
				break;
			}
			int m = input.nextInt();

			int d = getNumberOfDays(y, m);
			System.out.printf("Number of days: %d\n", d);
		}
	}

	static int getNumberOfDays(int y, int m) {
		int[] days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (m != 2) {
			return days[m - 1];
		}
		return isLeapYear(y) ? 29 : 28;
	}

	static boolean isLeapYear(int y) {
		return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	}
}
