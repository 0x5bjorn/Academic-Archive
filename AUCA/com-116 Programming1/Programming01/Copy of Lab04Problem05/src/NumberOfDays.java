import java.util.*;

public class NumberOfDays {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Year? ");
		int y = input.nextInt();
		System.out.print("Month? ");
		int m = input.nextInt();
		if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
			System.out.println("Number of days: 31");
		} else if (m==4 || m==6 || m==9 || m==11){
			System.out.println("Number of days: 30");
		} else if (m==2){
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
				System.out.println("Number of days: 29");
			} else {
				System.out.println("Number of days: 28");
			}
		}
	}
}