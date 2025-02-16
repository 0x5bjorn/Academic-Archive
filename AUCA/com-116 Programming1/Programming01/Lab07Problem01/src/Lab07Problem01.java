import java.util.*;

public class Lab07Problem01 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Your coordinate: ");
		int x = input.nextInt();
		
		System.out.print("Coordinate of 1st point: ");
		int x1 = input.nextInt();
		
		System.out.print("Coordinate of 2nd point: ");
		int x2 = input.nextInt();
		
		int d1 = abs(x-x1);
		int d2 = abs(x-x2);
		
		if (d1<d2) {
			System.out.printf("1st point is closer. Distance %d\n", d1);
		} else if (d1>d2) {
			System.out.printf("2nd point is closer. Distance %d\n", d2);
		} else {
			System.out.println("Same distance");
		}
	}
	
	static int abs(int x) {
		int r = x;
		if (r<0) {
			r = -r;
		}
		return r;
	}
}
