import java.util.*;

public class Problem1052 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
	/*	if (n==1) {
			System.out.println("January");
		}
		else if (n==2) {
			System.out.println("February");
		}
		*/
		int[] list = {0,1,2,3,4,5,6,7,8,9,10,11,12};
		String[] list1 = {"","January","February","March",
						  "April","May","June",
						  "July","August","September",
						  "October","November","December"};
		for (int n1: list) {
			System.out.println(list1[n]);
			break;
		}
	}

}
