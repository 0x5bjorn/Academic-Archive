import java.util.*;

public class SeasonName {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("month? ");
		int num = input.nextInt();
		if (num == 12 || num == 1 || num == 2) {
			System.out.println("winter");
		}
		else if (num == 3 || num == 4 || num == 5) {
			System.out.println("spring");
		}
		else if (num == 6 ||	 num == 7 || num == 8) {
			System.out.println("summer");
		}
		else if (num == 9 || num == 10 || num == 11) {
			System.out.println("autumn");
		}
	}
}
