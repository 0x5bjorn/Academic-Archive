import java.util.*;

public class Queen {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int x1 = input.nextInt();
			int y1 = input.nextInt();
			int x2 = input.nextInt();
			int y2 = input.nextInt();
			
			if (x1==0 && y1==0 && x2==0 && y2==0) {
				break;
			}
			
			int dx = x1-x2;
			int dy = y1-y2;
			int t = Math.abs(dx) - Math.abs(dy);
			
			if (x1==x2 && y1==y2) {
				System.out.println("0");
			} else if (x1==x2 || y1==y2) {
				System.out.println("1");
			} else if (t==0) {
				System.out.println("1");
			} else {
				System.out.println("2");
			}
		}
	}
}
