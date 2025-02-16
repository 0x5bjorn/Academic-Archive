import java.util.*;

public class Volume {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("1st dimension? ");
		int first = input.nextInt();
		System.out.print("2nd dimension? ");
		int second = input.nextInt();
		System.out.print("3rd dimension? ");
		int third = input.nextInt();
		System.out.printf("The volume of the box (%d * %d * %d) is %d", 
				first, second, third, first * second * third);
	}
}
