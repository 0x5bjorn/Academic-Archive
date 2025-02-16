import java.util.*;

public class Grades {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		System.out.print("Number of points? ");
		int G = input.nextInt();
		if (G <= 100 && G >= 90) {
			System.out.print("Grade: A");
		}
		else if (G < 90 && G >= 80) {
			System.out.print("Grade: B");
		}
		else if (G < 80 && G >= 70) {
			System.out.print("Grade: C");
		}
		else if (G < 70 && G >= 60) {
			System.out.print("Grade: D");
		}
		else if (G < 60) {
			System.out.print("Grade: F");
		}
		else {
			System.out.printf("%d is not in the permitted range.", G);
		}
	}

}
