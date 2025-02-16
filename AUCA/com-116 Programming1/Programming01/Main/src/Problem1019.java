import java.util.*;

public class Problem1019 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int hours = N / 3600;
		int minutes = N % 3600 / 60;
		int seconds = N % 60;
		System.out.printf("%d:%d:%d\n", hours, minutes, seconds);
		
		
	}
}