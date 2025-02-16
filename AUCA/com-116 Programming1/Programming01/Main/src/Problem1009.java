import java.util.*;

public class Problem1009 {

	public static void main(String[] args) {
			Scanner input = new Scanner(System.in);
			String name = input.next();
			double fsalary = input.nextDouble();
			double msalary = input.nextDouble();
			double total = fsalary + (msalary * 15 / 100);
			System.out.printf("TOTAL = R$ %.2f\n", total);
			

	}

}
