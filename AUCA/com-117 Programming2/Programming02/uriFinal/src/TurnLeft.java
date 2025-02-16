import java.util.*;

public class TurnLeft {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int n = input.nextInt();
			if (n==0) break;
			
			String m = input.next();
			int dir = 0;
			execute(n, m, dir);
		}
	}

	static void execute(int n, String m, int dir) {
		for (int i = 0; i < n; ++i) {
			char c = m.charAt(i);
			if (c == 'D') {
				if (dir == 3) {
					dir = 0;
				} else {
					dir++;
				}
			} else if (c == 'E') {
				if (dir == 0) {
					dir = 3;
				} else {
					dir--;
				}
			}
		}
		
		if 		(dir == 0) System.out.println('N');
		else if (dir == 1) System.out.println('L');
		else if (dir == 2) System.out.println('S');
		else if (dir == 3) System.out.println('O');
	}
}
