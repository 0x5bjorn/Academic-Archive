import java.util.*;

public class DigitCalculator {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("A four-digit integer? ");
		int a = input.nextInt();
		
		int result = a / 1000     + 
					 a / 100 % 10 + 
					 a / 10 % 10  + 
					 a % 10;
				
		System.out.print("The sum of all digits is " + result);

	}

}
