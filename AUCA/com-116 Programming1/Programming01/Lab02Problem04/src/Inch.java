import java.util.*;

public class Inch {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("Length in inches? ");
		double n = input.nextDouble();
		
		double result = n * 2.54;
		
		System.out.printf("%f in. = %f cm.\n", n, result);
	}

}
