import java.util.Scanner;

public class Swapper2 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("1st value? ");
		int first = input.nextInt();

		System.out.print("2nd value? ");
		int second = input.nextInt();
		
		System.out.println("Before swapping: a = " + first + "; b = " + second + ";");
		
		first = first + second;
		second = first - second;
		first = first - second;
		
		System.out.println("After swapping: a = " + first + "; b = " + second + ";");

	}

}
