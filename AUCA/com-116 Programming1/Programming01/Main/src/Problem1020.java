import java.util.*;

public class Problem1020 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int year = n / 365;
		int month = n % 365 / 30;
		int day = n % 365 % 30;
		System.out.printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", year, month, day);
		
		
	}
}