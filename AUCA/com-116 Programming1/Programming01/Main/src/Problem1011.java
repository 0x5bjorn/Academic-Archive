import java.util.*;

public class Problem1011 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int R = input.nextInt();
		double pi = 3.14159;
		double volume = (4/3.0) * pi * R * R * R;
		System.out.printf("VOLUME = %.3f\n", volume);
			
	}	

}
