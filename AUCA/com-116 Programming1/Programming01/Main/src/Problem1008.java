import java.util.*;

public class Problem1008 {

	public static void main(String[] args) {
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			int hoursnumber = input.nextInt();
			double perhour = input.nextDouble();
			System.out.printf("NUMBER = %d\n", number);
			double salary = hoursnumber * perhour;
			System.out.printf("SALARY = U$ %.2f\n", salary);
	}
}
