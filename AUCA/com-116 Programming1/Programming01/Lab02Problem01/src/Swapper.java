import java.util.*;

public class Swapper {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("1st value? ");
		int first = input.nextInt();

		System.out.print("2nd value? ");
		int second = input.nextInt();
		
		System.out.println("Before swapping: a = " + first + "; b = " + second + ";");
		
		int temp = first;
		first = second;
		second = temp;
		
		System.out.println("After swapping: a = " + first + "; b = " + second + ";");

	}

}
