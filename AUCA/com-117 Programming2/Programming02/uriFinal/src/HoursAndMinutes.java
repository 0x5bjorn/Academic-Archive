import java.util.*;

public class HoursAndMinutes {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (input.hasNextLine()) {
			String m = input.nextLine();
			if (Integer.parseInt(m) % 6 == 0) {
				System.out.println("Y");
			} else {
				System.out.println("N");
			}
		}
	}
}