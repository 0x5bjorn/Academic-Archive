import java.util.*;

public class Problem1074 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int x = 0;
		while (x<n) {
			int b = input.nextInt();
			if (b>=0 && b%2==0){
				if (b==0) {
					System.out.println("NULL");
				}
				else {
					System.out.println("EVEN POSITIVE");
				}
			}
			if (b>0 && b%2!=0) {
				System.out.println("ODD POSITIVE");
			}
			if (b<0 && b%2==0){
				System.out.println("EVEN NEGATIVE");
			}
			if (b<0 && b%2!=0) {
				System.out.println("ODD NEGATIVE");
			}	
			++x;
		}
	}
}
